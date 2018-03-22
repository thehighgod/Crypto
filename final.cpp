 

    #include<iostream>

    #include<math.h>

    #include<string.h>

    #include<stdlib.h>

    #include<stdio.h> 

    using namespace std;

     

    long int p, q, n, t, flag, e[100], d[100], temp[100], j, m[100], en[100], i;

    char msg[100];

    int prime(long int);

    void ce();

    long int cd(long int);

    void encrypt();

    void decrypt();

    int prime(long int pr)

    {

        int i;

        j = sqrt(pr);

        for (i = 2; i <= j; i++)

        {

            if (pr % i == 0)

                return 0;

        }

        return 1;

    }

unsigned char s_box[256] =  
 {0x63 ,0x7c ,0x77 ,0x7b ,0xf2 ,0x6b ,0x6f ,0xc5 ,0x30 ,0x01 ,0x67 ,0x2b ,0xfe ,0xd7 ,0xab ,0x76
 ,0xca ,0x82 ,0xc9 ,0x7d ,0xfa ,0x59 ,0x47 ,0xf0 ,0xad ,0xd4 ,0xa2 ,0xaf ,0x9c ,0xa4 ,0x72 ,0xc0
 ,0xb7 ,0xfd ,0x93 ,0x26 ,0x36 ,0x3f ,0xf7 ,0xcc ,0x34 ,0xa5 ,0xe5 ,0xf1 ,0x71 ,0xd8 ,0x31 ,0x15
 ,0x04 ,0xc7 ,0x23 ,0xc3 ,0x18 ,0x96 ,0x05 ,0x9a ,0x07 ,0x12 ,0x80 ,0xe2 ,0xeb ,0x27 ,0xb2 ,0x75
 ,0x09 ,0x83 ,0x2c ,0x1a ,0x1b ,0x6e ,0x5a ,0xa0 ,0x52 ,0x3b ,0xd6 ,0xb3 ,0x29 ,0xe3 ,0x2f ,0x84
 ,0x53 ,0xd1 ,0x00 ,0xed ,0x20 ,0xfc ,0xb1 ,0x5b ,0x6a ,0xcb ,0xbe ,0x39 ,0x4a ,0x4c ,0x58 ,0xcf
 ,0xd0 ,0xef ,0xaa ,0xfb ,0x43 ,0x4d ,0x33 ,0x85 ,0x45 ,0xf9 ,0x02 ,0x7f ,0x50 ,0x3c ,0x9f ,0xa8
 ,0x51 ,0xa3 ,0x40 ,0x8f ,0x92 ,0x9d ,0x38 ,0xf5 ,0xbc ,0xb6 ,0xda ,0x21 ,0x10 ,0xff ,0xf3 ,0xd2
 ,0xcd ,0x0c ,0x13 ,0xec ,0x5f ,0x97 ,0x44 ,0x17 ,0xc4 ,0xa7 ,0x7e ,0x3d ,0x64 ,0x5d ,0x19 ,0x73
 ,0x60 ,0x81 ,0x4f ,0xdc ,0x22 ,0x2a ,0x90 ,0x88 ,0x46 ,0xee ,0xb8 ,0x14 ,0xde ,0x5e ,0x0b ,0xdb
 ,0xe0 ,0x32 ,0x3a ,0x0a ,0x49 ,0x06 ,0x24 ,0x5c ,0xc2 ,0xd3 ,0xac ,0x62 ,0x91 ,0x95 ,0xe4 ,0x79
 ,0xe7 ,0xc8 ,0x37 ,0x6d ,0x8d ,0xd5 ,0x4e ,0xa9 ,0x6c ,0x56 ,0xf4 ,0xea ,0x65 ,0x7a ,0xae ,0x08
 ,0xba ,0x78 ,0x25 ,0x2e ,0x1c ,0xa6 ,0xb4 ,0xc6 ,0xe8 ,0xdd ,0x74 ,0x1f ,0x4b ,0xbd ,0x8b ,0x8a
 ,0x70 ,0x3e ,0xb5 ,0x66 ,0x48 ,0x03 ,0xf6 ,0x0e ,0x61 ,0x35 ,0x57 ,0xb9 ,0x86 ,0xc1 ,0x1d ,0x9e
 ,0xe1 ,0xf8 ,0x98 ,0x11 ,0x69 ,0xd9 ,0x8e ,0x94 ,0x9b ,0x1e ,0x87 ,0xe9 ,0xce ,0x55 ,0x28 ,0xdf
 ,0x8c ,0xa1 ,0x89 ,0x0d ,0xbf ,0xe6 ,0x42 ,0x68 ,0x41 ,0x99 ,0x2d ,0x0f ,0xb0 ,0x54 ,0xbb ,0x16};
 
 unsigned char mul2[]=
 {
    0x00,0x02,0x04,0x06,0x08,0x0a,0x0c,0x0e,0x10,0x12,0x14,0x16,0x18,0x1a,0x1c,0x1e,
0x20,0x22,0x24,0x26,0x28,0x2a,0x2c,0x2e,0x30,0x32,0x34,0x36,0x38,0x3a,0x3c,0x3e,
0x40,0x42,0x44,0x46,0x48,0x4a,0x4c,0x4e,0x50,0x52,0x54,0x56,0x58,0x5a,0x5c,0x5e,
0x60,0x62,0x64,0x66,0x68,0x6a,0x6c,0x6e,0x70,0x72,0x74,0x76,0x78,0x7a,0x7c,0x7e,
0x80,0x82,0x84,0x86,0x88,0x8a,0x8c,0x8e,0x90,0x92,0x94,0x96,0x98,0x9a,0x9c,0x9e,
0xa0,0xa2,0xa4,0xa6,0xa8,0xaa,0xac,0xae,0xb0,0xb2,0xb4,0xb6,0xb8,0xba,0xbc,0xbe,
0xc0,0xc2,0xc4,0xc6,0xc8,0xca,0xcc,0xce,0xd0,0xd2,0xd4,0xd6,0xd8,0xda,0xdc,0xde,
0xe0,0xe2,0xe4,0xe6,0xe8,0xea,0xec,0xee,0xf0,0xf2,0xf4,0xf6,0xf8,0xfa,0xfc,0xfe,
0x1b,0x19,0x1f,0x1d,0x13,0x11,0x17,0x15,0x0b,0x09,0x0f,0x0d,0x03,0x01,0x07,0x05,
0x3b,0x39,0x3f,0x3d,0x33,0x31,0x37,0x35,0x2b,0x29,0x2f,0x2d,0x23,0x21,0x27,0x25,
0x5b,0x59,0x5f,0x5d,0x53,0x51,0x57,0x55,0x4b,0x49,0x4f,0x4d,0x43,0x41,0x47,0x45,
0x7b,0x79,0x7f,0x7d,0x73,0x71,0x77,0x75,0x6b,0x69,0x6f,0x6d,0x63,0x61,0x67,0x65,
0x9b,0x99,0x9f,0x9d,0x93,0x91,0x97,0x95,0x8b,0x89,0x8f,0x8d,0x83,0x81,0x87,0x85,
0xbb,0xb9,0xbf,0xbd,0xb3,0xb1,0xb7,0xb5,0xab,0xa9,0xaf,0xad,0xa3,0xa1,0xa7,0xa5,
0xdb,0xd9,0xdf,0xdd,0xd3,0xd1,0xd7,0xd5,0xcb,0xc9,0xcf,0xcd,0xc3,0xc1,0xc7,0xc5,
0xfb,0xf9,0xff,0xfd,0xf3,0xf1,0xf7,0xf5,0xeb,0xe9,0xef,0xed,0xe3,0xe1,0xe7,0xe5
};

