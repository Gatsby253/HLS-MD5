#include <stdio.h>
#include<stdlib.h>
#include "platform.h"
#include "xil_printf.h"
#include "xil_io.h"
#include "xtime_l.h"
#include "xmd5_top_hw.h"
#include "xmd5_top.h"
//UART Bode 115200
int main()
{
	init_platform();

	// Paste the input string here
	char seq[16384]="hbkwP#GN5+I6HjiSe7TseZre(CWiZy@rMjc%4nMiA8sj3YA$bfAhZu8FhY6Xs!(Id%wbOe)%IO$CVHgG%+KV5uM*Keu*hfhmIPY1onVb)9cC@BFF^onawYu^vajis$b$X5)8P!!W8_zGBMc*%Hs!!qD3et^Ka6uK$41&D7&)m3)Sb5BsmpBx!L6&+oWWs&PA1EM*sLlBkfUj3AUS63Bo8BJO(B1WCaC_2C3a6C%Z^WkeeSk7kw#uL1v!mD9KUb@apIA3XV72PW2Vs@G(Tm!3HS24*J8hLMrbk6*0oVhzSppSUWCVLQsnE6%q)Kw&GXcEd&0UkHaE40#MRuW#~fT~*Rszk@mO%ZEP*r9eEaufKJPpe@7!$#VGfG6FggjwTq4UZDc$bF~wBebG3Ct!CPN6FYRU$NTOIMfBYaec1&nIr8vMDmQ9AEHa0ES^ek3L1EBDyRRd9_D^Y@1nhkK$*TYyE^xNmjIJ7#MEULm_rhmUvN)l^mtg0Fx4Ra@K^5trijl59l!p@3eo*VQFxjRhUj6byc^4piznhEpZ@^hqefT$F2_VDuLWZ#s(*iznjIn9#SmM(d8hG&OV7b_Z9$3oWk1HlP2**QWOdZ5nWoKx2YyL0qHBsCgazfjf3SqczN)NO3$f8Vx&IFLy1cH_uj!UqYiYewF@s3M&~YO~rsj95S3JD9t7c~gZ+!#+xTqhKN4xu~b$*OT2c&S74&EngA8tVitiof0#^mOyZErbv!sBR5)wIdzdC1Zu~QLcXJVeVzaONm2pjH!)YcngCFqFAtCsp1A5IcET01~*kFc9G_RInuQEY+zF*_yV83MoDYo)BS_ZgwNRfABEs*nZZ#i!z0PWcrq)I+Usn8fCcL5YmnNcoH7VPHWeK5JN%f18jO3SvnhkmyuckD+_ebOI6FOzY7y*8bVtVPnL1gftb~xeD#wBfGq4cPVNBzUaLS&)Q60~*H&#digjetaSGN#sQMTd63KJCiplxY$Cpl$unnj+1+YO2@3t";

	// Input the string to BRAM
    int i;
    for(i=0;i<16384;i++)
    {
		Xil_Out8(XPAR_AXI_BRAM_CTRL_0_S_AXI_BASEADDR+i,seq[i]);
    	if(seq[i]=='\0')
			break;
    }
	// Check the BRAM whether the string is already in it or not, and print the string in the BRAM
    xil_printf("\nInput:");
    for(i=0;i<16384;i++)
	{
        char rev=Xil_In8(XPAR_AXI_BRAM_CTRL_0_S_AXI_BASEADDR+i);
        xil_printf("%c",rev? rev:' ');
        if(rev == '\0') break;
    }
    xil_printf("\n");

    // Initialization
    XMd5_top HlsXmd5_top;
    XMd5_top_Config *ExamplePtr;
    xil_printf("\nLook up the device configuration.\n");
    ExamplePtr = XMd5_top_LookupConfig(XPAR_MD5_TOP_0_DEVICE_ID);
    if (!ExamplePtr)
	{
    	xil_printf("ERROR: Lookup of accelerator configuration failed.\n\r");
		return XST_FAILURE;
    }
    xil_printf("Initialize the device\n");
    long status = XMd5_top_CfgInitialize(&HlsXmd5_top, ExamplePtr);
    if (status != XST_SUCCESS)
	{
		xil_printf("ERROR: Could not initialize accelerator.\n\r");
		return(-1);
    }
    XMd5_top_Set_inout_t(&HlsXmd5_top,XPAR_AXI_BRAM_CTRL_0_S_AXI_BASEADDR);
    XMd5_top_Initialize(&HlsXmd5_top, XPAR_MD5_TOP_0_DEVICE_ID);

    XTime tEnd, tCur;
    double tUsed;
    XTime_GetTime(&tCur);
    XMd5_top_Start(&HlsXmd5_top);				// Start the MD5 process
    while (XMd5_top_IsDone(&HlsXmd5_top) == 0) ;		//Wait the MD5 process done
    XTime_GetTime(&tEnd);

    // Print the result
    xil_printf("\n");
    xil_printf("output:");
    for(i=0;i<16;i++)
	{
		char rev=Xil_In8(XPAR_AXI_BRAM_CTRL_0_S_AXI_BASEADDR+i);
		xil_printf("%02x",rev? rev:' ');
		if(rev == '\0') break;
    }

    // Print the elapsed time in ms
    xil_printf("\n");
    tUsed=((double)(tEnd-tCur)/(double)COUNTS_PER_SECOND)*1000;
    printf("\nTime elapsed is %f ms.\n",tUsed);

    cleanup_platform();
    return 0;
}
