#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/wait.h>
int check_pram(int ,const char* ,int );//参数验证
int block_cur(const char* ,int );//切片
int process_create(const char* ,const char* ,int ,int );//进程创建
int process_wait(void);//进程回收
