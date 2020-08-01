#include <ap_int.h>

struct MD5_CTX{
	ap_uint<32> data_len[2];
	ap_uint<32> state[4];
	ap_uint<32> buffer[16];
};

struct axis_stream{
	ap_uint<32> data;
	ap_uint<1> user;
	ap_uint<1> last;
};

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

void MD5Init(MD5_CTX *context, ap_uint<64> data_size);

void MD5Transform(ap_uint<32> state[4], ap_uint<32> x[16]);

void MD5Offload(MD5_CTX *context, axis_stream* md5_value);

void MD5(axis_stream* data, ap_uint<32> len0, ap_uint<32> len1, axis_stream * md5_value);

