#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

typedef unsigned char unChar;

unChar fn(unChar a){
    if ((a>>7) ==0){
        a = a<<1;
    }else {
        a = (a<<1)^27;
    }
    return a;
}
unChar sub(unChar a){
    unChar sub_bytes[16][16]={ {0x63,0x7C,0x77,0x7B,0xF2,0x6B,0x6F,0xC5,0x30,0x01,0x67,0x2B,0xFE,0xD7,0xAB,0x76},
                            {0xCA,0x82,0xC9,0x7D,0xFA,0x59,0x47,0xF0,0xAD,0xD4,0xA2,0xAF,0x9C,0xA4,0x72,0xC0},
                            {0xB7,0xFD,0x93,0x26,0x36,0x3F,0xF7,0xCC,0x34,0xA5,0xE5,0xF1,0x71,0xD8,0x31,0x15},
                            {0x04,0xC7,0x23,0xC3,0x18,0x96,0x05,0x9A,0x07,0x12,0x80,0xE2,0xEB,0x27,0xB2,0x75},
                            {0x09,0x83,0x2C,0x1A,0x1B,0x6E,0x5A,0xA0,0x52,0x3B,0xD6,0xB3,0x29,0xE3,0x2F,0x84},
                            {0x53,0xD1,0x00,0xED,0x20,0xFC,0xB1,0x5B,0x6A,0xCB,0xBE,0x39,0x4A,0x4C,0x58,0xCF},
                            {0xD0,0xEF,0xAA,0xFB,0x43,0x4D,0x33,0x85,0x45,0xF9,0x02,0x7F,0x50,0x3C,0x9F,0xA8},
                            {0x51,0xA3,0x40,0x8F,0x92,0x9D,0x38,0xF5,0xBC,0xB6,0xDA,0x21,0x10,0xFF,0xF3,0xD2},
                            {0xCD,0x0C,0x13,0xEC,0x5F,0x97,0x44,0x17,0xC4,0xA7,0x7E,0x3D,0x64,0x5D,0x19,0x73},
                            {0x60,0x81,0x4F,0xDC,0x22,0x2A,0x90,0x88,0x46,0xEE,0xB8,0x14,0xDE,0x5E,0x0B,0xDB},
                            {0xE0,0x32,0x3A,0x0A,0x49,0x06,0x24,0x5C,0xC2,0xD3,0xAC,0x62,0x91,0x95,0xE4,0x79},
                            {0xE7,0xC8,0x37,0x6D,0x8D,0xD5,0x4E,0xA9,0x6C,0x56,0xF4,0xEA,0x65,0x7A,0xAE,0x08},
                            {0xBA,0x78,0x25,0x2E,0x1C,0xA6,0xB4,0xC6,0xE8,0xDD,0x74,0x1F,0x4B,0xBD,0x8B,0x8A},
                            {0x70,0x3E,0xB5,0x66,0x48,0x03,0xF6,0x0E,0x61,0x35,0x57,0xB9,0x86,0xC1,0x1D,0x9E},
                            {0xE1,0xF8,0x98,0x11,0x69,0xD9,0x8E,0x94,0x9B,0x1E,0x87,0xE9,0xCE,0x55,0x28,0xDF},
                            {0x8C,0xA1,0x89,0x0D,0xBF,0xE6,0x42,0x68,0x41,0x99,0x2D,0x0F,0xB0,0x54,0xBB,0x16}
    };
    a=sub_bytes[a>>4][a&15];
    return a;
}
unChar INV_sub(unChar a){
    unChar inv_s[16][16]={ {0x52, 0x09, 0x6A, 0xD5, 0x30, 0x36, 0xA5, 0x38, 0xBF, 0x40, 0xA3, 0x9E, 0x81, 0xF3, 0xD7, 0xFB},
                            {0x7C, 0xE3, 0x39, 0x82, 0x9B, 0x2F, 0xFF, 0x87, 0x34, 0x8E, 0x43, 0x44, 0xC4, 0xDE, 0xE9, 0xCB},
                            {0x54, 0x7B, 0x94, 0x32, 0xA6, 0xC2, 0x23, 0x3D, 0xEE, 0x4C, 0x95, 0x0B, 0x42, 0xFA, 0xC3, 0x4E},
                            {0x08, 0x2E, 0xA1, 0x66, 0x28, 0xD9, 0x24, 0xB2, 0x76, 0x5B, 0xA2, 0x49, 0x6D, 0x8B, 0xD1, 0x25},
                            {0x72, 0xF8, 0xF6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xD4, 0xA4, 0x5C, 0xCC, 0x5D, 0x65, 0xB6, 0x92},
                            {0x6C, 0x70, 0x48, 0x50, 0xFD, 0xED, 0xB9, 0xDA, 0x5E, 0x15, 0x46, 0x57, 0xA7, 0x8D, 0x9D, 0x84},
                            {0x90, 0xD8, 0xAB, 0x00, 0x8C, 0xBC, 0xD3, 0x0A, 0xF7, 0xE4, 0x58, 0x05, 0xB8, 0xB3, 0x45, 0x06},
                            {0xD0, 0x2C, 0x1E, 0x8F, 0xCA, 0x3F, 0x0F, 0x02, 0xC1, 0xAF, 0xBD, 0x03, 0x01, 0x13, 0x8A, 0x6B},
                            {0x3A, 0x91, 0x11, 0x41, 0x4F, 0x67, 0xDC, 0xEA, 0x97, 0xF2, 0xCF, 0xCE, 0xF0, 0xB4, 0xE6, 0x73},
                            {0x96, 0xAC, 0x74, 0x22, 0xE7, 0xAD, 0x35, 0x85, 0xE2, 0xF9, 0x37, 0xE8, 0x1C, 0x75, 0xDF, 0x6E},
                            {0x47, 0xF1, 0x1A, 0x71, 0x1D, 0x29, 0xC5, 0x89, 0x6F, 0xB7, 0x62, 0x0E, 0xAA, 0x18, 0xBE, 0x1B},
                            {0xFC, 0x56, 0x3E, 0x4B, 0xC6, 0xD2, 0x79, 0x20, 0x9A, 0xDB, 0xC0, 0xFE, 0x78, 0xCD, 0x5A, 0xF4},
                            {0x1F, 0xDD, 0xA8, 0x33, 0x88, 0x07, 0xC7, 0x31, 0xB1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xEC, 0x5F},
                            {0x60, 0x51, 0x7F, 0xA9, 0x19, 0xB5, 0x4A, 0x0D, 0x2D, 0xE5, 0x7A, 0x9F, 0x93, 0xC9, 0x9C, 0xEF},
                            {0xA0, 0xE0, 0x3B, 0x4D, 0xAE, 0x2A, 0xF5, 0xB0, 0xC8, 0xEB, 0xBB, 0x3C, 0x83, 0x53, 0x99, 0x61},
                  {0x17, 0x2B, 0x04, 0x7E, 0xBA, 0x77, 0xD6, 0x26, 0xE1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0C, 0x7D}
 };
 a=inv_s[a>>4][a&15];
 return a;
}
void K_sheduling(int inp_key1[],unChar r_keys[15][4][4]){
    unChar inp_key[256];
    for(int i=0;i<256;i++){
        inp_key[i]=inp_key1[i]+'0';
    }
    unChar arr[8][4]={{}};
    unChar arr1[8][4]={{}};
    for(int i1=0;i1<=31;i1++){
      //  unChar sub[]={};
        char sub[8];
        int c = 0;
        while (c < 8) {
            sub[c] = inp_key[(i1*8)+c];
            c++;
        }
        sub[c] = '\0';
        long int binaryval=atol(sub);
        long int hexadecimalval = 0, i=1, remainder;
        while (binaryval != 0){
            remainder = binaryval % 10;
            hexadecimalval = hexadecimalval + remainder * i;
            i = i * 2;
            binaryval = binaryval / 10;
        }
        arr[i1/4][i1%4]=hexadecimalval;
    }
    unChar round_constants[7][4]={ {0x01,0x00,0x00,0x00},
                                      {0x02,0x00,0x00,0x00},
                                      {0x04,0x00,0x00,0x00},
                                      {0x08,0x00,0x00,0x00},
                                      {0x10,0x00,0x00,0x00},
                                      {0x20,0x00,0x00,0x00},
                                      {0x40,0x00,0x00,0x00},
    };
    unChar words[60][4]={};
    for(int i=0;i<=7;i++){
        for(int j=0;j<=3;j++){
            words[i][j]=arr[i][j];
        }
    }
    for(int i=8;i<60;i++){
        unChar temp[1][4]={};
        for(int j=0;j<=3;j++){
            temp[0][j]=words[i-1][j];
        }
        if((i%8) == 0){
            unChar a=temp[0][0];
            for(int j=0;j<=2;j++){
                temp[0][j]=sub(temp[0][(j+1)%4]) ^ round_constants[(i/8)-1][j];
            }
            temp[0][3]=sub(a) ^ round_constants[(i/8)-1][3];
        }
        if((i%8) == 4){
            for(int i1=0;i1<4;i1++){
                temp[0][i1]=sub(temp[0][i1]);
            }
        }
        for(int j=0;j<=3;j++){
            words[i][j]=words[i-8][j] ^ temp[0][j];
        }
    }
    int q=0;
    for(int i=0;i<60;i++){
        if(q==4){
            q=0;
        }
        for(int j=0;j<4;j++){
            r_keys[i/4][j][q]=words[i][j];
        }
        q++;
    }
}
void AES_ENC(unChar msg[4][4],unChar r_keys[15][4][4]){
    for(int i=0;i<=3;i++){
        for(int j=0;j<=3;j++){
            msg[i][j]=msg[i][j] ^ r_keys[0][i][j];
        }
    }

    for(int i=1;i<14;i++){
        for(int j=0;j<=3;j++){
            for(int k=0;k<=3;k++){
                msg[j][k]=sub(msg[j][k]);
            }
        }


        unChar dummy[4][4]={};
        for(int j=0;j<=3;j++){
            for(int k=0;k<=3;k++){
                dummy[j][k]=msg[j][k];
            }
        }
        for(int j=0;j<=3;j++){
            for(int k=0;k<=3;k++){
                msg[j][k]=dummy[j][(k+j)%4];
            }
        }



        unChar D1[4][4]={};
        for(int j=0;j<=3;j++){
            for(int k=0;k<=3;k++){
                D1[j][k]=msg[j][k];
            }
        }
        for(int k=0;k<=3;k++){
          for(int j=0;j<=3;j++){
              msg[j][k] = fn(D1[j][k]) ^ fn(D1[(j+1)%4][k]) ^ D1[(j+1)%4][k] ^ D1[(j+2)%4][k] ^ D1[(j+3)%4][k];
          }
        }




        for(int k=0;k<=3;k++){
          for(int j=0;j<=3;j++){
            msg[k][j]=msg[k][j] ^ r_keys[i][k][j];
          }
        }


    }
    for(int j=0;j<=3;j++){
        for(int k=0;k<=3;k++){
            msg[j][k]=sub(msg[j][k]);
        }
    }
    unChar dummy[4][4]={};
    for(int j=0;j<=3;j++){
        for(int k=0;k<=3;k++){
            dummy[j][k]=msg[j][k];
        }
    }
    for(int j=0;j<=3;j++){
        for(int k=0;k<=3;k++){
            msg[j][k]=dummy[j][(k+j)%4];
        }
    }
    for(int k=0;k<=3;k++){
        for(int j=0;j<=3;j++){
            msg[k][j]=msg[k][j] ^ r_keys[14][k][j];
        }
    }

}
void rightrotate(int dummy[32],int pos){
    int a[pos];
    for(int i=0;i<pos;i++){
        a[i]=dummy[31-i];
    }
    for(int i=31;i>=pos;i--){
        dummy[i]=dummy[i-pos];
    }
    for(int i=0;i<pos;i++){
        dummy[i]=a[pos-1-i];
    }
}
void rightshift(int dummy[32],int pos){
    for(int i=31;i>=pos;i--){
        dummy[i]=dummy[i-pos];
    }
    for(int i=0;i<pos;i++){
        dummy[i]=0;
    }
}
void add(int add1[32],int arr[32]){
    int carry=0,p=31;
    for(int i=31;i>=0;i--) {
        if((add1[i] + arr[i] + carry ) == 0) {
            add1[p] = 0;
            carry = 0;
            p--;
            continue;
        }
        if((add1[i] + arr[i] + carry) == 1) {
            add1[p] = 1;
            carry = 0;
            p--;
            continue;
        }
        if((add1[i] + arr[i] + carry) == 2) {
            add1[p] = 0;
            carry = 1;
            p--;
            continue;
        }
        if((add1[i] + arr[i] + carry) > 2) {
            add1[p] = 1;
            carry = 1;
            p--;
            continue;
        }
    }
}
void sha(char num[],int result[]){
    int q=0,o=strlen(num);
    int count=0,count1=0,count2=0,l=0;
    int aa[10][8]={{0,0,1,1,0,0,0,0},
                   {0,0,1,1,0,0,0,1},
                   {0,0,1,1,0,0,1,0},
                   {0,0,1,1,0,0,1,1},
                   {0,0,1,1,0,1,0,0},
                   {0,0,1,1,0,1,0,1},
                   {0,0,1,1,0,1,1,0},
                   {0,0,1,1,0,1,1,1},
                   {0,0,1,1,1,0,0,0},
                   {0,0,1,1,1,0,0,1}
    };

    int bin[o*8],bin1[o*8];
    for(int i=0;i<o;i++){
        int r=num[i];
        for(int i1=0;i1<8;i1++){
            bin[count]=aa[r-48][i1];
            count++;
        }
    }

    int d=(447-count);
    while(d<0){
        d=512+d;
        count1++;
    }
    int y[512+(count1*512)];
    for(int i=0;i<512+(count1*512);i++){
        y[i]=bin[i];
        if(i%8==0 && i!=0){
            o--;
        }
    }
    y[count]=1;
    for(int i=count+1;i<count+1+d;i++){
        y[i]=0;
    }
    for(int i=0;count>0;i++){
        bin1[i]=count%2;count=count/2;
        count2++;
    }
    for(int i=0;i<64-count2;i++){
        y[448+(512*count1)+i]=0;
    }
    for(int i=0;i<count2;i++){
        y[511+(512*count1)-i]=bin1[i];
    }
    int M[count1+1][512];int row=0;
    for(int i=0;i<512*(count1+1);i++){
        if(i%512==0&&i!=0){
            row++;
        }
        M[row][i-(512*row)]=y[i];
    }
    int hash[8][32]={{0,1,1,0,1,0,1,0,0,0,0,0,1,0,0,1,1,1,1,0,0,1,1,0,0,1,1,0,0,1,1,1},
                     {1,0,1,1,1,0,1,1,0,1,1,0,0,1,1,1,1,0,1,0,1,1,1,0,1,0,0,0,0,1,0,1},
                     {0,0,1,1,1,1,0,0,0,1,1,0,1,1,1,0,1,1,1,1,0,0,1,1,0,1,1,1,0,0,1,0},
                     {1,0,1,0,0,1,0,1,0,1,0,0,1,1,1,1,1,1,1,1,0,1,0,1,0,0,1,1,1,0,1,0},
                     {0,1,0,1,0,0,0,1,0,0,0,0,1,1,1,0,0,1,0,1,0,0,1,0,0,1,1,1,1,1,1,1},
                     {1,0,0,1,1,0,1,1,0,0,0,0,0,1,0,1,0,1,1,0,1,0,0,0,1,0,0,0,1,1,0,0},
                     {0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,0,1,1,0,0,1,1,0,1,0,1,0,1,1},
                     {0,1,0,1,1,0,1,1,1,1,1,0,0,0,0,0,1,1,0,0,1,1,0,1,0,0,0,1,1,0,0,1}
    };
    int k[64][32]={{0,1,0,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,1,1,1,1,0,0,1,1,0,0,0}, {0,1,1,1,0,0,0,1,0,0,1,1,0,1,1,1,0,1,0,0,0,1,0,0,1,0,0,1,0,0,0,1}, {1,0,1,1,0,1,0,1,1,1,0,0,0,0,0,0,1,1,1,1,1,0,1,1,1,1,0,0,1,1,1,1}, {1,1,1,0,1,0,0,1,1,0,1,1,0,1,0,1,1,1,0,1,1,0,1,1,1,0,1,0,0,1,0,1},
               {0,0,1,1,1,0,0,1,0,1,0,1,0,1,1,0,1,1,0,0,0,0,1,0,0,1,0,1,1,0,1,1}, {0,1,0,1,1,0,0,1,1,1,1,1,0,0,0,1,0,0,0,1,0,0,0,1,1,1,1,1,0,0,0,1}, {1,0,0,1,0,0,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,1,0,1,0,1,0,0,1,0,0}, {1,0,1,0,1,0,1,1,0,0,0,1,1,1,0,0,0,1,0,1,1,1,1,0,1,1,0,1,0,1,0,1},
               {1,1,0,1,1,0,0,0,0,0,0,0,0,1,1,1,1,0,1,0,1,0,1,0,1,0,0,1,1,0,0,0}, {0,0,0,1,0,0,1,0,1,0,0,0,0,0,1,1,0,1,0,1,1,0,1,1,0,0,0,0,0,0,0,1}, {0,0,1,0,0,1,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,1,0,1,1,0,1,1,1,1,1,0}, {0,1,0,1,0,1,0,1,0,0,0,0,1,1,0,0,0,1,1,1,1,1,0,1,1,1,0,0,0,0,1,1},
               {0,1,1,1,0,0,1,0,1,0,1,1,1,1,1,0,0,1,0,1,1,1,0,1,0,1,1,1,0,1,0,0}, {1,0,0,0,0,0,0,0,1,1,0,1,1,1,1,0,1,0,1,1,0,0,0,1,1,1,1,1,1,1,1,0}, {1,0,0,1,1,0,1,1,1,1,0,1,1,1,0,0,0,0,0,0,0,1,1,0,1,0,1,0,0,1,1,1}, {1,1,0,0,0,0,0,1,1,0,0,1,1,0,1,1,1,1,1,1,0,0,0,1,0,1,1,1,0,1,0,0},
               {1,1,1,0,0,1,0,0,1,0,0,1,1,0,1,1,0,1,1,0,1,0,0,1,1,1,0,0,0,0,0,1}, {1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,0,1,0,0,0,1,1,1,1,0,0,0,0,1,1,0}, {0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,0,0,1,1,1,0,1,1,1,0,0,0,1,1,0}, {0,0,1,0,0,1,0,0,0,0,0,0,1,1,0,0,1,0,1,0,0,0,0,1,1,1,0,0,1,1,0,0},
               {0,0,1,0,1,1,0,1,1,1,1,0,1,0,0,1,0,0,1,0,1,1,0,0,0,1,1,0,1,1,1,1}, {0,1,0,0,1,0,1,0,0,1,1,1,0,1,0,0,1,0,0,0,0,1,0,0,1,0,1,0,1,0,1,0}, {0,1,0,1,1,1,0,0,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,1,1,1,0,1,1,1,0,0}, {0,1,1,1,0,1,1,0,1,1,1,1,1,0,0,1,1,0,0,0,1,0,0,0,1,1,0,1,1,0,1,0},
               {1,0,0,1,1,0,0,0,0,0,1,1,1,1,1,0,0,1,0,1,0,0,0,1,0,1,0,1,0,0,1,0}, {1,0,1,0,1,0,0,0,0,0,1,1,0,0,0,1,1,1,0,0,0,1,1,0,0,1,1,0,1,1,0,1}, {1,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,0,0,1,1,1,1,1,0,0,1,0,0,0}, {1,0,1,1,1,1,1,1,0,1,0,1,1,0,0,1,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1},
               {1,1,0,0,0,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,1,1,0,0,1,1}, {1,1,0,1,0,1,0,1,1,0,1,0,0,1,1,1,1,0,0,1,0,0,0,1,0,1,0,0,0,1,1,1}, {0,0,0,0,0,1,1,0,1,1,0,0,1,0,1,0,0,1,1,0,0,0,1,1,0,1,0,1,0,0,0,1}, {0,0,0,1,0,1,0,0,0,0,1,0,1,0,0,1,0,0,1,0,1,0,0,1,0,1,1,0,0,1,1,1},
               {0,0,1,0,0,1,1,1,1,0,1,1,0,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,0,1,0,1}, {0,0,1,0,1,1,1,0,0,0,0,1,1,0,1,1,0,0,1,0,0,0,0,1,0,0,1,1,1,0,0,0}, {0,1,0,0,1,1,0,1,0,0,1,0,1,1,0,0,0,1,1,0,1,1,0,1,1,1,1,1,1,1,0,0}, {0,1,0,1,0,0,1,1,0,0,1,1,1,0,0,0,0,0,0,0,1,1,0,1,0,0,0,1,0,0,1,1},
               {0,1,1,0,0,1,0,1,0,0,0,0,1,0,1,0,0,1,1,1,0,0,1,1,0,1,0,1,0,1,0,0}, {0,1,1,1,0,1,1,0,0,1,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,0,1,1,1,0,1,1}, {1,0,0,0,0,0,0,1,1,1,0,0,0,0,1,0,1,1,0,0,1,0,0,1,0,0,1,0,1,1,1,0}, {1,0,0,1,0,0,1,0,0,1,1,1,0,0,1,0,0,0,1,0,1,1,0,0,1,0,0,0,0,1,0,1},
               {1,0,1,0,0,0,1,0,1,0,1,1,1,1,1,1,1,1,1,0,1,0,0,0,1,0,1,0,0,0,0,1}, {1,0,1,0,1,0,0,0,0,0,0,1,1,0,1,0,0,1,1,0,0,1,1,0,0,1,0,0,1,0,1,1}, {1,1,0,0,0,0,1,0,0,1,0,0,1,0,1,1,1,0,0,0,1,0,1,1,0,1,1,1,0,0,0,0}, {1,1,0,0,0,1,1,1,0,1,1,0,1,1,0,0,0,1,0,1,0,0,0,1,1,0,1,0,0,0,1,1},
               {1,1,0,1,0,0,0,1,1,0,0,1,0,0,1,0,1,1,1,0,1,0,0,0,0,0,0,1,1,0,0,1}, {1,1,0,1,0,1,1,0,1,0,0,1,1,0,0,1,0,0,0,0,0,1,1,0,0,0,1,0,0,1,0,0}, {1,1,1,1,0,1,0,0,0,0,0,0,1,1,1,0,0,0,1,1,0,1,0,1,1,0,0,0,0,1,0,1}, {0,0,0,1,0,0,0,0,0,1,1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,1,1,1,0,0,0,0},
               {0,0,0,1,1,0,0,1,1,0,1,0,0,1,0,0,1,1,0,0,0,0,0,1,0,0,0,1,0,1,1,0}, {0,0,0,1,1,1,1,0,0,0,1,1,0,1,1,1,0,1,1,0,1,1,0,0,0,0,0,0,1,0,0,0}, {0,0,1,0,0,1,1,1,0,1,0,0,1,0,0,0,0,1,1,1,0,1,1,1,0,1,0,0,1,1,0,0}, {0,0,1,1,0,1,0,0,1,0,1,1,0,0,0,0,1,0,1,1,1,1,0,0,1,0,1,1,0,1,0,1},
               {0,0,1,1,1,0,0,1,0,0,0,1,1,1,0,0,0,0,0,0,1,1,0,0,1,0,1,1,0,0,1,1}, {0,1,0,0,1,1,1,0,1,1,0,1,1,0,0,0,1,0,1,0,1,0,1,0,0,1,0,0,1,0,1,0}, {0,1,0,1,1,0,1,1,1,0,0,1,1,1,0,0,1,1,0,0,1,0,1,0,0,1,0,0,1,1,1,1}, {0,1,1,0,1,0,0,0,0,0,1,0,1,1,1,0,0,1,1,0,1,1,1,1,1,1,1,1,0,0,1,1},
               {0,1,1,1,0,1,0,0,1,0,0,0,1,1,1,1,1,0,0,0,0,0,1,0,1,1,1,0,1,1,1,0}, {0,1,1,1,1,0,0,0,1,0,1,0,0,1,0,1,0,1,1,0,0,0,1,1,0,1,1,0,1,1,1,1}, {1,0,0,0,0,1,0,0,1,1,0,0,1,0,0,0,0,1,1,1,1,0,0,0,0,0,0,1,0,1,0,0}, {1,0,0,0,1,1,0,0,1,1,0,0,0,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0},
               {1,0,0,1,0,0,0,0,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0}, {1,0,1,0,0,1,0,0,0,1,0,1,0,0,0,0,0,1,1,0,1,1,0,0,1,1,1,0,1,0,1,1}, {1,0,1,1,1,1,1,0,1,1,1,1,1,0,0,1,1,0,1,0,0,0,1,1,1,1,1,1,0,1,1,1}, {1,1,0,0,0,1,1,0,0,1,1,1,0,0,0,1,0,1,1,1,1,0,0,0,1,1,1,1,0,0,1,0}
    };
    for(int i=0;i<=row;i++){
        int word[64][32],row1=0;
        for(int i1=0;i1<512;i1++){
            if(i1%32==0){
                row1++;
            }
            word[row1][i1-row1*32]=M[i][i1];
        }
        for(int i1=16;i1<64;i1++){
            int D1[32],D2[32],D3[32],s0[32],s1[32];
            for(int i2=0;i2<32;i2++){
                D1[i2]=word[i1-15][i2];
                D2[i2]=word[i1-15][i2];
                D3[i2]=word[i1-15][i2];
            }
            rightrotate(D1,7);
            rightrotate(D2,18);
            rightshift(D3,3);
            for(int i2=0;i2<32;i2++){
                s0[i2]=D1[i2]^D2[i2]^D3[i2];
            }
            for(int i2=0;i2<32;i2++){
                D1[i2]=word[i1-2][i2];
                D2[i2]=word[i1-2][i2];
                D3[i2]=word[i1-2][i2];
            }
            rightrotate(D1,17);
            rightrotate(D2,19);
            rightshift(D3,10);
            for(int i2=0;i2<32;i2++){
                s1[i2]=D1[i2] ^ D2[i2] ^ D3[i2];
            }
            int add1[32]={0};
            add(add1,word[i1-16]);
            add(add1,s0);
            add(add1,word[i1-7]);
            add(add1,s1);
            for(int i2=0;i2<32;i2++){
                word[i1][i2]=add1[i2];
            }
        }
        int A1[8][32];
        for(int i1=0;i1<8;i1++){
            for(int i2=0;i2<32;i2++){
                A1[i1][i2]=hash[i1][i2];
            }
        }
        for(int i1=0;i1<64;i1++){
            int D1[32],D2[32],D3[32],s0[32],s1[32],ch[32],temp1[32],temp2[32],maj[32];
            for(int i2=0;i2<32;i2++){
                D1[i2]=A1[4][i2];
                D2[i2]=A1[4][i2];
                D3[i2]=A1[4][i2];
            }
            rightrotate(D1,6);
            rightrotate(D2,11);
            rightrotate(D3,25);
            for(int i2=0;i2<32;i2++){
                s1[i2]=D1[i2] ^ D2[i2] ^ D3[i2];
            }
            for(int i2=0;i2<32;i2++){
                D1[i2]=A1[4][i2] & A1[5][i2];
                if(A1[4][i2]==0){
                    D2[i2]=1;
                }
                else{
                    D2[i2]=0;
                }
                D3[i2]=D2[i2] & A1[6][i2];
            }
            for(int i2=0;i2<32;i2++){
                ch[i2]=D1[i2] ^ D3[i2];
            }
            int add1[32]={0};
            add(add1,A1[7]);
            add(add1,s1);
            add(add1,ch);
            add(add1,k[i1]);
            add(add1,word[i1]);
            for(int i2=0;i2<32;i2++){
                temp1[i2]=add1[i2];
                add1[i2]=0;
            }
            for(int i2=0;i2<32;i2++){
                D1[i2]=A1[0][i2];
                D2[i2]=A1[0][i2];
                D3[i2]=A1[0][i2];
            }
            rightrotate(D1,2);
            rightrotate(D2,13);
            rightrotate(D3,22);
            for(int i2=0;i2<32;i2++){
                s0[i2]=D1[i2]^D2[i2]^D3[i2];
            }
            for(int i2=0;i2<32;i2++){
                D1[i2]=A1[0][i2] & A1[1][i2];
                D2[i2]=A1[0][i2] & A1[2][i2];
                D3[i2]=A1[1][i2] & A1[2][i2];
            }
            for(int i2=0;i2<32;i2++){
                maj[i2]=D1[i2]^D2[i2]^D3[i2];
            }
            add(add1,s0);
            add(add1,maj);
            for(int i2=0;i2<32;i2++){
                temp2[i2]=add1[i2];
                add1[i2]=0;
            }
            for(int i2=0;i2<32;i2++){
                A1[7][i2]=A1[6][i2];
                A1[6][i2]=A1[5][i2];
                A1[5][i2]=A1[4][i2];
            }
            add(add1,A1[3]);
            add(add1,temp1);
            for(int i2=0;i2<32;i2++){
                A1[4][i2]=add1[i2];
                add1[i2]=0;
            }
            for(int i2=0;i2<32;i2++){
                A1[3][i2]=A1[2][i2];
                A1[2][i2]=A1[1][i2];
                A1[1][i2]=A1[0][i2];
            }
            add(add1,temp1);
            add(add1,temp2);
            for(int i2=0;i2<32;i2++){
                A1[0][i2]=add1[i2];
                add1[i2]=0;
            }
        }
        for(int i1=0;i1<8;i1++){
            int add1[32]={0};
            add(add1,hash[i1]);
            add(add1,A1[i1]);
            for(int i2=0;i2<32;i2++){
                hash[i1][i2]=add1[i2];
            }
        }
    }
    int p=0;
    for(int i=0;i<8;i++){
        for(int i1=0;i1<32;i1++){
            result[p]=hash[i][i1];
            p++;
        }
    }
}
void AES_DEC(unChar msg[4][4],unChar r_keys[15][4][4]){
    for(int k=0;k<=3;k++){
        for(int j=0;j<=3;j++){
            msg[k][j]=msg[k][j] ^ r_keys[14][k][j];
        }
    }
    unChar D2[4][4]={{}};
    for(int j=0;j<=3;j++){
        for(int k=0;k<=3;k++){
            D2[j][k]=msg[j][k];
        }
    }
    for(int j=0;j<=3;j++){
        for(int k=0;k<=3;k++){
            msg[j][k]=D2[j][(k+j)%4];
            if(j!=0 && j!=2){
                msg[j][k]=D2[j][(k+j+2)%4];
            }
        }
    }

    for(int j=0;j<=3;j++){
            for(int k=0;k<=3;k++){
                msg[j][k]=INV_sub(msg[j][k]);
            }
    }

    for(int i=13;i>=1;i--){
        for(int k=0;k<=3;k++){
          for(int j=0;j<=3;j++){
            msg[k][j]=msg[k][j] ^ r_keys[i][k][j];
          }
        }
        unChar dumm[4][4]={{}};
        for(int j=0;j<=3;j++){
            for(int k=0;k<=3;k++){
                dumm[j][k]=msg[j][k];
            }
        }
        for(int k=0;k<=3;k++){
          for(int j=0;j<=3;j++){
            msg[j][k] = fn(fn(fn(dumm[j][k]))) ^ fn(fn(dumm[j][k])) ^ fn(dumm[j][k]) ^ fn(fn(fn(dumm[(j+1)%4][k]))) ^ fn(dumm[(j+1)%4][k]) ^ dumm[(j+1)%4][k] ^ fn(fn(fn(dumm[(j+2)%4][k]))) ^ fn(fn(dumm[(j+2)%4][k])) ^ dumm[(j+2)%4][k] ^ fn(fn(fn(dumm[(j+3)%4][k]))) ^ dumm[(j+3)%4][k];
          }
        }
        unChar dummy5[4][4]={{}};
        for(int j=0;j<=3;j++){
        for(int k=0;k<=3;k++){
            dummy5[j][k]=msg[j][k];
        }
        }
        for(int j=0;j<=3;j++){
        for(int k=0;k<=3;k++){
            msg[j][k]=dummy5[j][(k+j)%4];
            if(j!=0 && j!=2){
                msg[j][k]=dummy5[j][(k+j+2)%4];
            }
        }
        }
        for(int j=0;j<=3;j++){
            for(int k=0;k<=3;k++){
                msg[j][k]=INV_sub(msg[j][k]);
            }
        }
    }
    for(int k=0;k<=3;k++){
        for(int j=0;j<=3;j++){
            msg[k][j]=msg[k][j] ^ r_keys[0][k][j];
        }
    }
}
int main(){
    int p=101,r1=0;
    int a[p],a1[p*p][2];
    for(int x=0;x<p;x++){
        a[x]=(x*x*x + 25*x + 31) % p;
    }
    for(int i=0;i<p;i++){
        for(int y=0;y<p;y++){
            if((y*y)%p == a[i]){
                a1[r1][0]=i;
                a1[r1][1]=y;
                r1++;
            }
        }
    }

    srand(time(0));
    int r=rand()%(r1+1);
    printf("A POINT ON CURVE: %d\t %d\n",a1[r][0],a1[r][1]);

    int nA=15,nB=68;

    int qA_x=nA*a1[r][0];     int qA_y=nA*a1[r][1];
    int qB_x=nB*a1[r][0];     int qB_y=nB*a1[r][1];
    int A_x=nA*qB_x;          int A_y=nA*qB_y;
    int B_x=nB*qA_x;          int B_y=nB*qA_y;
    printf("\nSECRET KEY COMPUTED BY ALICE: %d\t%d\nSECRET KEY COMPUTED BY BOB:   %d\t%d\n",A_x,A_y,B_x,B_y);

    char ka[20],D1[10],kb[20],D2[10];
    sprintf(ka, "%d",A_x);         sprintf(kb, "%d",B_x);
    sprintf(D1, "%d",A_y);     sprintf(D2, "%d",B_y);
    strcat(ka,D1);             strcat(kb,D2);
    int k_A[256],k_B[256];
    sha(ka,k_A);
    sha(kb,k_B);
    printf("k_A = SHA-256(A_x||A_y)\n");
    int p1=0;
    for(int i=0;i<8;i++){
        for(int i1=0;i1<32;i1++){
            if(i1%8==0 && i1!=0){
                printf(" ");
            }
            printf("%d",k_A[p1]);
            p1++;
        }
        printf(" ");
    }
    printf("\nk_B = SHA-256(B_x||B_y)\n");
    int p2=0;
    for(int i=0;i<8;i++){
        for(int i1=0;i1<32;i1++){
            if(i1%8==0 && i1!=0){
                printf(" ");
            }
            printf("%d",k_B[p2]);
            p2++;
        }
        printf(" ");
    }

    unChar m[8][4] = {{0xff,0xbb,0x88,0xcc},
                             {0xee,0xaa,0x99,0xdd},
                             {0xdd,0x99,0xaa,0xee},
                             {0xcc,0x88,0xbb,0xff},
                             {0x00,0x44,0x77,0x33},
                             {0x11,0x55,0x66,0x22},
                             {0x22,0x66,0x55,0x11},
                             {0x33,0x77,0x44,0x00}
    };
    printf("\n------------------------------------------------\n");
    unChar msg[2][4][4]={{{}}};
    int col=0;
    for(int i=0;i<2;i++){
        int row=0;
        for(int i1=0;i1<8;i1++){
            if(row==4){
                row=row-4;
                col++;
            }
            msg[0][row][col]=m[i1][i];
            msg[1][row][col]=m[i1][i+2];
            row++;
        }
        col++;
    }
    unChar r_keys[15][4][4];
    K_sheduling(k_A,r_keys);
    AES_ENC(msg[0],r_keys);
    for(int i=0;i<4;i++){
        for(int i1=0;i1<4;i1++){
            msg[1][i][i1]=msg[0][i][i1] ^ msg[1][i][i1];
        }
    }
    AES_ENC(msg[1],r_keys);
    unChar c_A[32];int o=0;
    for(int i=0;i<4;i++){
        for(int i1=0;i1<4;i1++){
            c_A[o]=msg[0][i1][i];
            c_A[o+16]=msg[1][i1][i];
            o++;
        }
    }
    printf("\nCIPHERED MESSAGE---------");
    for(int i=0;i<32;i++){
        printf("%x\t",c_A[i]);
    }


    int m_bin[256];
    for(int i=0;i<32;i++){
        for(int i1=0;i1<8;i1++){
            m_bin[(7-i1)+8*i]=m[i%8][i/8] & 1;
            m[i%8][i/8]>>=1;
        }
    }
    char dp[513];
    for(int i=0;i<=255;i++){
        dp[i]=k_A[i]+'0';
        dp[256+i]=m_bin[i]+'0';
    }
    if(k_A[254]==1){
        dp[254]='0';
    }else{
        dp[254]='1';
    }dp[512]='\0';
    // printf("\n%s\n",dp);
    int Mp[256];
    sha(dp,Mp);
    char dp1[513];
    for(int i=0;i<256;i++){
        dp1[i]=k_A[i]+'0';
        dp1[256+i]=Mp[i]+'0';
    }
    if(k_A[255]==1){
        dp1[255]=0+'0';
    }else{
        dp1[255]=1+'0';
    }dp1[512]='\0';
    int MAC_A[256];
    sha(dp1,MAC_A);
    printf("\nMAC_A=SHA-256((KA xor 1)||SHA-256((KA xor 2)||MA))\n");
    for(int i=0;i<256;i++){
        if(i%8==0 && i!=0){
            printf("  ");
        }
        printf("%d",MAC_A[i]);
    }

    printf("\nBOB DECRYPTED MESSAGE---");
    unChar r_keys1[15][4][4];
    unChar C_msg[2][4][4]={{{}}};
    int t=0;
    for(int i=0;i<4;i++){
        for(int i1=0;i1<4;i1++){
            C_msg[0][i1][i]=c_A[t];
            C_msg[1][i1][i]=c_A[t+16];
            t++;
        }
    }
    K_sheduling(k_B,r_keys1);
    AES_DEC(C_msg[1],r_keys1);
    for(int i=0;i<4;i++){
        for(int i1=0;i1<4;i1++){
            C_msg[1][i][i1]=C_msg[0][i][i1] ^ C_msg[1][i][i1];
        }
    }
    AES_DEC(C_msg[0],r_keys1);
    for(int i=0;i<4;i++){
        for(int i1=0;i1<4;i1++){
            printf("%x\t",C_msg[0][i1][i]);
        }
    }
    for(int i=0;i<4;i++){
        for(int i1=0;i1<4;i1++){
            printf("%x\t",C_msg[1][i1][i]);
        }
    }



    unChar cipher_m[8][4];
    int col1=0;
    for(int i=0;i<2;i++){
        int row=0;
        for(int i1=0;i1<8;i1++){
            if(row==4){
                row=row-4;
                col1++;
            }
            cipher_m[i1][i]=C_msg[0][row][col1];
            cipher_m[i1][i+2]=C_msg[1][row][col1];
            row++;
        }
        col1++;
    }

    int m_bin_1[256];
    for(int i=0;i<32;i++){
        for(int i1=0;i1<8;i1++){
            m_bin_1[(7-i1)+8*i]=cipher_m[i%8][i/8] & 1;
            cipher_m[i%8][i/8]>>=1;
        }
    }
    char dp2[513];
    for(int i=0;i<256;i++){
        dp2[i]=k_B[i]+'0';
        dp2[256+i]=m_bin_1[i]+'0';
    }
    if(k_B[254]==1){
        dp2[254]=0+'0';
    }else{
        dp2[254]=1+'0';
    }dp2[512]='\0';
    int Mp1[256];
    sha(dp2,Mp1);
    char dp3[513];
    for(int i=0;i<256;i++){
        dp3[i]=k_B[i]+'0';
        dp3[256+i]=Mp1[i]+'0';
    }
    if(k_B[255]==1){
        dp3[255]=0+'0';
    }
    else{
        dp3[255]=1+'0';
    }
    dp3[512]='\0';
    int MAC_B[256];
    sha(dp3,MAC_B);
    printf("\nMAC_B=SHA-256((K_B xor 1)||SHA-256((K_B xor 2)||M_B))\n");
    for(int i=0;i<256;i++){
        if(i%8==0 && i!=0){
            printf("  ");
        }
        printf("%d",MAC_B[i]);
    }
    printf("\n\n K_A = K_B, M_A = M_B and MAC_A = MAC_B");

    return 0;
}
