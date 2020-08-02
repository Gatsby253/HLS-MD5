TestBench: *md5_test.c*

Source Files: *md5.c*, *md5_main.c*, *top.c*, *md5.h*

Note:

Function "md5_top" in *top.c* is the top module of the whole design, but when simulation the function "md5" in *md5_main.c* should be the top module.

*top.c*中的函数"md5_top"是整个设计的top module，但是在进行仿真时要将*md5_main.c*中的函数`md5`设为top module。
