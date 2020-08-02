HLS-MD5
=======
This is the repository for HLS-MD5, which is a 2020 Xilinx Summer School (2020年新工科联盟-Xilinx暑期学校) project. The team is made up of 3 members. 

HLS-MD5 implements MD5 algorithm on FPGA using Vivado HLS. The porject contains two independent parts: MD5_PYNQ and MD5_SDK. Both MD5_PYNQ and MD5_SDK are implementations of MD5 algorithm on FPGA.

这是2020年新工科联盟-Xilinx暑期学校的项目，小组由3人组成。

HLS-MD5使用Vivado HLS在FPGA上实现了MD5算法。HLS-MD5包含两个独立的部分MD5_PYNQ和MD5_SDK。MD5_PYNQ和MD5_SDK均为MD5算法在FPGA上的实现。
## MD5_PYNQ
In MD5_PYNQ we utilize HLS to implement MD5 algorithm in the PL part, and utilize Jupyter (Python3) based on the PYNQ framework in the PS part. The input data is stored in Memory and then transferred to PL using AXIS and DMA.

MD5_PYNQ使用HLS在PL中实现MD5算法，使用PYNQ框架中的Jupyter (Python3)实现PS部分的工作。输入的数据存放在Memory中，然后通过AXIS和DMA传入到PL。 
## MD5_SDK
In MD5_SDK we utilize HLS to implement MD5 algorithm in the PL part and utilize Xilinx SDK (C Language) in PS. The input data is directly stored in BRAM and then transferred to PL using M_AXI. MD5_SDK does not need a PYNQ framework to run.

MD5_SDK使用HLS在PL中实现MD5算法，使用SDK和C语言实现PS部分的工作。输入的数据直接存入BRAM中然后通过M_AXI传入到PL。MD5_SDK的运行不需要PYNQ框架。
## Platform
- Xilinx PYNQ-Z2 Board
- Vivado 2018.3
- Vivado HLS 2018.3
- PYNQ-Z2 Boot Image V2.4 

## Contents
*Sourcecode*: *Sourcecode* contains the source code of the project. *MD5_PYNQ* folder contains the source code of MD5_PYNQ and *MD5_SDK* folder contains the source code of MD5_SDK. The source files include HLS C/C++ code, Jupyter code for MD5_PYNQ and the SDK C code for MD5_SDK. *Sourcecode* also contains the Vivado Block Design `.tcl` file and some test data.

*ExecutableFiles*: *ExecutableFiles* contains two folders MD5_PYNQ and MD5_SDK. Floder *MD5_PYNQ* contains `.bit` file, `.hwh` fiel and `.tcl` files for Jupyter. Folder *MD5_SDK* contains `.bit` file and the SDK `.elf` file.

*Sourcecode*: *Sourcecode*文件夹包含了项目的所有源代码。其中*MD5_PYNQ*文件夹和*MD5_SDK*文件夹分别包含了MD5_PYNQ和MD5_SDK的源代码。源代码包含HLS C/C++源文件、MD5_PYNQ的Jupyter文件、MD5_SDK的SDK C代码。这个文件夹中还有Vivado Block Design的tcl文件和一些测试数据。

*ExecutableFiles*: *ExecutableFiles*文件夹包含了*MD5_PYNQ*文件夹和*MD5_SDK*文件夹。*MD5_PYNQ*文件夹包含`.bit`, `.hwh`以及`.tcl`文件用于Jupyter。*MD5_SDK*文件夹包含了`.bit`文件以及SDK的`.elf`文件。

## Examples
- MD5_PYNQ input file: *Sourcecode/MD5_PYNQ/testdata/testdata1* 
<p align="center">
<img src ="./Images/pic1.jpg">
</p>

- MD5_SDK input string: The first line in *Sourcecode/MD5_SDK/testdata/testdata* 
<p align="center">
<img src ="./Images/pic2.jpg">
</p>

