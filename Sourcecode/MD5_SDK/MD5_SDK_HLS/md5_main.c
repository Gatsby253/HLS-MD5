#include "md5.h"
// This function "md5" is the md5 function but not the top module of the whole design
// However, when C simulation and cosimulation, the top module should be this "md5"

// In this design we have to specify a maximum input and output length.
int md5(char data_in[LENGTH], uint8 md5_value[16])
{
#pragma HLS ARRAY_PARTITION variable=md5_value complete dim=1
	uint64 ret_size;									//64-bit length of the input
	MD5Length(data_in, &ret_size);						//Use FPGA to calculate the length of the input
	uint32 md5_value_temp[4];

	uint32 * data = (uint32 *)data_in;

	MD5_CTX md5;
	MD5Init(&md5, ret_size<<3);							//Initialize the MD4 struct
	uint64 loop_counter = ret_size >> 6;				//loop_count = length / 64
	uint8 remainder = ret_size&0x000000000000003F;		//remainder = length % 64
	uint64 i;
	uint64 j = 0;
	Loop_MD5:
    for(i=0; i<loop_counter; i++){						//Calculate MD5 : the 64-byte fragments
	#pragma HLS PIPELINE
	#pragma HLS LOOP_TRIPCOUNT min=0 max=256
        MD5Update(&md5, &data[j]);
        j= j + 16;
    }

    MD5Padding(&md5, &data[j], remainder);			  	//Calculate MD5: pad and calculate the last fragment whose length < 64

//  divide, reverse and load for output
    Loop_Divide:
	for(uint8 k = 0; k < 4; k++){
	#pragma HLS UNROLL
		*(md5_value+4*k) = md5.state[k];
		*(md5_value+4*k+1) = md5.state[k] >> 8;
		*(md5_value+4*k+2) = md5.state[k] >> 16;
		*(md5_value+4*k+3) = md5.state[k] >> 24;
	}

	return 0;
}
