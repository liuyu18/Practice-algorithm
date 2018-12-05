#include <stdio.h>
#include "log.h"
void test(){
    printf("测试函数");
}
int main(int argc, char const *argv[])
{
    printf("进入main函数\n");
    log_debug("测试",LOG_LEVEL_ALL,1,"测试");
    return 0;
}



