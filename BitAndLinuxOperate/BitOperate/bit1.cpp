#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bitset>
using namespace std;
static void logBit(){
	// 0001 0011
	// 1  3
	// 0x13
	// 16 + 2+ 1
unsigned int a = 0x13;
unsigned int b = a << 2;
unsigned int c = a >> 2;
cout << hex << b << endl; //输出十六进制数
cout<<"二进制    "<<bitset<8>(b)<<"   "<<bitset<16>(b)<<endl;

    // printf("二进制 --> %s\n", b);
    // printf("二进制 --> %s\n", c);

    // unsigned int d1 = 0x12;
    // unsigned int d2 = d1 << 4;
    // printf("十六进制 --> %X\n", d1);
    // printf("十六进制 --> %X\n", d2);
    // itoa(d1, d11, 2);
    // itoa(d2, d22, 2);
    // printf("二进制 --> %s\n", d11);
    // printf("二进制 --> %s\n", d22);
    // // char ch1 = 1;
    // itoa(ch1, ch11, 2);
    // printf("二进制 --> %s\n", ch11);
	// char ch2 = ch1 << 7; // 1000 0000
    // itoa(ch2, ch22, 2);
    // printf("二进制 --> %s\n", ch22);
	// unsigned  int flags = 1u  << 7;

}
