#ifndef TWOFISH_H
#define TWOFISH_H

#define TC_MINIMIZE_CODE_SIZE 1

#if defined(__cplusplus)
extern "C"
{
#endif

#define LE32(x) (x)

#ifndef u4byte
#define u4byte	unsigned int
#endif
#ifndef u1byte
#define u1byte	unsigned char
#endif

#ifndef extract_byte
#define extract_byte(x,n)   ((u1byte)((x) >> (8 * n)))
#endif

#ifndef rotl

#define rotr(x,n) (((x)>>(n))|((x)<<(32-(n))))
#define rotl(x,n) (((x)<<(n))|((x)>>(32-(n))))

#endif
typedef struct
{
	u4byte l_key[40];
	u4byte s_key[4];
#if !defined (TC_MINIMIZE_CODE_SIZE) || defined (TC_WINDOWS_BOOT_TWOFISH)
	u4byte mk_tab[4 * 256];
#endif
	u4byte k_len;
} TwofishInstance;

#define TWOFISH_KS		sizeof(TwofishInstance)

u4byte * twofish_set_key(TwofishInstance *instance, const u4byte in_key[], const u4byte key_len);
void twofish_encrypt(TwofishInstance *instance, const u4byte in_blk[4], u4byte out_blk[]);
void twofish_decrypt(TwofishInstance *instance, const u4byte in_blk[4], u4byte out_blk[4]);

#if defined(__cplusplus)
}
#endif

#endif // TWOFISH_H