unsigned char mul3[]=
{
    0x00,0x03,0x06,0x05,0x0c,0x0f,0x0a,0x09,0x18,0x1b,0x1e,0x1d,0x14,0x17,0x12,0x11,
0x30,0x33,0x36,0x35,0x3c,0x3f,0x3a,0x39,0x28,0x2b,0x2e,0x2d,0x24,0x27,0x22,0x21,
0x60,0x63,0x66,0x65,0x6c,0x6f,0x6a,0x69,0x78,0x7b,0x7e,0x7d,0x74,0x77,0x72,0x71,
0x50,0x53,0x56,0x55,0x5c,0x5f,0x5a,0x59,0x48,0x4b,0x4e,0x4d,0x44,0x47,0x42,0x41,
0xc0,0xc3,0xc6,0xc5,0xcc,0xcf,0xca,0xc9,0xd8,0xdb,0xde,0xdd,0xd4,0xd7,0xd2,0xd1,
0xf0,0xf3,0xf6,0xf5,0xfc,0xff,0xfa,0xf9,0xe8,0xeb,0xee,0xed,0xe4,0xe7,0xe2,0xe1,
0xa0,0xa3,0xa6,0xa5,0xac,0xaf,0xaa,0xa9,0xb8,0xbb,0xbe,0xbd,0xb4,0xb7,0xb2,0xb1,
0x90,0x93,0x96,0x95,0x9c,0x9f,0x9a,0x99,0x88,0x8b,0x8e,0x8d,0x84,0x87,0x82,0x81,
0x9b,0x98,0x9d,0x9e,0x97,0x94,0x91,0x92,0x83,0x80,0x85,0x86,0x8f,0x8c,0x89,0x8a,
0xab,0xa8,0xad,0xae,0xa7,0xa4,0xa1,0xa2,0xb3,0xb0,0xb5,0xb6,0xbf,0xbc,0xb9,0xba,
0xfb,0xf8,0xfd,0xfe,0xf7,0xf4,0xf1,0xf2,0xe3,0xe0,0xe5,0xe6,0xef,0xec,0xe9,0xea,
0xcb,0xc8,0xcd,0xce,0xc7,0xc4,0xc1,0xc2,0xd3,0xd0,0xd5,0xd6,0xdf,0xdc,0xd9,0xda,
0x5b,0x58,0x5d,0x5e,0x57,0x54,0x51,0x52,0x43,0x40,0x45,0x46,0x4f,0x4c,0x49,0x4a,
0x6b,0x68,0x6d,0x6e,0x67,0x64,0x61,0x62,0x73,0x70,0x75,0x76,0x7f,0x7c,0x79,0x7a,
0x3b,0x38,0x3d,0x3e,0x37,0x34,0x31,0x32,0x23,0x20,0x25,0x26,0x2f,0x2c,0x29,0x2a,
0x0b,0x08,0x0d,0x0e,0x07,0x04,0x01,0x02,0x13,0x10,0x15,0x16,0x1f,0x1c,0x19,0x1a
};

unsigned char rcon[256] = {
    0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a, 
    0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39, 
    0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a, 
    0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 
    0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef, 
    0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc, 
    0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 
    0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3, 
    0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94, 
    0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 
    0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35,
    0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f,
    0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04,
    0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63,
    0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd,
    0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb, 0x8d
};


void KeyExpansionCore(unsigned char *in ,unsigned char i)
{
	//Rotate left;
	unsigned int* q= (unsigned int*)in;
	*q=(*q>>8)|((*q & 0xff) << 24);
       /* unsigned char t = in[0];

	in[0]=in[1];
	in[1]=in[2];
	in[2]=in[3];
	in[3]=t;

       */

       //S-Box four bytes long;
       in[0]=s_box[in[0]]; in[1]=s_box[in[1]];
       in[2]=s_box[in[2]]; in[3]=s_box[in[3]];

       //Rcon first byte is added and XORed to the Rcon value in lookup table
       in[0]^=rcon[i]; // i value will only be the first 2 rows (hopefully)
}

