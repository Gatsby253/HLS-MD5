#include "md5.h"
#include <iostream>
#include <iomanip>
using namespace std;
//Note that when cosimulation the TestBench will fail if inputing multiple test strings sequentially.
//We can only input one string in each cosimulation. Others should be commented.

// The length of the test input
//#define DL1 56
//#define DL2 44
//#define DL3 60
#define DL4 272

//char testdata1[] = "lpz7DrML70FVrHqv96NctqSMexImCCv4eozUEQvapLqvQGsEdtHDrUYz";  //56
//// MD5:938b8f1c  49548c16  fe746143  e33790bd
//
//char testdata2[] = "VydK8F6eQ4b5hlfgljK194c7YNOWjUzXPg3eMzPGPizQ";              //44
//// MD5:2397be31  6d3e1e82  db9ef93b  54c719da
//
//char testdata3[] = "Lqo0lduDCaAwEsSPrNyn6ovMAYW1LBPecSH0dkwq4tWgd5kHzgD5v3tz8IKL";//60
//// MD5:e2c2d6e6  8e9a02db  2063ca38  ffa54388

//272
char testdata4[] = "HagBxRmteDe8L0l9MgpdL6YKjbnbLJ2Hb2heqKnOO5Br24rMwU3otVgwghRGNlD5Oi4iBN8A6PkgsSXd3fwtVp1TeQG0b1fmfNBlSuQai2Xn0ovGuQ8cKtLIhgWmYMTNfFYdTcDIFRLdZIydHrcspL45JGvwzYoMzuJJXVK2hR4LMeNlPkwVbk2hKKFvEQeL4lcshtyCXLAGwQfFU1jHYHn0j8RtZsdVriTpPwvVYVr5pBcHpBdVPa9yDxb23A79YjT43D2itxd6CcgA";
// MD5:6b2c5f29 ce2f1aed  1df9a1c3  e4db5f53

int main(){
//	axis_stream test1[DL1];
//	axis_stream test2[DL2];
//	axis_stream test3[DL3];
	axis_stream test4[DL4];
	int i;
	//Initialize
//	for(i = 0; i < DL1; i++){
//		test1[i].data.range( 7, 0) = testdata1[i*4  ];
//		test1[i].data.range(15, 8) = testdata1[i*4+1];
//		test1[i].data.range(23,16) = testdata1[i*4+2];
//		test1[i].data.range(31,24) = testdata1[i*4+3];
//		test1[i].user = (i == 0)?1:0;
//		test1[i].last = (i == DL1-1)?1:0;
//	}
//
//	for(i = 0; i < DL2; i++){
//		test2[i].data.range( 7, 0) = testdata2[i*4  ];
//		test2[i].data.range(15, 8) = testdata2[i*4+1];
//		test2[i].data.range(23,16) = testdata2[i*4+2];
//		test2[i].data.range(31,24) = testdata2[i*4+3];
//		test2[i].user = (i == 0)?1:0;
//		test2[i].last = (i == DL2-1)?1:0;
//	}
//
//	for(i = 0; i < DL3; i++){
//		test3[i].data.range( 7, 0) = testdata3[i*4  ];
//		test3[i].data.range(15, 8) = testdata3[i*4+1];
//		test3[i].data.range(23,16) = testdata3[i*4+2];
//		test3[i].data.range(31,24) = testdata3[i*4+3];
//		test3[i].user = (i == 0)?1:0;
//		test3[i].last = (i == DL3-1)?1:0;
//	}

	for(i = 0; i < DL4; i++){
		test4[i].data.range( 7, 0) = testdata4[i*4  ];
		test4[i].data.range(15, 8) = testdata4[i*4+1];
		test4[i].data.range(23,16) = testdata4[i*4+2];
		test4[i].data.range(31,24) = testdata4[i*4+3];
		test4[i].user = (i == 0)?1:0;
		test4[i].last = (i == DL4-1)?1:0;
	}

//	ap_uint<32> test1_len[2] = {56,0};
//	ap_uint<32> test2_len[2] = {44,0};
//	ap_uint<32> test3_len[2] = {60,0};
	ap_uint<32> test4_len[2] = {272,0};


//	axis_stream md5_value_1[4];
//	axis_stream md5_value_2[4];
//	axis_stream md5_value_3[4];
    axis_stream md5_value_4[4];

//	MD5(test1, test1_len[0], test1_len[1], md5_value_1);
//	MD5(test2, test2_len[0], test2_len[1], md5_value_2);
//	MD5(test3, test3_len[0], test3_len[1], md5_value_3);
    MD5(test4, test4_len[0], test4_len[1], md5_value_4);

//	for(i = 0; i<4; i++)
//	cout<<hex<<md5_value_1[i].data<<"  ";
//	cout<<'\n';
//
//	for(i = 0; i<4; i++)
//		cout<<hex<<md5_value_2[i].data<<"  ";
//	cout<<'\n';
//
//	for(i = 0; i<4; i++)
//		cout<<hex<<md5_value_3[i].data<<"  ";
//	cout<<'\n';

	for(i = 0; i<4; i++)
		cout<<hex<<md5_value_4[i].data<<"  ";
	cout<<'\n';
 }
