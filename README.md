# HLS-MD5

![License](https://img.shields.io/github/license/Gatsby253/HLS-MD5) ![issues](https://img.shields.io/github/issues/Gatsby253/HLS-MD5)

README: [English](https://github.com/Gatsby253/HLS-MD5/blob/master/README.md) | [中文](https://github.com/Gatsby253/HLS-MD5/blob/master/README-zh.md)

**This is the repository for HLS-MD5, which is a 2020 Xilinx Summer School project. The team is made up of 3 members.**


HLS-MD5 implements MD5 algorithm on FPGA using Vivado HLS. The porject contains two independent parts: MD5_PYNQ and MD5_SDK. Both MD5_PYNQ and MD5_SDK are implementations of MD5 algorithm on FPGA.

## MD5_PYNQ
In MD5_PYNQ we utilize HLS to implement MD5 algorithm in the PL part, and utilize Jupyter (Python3) based on the PYNQ framework in the PS part. The input data is stored in Memory and then transferred to PL using AXIS and DMA.

## MD5_SDK
In MD5_SDK we utilize HLS to implement MD5 algorithm in the PL part and utilize Xilinx SDK (C Language) in PS. The input data is directly stored in BRAM and then transferred to PL using M_AXI. MD5_SDK does not need a PYNQ framework to run.

## Platform
- Xilinx PYNQ-Z2 Board
- Vivado 2018.3
- Vivado HLS 2018.3
- PYNQ-Z2 Boot Image V2.4 

## Contents
*Sourcecode*: *Sourcecode* contains the source code of the project. *MD5_PYNQ* folder contains the source code of MD5_PYNQ and *MD5_SDK* folder contains the source code of MD5_SDK. The source files include HLS C/C++ code, Jupyter code for MD5_PYNQ and the SDK C code for MD5_SDK. *Sourcecode* also contains the Vivado Block Design `.tcl` file and some test data.

*ExecutableFiles*: *ExecutableFiles* contains two folders MD5_PYNQ and MD5_SDK. Floder *MD5_PYNQ* contains `.bit` file, `.hwh` fiel and `.tcl` files for Jupyter. Folder *MD5_SDK* contains `.bit` file and the SDK `.elf` file.

## Quick Start
Open a terminal in Jupyter Lab and run:

`pip3 install git+https://github.com/Gatsby253/HLS-MD5.git`

Open folder *HLS-MD5* in Jupyter, and open *MD5.ipynb*. This is the project's Jupyter Notebook. Click "Cell->Run All" to run all the cells sequentially, or click "Run" botton to run each cell individually.
## Examples
- MD5_PYNQ input file: *Sourcecode/MD5_PYNQ/testdata/testdata1* 
<p align="center">
<img src ="./Images/pic1.jpg">
</p>

- MD5_SDK input string: The first line in *Sourcecode/MD5_SDK/testdata/testdata* 
<p align="center">
<img src ="./Images/pic2.jpg">
</p>