void KeyExpansion(unsigned char* inputKey,unsigned char* expandedKeys)
{
    //The first 16 bytes of expanded key is the original key;
    for(int i=0;i<16;i++)
    expandedKeys[i]= inputKey[i];

    //Variables;
    int bytesGenerated = 16;  //We've generated the first 16 bytes so far;to keep track of no.of bytes we generated
    int rconIteration = 1;    // RCon iteration begins at 1;
    unsigned char temp[4];    // Temporary storage for core

    while(bytesGenerated < 176)
    {
	//Read 4 bytes for the core and store it in the temporary variable;
	for(int i=0;i<4;i++)
	temp[i]= expandedKeys[i+ bytesGenerated -4];

	//Perform the core once for each 16 byte key;
	if(bytesGenerated % 16 ==0)
	{
	    KeyExpansionCore(temp,rconIteration);
	    rconIteration++;
	// or do rconIteration++ separately;
	}

	//XOR temp with [bytesGenerated-16]. and store in expandedKeys:

	for(unsigned char a=0;a<4;a++)
	{
		expandedKeys[bytesGenerated]= expandedKeys[bytesGenerated - 16]^ temp[a];
		bytesGenerated++;
	}
    }
}


void SubBytes(unsigned char* state)
{
    for(int i=0;i<16;i++)
    state[i]=s_box[state[i]];
}
void ShiftRows(unsigned char* state)
{
    unsigned char tmp[16];
    tmp[0]=state[0];
    tmp[1]=state[5];
    tmp[2]=state[10];
    tmp[3]=state[15];

     tmp[4]=state[4];
    tmp[5]=state[9];
    tmp[6]=state[14];
    tmp[7]=state[3];

     tmp[8]=state[8];
    tmp[9]=state[13];
    tmp[10]=state[2];
    tmp[11]=state[7];

     tmp[12]=state[12];
    tmp[13]=state[1];
    tmp[14]=state[6];
    tmp[15]=state[11];

    for(int i=0;i<16;i++)
    state[i]=tmp[i];
}
void MixColumns(unsigned char* state)
{
    unsigned char tmp[16];

    tmp[0] = (unsigned char)(mul2[state[0]] ^ mul3[state[1]] ^ state[2] ^ state[3]);
 tmp[1] = (unsigned char)(state[0] ^ mul2[state[1]] ^ mul3[state[2]] ^ state[3]);
 tmp[2] = (unsigned char)(state[0] ^ state[1] ^ mul2[state[2]] ^ mul3[state[3]]);
 tmp[3] = (unsigned char)(mul3[state[0]] ^ state[1] ^ state[2] ^ mul2[state[3]]);

 tmp[4] = (unsigned char)(mul2[state[4]] ^ mul3[state[5]] ^ state[6] ^ state[7]);
 tmp[5] = (unsigned char)(state[4] ^ mul2[state[5]] ^ mul3[state[6]] ^ state[7]);
 tmp[6] = (unsigned char)(state[4] ^ state[5] ^ mul2[state[6]] ^ mul3[state[7]]);
 tmp[7] = (unsigned char)(mul3[state[4]] ^ state[5] ^ state[6] ^ mul2[state[7]]);

 tmp[8] = (unsigned char)(mul2[state[8]] ^ mul3[state[9]] ^ state[10] ^ state[11]);
 tmp[9] = (unsigned char)(state[8] ^ mul2[state[9]] ^ mul3[state[10]] ^ state[11]);
 tmp[10] = (unsigned char)(state[8] ^ state[9] ^ mul2[state[10]] ^ mul3[state[11]]);
 tmp[11] = (unsigned char)(mul3[state[8]] ^ state[9] ^ state[10] ^ mul2[state[11]]);

 tmp[12] = (unsigned char)(mul2[state[12]] ^ mul3[state[13]] ^ state[14] ^ state[15]);
 tmp[13] = (unsigned char)(state[12] ^ mul2[state[13]] ^ mul3[state[14]] ^ state[15]);
 tmp[14] = (unsigned char)(state[12] ^ state[13] ^ mul2[state[14]] ^ mul3[state[15]]);
 tmp[15] = (unsigned char)(mul3[state[12]] ^ state[13] ^ state[14] ^ mul2[state[15]]);

 for(int i=0;i<16;i++)
    state[i]=tmp[i];
}
void AddRoundKey(unsigned char* state,unsigned char* roundKey)
{
    for(int i=0;i<16;i++)
    state[i] ^= roundKey[i];
}

void AES_encrypt(unsigned char* message,unsigned char* key)
{
    unsigned char state[16];
    for(int i=0;i<16;i++)
    state[i]=message[i];
    int numberOfRounds=9; // Depends on the key length; For 128 bit key,we have 10 cycles.

    //Expand the keys:
    unsigned char expandedKey[176]; // Better option would be to expand the keys outside and then use it;
    KeyExpansion(key,expandedKey);//Slower implementation

    AddRoundKey(state,key); //Add Round key

    for(int i=0;i<numberOfRounds;i++)
    {
	SubBytes(state);
	ShiftRows(state);
	MixColumns(state);
	AddRoundKey(state,expandedKey + (16 * (i+1)));
     }
     //Final Round
	SubBytes(state);
	ShiftRows(state);
	AddRoundKey(state,expandedKey + 160);

	// Copy over encrpyted message state to message;
	for(int i=0;i<16;i++)
	message[i]=state[i]; //We'll lose the original message
  }

  // I could use cout with %x to print out hex values but the formatting doesnt pad it with zeroes

  void PrintHex(unsigned char x)
  {
	if(x/16 <10) cout<<(char)((x/16) + '0');
	if(x/16 >=10) cout<<(char)((x/16 -10) + 'A');

	if(x%16 <10 ) cout<<(char)((x%16) + '0');
	if(x%16 >=10) cout<<(char)((x%16 - 10) + 'A');
  }

int key[64]=
{
    0,0,0,1,0,0,1,1,
    0,0,1,1,0,1,0,0,
    0,1,0,1,0,1,1,1,
    0,1,1,1,1,0,0,1,
    1,0,0,1,1,0,1,1,
    1,0,1,1,1,1,0,0,
    1,1,0,1,1,1,1,1,
    1,1,1,1,0,0,0,1
};
class Des
{
public:
    int keyi[16][48],
        total[64],
        left[32],
        right[32],
        ck[28],
        dk[28],
        expansion[48],
        z[48],
        xor1[48],
        sub[32],
        p[32],
        xor2[32],
        temp[64],
        pc1[56],
        ip[64],
        inv[8][8];
 
