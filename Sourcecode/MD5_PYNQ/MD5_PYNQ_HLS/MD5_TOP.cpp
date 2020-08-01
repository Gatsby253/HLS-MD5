#include "md5.h"

// This function is the top module.
void MD5(axis_stream* data, ap_uint<32> len0, ap_uint<32> len1, axis_stream * md5_value)
{
#pragma HLS INTERFACE axis  port=data      bundle=INPUT   //depth=272
#pragma HLS INTERFACE axis  port=md5_value bundle=OUTPUT  //depth=16
// The depth is just for cosimulation.
// When cosimulation we must add the depth. When synthesis we can delete the depth.

#pragma HLS INTERFACE s_axilite port=len0 bundle=CONTROL_BUS offset=0x14 clock=AXI_LITE_clk
#pragma HLS INTERFACE s_axilite port=len1 bundle=CONTROL_BUS offset=0x1C clock=AXI_LITE_clk
#pragma HLS INTERFACE s_axilite port=return bundle=CONTROL_BUS clock=AXI_LITE_clk

#pragma HLS INTERFACE ap_stable port=len0
#pragma HLS INTERFACE ap_stable port=len1


    ap_uint<64> ret_size;				//64-bit length of the input
    ret_size.range(31, 0) = len0;
    ret_size.range(63,32) = len1;
	MD5_CTX md5_pack;

	MD5Init(&md5_pack, ret_size<<3);	//Initialize the MD5 struct

	//Load data and do the MD5 calculation
	ap_uint<8> remainder = ret_size.range(6, 0);			//The remainder = ret_size % 64
	ap_uint<8> j;
	ap_uint<64> i;
	ap_uint<64> loop_counter = ret_size >> 6;				//The loop_counter = ret_size / 64

	Loop_MD5:												//Calculate MD5 : the 64-byte fragments
	for(i=0; i<loop_counter; i++){
	#pragma HLS PIPELINE
	#pragma HLS LOOP_TRIPCOUNT min=0 max=1023

		for(int j = 0; j < 16; j++){
		#pragma HLS UNROLL
			md5_pack.buffer[j] = data->data;
			data++;
		}

		MD5Transform(md5_pack.state, md5_pack.buffer);
    }

	//Calculate MD5: pad and calculate the last fragment whose length < 64
    ap_uint<8> index;
    ap_uint<8> ret;
    ap_uint<8> pad_length;
    ap_uint<64> data_size;
    ap_uint<32> pad_data;

    index = remainder>>2;								    //Add the data of the last fragment
    Loop_Load1:
    for(j = 0; j < index; j++){
	#pragma HLS LOOP_TRIPCOUNT min=0 max=15
    	md5_pack.buffer[j] = data->data;
		data++;
	}

    ret  = (4 - (remainder & 0x03))<<3;
    if(ret==32)
    	pad_data = 0x00000080;
    else
    	pad_data = (data->data) | (0x00000080<<ret);

    pad_length = (remainder<56) ? 14-1-index : 30-1-index;	//Judge if there's enough room for adding the length to the last fragment

    md5_pack.buffer[index] = pad_data;		//Pad the byte including 0x80
    index++;

    Loop_padding:							//Pad 0
    for(j = pad_length; j>0; j--){
	#pragma HLS LOOP_TRIPCOUNT min=0 max=30
    	if(index==16){
    	    MD5Transform(md5_pack.state, md5_pack.buffer);	//If no room for adding the length, add one more fragment
    	    index=0;
    	}
    	md5_pack.buffer[index] = 0;
        index++;
    }

    md5_pack.buffer[14] = md5_pack.data_len[0];				//Add the length
    md5_pack.buffer[15] = md5_pack.data_len[1];
    MD5Transform(md5_pack.state, md5_pack.buffer);

// Offload the result and reverse the order
    MD5Offload(&md5_pack, md5_value);
}


