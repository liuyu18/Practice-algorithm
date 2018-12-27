#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bitset>
using namespace std;

int main(int argc, char const *argv[]){
    // int a = 1;
    // int b = 0;
    // int c = a&b;
    // cout<<"二进制"<<bitset<8>(c)<<endl;
    // printf("十六进制 --> %X\n", c);



    // // 0x1f<<3
    // // 1   1 1 1 1
    // // 16  8 4 2 1
    // int c1 = (0x1f << 3);
    // //1   1  1  1  1 0 0 0
    // //128 64 32 16 8 0 0 0
    // cout<<"二进制c1:"<<bitset<8>(c1)<<endl;
    // printf("十六进制c1 --> %X\n", c1);

    // int c2 = ((0x1f<<3) | (7<<23));
    // cout<<"二进制c2:"<<bitset<30>(c2)<<endl;
    // printf("十六进制c2 --> %X\n", c2);

    // int c3 = (~(0xff<<4));
    // cout<<"二进制c3:"<<bitset<30>(c3)<<endl;
    // printf("十六进制c3 --> %X\n", c3);

    // //给定一个a 设置bit3 其他位不变
    // int a1 = 2018;
    // printf("---------\n");
    // cout<<"二进制a1:"<<bitset<8>(a1)<<endl;
    // printf("十六进制a1 --> %X\n", a1);
    // a1 = a1|(1<<3);
    // printf("---------\n");
    // cout<<"二进制a1:"<<bitset<8>(a1)<<endl;
    // printf("十六进制a1 --> %X\n", a1);


    // // 给定一个整形数a，取出a的bit3~bit8
    // // 2018 -> 111 1110 0010
    // // (a1 >> 3)
    // a1 &= (0x3f<<3);

    // printf("---------\n");
    // cout<<"二进制a1:"<<bitset<8>(a1)<<endl;
    // printf("十六进制a1 --> %X\n", a1);

    // a1 >>= 3;

    // printf("---------\n");
    // cout<<"二进制a1:"<<bitset<8>(a1)<<endl;
    // printf("十六进制a1 --> %X\n", a1);

    int a2 = 201812;
    cout<<"二进制a2之前:"<<bitset<20>(a2)<<endl;
    printf("十六进制a2 之前--> %X\n", a2);
    printf("--------------------------------\n");
    a2 &= (0x7ff<<7);

    int tmp = (0x7ff<<7);
    cout<<"二进制tmp:"<<bitset<20>(tmp)<<endl;
    printf("十六进制tmp --> %X\n", tmp);
    printf("--------------------------------\n");
    cout<<"二进制a2:"<<bitset<20>(a2)<<endl;
    printf("十六进制a2 --> %X\n", a2);
    printf("--------------------------------\n");
    a2>>=7;
    cout<<"二进制a2最后:"<<bitset<20>(a2)<<endl;
    printf("十六进制a2最后 --> %X\n", a2);
    printf("--------------------------------\n");
    return 0;
}