    char final[1000];
    void IP();
    void PermChoice1();
    void PermChoice2();
    void Expansion();
    void inverse();
    void xor_two();
    void xor_oneE(int);
    void xor_oneD(int);
    void substitution();
    void permutation();
    void keygen();
    char * Encrypt(char *);
    char * Decrypt(char *);
};
void Des::IP() //Initial Permutation
{
    int k=58,i;
    for(i=0; i<32; i++)
    {
        ip[i]=total[k-1];
        if(k-8>0)  k=k-8;
        else       k=k+58;
    }
    k=57;
    for( i=32; i<64; i++)
    {
        ip[i]=total[k-1];
        if(k-8>0)   k=k-8;
        else     k=k+58;
    }
}
void Des::PermChoice1() //Permutation Choice-1
{
    int k=57,i;
    for(i=0; i<28; i++)
    {
        pc1[i]=key[k-1];
        if(k-8>0)    k=k-8;
        else      k=k+57;
    }
    k=63;
    for( i=28; i<52; i++)
    {
        pc1[i]=key[k-1];
        if(k-8>0)    k=k-8;
        else         k=k+55;
    }
    k=28;
    for(i=52; i<56; i++)
    {
        pc1[i]=key[k-1];
        k=k-8;
    }
 
}
void Des::Expansion() //Expansion Function applied on `right' half
{
    int exp[8][6],i,j,k;
    for( i=0; i<8; i++)
    {
        for( j=0; j<6; j++)
        {
            if((j!=0)||(j!=5))
            {
                k=4*i+j;
                exp[i][j]=right[k-1];
            }
            if(j==0)
            {
                k=4*i;
                exp[i][j]=right[k-1];
            }
            if(j==5)
            {
                k=4*i+j;
                exp[i][j]=right[k-1];
            }
        }
    }
    exp[0][0]=right[31];
    exp[7][5]=right[0];
 
    k=0;
    for(i=0; i<8; i++)
        for(j=0; j<6; j++)
            expansion[k++]=exp[i][j];
}
void Des::PermChoice2()
{
    int per[56],i,k;
    for(i=0; i<28; i++) per[i]=ck[i];
    for(k=0,i=28; i<56; i++) per[i]=dk[k++];
 
    z[0]=per[13];
    z[1]=per[16];
    z[2]=per[10];
    z[3]=per[23];
    z[4]=per[0];
    z[5]=per[4];
    z[6]=per[2];
    z[7]=per[27];
    z[8]=per[14];
    z[9]=per[5];
    z[10]=per[20];
    z[11]=per[9];
    z[12]=per[22];
    z[13]=per[18];
    z[14]=per[11];
    z[15]=per[3];
    z[16]=per[25];
    z[17]=per[7];
    z[18]=per[15];
    z[19]=per[6];
    z[20]=per[26];
    z[21]=per[19];
    z[22]=per[12];
    z[23]=per[1];
    z[24]=per[40];
    z[25]=per[51];
    z[26]=per[30];
    z[27]=per[36];
    z[28]=per[46];
    z[29]=per[54];
    z[30]=per[29];
    z[31]=per[39];
    z[32]=per[50];
    z[33]=per[46];
    z[34]=per[32];
    z[35]=per[47];
    z[36]=per[43];
    z[37]=per[48];
    z[38]=per[38];
    z[39]=per[55];
    z[40]=per[33];
    z[41]=per[52];
    z[42]=per[45];
    z[43]=per[41];
    z[44]=per[49];
    z[45]=per[35];
    z[46]=per[28];
    z[47]=per[31];
}
void Des::xor_oneE(int round) //for Encrypt
{
    int i;
    for(i=0; i<48; i++)
        xor1[i]=expansion[i]^keyi[round-1][i];
}
void Des::xor_oneD(int round) //for Decrypt
{
    int i;
    for(i=0; i<48; i++)
        xor1[i]=expansion[i]^keyi[16-round][i];
}
 
void Des::substitution()
{
    int s1[4][16]=
    {
        14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7,
        0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8,
        4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0,
        15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13
    };
 
    int s2[4][16]=
    {
        15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10,
        3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5,
        0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15,
        13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9
    };
 
    int s3[4][16]=
    {
        10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8,
        13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1,
        13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7,
        1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12
    };
 
    int s4[4][16]=
    {
        7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15,
        13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9,
        10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4,
        3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14
    };
 
    int s5[4][16]=
    {
        2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9,
        14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6,
        4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14,
        11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3
    };
 
    int s6[4][16]=
    {
        12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11,
        10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8,
        9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6,
        4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13
    };
 
    int s7[4][16]=
    {
        4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1,
        13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6,
        1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2,
        6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12
    };
 
    int s8[4][16]=
    {
        13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7,
        1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2,
        7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8,
        2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11
    };
    int a[8][6],k=0,i,j,p,q,count=0,g=0,v;
 
    for(i=0; i<8; i++)
    {
        for(j=0; j<6; j++)
        {
            a[i][j]=xor1[k++];
        }
    }
 
    for( i=0; i<8; i++)
    {
        p=1;
        q=0;
        k=(a[i][0]*2)+(a[i][5]*1);
        j=4;
        while(j>0)
        {
            q=q+(a[i][j]*p);
            p=p*2;
            j--;
        }
        count=i+1;
        switch(count)
        {
        case 1:
            v=s1[k][q];
            break;
        case 2:
            v=s2[k][q];
            break;
        case 3:
            v=s3[k][q];
            break;
        case 4:
            v=s4[k][q];
            break;
        case 5:
            v=s5[k][q];
            break;
        case 6:
            v=s6[k][q];
            break;
        case 7:
            v=s7[k][q];
            break;
        case 8:
            v=s8[k][q];
            break;
        }
 
        int d,i=3,a[4];
        while(v>0)
        {
            d=v%2;
            a[i--]=d;
            v=v/2;
        }
        while(i>=0)
        {
            a[i--]=0;
        }
 
        for(i=0; i<4; i++)
            sub[g++]=a[i];
    }
}
 
