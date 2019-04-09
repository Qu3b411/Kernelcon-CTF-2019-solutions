#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include<openssl/sha.h>
int main()
{
unsigned char Boolean = 1;
SHA256_CTX shactx;
SHA256_Init(&shactx);
 char* message = malloc (0xff);

unsigned char seed[] = {0x1f,0xd5,0x1d,0xce,0x6e,0x2a,0x8d,0x1f,
                       0xae,0xcb,0x5e,0x8f,0x3a,0x19,0x20,0xd9,
                       0x49,0xf5,0xae,0x93,0x1b,0xbc,0x76,0x9d,
                       0xea,0xd1,0x5f,0x23,0x60,0x48,0x8c,0x80};
unsigned char check[]={0xa1,0x49,0x2a,0x40,0x44,0x16,0xcf,0x2e,
                       0xec,0x8e,0x2c,0x6f,0x95,0x0d,0xa2,0x5b,
                       0x45,0xc0,0x15,0x58,0xd2,0x06,0xf7,0xfe,
                       0xa4,0xde,0x76,0xb1,0x01,0x1d,0xd4,0x91};
printf("Login: ");
if(fgets(message,0xfe,stdin) == NULL)
{
    fprintf(stderr,"%s","This is an error caused by a malfunction of fgets, it is not part of your challange, please notify staff");
    return 1;
}
    for(int x = 0; x<32; x++)
    {
        *(seed+x)^=(*(message+0));
    }
        SHA256_Update(&shactx,seed,32);
        SHA256_Final(seed,&shactx);
    for(int x = 0; x<32; x++)
    {
      Boolean &=(*(seed+x)==(*(check+x)));
    }
    if(Boolean == 1 )
    {
        for(int x = 0; x<1000000; x++)
        {
                SHA256_Update(&shactx,seed,32);
                SHA256_Final(seed,&shactx);
        }
    }
    else{

        printf("Invalid Password!\n");
        return -1;
    }

/*********************************************************************/
    unsigned char check1[] = {0xcf,0xd9,0x8d,0x8a,0x8d,0xc3,0x60,0xfa,
                              0xa5,0xfd,0xca,0x0b,0xa3,0x88,0xbb,0x09,
                              0x33,0xe6,0x27,0x40,0xbf,0x4e,0xec,0x83,
                              0xcf,0x37,0x4f,0x2b,0xdc,0x9e,0x4a,0x55};
   for(int x = 0; x<32; x++)
    {
        *(seed+x)^=(*(message+1));
    }
        SHA256_Update(&shactx,seed,32);
        SHA256_Final(seed,&shactx);
    for(int x = 0; x<32; x++)
    {
     //   printf("0x%02x,",*(seed+x));
        Boolean &=(*(seed+x)==(*(check1+x)));
    }
    if(Boolean == 1 )
    {
        for(int x = 0; x<1000000; x++)
        {
                SHA256_Update(&shactx,seed,32);
                SHA256_Final(seed,&shactx);
        }
    }
    else{

        printf("Invalid Password!\n");
        return -1;
    }
/*********************************************************************/
    unsigned char check2[] = {0x5b,0x1b,0xdd,0x0d,0x02,0x96,0x90,0x13,
                              0xbb,0xbd,0x4f,0x73,0x76,0xe5,0x88,0xab,
                              0x0f,0x03,0x8c,0xc4,0xb6,0x44,0x2e,0xa6,
                              0xf8,0xd8,0x56,0x38,0xb3,0x90,0x2d,0xc9};
   for(int x = 0; x<32; x++)
    {
        *(seed+x)^=(*(message+2));
    }
        SHA256_Update(&shactx,seed,32);
        SHA256_Final(seed,&shactx);
    for(int x = 0; x<32; x++)
    {
       // printf("0x%02x,",*(seed+x));
        Boolean &=(*(seed+x)==(*(check2+x)));
    }
    if(Boolean == 1 )
    {
        for(int x = 0; x<1000000; x++)
        {
                SHA256_Update(&shactx,seed,32);
                SHA256_Final(seed,&shactx);
        }
    }
    else{

        printf("Invalid Password!\n");
        return -1;
    }
/*********************************************************************/
    unsigned char check3[] = {0x4c,0x6a,0x9f,0xb8,0xda,0xca,0x67,0x37,
                              0x7c,0xd1,0xad,0x80,0xa7,0xf9,0xfe,0x82,
                              0xdf,0xec,0xfe,0x4c,0x23,0x14,0xa9,0x70,
                              0xfe,0x86,0x47,0x02,0xbe,0x48,0xcf,0xb1,};
   for(int x = 0; x<32; x++)
    {
        *(seed+x)^=(*(message+3));
    }
        SHA256_Update(&shactx,seed,32);
        SHA256_Final(seed,&shactx);
    for(int x = 0; x<32; x++)
    {
        //printf("0x%02x,",*(seed+x));
        Boolean &=(*(seed+x)==(*(check3+x)));
    }
    if(Boolean == 1 )
    {
        for(int x = 0; x<1000000; x++)
        {
                SHA256_Update(&shactx,seed,32);
                SHA256_Final(seed,&shactx);
        }
    }
    else{

        printf("Invalid Password!\n");
        return -1;
    }
/*********************************************************************/
    unsigned char check4[] = {0x92,0xcc,0x68,0x9b,0x23,0x5c,0x03,0x32,
                              0xe9,0xfe,0x25,0xd9,0xae,0x1c,0x6c,0xf4,
                              0x3a,0x76,0xd6,0x95,0x6c,0x22,0x1a,0x05,
                              0x96,0x3d,0x74,0x0c,0xfd,0x00,0x22,0xe0};
   for(int x = 0; x<32; x++)
    {
        *(seed+x)^=(*(message+4));
    }
        SHA256_Update(&shactx,seed,32);
        SHA256_Final(seed,&shactx);
    for(int x = 0; x<32; x++)
    {
     //   printf("0x%02x,",*(seed+x));
        Boolean &=(*(seed+x)==(*(check4+x)));
    }
    if(Boolean == 1 )
    {
        for(int x = 0; x<1000000; x++)
        {
                SHA256_Update(&shactx,seed,32);
                SHA256_Final(seed,&shactx);
        }
    }
    else{

        printf("Invalid Password!\n");
        return -1;
    }


/*********************************************************************/
    unsigned char check5[] = {0x90,0x89,0x03,0x47,0x8a,0x7f,0xa8,0x4f,
                              0x39,0xfc,0xbb,0x4c,0x54,0xb7,0x34,0x4e,
                              0x81,0xfd,0x74,0x9b,0x12,0xf6,0xd8,0x3b,
                              0x6c,0x86,0x9c,0xfd,0x55,0x92,0x39,0xe3};
   for(int x = 0; x<32; x++)
    {
        *(seed+x)^=(*(message+5));
    }
        SHA256_Update(&shactx,seed,32);
        SHA256_Final(seed,&shactx);
    for(int x = 0; x<32; x++)
    {
       // printf("0x%02x,",*(seed+x));
        Boolean &=(*(seed+x)==(*(check5+x)));
    }
    if(Boolean == 1 )
    {
        for(int x = 0; x<1000000; x++)
        {
                SHA256_Update(&shactx,seed,32);
                SHA256_Final(seed,&shactx);
        }
    }
    else{

        printf("Invalid Password!\n");
        return -1;
    }

/*********************************************************************/
    unsigned char check6[] = {0xac,0x66,0x28,0x00,0xde,0xd8,0xf2,0xea,
                              0xa6,0x46,0xb7,0xc1,0x76,0x08,0x6b,0x74,
                              0xad,0xb8,0x4b,0x5a,0xd4,0x45,0x32,0x83,
                              0xb4,0xd1,0x55,0xc0,0xdc,0x6f,0xa6,0x63};
   for(int x = 0; x<32; x++)
    {
        *(seed+x)^=(*(message+6));
    }
        SHA256_Update(&shactx,seed,32);
        SHA256_Final(seed,&shactx);
    for(int x = 0; x<32; x++)
    {
        //printf("0x%02x,",*(seed+x));
        Boolean &=(*(seed+x)==(*(check6+x)));
    }
    if(Boolean == 1 )
    {
        for(int x = 0; x<1000000; x++)
        {
                SHA256_Update(&shactx,seed,32);
                SHA256_Final(seed,&shactx);
        }
    }
    else{

        printf("Invalid Password!\n");
        return -1;
    }
/*********************************************************************/
    unsigned char check7[] = {0x18,0x7f,0xf2,0x1b,0x55,0xc8,0xe2,0x50,
                              0x19,0x89,0x12,0x7b,0xb7,0x2c,0x1c,0x0b,
                              0x70,0x68,0x24,0x04,0x46,0x4f,0x5e,0x92,
                              0x53,0x39,0x45,0x2a,0xa7,0x9b,0x04,0xb1};
 // printf("md5");
   for(int x = 0; x<32; x++)
    {
        *(seed+x)^=(*(message+7));
    }
        SHA256_Update(&shactx,seed,32);
        SHA256_Final(seed,&shactx);
    for(int x = 0; x<32; x++)
    {
       // printf("0x%02x,",*(seed+x));
        Boolean &=(*(seed+x)==(*(check7+x)));
    }
    if(Boolean == 1 )
    {
        for(int x = 0; x<1000000; x++)
        {
                SHA256_Update(&shactx,seed,32);
                SHA256_Final(seed,&shactx);
        }
    }
    else{

        printf("Invalid Password!\n");
        return -1;
    }
/*********************************************************************/
    unsigned char check8[] = {0x35,0x0e,0x59,0x02,0x6a,0x42,0xe2,0x67,
                              0x02,0xcf,0x72,0xc7,0x10,0xd7,0xad,0x88,
                              0xd1,0x2c,0x3c,0x58,0xf9,0x27,0xdd,0x1f,
                              0x23,0xcd,0xfa,0xd3,0x46,0xd8,0x61,0x42,};
   for(int x = 0; x<32; x++)
    {
        *(seed+x)^=(*(message+8));
    }
        SHA256_Update(&shactx,seed,32);
        SHA256_Final(seed,&shactx);
    for(int x = 0; x<32; x++)
    {
       // printf("0x%02x,",*(seed+x));
        Boolean &=(*(seed+x)==(*(check8+x)));
    }
    if(Boolean == 1 )
    {
        for(int x = 0; x<1000000; x++)
        {
                SHA256_Update(&shactx,seed,32);
                SHA256_Final(seed,&shactx);
        }
    }
    else{

        printf("Invalid Password!\n");
        return -1;
    }
/*********************************************************************/
    unsigned char check9[] = {0x4c,0xee,0xf9,0xa9,0x29,0x99,0xf8,0x0f,
                              0x3d,0xee,0xad,0xf8,0x0d,0xa1,0x14,0x02,
                              0x5f,0x05,0x7e,0x80,0xa0,0x18,0xc9,0x17,
                              0x33,0x32,0xd8,0xc8,0x47,0xed,0xbc,0x69};
   for(int x = 0; x<32; x++)
    {
        *(seed+x)^=(*(message+9));
    }
        SHA256_Update(&shactx,seed,32);
        SHA256_Final(seed,&shactx);
    for(int x = 0; x<32; x++)
    {
        //printf("0x%02x,",*(seed+x));
        Boolean &=(*(seed+x)==(*(check9+x)));
    }
    if(Boolean == 1 )
    {
        for(int x = 0; x<1000000; x++)
        {
                SHA256_Update(&shactx,seed,32);
                SHA256_Final(seed,&shactx);
        }
    }
    else{

        printf("Invalid Password!\n");
        return -1;
    }
/*********************************************************************/
    unsigned char check10[] = {0xf7,0x73,0xc8,0x26,0xcd,0x3e,0x94,0xda,
                               0x76,0x01,0x6e,0x35,0xf4,0xba,0x80,0x2a,
                               0x3b,0xfb,0xb0,0x41,0x69,0x3c,0xa9,0x38,
                               0xfa,0x29,0x1c,0xa3,0xcd,0xf7,0x70,0x79};
   for(int x = 0; x<32; x++)
    {
        *(seed+x)^=(*(message+10));
    }
        SHA256_Update(&shactx,seed,32);
        SHA256_Final(seed,&shactx);
    for(int x = 0; x<32; x++)
    {
       // printf("0x%02x,",*(seed+x));
        Boolean &=(*(seed+x)==(*(check10+x)));
    }
    if(Boolean == 1 )
    {
        for(int x = 0; x<1000000; x++)
        {
                SHA256_Update(&shactx,seed,32);
                SHA256_Final(seed,&shactx);
        }
    }
    else{

        printf("Invalid Password!\n");
        return -1;
    }


/*********************************************************************/
    unsigned char check11[] = {0xf0,0xd7,0xa7,0xf4,0x73,0xc4,0xe4,0xec,
                               0x9c,0x7d,0xd0,0x97,0x9c,0xa2,0x8b,0x5b,
                               0xee,0x43,0x2b,0xe6,0x56,0xe9,0xd8,0x00,
                               0x0e,0x77,0xa1,0xb8,0xa9,0x4a,0x1e,0x02};
   for(int x = 0; x<32; x++)
    {
        *(seed+x)^=(*(message+11));
    }
        SHA256_Update(&shactx,seed,32);
        SHA256_Final(seed,&shactx);
    for(int x = 0; x<32; x++)
    {
       // printf("0x%02x,",*(seed+x));
        Boolean &=(*(seed+x)==(*(check11+x)));
    }
    if(Boolean == 1 )
    {
        for(int x = 0; x<1000000; x++)
        {
                SHA256_Update(&shactx,seed,32);
                SHA256_Final(seed,&shactx);
        }
    }
    else{

        printf("Invalid Password!\n");
        return -1;
    }

/*********************************************************************/
    unsigned char check12[] = {0x85,0xea,0x32,0xd4,0x76,0xdf,0x87,0xab,
                               0xc2,0x9c,0x4b,0x90,0xa4,0x28,0xd5,0x2c,
                               0x95,0x49,0x7f,0x83,0x61,0xb3,0x85,0x50,
                               0xbc,0x66,0x2c,0x5c,0x3a,0x25,0xea,0xb4};
   for(int x = 0; x<32; x++)
    {
        *(seed+x)^=(*(message+12));
    }
        SHA256_Update(&shactx,seed,32);
        SHA256_Final(seed,&shactx);
    for(int x = 0; x<32; x++)
    {
       // printf("0x%02x,",*(seed+x));
        Boolean &=(*(seed+x)==(*(check12+x)));
    }
    if(Boolean == 1 )
    {
        for(int x = 0; x<1000000; x++)
        {
                SHA256_Update(&shactx,seed,32);
                SHA256_Final(seed,&shactx);
        }
    }
    else{

        printf("Invalid Password!\n");
        return -1;
    }
/**********************************************************************/
    unsigned char check13[] = {0xa6,0x8e,0x7e,0xaf,0x50,0xab,0x66,0xf7,
                               0x0c,0xde,0xfb,0x84,0x69,0x5d,0x5c,0x4e,
                               0x79,0xcd,0x29,0xca,0x41,0xcd,0x90,0x67,
                               0xb6,0x8c,0x21,0x80,0x20,0x00,0x59,0xfe};
 // printf("md5");
   for(int x = 0; x<32; x++)
    {
        *(seed+x)^=(*(message+13));
    }
        SHA256_Update(&shactx,seed,32);
        SHA256_Final(seed,&shactx);
    for(int x = 0; x<32; x++)
    {
        //printf("0x%02x,",*(seed+x));
        Boolean &=(*(seed+x)==(*(check13+x)));
    }
    if(Boolean == 1 )
    {
        for(int x = 0; x<1000000; x++)
        {
                SHA256_Update(&shactx,seed,32);
                SHA256_Final(seed,&shactx);
        }
    }
    else{

        printf("Invalid Password!\n");
        return -1;
    }
/*********************************************************************/
    unsigned char check14[] = {0x2c,0xf5,0xb4,0xd3,0xcf,0xb7,0xd7,0x6c,
                               0x59,0x47,0x7c,0x27,0x84,0x55,0x8d,0x98,
                               0x41,0x2f,0x49,0x58,0xa9,0x4c,0x4f,0xd3,
                               0x9e,0xe1,0x1a,0x40,0xc1,0x9f,0x56,0xc2};
   for(int x = 0; x<32; x++)
    {
        *(seed+x)^=(*(message+14));
    }
        SHA256_Update(&shactx,seed,32);
        SHA256_Final(seed,&shactx);
    for(int x = 0; x<32; x++)
    {
        //printf("0x%02x,",*(seed+x));
        Boolean &=(*(seed+x)==(*(check14+x)));
    }
    if(Boolean == 1 )
    {
        for(int x = 0; x<1000000; x++)
        {
                SHA256_Update(&shactx,seed,32);
                SHA256_Final(seed,&shactx);
        }
    }
    else{

        printf("Invalid Password!\n");
        return -1;
    }
/*********************************************************************/
    unsigned char check15[] = {0x13,0xf2,0xf3,0xc5,0xa7,0x55,0xf7,0x92,
                               0x06,0xd8,0x2b,0x7b,0x6a,0xab,0x61,0xc4,
                               0x13,0x36,0x18,0x98,0x3a,0x2d,0xca,0xb3,
                               0x03,0xd3,0xe9,0xaa,0xd2,0xf7,0x18,0x47};
   for(int x = 0; x<32; x++)
    {
        *(seed+x)^=(*(message+15));
    }
        SHA256_Update(&shactx,seed,32);
        SHA256_Final(seed,&shactx);
    for(int x = 0; x<32; x++)
    {
        //printf("0x%02x,",*(seed+x));
        Boolean &=(*(seed+x)==(*(check15+x)));
    }
    if(Boolean == 1 )
    {
        for(int x = 0; x<1000000; x++)
        {
                SHA256_Update(&shactx,seed,32);
                SHA256_Final(seed,&shactx);
        }
    }
    else{

        printf("Invalid Password!\n");
        return -1;
    }
/*********************************************************************/
    unsigned char check16[] = {0x86,0xa1,0x2c,0xbe,0x72,0xce,0x3e,0x27,
                               0xe1,0x3c,0xe4,0x39,0x8c,0x2f,0x2f,0xda,
                               0x23,0x71,0xad,0xd9,0xe7,0x70,0x19,0xe1,
                               0xaa,0x1c,0x8d,0x7b,0x0a,0xa7,0x45,0x0e};
   for(int x = 0; x<32; x++)
    {
        *(seed+x)^=(*(message+16));
    }
        SHA256_Update(&shactx,seed,32);
        SHA256_Final(seed,&shactx);
    for(int x = 0; x<32; x++)
    {
        //printf("0x%02x,",*(seed+x));
        Boolean &=(*(seed+x)==(*(check16+x)));
    }
    if(Boolean == 1 )
    {
        for(int x = 0; x<1000000; x++)
        {
                SHA256_Update(&shactx,seed,32);
                SHA256_Final(seed,&shactx);
        }
    }
    else{

        printf("Invalid Password!\n");
        return -1;
    }
/**ENCODEING BREAK**/
/*********************************************************************/
    unsigned char check17[] = {0x3b,0xd5,0xff,0xb6,0xd5,0xf0,0x1e,0x52,0x5a,0xfb,0x09,0x26,0xd1,0x58,0xe4,0x8e,0xd7,0xe4,0x1c,0xa8,0x69,0x37,0x31,0x89,0xb4,0xc0,0xad,0x84,0xc7,0x57,0x32,0x72};
   for(int x = 0; x<32; x++)
    {
        *(seed+x)^=(*(message+17));
    }
        SHA256_Update(&shactx,seed,32);
        SHA256_Final(seed,&shactx);
    for(int x = 0; x<32; x++)
    {
       // printf("0x%02x,",*(seed+x));
        Boolean &=(*(seed+x)==(*(check17+x)));
    }
    if(Boolean == 1 )
    {
        for(int x = 0; x<1000000; x++)
        {
                SHA256_Update(&shactx,seed,32);
                SHA256_Final(seed,&shactx);
        }
    }
    else{

        printf("Invalid Password!\n");
        return -1;
    }
/*********************************************************************/
    unsigned char check18[] = {0xa0,0x00,0x0a,0x33,0xb5,0x1e,0x14,0x30,0x6d,0x94,0x86,0xcb,0x81,0x50,0x9a,0xaa,0xcb,0x0a,0x69,0x1b,0xfd,0x33,0xa2,0x7d,0x1b,0x70,0x29,0x37,0x8f,0x0c,0xe9,0xf4};
   for(int x = 0; x<32; x++)
    {
        *(seed+x)^=(*(message+18));
    }
        SHA256_Update(&shactx,seed,32);
        SHA256_Final(seed,&shactx);
    for(int x = 0; x<32; x++)
    {
        //printf("0x%02x,",*(seed+x));
        Boolean &=(*(seed+x)==(*(check18+x)));
    }
    if(Boolean == 1 )
    {
        for(int x = 0; x<1000000; x++)
        {
                SHA256_Update(&shactx,seed,32);
                SHA256_Final(seed,&shactx);
        }
    }
    else{

        printf("Invalid Password!\n");
        return -1;
    }
/*********************************************************************/
    unsigned char check19[] = {0x21,0x9f,0x79,0xad,0xda,0x88,0xab,0xcd,0xdb,0x0e,0xf3,0x5b,0xdb,0x54,0x29,0xd5,0x99,0x92,0x50,0xae,0xdd,0x12,0x00,0x78,0xdc,0x5d,0x8d,0x7e,0x01,0x74,0xf3,0xa5};
   for(int x = 0; x<32; x++)
    {
        *(seed+x)^=(*(message+19));
    }
        SHA256_Update(&shactx,seed,32);
        SHA256_Final(seed,&shactx);
    for(int x = 0; x<32; x++)
    {
        //printf("0x%02x,",*(seed+x));
        Boolean &=(*(seed+x)==(*(check19+x)));
    }
    if(Boolean == 1 )
    {
        for(int x = 0; x<1000000; x++)
        {
                SHA256_Update(&shactx,seed,32);
                SHA256_Final(seed,&shactx);
        }
    }
    else{

        printf("Invalid Password!\n");
        return -1;
    }
/*********************************************************************/
    unsigned char check20[] = {0x43,0x0c,0x8f,0x51,0xa4,0xb0,0xed,0xf2,0xe6,0x01,0x93,0xbd,0x73,0xdc,0x32,0x4b,0x50,0x98,0x40,0xbe,0x20,0xd0,0xe2,0x7f,0x5d,0xa1,0xec,0xb6,0xa4,0x2f,0xce,0xec};
   for(int x = 0; x<32; x++)
    {
        *(seed+x)^=(*(message+20));
    }
        SHA256_Update(&shactx,seed,32);
        SHA256_Final(seed,&shactx);
    for(int x = 0; x<32; x++)
    {
        //printf("0x%02x,",*(seed+x));
        Boolean &=(*(seed+x)==(*(check20+x)));
    }
    if(Boolean == 1 )
    {
        for(int x = 0; x<1000000; x++)
        {
                SHA256_Update(&shactx,seed,32);
                SHA256_Final(seed,&shactx);
        }
    }
    else{

        printf("Invalid Password!\n");
        return -1;
    }


/*********************************************************************/
    unsigned char check21[] = {0xe2,0x22,0xf3,0xbc,0xc1,0xb5,0xf0,0x2c,0xe7,0x26,0x9f,0xc3,0x29,0x86,0x07,0xb6,0xda,0xbc,0x29,0x4b,0x67,0x0c,0x62,0xf4,0xcf,0xce,0x33,0xac,0xaa,0x06,0xec,0x44};
   for(int x = 0; x<32; x++)
    {
        *(seed+x)^=(*(message+21));
    }
        SHA256_Update(&shactx,seed,32);
        SHA256_Final(seed,&shactx);
    for(int x = 0; x<32; x++)
    {
     //   printf("0x%02x,",*(seed+x));
        Boolean &=(*(seed+x)==(*(check21+x)));
    }
    if(Boolean == 1 )
    {
        for(int x = 0; x<1000000; x++)
        {
                SHA256_Update(&shactx,seed,32);
                SHA256_Final(seed,&shactx);
        }
    }
    else{

        printf("Invalid Password!\n");
        return -1;
    }

/*********************************************************************/
    unsigned char check22[] = {0xf5,0xf1,0x2f,0xfa,0x97,0xb6,0x65,0xa8,0xfa,0xf0,0x7c,0x85,0xbf,0x68,0x09,0x4d,0xf3,0x8d,0x4d,0xcf,0xff,0x2e,0xbe,0x02,0x18,0xa2,0xc7,0x7b,0xa7,0x03,0xd9,0x42};
   for(int x = 0; x<32; x++)
    {
        *(seed+x)^=(*(message+22));
    }
        SHA256_Update(&shactx,seed,32);
        SHA256_Final(seed,&shactx);
    for(int x = 0; x<32; x++)
    {
       // printf("0x%02x,",*(seed+x));
        Boolean &=(*(seed+x)==(*(check22+x)));
    }
    if(Boolean == 1 )
    {
        for(int x = 0; x<1000000; x++)
        {
                SHA256_Update(&shactx,seed,32);
                SHA256_Final(seed,&shactx);
        }
    }
    else{

        printf("Invalid Password!\n");
        return -1;
    }
/*********************************************************************/
    unsigned char check23[] = {0x3d,0x3f,0xcc,0x52,0x8a,0xa3,0xbe,0xb4,0x03,0x0f,0x3c,0x75,0x58,0xa4,0xb7,0xaf,0x99,0xa0,0xcd,0x0a,0x06,0xed,0x1c,0x47,0x44,0x8b,0x69,0x1b,0xd1,0x2d,0xd8,0x4f};
 // printf("md5");
   for(int x = 0; x<32; x++)
    {
        *(seed+x)^=(*(message+23));
    }
        SHA256_Update(&shactx,seed,32);
        SHA256_Final(seed,&shactx);
    for(int x = 0; x<32; x++)
    {
        //printf("0x%02x,",*(seed+x));
        Boolean &=(*(seed+x)==(*(check23+x)));
    }
    if(Boolean == 1 )
    {
        for(int x = 0; x<1000000; x++)
        {
                SHA256_Update(&shactx,seed,32);
                SHA256_Final(seed,&shactx);
        }
    }
    else{

        printf("Invalid Password!\n");
        return -1;
    }
/*********************************************************************/
    unsigned char check24[] = {0xdf,0xd1,0x74,0xc4,0x17,0x74,0xc6,0x3c,0x64,0x9f,0x64,0xfc,0x1c,0xfd,0x56,0xb4,0x0d,0xc9,0xe8,0x7d,0xa1,0xac,0x90,0x71,0x9f,0x3a,0xc6,0xe7,0x26,0x5a,0x12,0x31};
   for(int x = 0; x<32; x++)
    {
        *(seed+x)^=(*(message+24));
    }
        SHA256_Update(&shactx,seed,32);
        SHA256_Final(seed,&shactx);
    for(int x = 0; x<32; x++)
    {
        //printf("0x%02x,",*(seed+x));
        Boolean &=(*(seed+x)==(*(check24+x)));
    }
    if(Boolean == 1 )
    {
        for(int x = 0; x<1000000; x++)
        {
                SHA256_Update(&shactx,seed,32);
                SHA256_Final(seed,&shactx);
        }
    }
    else{

        printf("Invalid Password!\n");
        return -1;
    }
/*********************************************************************/
    unsigned char check25[] = {0x49,0x19,0x9e,0x0e,0x5b,0x6f,0x8c,0x8e,0x11,0xb0,0x9f,0x93,0x40,0x5e,0x42,0x54,0xac,0x32,0xaf,0xa0,0x93,0xc2,0xc7,0xa3,0x67,0x4b,0x96,0xda,0x8d,0x12,0x0b,0xc8};
   for(int x = 0; x<32; x++)
    {
        *(seed+x)^=(*(message+25));
    }
        SHA256_Update(&shactx,seed,32);
        SHA256_Final(seed,&shactx);
    for(int x = 0; x<32; x++)
    {
        //printf("0x%02x,",*(seed+x));
        Boolean &=(*(seed+x)==(*(check25+x)));
    }
    if(Boolean == 1 )
    {
        for(int x = 0; x<1000000; x++)
        {
                SHA256_Update(&shactx,seed,32);
                SHA256_Final(seed,&shactx);
        }
    }
    else{

        printf("Invalid Password!\n");
        return -1;
    }
/*********************************************************************/
    unsigned char check26[] = {0x64,0x0f,0x60,0x7e,0x84,0x08,0x7b,0x0d,0x47,0x76,0xf2,0xcb,0xea,0xad,0x81,0x15,0x94,0x40,0xe2,0x01,0x5e,0x2c,0x40,0x37,0x5d,0x0d,0x92,0x05,0x8b,0x56,0x14,0x69};
   for(int x = 0; x<32; x++)
    {
        *(seed+x)^=(*(message+26));
    }
        SHA256_Update(&shactx,seed,32);
        SHA256_Final(seed,&shactx);
    for(int x = 0; x<32; x++)
    {
       // printf("0x%02x,",*(seed+x));
        Boolean &=(*(seed+x)==(*(check26+x)));
    }
    if(Boolean == 1 )
    {
        for(int x = 0; x<1000000; x++)
        {
                SHA256_Update(&shactx,seed,32);
                SHA256_Final(seed,&shactx);
        }
    }
    else{

        printf("Invalid Password!\n");
        return -1;
    }


/*********************************************************************/
    unsigned char check27[] = {0xf9,0x98,0x18,0x13,0x05,0x77,0x65,0x92,0x93,0x43,0x11,0xfb,0x9f,0x2c,0xf8,0xb3,0x44,0x55,0x22,0x31,0x37,0x1e,0x21,0xe3,0xa8,0x28,0xd6,0x0d,0x13,0x47,0x0e,0x42};
   for(int x = 0; x<32; x++)
    {
        *(seed+x)^=(*(message+27));
    }
        SHA256_Update(&shactx,seed,32);
        SHA256_Final(seed,&shactx);
    for(int x = 0; x<32; x++)
    {
       // printf("0x%02x,",*(seed+x));
        Boolean &=(*(seed+x)==(*(check27+x)));
    }
    if(Boolean == 1 )
    {
        for(int x = 0; x<1000000; x++)
        {
                SHA256_Update(&shactx,seed,32);
                SHA256_Final(seed,&shactx);
        }
    }
    else{

        printf("Invalid Password!\n");
        return -1;
    }

/*********************************************************************/
    unsigned char check28[] = {0xa8,0xd0,0x9a,0x27,0x63,0x40,0xb0,0x6d,0x72,0x36,0x70,0x56,0xd1,0xee,0xf6,0x9d,0x37,0x4b,0x69,0x6b,0x09,0x3b,0x41,0xaf,0x13,0xdf,0x44,0x47,0xfa,0x7b,0xaa,0xa6};
   for(int x = 0; x<32; x++)
    {
        *(seed+x)^=(*(message+28));
    }
        SHA256_Update(&shactx,seed,32);
        SHA256_Final(seed,&shactx);
    for(int x = 0; x<32; x++)
    {
        //printf("0x%02x,",*(seed+x));
        Boolean &=(*(seed+x)==(*(check28+x)));
    }
    if(Boolean == 1 )
    {
        for(int x = 0; x<1000000; x++)
        {
                SHA256_Update(&shactx,seed,32);
                SHA256_Final(seed,&shactx);
        }
    }
    else{

        printf("Invalid Password!\n");
        return -1;
    }
/**********************************************************************/
    unsigned char check29[] = {0xad,0x85,0xd3,0xda,0xb1,0xd7,0xec,0x24,0x0f,0xb7,0x61,0x92,0x65,0x78,0xde,0x39,0xb7,0xff,0xdb,0xbb,0x6d,0xfe,0x65,0xf8,0xce,0xe7,0x9e,0x11,0x41,0x93,0x30,0xcb};
 // printf("md5");
   for(int x = 0; x<32; x++)
    {
        *(seed+x)^=(*(message+29));
    }
        SHA256_Update(&shactx,seed,32);
        SHA256_Final(seed,&shactx);
    for(int x = 0; x<32; x++)
    {
        //printf("0x%02x,",*(seed+x));
        Boolean &=(*(seed+x)==(*(check29+x)));
    }
    if(Boolean == 1 )
    {
        for(int x = 0; x<1000000; x++)
        {
                SHA256_Update(&shactx,seed,32);
                SHA256_Final(seed,&shactx);
        }
    }
    else{

        printf("Invalid Password!\n");
        return -1;
    }
/*********************************************************************/
    unsigned char check30[] = {0xe6,0xfd,0xf1,0xed,0x9b,0x7e,0xf1,0x20,0xbc,0xfb,0x8b,0x0e,0x8f,0xa0,0x5d,0xa6,0x01,0x93,0xe9,0xfb,0x10,0x5f,0xa5,0xbf,0xcb,0x00,0x05,0xec,0x00,0xd6,0xc3,0x41};
   for(int x = 0; x<32; x++)
    {
        *(seed+x)^=(*(message+30));
    }
        SHA256_Update(&shactx,seed,32);
        SHA256_Final(seed,&shactx);
    for(int x = 0; x<32; x++)
    {
        //printf("0x%02x,",*(seed+x));
        Boolean &=(*(seed+x)==(*(check30+x)));
    }
    if(Boolean == 1 )
    {
        for(int x = 0; x<1000000; x++)
        {
                SHA256_Update(&shactx,seed,32);
                SHA256_Final(seed,&shactx);
        }
    }
    else{

        printf("Invalid Password!\n");
        return -1;
    }
/*********************************************************************/
unsigned char check31[] = {0xea,0x16,0xb6,0x97,0x79,0x7d,0xd2,0x56,0x23,0x0c,0x52,0xaa,0x12,0x60,0x78,0xef,0xbc,0x22,0xff,0x59,0xb1,0x74,0xfa,0x1d,0x40,0x3a,0x28,0x89,0x3c,0x81,0xbb,0x66};
   for(int x = 0; x<32; x++)
    {
        *(seed+x)^=(*(message+31));
    }
        SHA256_Update(&shactx,seed,32);
        SHA256_Final(seed,&shactx);
    for(int x = 0; x<32; x++)
    {
        //printf("0x%02x,",*(seed+x));
        Boolean &=(*(seed+x)==(*(check31+x)));
    }
    if(Boolean == 1 )
    {
        for(int x = 0; x<1000000; x++)
        {
                SHA256_Update(&shactx,seed,32);
                SHA256_Final(seed,&shactx);
        }
    }
    else{

        printf("Invalid Password!\n");
        return -1;
    }
/*********************************************************************/
    unsigned char check32[] = {0x88,0x94,0xe2,0x39,0x2e,0xc5,0x3e,0xcd,0xb9,0x0e,0x6a,0xa5,0x95,0x56,0x1f,0x04,0xfa,0xa2,0x12,0xb9,0x4b,0xeb,0x02,0x1c,0x77,0xfb,0xd7,0xae,0x66,0xae,0x5d,0xcc};
   for(int x = 0; x<32; x++)
    {
        *(seed+x)^=(*(message+32));
    }
        SHA256_Update(&shactx,seed,32);
        SHA256_Final(seed,&shactx);
    for(int x = 0; x<32; x++)
    {
        //printf("0x%02x,",*(seed+x));
        Boolean &=(*(seed+x)==(*(check32+x)));
    }
    if(Boolean == 1 )
    {
        for(int x = 0; x<1000000; x++)
        {
                SHA256_Update(&shactx,seed,32);
                SHA256_Final(seed,&shactx);
        }
    }
    else{

        printf("Invalid Password!\n");
        return -1;
    }
    /*********************************************************************/
    unsigned char check33[] = {0xa8,0x0c,0x4c,0xe8,0x72,0x74,0xc3,0x5d,0xb0,0xdd,0x00,0x8e,0xd4,0xc0,0x43,0xc9,0x6c,0x1e,0x4d,0xdc,0xbb,0x3d,0x5f,0x15,0x92,0x70,0x37,0xe7,0xb1,0x60,0xca,0x3d};
   for(int x = 0; x<32; x++)
    {
        *(seed+x)^=(*(message+33));
    }
        SHA256_Update(&shactx,seed,32);
        SHA256_Final(seed,&shactx);
    for(int x = 0; x<32; x++)
    {
        //printf("0x%02x,",*(seed+x));
        Boolean &=(*(seed+x)==(*(check33+x)));
    }
    if(Boolean == 1 )
    {
        for(int x = 0; x<1000000; x++)
        {
                SHA256_Update(&shactx,seed,32);
                SHA256_Final(seed,&shactx);
        }
    }
    else{

        printf("Invalid Password!\n");
        return -1;
    }
/*********************************************************************/
    unsigned char check34[] = {0x2c,0x85,0x44,0x4d,0xef,0x26,0xe6,0x04,0x58,0x61,0xd9,0x3a,0x19,0xf8,0xd5,0xd4,0x2b,0x1c,0xeb,0xb8,0xcd,0x71,0x79,0xcd,0xd2,0x03,0x44,0x0f,0xc8,0x22,0x7e,0x2b};
   for(int x = 0; x<32; x++)
    {
        *(seed+x)^=(*(message+34));
    }
        SHA256_Update(&shactx,seed,32);
        SHA256_Final(seed,&shactx);
    for(int x = 0; x<32; x++)
    {
      //  printf("0x%02x,",*(seed+x));
        Boolean &=(*(seed+x)==(*(check34+x)));
    }
    if(Boolean == 1 )
    {
        for(int x = 0; x<1000000; x++)
        {
                SHA256_Update(&shactx,seed,32);
                SHA256_Final(seed,&shactx);
        }
    }
    else{

        printf("Invalid Password!\n");
        return -1;
    }
/*********************************************************************/
    unsigned char check35[] = {0x8a,0xc0,0x24,0xe5,0x50,0x40,0x20,0xde,0xd5,0x55,0xae,0x3b,0x04,0xf3,0xac,0xb8,0xa1,0xca,0x15,0xa7,0x08,0x4f,0x8e,0xb5,0x90,0xe1,0x1b,0x96,0xa1,0x43,0xfd,0xa3};
   for(int x = 0; x<32; x++)
    {
        *(seed+x)^=(*(message+35));
    }
        SHA256_Update(&shactx,seed,32);
        SHA256_Final(seed,&shactx);
    for(int x = 0; x<32; x++)
    {
        //printf("0x%02x,",*(seed+x));
        Boolean &=(*(seed+x)==(*(check35+x)));
    }
    if(Boolean == 1 )
    {
        for(int x = 0; x<1000000; x++)
        {
                SHA256_Update(&shactx,seed,32);
                SHA256_Final(seed,&shactx);
        }
    }
    else{

        printf("Invalid Password!\n");
        return -1;
    }
/*********************************************************************/
    unsigned char check36[] = {0x28,0x9e,0xf0,0xc3,0xf5,0x7b,0x4f,0x2c,0xc0,0x6d,0xc1,0xd7,0xe7,0x14,0xce,0x39,0x78,0x85,0xd5,0xef,0x0e,0x8e,0xd5,0x6e,0x9b,0x96,0x4b,0x7e,0x11,0x9c,0x67,0x44};
   for(int x = 0; x<32; x++)
    {
        *(seed+x)^=(*(message+36));
    }
        SHA256_Update(&shactx,seed,32);
        SHA256_Final(seed,&shactx);
    for(int x = 0; x<32; x++)
    {
        //printf("0x%02x,",*(seed+x));
        Boolean &=(*(seed+x)==(*(check36+x)));
    }
    if(Boolean == 1 )
    {
        for(int x = 0; x<1000000; x++)
        {
                SHA256_Update(&shactx,seed,32);
                SHA256_Final(seed,&shactx);
        }
    }
    else{

        printf("Invalid Password!\n");
        return -1;
    }


/*********************************************************************/
    unsigned char check37[] = {0x5d,0x6b,0xde,0xe6,0x3b,0x6b,0xa1,0x86,0x99,0x3e,0x39,0xab,0x33,0xb2,0x48,0x53,0xd4,0x6f,0x21,0xe1,0x9d,0xe2,0xaf,0x72,0x00,0x2b,0x0b,0x5b,0x82,0x0a,0xba,0x80};
   for(int x = 0; x<32; x++)
    {
        *(seed+x)^=(*(message+37));
    }
        SHA256_Update(&shactx,seed,32);
        SHA256_Final(seed,&shactx);
    for(int x = 0; x<32; x++)
    {
        //printf("0x%02x,",*(seed+x));
        Boolean &=(*(seed+x)==(*(check37+x)));
    }
    if(Boolean == 1 )
    {
        for(int x = 0; x<1000000; x++)
        {
                SHA256_Update(&shactx,seed,32);
                SHA256_Final(seed,&shactx);
        }
    }
    else{

        printf("Invalid Password!\n");
        return -1;
    }

/*********************************************************************/
    unsigned char check38[] = {0x16,0xc1,0x3c,0xac,0x67,0x22,0xed,0x9a,0xb3,0x8b,0x5e,0xee,0x0a,0xfa,0x16,0xb3,0x1b,0x00,0xe9,0x6f,0x56,0xae,0xa3,0x1f,0xed,0xa4,0xc7,0xa4,0xcf,0xf8,0x53,0x1d};
   for(int x = 0; x<32; x++)
    {
        *(seed+x)^=(*(message+38));
    }
        SHA256_Update(&shactx,seed,32);
        SHA256_Final(seed,&shactx);
    for(int x = 0; x<32; x++)
    {
        //printf("0x%02x,",*(seed+x));
        Boolean &=(*(seed+x)==(*(check38+x)));
    }
    if(Boolean == 1 )
    {
        for(int x = 0; x<1000000; x++)
        {
                SHA256_Update(&shactx,seed,32);
                SHA256_Final(seed,&shactx);
        }
    }
    else{

        printf("Invalid Password!\n");
        return -1;
    }
/*********************************************************************/
    unsigned char check39[] = {
0xe5,0x5e,0x87,0x1f,0xf9,0x1f,0x5a,0x04,0xef,0x2f,0xf4,0xfa,0x54,0x6d,0xff,0xef,0xd4,0x90,0x25,0x5c,0xd0,0x00,0xf4,0xac,0xf9,0xa5,0x4d,0x32,0x35,0x53,0x34,0x9c};
 // printf("md5");
   for(int x = 0; x<32; x++)
    {
        *(seed+x)^=(*(message+39));
    }
        SHA256_Update(&shactx,seed,32);
        SHA256_Final(seed,&shactx);
    for(int x = 0; x<32; x++)
    {
        //printf("0x%02x,",*(seed+x));
        Boolean &=(*(seed+x)==(*(check39+x)));
    }
    if(Boolean == 1 )
    {
        for(int x = 0; x<1000000; x++)
        {
                SHA256_Update(&shactx,seed,32);
                SHA256_Final(seed,&shactx);
        }
    }
    else{

        printf("Invalid Password!\n");
        return -1;
    }

printf("Congratulations!\n");

return 0;
}




