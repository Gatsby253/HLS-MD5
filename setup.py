import numpy as np
from pynq import Xlnk
from pynq import Overlay
import os
import hashlib
import time

#Download the MD5 IP bitstream
MD5_Design = Overlay("./bitstream/MD5VIVADO.bit")

#Create DMA and MD5 IP objects.
DMA = MD5_Design.axi_dma_0
MD5 = MD5_Design.MD5_0
#Check Status
sendstatus = DMA.sendchannel.running
recvstatus = DMA.recvchannel.running
print("DMA Channel status: Send: ", sendstatus, " Recv: ", recvstatus)



#Load Data

#string
#test_string = b"lpz7DrML70FVrHqv96NctqSMexImCCv4eozUEQvapLqvQGsEdtHDrUYz"
#data_length = np.dtype(np.uint64)
#data_length = len(test_string)
#data_in = np.frombuffer(test_string,dtype = np.uint8)

#file
file_path = "./testdata/testdata1" 
data_length = np.dtype(np.uint64)
data_length = os.path.getsize(file_path)
data_in = np.fromfile(file_path,dtype = np.uint8)

#Write data length to MD5 module.
len0 = np.dtype(np.uint32)
len1 = np.dtype(np.uint32)
len0 = data_length & 0x00000000FFFFFFFF
len1 = (data_length>>32)& 0x00000000FFFFFFFF
MD5.write(0x14, len0) #rows
MD5.write(0x1c, len1) #cols



#Allocate memory to process data on PL. Data is provided as contiguous memory blocks.
xlnk = Xlnk()
in_buffer = xlnk.cma_array(shape=(data_length,),dtype=np.uint8)
out_buffer = xlnk.cma_array(shape=(4,),dtype=np.uint32)
np.copyto(in_buffer,data_in)

#Start the MD5 process and wait to complete.
DMA.sendchannel.transfer(in_buffer)
DMA.recvchannel.transfer(out_buffer)
start1 = time.time()
MD5.write(0x00,0x81) # start
DMA.sendchannel.wait()
DMA.recvchannel.wait()
end1 = time.time()



#Print MD5 Value and elapsed time: FPGA vs ARM CPU

print("MD5 FPGA:")
print('MD5:%08x%08x%08x%08x' % (out_buffer[0],out_buffer[1],out_buffer[2],out_buffer[3]))
print("Time elapsed:%.8f ms." % ((end1-start1)*1000))

hash_md5 = hashlib.md5()
#string
#start2 = time.time()
#hash_md5.update(test_string)
#end2 = time.time()

#file
start2 = time.time()
with open(file_path,'rb') as f:
    for chunk in iter(lambda: f.read(4096), b""):
            hash_md5.update(chunk)
end2 = time.time()

print("MD5 ARM:")
print("MD5:{}".format(hash_md5.hexdigest()))
print("Time elapsed:%.8f ms." % ((end2-start2)*1000))