void Des::permutation()
{
    p[0]=sub[15];
    p[1]=sub[6];
    p[2]=sub[19];
    p[3]=sub[20];
    p[4]=sub[28];
    p[5]=sub[11];
    p[6]=sub[27];
    p[7]=sub[16];
    p[8]=sub[0];
    p[9]=sub[14];
    p[10]=sub[22];
    p[11]=sub[25];
    p[12]=sub[4];
    p[13]=sub[17];
    p[14]=sub[30];
    p[15]=sub[9];
    p[16]=sub[1];
    p[17]=sub[7];
    p[18]=sub[23];
    p[19]=sub[13];
    p[20]=sub[31];
    p[21]=sub[26];
    p[22]=sub[2];
    p[23]=sub[8];
    p[24]=sub[18];
    p[25]=sub[12];
    p[26]=sub[29];
    p[27]=sub[5];
    p[28]=sub[21];
    p[29]=sub[10];
    p[30]=sub[3];
    p[31]=sub[24];
}
 
void Des::xor_two()
{
    int i;
    for(i=0; i<32; i++)
    {
        xor2[i]=left[i]^p[i];
    }
}
 
void Des::inverse()
{
    int p=40,q=8,k1,k2,i,j;
    for(i=0; i<8; i++)
    {
        k1=p;
        k2=q;
        for(j=0; j<8; j++)
        {
            if(j%2==0)
            {
                inv[i][j]=temp[k1-1];
                k1=k1+8;
            }
            else if(j%2!=0)
            {
                inv[i][j]=temp[k2-1];
                k2=k2+8;
            }
        }
        p=p-1;
        q=q-1;
    }
}
 
char * Des::Encrypt(char *Text1)
{
    int i,a1,j,nB,m,iB,k,K,B[8],n,t,d,round;
    char *Text=new char[1000];
    strcpy(Text,Text1);
    i=strlen(Text);
    int mc=0;
    a1=i%8;
    if(a1!=0) for(j=0; j<8-a1; j++,i++) Text[i]=' ';
    Text[i]='\0';
    keygen();
    for(iB=0,nB=0,m=0; m<(strlen(Text)/8); m++) //Repeat for TextLenth/8 times.
    {
        for(iB=0,i=0; i<8; i++,nB++)
        {
            n=(int)Text[nB];
            for(K=7; n>=1; K--)
            {
                B[K]=n%2;  //Converting 8-Bytes to 64-bit Binary Format
                n/=2;
            }
            for(; K>=0; K--) B[K]=0;
            for(K=0; K<8; K++,iB++) total[iB]=B[K]; //Now `total' contains the 64-Bit binary format of 8-Bytes
        }
        IP(); //Performing initial permutation on `total[64]'
        for(i=0; i<64; i++) total[i]=ip[i]; //Store values of ip[64] into total[64]
 
        for(i=0; i<32; i++) left[i]=total[i]; //     +--> left[32]
        // total[64]--|
        for(; i<64; i++) right[i-32]=total[i]; //            +--> right[32]
        for(round=1; round<=16; round++)
        {
            Expansion(); //Performing expansion on `right[32]' to get  `expansion[48]'
            xor_oneE(round); //Performing XOR operation on expansion[48],z[48] to get xor1[48]
            substitution();//Perform substitution on xor1[48] to get sub[32]
            permutation(); //Performing Permutation on sub[32] to get p[32]
            xor_two(); //Performing XOR operation on left[32],p[32] to get xor2[32]
            for(i=0; i<32; i++) left[i]=right[i]; //Dumping right[32] into left[32]
            for(i=0; i<32; i++) right[i]=xor2[i]; //Dumping xor2[32] into right[32]
        }
        for(i=0; i<32; i++) temp[i]=right[i]; // Dumping   -->[ swap32bit ]
        for(; i<64; i++) temp[i]=left[i-32]; //    left[32],right[32] into temp[64]
 
        inverse(); //Inversing the bits of temp[64] to get inv[8][8]
        /* Obtaining the Cypher-Text into final[1000]*/
        k=128;
        d=0;
        for(i=0; i<8; i++)
        {
            for(j=0; j<8; j++)
            {
                d=d+inv[i][j]*k;
                k=k/2;
            }
            final[mc++]=(char)d;
            k=128;
            d=0;
        }
    } //for loop ends here
    final[mc]='\0';
    return(final);
}
char * Des::Decrypt(char *Text1)
{
    int i,a1,j,nB,m,iB,k,K,B[8],n,t,d,round;
    char *Text=new char[1000];
    unsigned char ch;
    strcpy(Text,Text1);
    i=strlen(Text);
    keygen();
    int mc=0;
    for(iB=0,nB=0,m=0; m<(strlen(Text)/8); m++) //Repeat for TextLenth/8 times.
    {
        for(iB=0,i=0; i<8; i++,nB++)
        {
            ch=Text[nB];
            n=(int)ch;//(int)Text[nB];
            for(K=7; n>=1; K--)
            {
                B[K]=n%2;  //Converting 8-Bytes to 64-bit Binary Format
                n/=2;
            }
            for(; K>=0; K--) B[K]=0;
            for(K=0; K<8; K++,iB++) total[iB]=B[K]; //Now `total' contains the 64-Bit binary format of 8-Bytes
        }
        IP(); //Performing initial permutation on `total[64]'
        for(i=0; i<64; i++) total[i]=ip[i]; //Store values of ip[64] into total[64]
 
        for(i=0; i<32; i++) left[i]=total[i]; //     +--> left[32]
        // total[64]--|
        for(; i<64; i++) right[i-32]=total[i]; //            +--> right[32]
        for(round=1; round<=16; round++)
        {
            Expansion(); //Performing expansion on `right[32]' to get  `expansion[48]'
            xor_oneD(round);
            substitution();//Perform substitution on xor1[48] to get sub[32]
            permutation(); //Performing Permutation on sub[32] to get p[32]
            xor_two(); //Performing XOR operation on left[32],p[32] to get xor2[32]
            for(i=0; i<32; i++) left[i]=right[i]; //Dumping right[32] into left[32]
            for(i=0; i<32; i++) right[i]=xor2[i]; //Dumping xor2[32] into right[32]
        } //rounds end here
        for(i=0; i<32; i++) temp[i]=right[i]; // Dumping   -->[ swap32bit ]
        for(; i<64; i++) temp[i]=left[i-32]; //    left[32],right[32] into temp[64]
 
        inverse(); //Inversing the bits of temp[64] to get inv[8][8]
        /* Obtaining the Cypher-Text into final[1000]*/
        k=128;
        d=0;
        for(i=0; i<8; i++)
        {
            for(j=0; j<8; j++)
            {
                d=d+inv[i][j]*k;
                k=k/2;
            }
            final[mc++]=(char)d;
            k=128;
            d=0;
        }
    } //for loop ends here
    final[mc]='\0';
    char *final1=new char[1000];
    for(i=0,j=strlen(Text); i<strlen(Text); i++,j++)
        final1[i]=final[j];
    final1[i]='\0';
    return(final);
}

