#include <ap_cint.h>
#define LENGTH 16384 //The Length of the input

typedef struct
{
	uint32 data_len[2];
	uint32 state[4];
	uint32 buffer[16];
} MD5_CTX;

#define F(x,y,z) ((x & y) | (~x & z))
#define G(x,y,z) ((x & z) | (y & ~z))
#define H(x,y,z) (x^y^z)
#define I(x,y,z) (y ^ (x | ~z))
#define ROTATE_LEFT(x,n) ((x << n) | (x >> (32-n)))

#define FF(a,b,c,d,x,s,ac) \
{ \
	a += F(b,c,d) + x + ac; \
	a = ROTATE_LEFT(a,s); \
	a += b; \
}
#define GG(a,b,c,d,x,s,ac) \
{ \
	a += G(b,c,d) + x + ac; \
	a = ROTATE_LEFT(a,s); \
	a += b; \
}
#define HH(a,b,c,d,x,s,ac) \
{ \
	a += H(b,c,d) + x + ac; \
	a = ROTATE_LEFT(a,s); \
	a += b; \
}
#define II(a,b,c,d,x,s,ac) \
{ \
	a += I(b,c,d) + x + ac; \
	a = ROTATE_LEFT(a,s); \
	a += b; \
}
void LoadData(uint32 *buff, uint32 * data, uint8 len);
void MD5Init(MD5_CTX *context, uint64 data_size);
void MD5Update(MD5_CTX *context, uint32 * input);
void MD5Padding(MD5_CTX *context, uint32 *input, uint8 inputlen);
void MD5Transform(uint32 state[4], uint32 x[16]);
void MD5Length(char data[LENGTH], uint64* length);
int md5(char data_in[LENGTH], uint8 md5_value[16]);
