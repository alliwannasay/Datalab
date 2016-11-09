#include <stdlib.h>
#include <stdio.h>
int bitCount(int x);
void outputByB(int x);

int main()
{
    int x = 0x7fffffff;
    int result = bitCount(x);
    printf("%x\n",result);
}

int bitCount(int x) {
    int auxFor2 = (0x55) | (0x55<<8);
    auxFor2 = auxFor2 | (auxFor2<<16);
    int auxFor4 = (0x33) | (0x33<<8);
    auxFor4 = auxFor4 | (auxFor4<<16);
    int auxFor8 = (0x0f) | (0x0f<<8);
    auxFor8 = auxFor8 | (auxFor8<<16);
    int auxFor16 = (0xff) | (0xff<<16);
    int auxFor32 = (0xff) | (0xff<<8);
    int count = (x+(x>>1))&auxFor2;
    outputByB(count);
    count = (count+(count>>2))&auxFor4;
    count = (count+(count>>4))&auxFor8;
    count = (count+(count>>8))&auxFor16;
    count = (count+(count>>16))&auxFor32;
    return count;
    
}

void outputByB(int x)
{
    char string[33];
    itoa(x,string,2);
    printf("十进制数：%d，二进制数：%s\n",x,string);
}