typedef union uwb {
    unsigned w;
    unsigned char b[4];
} MD5union;
 
typedef unsigned DigestArray[4];
 
unsigned func0( unsigned abcd[] ){
    return ( abcd[1] & abcd[2]) | (~abcd[1] & abcd[3]);}
 
unsigned func1( unsigned abcd[] ){
    return ( abcd[3] & abcd[1]) | (~abcd[3] & abcd[2]);}
 
unsigned func2( unsigned abcd[] ){
    return  abcd[1] ^ abcd[2] ^ abcd[3];}
 
unsigned func3( unsigned abcd[] ){
    return abcd[2] ^ (abcd[1] |~ abcd[3]);}
 
typedef unsigned (*DgstFctn)(unsigned a[]);
 
/*Use binary integer part of the sines of integers (Radians) as constants*/
/*or*/
/* Hardcode the below table but i want generic code that why coded it
using calcuate table function
k[ 0.. 3] := { 0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee }
k[ 4.. 7] := { 0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501 }
k[ 8..11] := { 0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be }
k[12..15] := { 0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821 }
k[16..19] := { 0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa }
k[20..23] := { 0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8 }
k[24..27] := { 0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed }
k[28..31] := { 0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a }
k[32..35] := { 0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c }
k[36..39] := { 0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70 }
k[40..43] := { 0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05 }
k[44..47] := { 0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665 }
k[48..51] := { 0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039 }
k[52..55] := { 0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1 }
k[56..59] := { 0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1 }
k[60..63] := { 0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391 }*/
 
unsigned *calctable( unsigned *k)
{
    double s, pwr;
    int i;
 
    pwr = pow( 2, 32);
    for (i=0; i<64; i++) {
        s = fabs(sin(1+i));
        k[i] = (unsigned)( s * pwr );
    }
    return k;
}
 
/*Rotate Left r by N bits
 or
We can directly hardcode below table but as i explained above we are opting
generic code so shifting the bit manually.
r[ 0..15] := {7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22}
r[16..31] := {5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20}
r[32..47] := {4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23}
r[48..63] := {6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21}
*/
unsigned rol( unsigned r, short N )
{
    unsigned  mask1 = (1<<N) -1;
    return ((r>>(32-N)) & mask1) | ((r<<N) & ~mask1);
}
 
unsigned *md5( const char *msg, int mlen)
{
    /*Initialize Digest Array as A , B, C, D */
    static DigestArray h0 = { 0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476 };
    static DgstFctn ff[] = { &func0, &func1, &func2, &func3 };
    static short M[] = { 1, 5, 3, 7 };
    static short O[] = { 0, 1, 5, 0 };
    static short rot0[] = { 7,12,17,22};
    static short rot1[] = { 5, 9,14,20};
    static short rot2[] = { 4,11,16,23};
    static short rot3[] = { 6,10,15,21};
    static short *rots[] = {rot0, rot1, rot2, rot3 };
    static unsigned kspace[64];
    static unsigned *k;
 
    static DigestArray h;
    DigestArray abcd;
    DgstFctn fctn;
    short m, o, g;
    unsigned f;
    short *rotn;
    union {
        unsigned w[16];
        char     b[64];
    }mm;
    int os = 0;
    int grp, grps, q, p;
    unsigned char *msg2;
 
    if (k==NULL) k= calctable(kspace);
 
    for (q=0; q<4; q++) h[q] = h0[q];   // initialize
 
    {
        grps  = 1 + (mlen+8)/64;
        msg2 = (unsigned char *)malloc( 64 * grps);
        memcpy( msg2, msg, mlen);
        msg2[mlen] = (unsigned char)0x80; 
        q = mlen + 1;
        while (q < 64*grps){ msg2[q] = 0; q++ ; }
        {
            MD5union u;
            u.w = 8*mlen;
            q -= 8;
            memcpy(msg2+q, &u.w, 4 );
        }
    }
 
    for (grp=0; grp<grps; grp++)
    {
        memcpy( mm.b, msg2+os, 64);
        for(q=0;q<4;q++) abcd[q] = h[q];
        for (p = 0; p<4; p++) {
            fctn = ff[p];
            rotn = rots[p];
            m = M[p]; o= O[p];
            for (q=0; q<16; q++) {
                g = (m*q + o) % 16;
                f = abcd[1] + rol( abcd[0]+ fctn(abcd) + k[q+16*p] + mm.w[g], rotn[q%4]);
 
                abcd[0] = abcd[3];
                abcd[3] = abcd[2];
                abcd[2] = abcd[1];
                abcd[1] = f;
            }
        }
        for (p=0; p<4; p++)
            h[p] += abcd[p];
        os += 64;
    }
    return h;
}   

