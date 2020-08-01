#include "md5.h"
#include <stdio.h>

// In this design we have to specify a maximum input and output length.
char test1[LENGTH] = "lpz7DrML70FVrHqv96NctqSMexImCCv4eozUEQvapLqvQGsEdtHDrUYz";  //56
// 938b8f1c49548c16fe746143e33790bd
char test2[LENGTH] = "VydK8F6eQ4b5hlfgljK194c7YNOWjUzXPg3eMzPGPizQ";              //44
// 2397be316d3e1e82db9ef93b54c719da
char test3[LENGTH] = "Lqo0lduDCaAwEsSPrNyn6ovMAYW1LBPecSH0dkwq4tWgd5kHzgD5v3tz8IKL";//60
// e2c2d6e68e9a02db2063ca38ffa54388
//272
char test4[LENGTH] = "HagBxRmteDe8L0l9MgpdL6YKjbnbLJ2Hb2heqKnOO5Br24rMwU3otVgwghRGNlD5Oi4iBN8A6PkgsSXd3fwtVp1TeQG0b1fmfNBlSuQai2Xn0ovGuQ8cKtLIhgWmYMTNfFYdTcDIFRLdZIydHrcspL45JGvwzYoMzuJJXVK2hR4LMeNlPkwVbk2hKKFvEQeL4lcshtyCXLAGwQfFU1jHYHn0j8RtZsdVriTpPwvVYVr5pBcHpBdVPa9yDxb23A79YjT43D2itxd6CcgA";
// 6b2c5f29ce2f1aed1df9a1c3e4db5f53

int main(){

    uint8 md5_value_1[16];
    uint8 md5_value_2[16];
    uint8 md5_value_3[16];
    uint8 md5_value_4[16];


    md5(test1,  md5_value_1);
    md5(test2,  md5_value_2);
    md5(test3,  md5_value_3);
    md5(test4,  md5_value_4);
    
    int i;
    for(i=0; i<16; i++){
    	printf("%02x", md5_value_1[i]);
    }
	printf("\n");

    for(i=0; i<16; i++){
    	printf("%02x", md5_value_2[i]);
    }
	printf("\n");

    for(i=0; i<16; i++){
    	printf("%02x", md5_value_3[i]);
    }
	printf("\n");

    for(i=0; i<16; i++){
    	printf("%02x", md5_value_4[i]);
    }
	printf("\n");

}
