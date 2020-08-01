#include "md5.h"
#include "string.h"
// This function "md5_top" is the top module of the whole design
// Note that when C simulation and cosimulation this "md5_top" should not the top module
void md5_top(
		volatile uint8 *inout_t
		){
#pragma HLS INTERFACE m_axi depth=50 port=inout_t offset=slave bundle=MASTER_BUS
#pragma HLS INTERFACE s_axilite port=return bundle=CRTL_BUS

char input_buff[LENGTH];
uint8 output_buff[16];
//uint8 flush[LENGTH]={0};
memcpy(input_buff,(const char*)inout_t,(LENGTH)*sizeof(char));
md5(input_buff,output_buff);
//memcpy((uint8*)inout_t,flush,(LENGTH)*sizeof(uint8));  //flush the inout port with zeros
memcpy((uint8*)inout_t,output_buff,16*sizeof(uint8));

}