void rc4(unsigned char * ByteInput, unsigned char * pwd,
		   unsigned char * &ByteOutput){
	unsigned char * temp;
	int i,j=0,t,tmp,tmp2,s[256], k[256];
	for (tmp=0;tmp<256;tmp++){
		s[tmp]=tmp;
		k[tmp]=pwd[(tmp % strlen((char *)pwd))];
	}
		for (i=0;i<256;i++){
		j = (j + s[i] + k[i]) % 256;
		tmp=s[i];
		s[i]=s[j];
		s[j]=tmp;
	}
temp = new unsigned char [ (int)strlen((char *)ByteInput)  + 1 ] ;
	i=j=0;
	for (tmp=0;tmp<(int)strlen((char *)ByteInput);tmp++){
	    i = (i + 1) % 256;
        j = (j + s[i]) % 256;
		tmp2=s[i];
		s[i]=s[j];
		s[j]=tmp2;
        t = (s[i] + s[j]) % 256;
if (s[t]==ByteInput[tmp])
	temp[tmp]=ByteInput[tmp];
else
	temp[tmp]=s[t]^ByteInput[tmp];
	}
temp[tmp]='\0';
ByteOutput=temp;
}
    int main()

    {

	int num,i=1;
	while(i)
	{
	cout<<"1. AES_Encryption\n 2. RSA Encryption and Decryption\n 3. DES encryption and decryption \n 4.MD5 Hashing \n 5.Cache Redundancy Check(CRC32)\n 6.ARCFOUR encryption(RC4)"<<endl;
	cin>>num;
	if(num==1)
		{
			unsigned char message[]="Ankit";
    			unsigned char key[16]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

    		int originalLen = strlen((const char*)message); // Length of the message with /0
    		int lenOfPaddedMessage = originalLen;// begins same as the message
		
    		if(lenOfPaddedMessage % 16 != 0)
     		lenOfPaddedMessage = (lenOfPaddedMessage /16 +1) * 16; // if length of padded message is 16,dont add extra padded bits,else add round to nearest 16

     		unsigned char* paddedMessage = new unsigned char[lenOfPaddedMessage];
     		for(int i=0; i< lenOfPaddedMessage; i++)
     		{
	 		if(i >= originalLen) paddedMessage[i] = 0; // If the padded message doesnt come as 16 bytes ,add 0's to the right
			 else paddedMessage[i] = message[i];// or copy it from the message as it is
     		}

    // Encrypt padded message:
    		for(int i=0; i< lenOfPaddedMessage; i+=16) // padded message jumping in blocks of 16 bytes
    		AES_encrypt(paddedMessage+i, key); // We are essentially expanding our key in this function; slow implementation;

    // Print the encrypted message in hexadecimals

    		cout<<"\n Encrypted message :"<<endl;
    		for(int i=0;i < lenOfPaddedMessage; i++)
    		{
			PrintHex(paddedMessage[i]);
			cout<<" ";
   		 }

    //getch();
   		 delete[] paddedMessage;
	}
	else if(num==2)
	{
        cout << "\nENTER FIRST PRIME NUMBER\n";

        cin >> p;

        flag = prime(p);

        if (flag == 0)

        {

            cout << "\nWRONG INPUT\n";

            exit(1);

        }

        cout << "\nENTER ANOTHER PRIME NUMBER\n";

        cin >> q;

        flag = prime(q);

        if (flag == 0 || p == q)

        {

            cout << "\nWRONG INPUT\n";

            exit(1);

        }

        cout << "\nENTER MESSAGE\n";

        fflush(stdin);

        cin >> msg;
	
	int len1= strlen(msg);

        for (i = 0; i<=len1 ; i++)

            m[i] = msg[i];

        n = p * q;

        t = (p - 1) * (q - 1);

        ce();

        cout << "\nPOSSIBLE VALUES OF e AND d ARE\n";

        for (i = 0; i < j - 1; i++)

            cout << e[i] << "\t" << d[i] << "\n";

        encrypt();

        decrypt();
	}
	else if(num==3)
	{

	 Des d1,d2;
   	 char *str=new char[1000];
    	char *str1=new char[1000];
    	//strcpy(str,"PHOENIX it & ece solutions.");
    	cout<<"Enter a string : ";
    	cin >> str;
    	str1=d1.Encrypt(str);
    	cout<<"\ni/p Text: "<<str<<endl;
    	cout<<"\nCypher  : "<<str1<<endl;
    	//  ofstream fout("out2_fil.txt"); fout<<str1; fout.close();
    	cout<<"\no/p Text: "<<d2.Decrypt(str1)<<endl;
	}
	
	else if(num==4)
	{
		int j,k;
    const char *msg = "My name is Ankit Tyagi";
    printf("\t MD5 ENCRYPTION ALGORITHM IN C++ \n\n");
    printf("Input String to be Encrypted using MD5 : \n\t%s",msg);
    unsigned *d = md5(msg, strlen(msg));
    MD5union u;
    printf("\n\n\nThe MD5 code for input string is : \n");
    printf("\t= 0x");
    for (j=0;j<4; j++){
        u.w = d[j];
        for (k=0;k<4;k++) printf("%02x",u.b[k]);
    }
    printf("\n");
    printf("\n\t MD5 Encyption Successfully Completed!!!\n\n");
    //getch();
    system("pause");
    return 0;
}

else if(num==5)
{
	int i,j,k,l;
     
    //Get Frame
    int fs;
    cout<<"\n Enter Frame size: ";
    cin>>fs;
     
    int f[20];
     
    cout<<"\n Enter Frame:";
    for(i=0;i<fs;i++)
    {
        cin>>f[i];
    }
 
    //Get Generator
    int gs;
    cout<<"\n Enter Generator size: ";
    cin>>gs;
     
    int g[20];
     
    cout<<"\n Enter Generator:";
    for(i=0;i<gs;i++)
    {
        cin>>g[i];
    }
 
    cout<<"\n Sender Side:";
    cout<<"\n Frame: ";
    for(i=0;i<fs;i++)
    {
        cout<<f[i];
    }
    cout<<"\n Generator :";
    for(i=0;i<gs;i++)
    {
        cout<<g[i];
    }
 
    //Append 0's
    int rs=gs-1;
    cout<<"\n Number of 0's to be appended: "<<rs;
    for (i=fs;i<fs+rs;i++)
    {
        f[i]=0;
    }
 
    int temp[20];
    for(i=0;i<20;i++)
    {
        temp[i]=f[i];
    }
 
    cout<<"\n Message after appending 0's :";
    for(i=0; i<fs+rs;i++)
    {
        cout<<temp[i];
    }
 
    //Division
    for(i=0;i<fs;i++)
    {
        j=0;
        k=i;
        //check whether it is divisible or not
        if (temp[k]>=g[j])
        {
            for(j=0,k=i;j<gs;j++,k++)
            {
                if((temp[k]==1 && g[j]==1) || (temp[k]==0 && g[j]==0))
                {
                    temp[k]=0;
                }
                else
                {
                    temp[k]=1;
                }
            }
        }
    }
 
    //CRC
    int crc[15];
    for(i=0,j=fs;i<rs;i++,j++)
    {
        crc[i]=temp[j];
    }
 
    cout<<"\n CRC bits: ";
    for(i=0;i<rs;i++)
    {
        cout<<crc[i];
    }
 
    cout<<"\n Transmitted Frame: ";
    int tf[15];
    for(i=0;i<fs;i++)
    {
        tf[i]=f[i];
    }
    for(i=fs,j=0;i<fs+rs;i++,j++)
    {
        tf[i]=crc[j];
    }
    for(i=0;i<fs+rs;i++)
    {
        cout<<tf[i];
    }
 
    cout<<"\n Receiver side : ";
    cout<<"\n Received Frame: ";
    for(i=0;i<fs+rs;i++)
    {
        cout<<tf[i];
    }
 
    for(i=0;i<fs+rs;i++)
    {
        temp[i]=tf[i];
    }
 
    //Division
    for(i=0;i<fs+rs;i++)
    {
        j=0;
        k=i;
        if (temp[k]>=g[j])
        {
            for(j=0,k=i;j<gs;j++,k++)
            {
                if((temp[k]==1 && g[j]==1) || (temp[k]==0 && g[j]==0))
                {
                    temp[k]=0;
                }
                else
                {
                    temp[k]=1;
                }
            }
        }
    }
 
    cout<<"\n Reaminder: ";
    int rrem[15];
    for (i=fs,j=0;i<fs+rs;i++,j++)
    {
        rrem[j]= temp[i];
    }
    for(i=0;i<rs;i++)
    {
        cout<<rrem[i];
    }
 
    int flag=0;
    for(i=0;i<rs;i++)
    {
        if(rrem[i]!=0)
        {
            flag=1;
        }
    }
 
    if(flag==0)
    {
        cout<<"\n Since Remainder Is 0 Hence Message Transmitted From Sender To Receriver Is Correct";
    }
    else
    {
        cout<<"\n Since Remainder Is Not 0 Hence Message Transmitted From Sender To Receriver Contains Error";
    }
}

else if(num==6)
{
	unsigned char * message;
	unsigned char * pwd;
	unsigned char * encrypted;
	unsigned char * decrypted;
	message=(unsigned char *)"Hello world!";
	pwd=(unsigned char *)"abc";
	rc4(message,pwd,encrypted);
	rc4(encrypted,pwd,decrypted);
	cout<<"Test"<<endl<<endl;
	cout<<"Message: "<<message<<endl;
	cout<<"Password: "<<pwd<<endl;
	cout<<"Message encrypted: "<<encrypted<<endl;
	cout<<"Message decrypted: "<<decrypted<<endl;
}
	else
	cout<<"Wrong option entered!!"<<endl;
	
	cout<<"Do you want to continue? Press 1 to continue and 0 to exit"<<endl;
	cin>>i;

}
        return 0;

 }
