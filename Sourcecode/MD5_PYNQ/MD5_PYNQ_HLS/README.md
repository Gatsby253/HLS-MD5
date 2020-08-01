TestBench: *MD5_TB.cpp*

Source Files: *MD5.h*, *MD5_FUNCTION.cpp*, *MD5_TOP.cpp*

Note:

1).When cosimulation the TestBench will fail if inputing multiple test strings sequentially. You can only input one string in each cosimulation. Other input strings in the TB should be commented.

C/RTL联合仿真时一次只能传入一个string，不能连续地传入多个string，否则联合仿真会崩溃。因此我们每次只传入一个string并将其他string注释掉。

2).In *MD5_TOP.cpp* the depth of the axis pragma is just for cosimulation. When cosimulation we must add the depth. When synthesis we can delete the depth.

在*MD5_TOP.cpp*中，axis的pragma的depth用于C/RTL联合仿真，而在综合时可以将depth删去。