void Des::keygen()
{
    PermChoice1();
 
    int i,j,k=0;
    for(i=0; i<28; i++)
    {
        ck[i]=pc1[i];
    }
    for(i=28; i<56; i++)
    {
        dk[k]=pc1[i];
        k++;
    }
    int noshift=0,round;
    for(round=1; round<=16; round++)
    {
        if(round==1||round==2||round==9||round==16)
            noshift=1;
        else
            noshift=2;
        while(noshift>0)
        {
            int t;
            t=ck[0];
            for(i=0; i<28; i++)
                ck[i]=ck[i+1];
            ck[27]=t;
            t=dk[0];
            for(i=0; i<28; i++)
                dk[i]=dk[i+1];
            dk[27]=t;
            noshift--;
        }
        PermChoice2();
        for(i=0; i<48; i++)
            keyi[round-1][i]=z[i];
    }
}

    void ce()

    {

        int k;

        k = 0;

        for (i = 2; i < t; i++)

        {

            if (t % i == 0)

                continue;

            flag = prime(i);

            if (flag == 1 && i != p && i != q)

            {

                e[k] = i;

                flag = cd(e[k]);

                if (flag > 0)

                {

                    d[k] = flag;

                    k++;

                }

                if (k == 99)

                    break;

            }

        }

    }

    long int cd(long int x)

    {

        long int k = 1;

        while (1)

        {

            k = k + t;

            if (k % x == 0)

                return (k / x);

        }

    }

    void encrypt()

    {

        long int pt, ct, key = e[0], k, len;

        i = 0;

        len = strlen(msg);

        while (i != len)

        {

            pt = m[i];

            pt = pt - 96;

            k = 1;

            for (j = 0; j < key; j++)

            {

                k = k * pt;

                k = k % n;

            }

            temp[i] = k;

            ct = k + 96;

            en[i] = ct;

            i++;

        }

        en[i] = -1;

        cout << "\nTHE ENCRYPTED MESSAGE IS\n";

        for (i = 0; en[i] != -1; i++)

            printf("%c", en[i]);

    }

    void decrypt()

    {

        long int pt, ct, key = d[0], k;

        i = 0;

        while (en[i] != -1)

        {

            ct = temp[i];

            k = 1;

            for (j = 0; j < key; j++)

            {

                k = k * ct;

                k = k % n;

            }

            pt = k + 96;

            m[i] = pt;

            i++;

        }

        m[i] = -1;

        cout << "\nTHE DECRYPTED MESSAGE IS\n";

        for (i = 0; m[i] != -1; i++)

            printf("%c", m[i]);

    }



