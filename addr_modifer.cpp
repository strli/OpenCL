/*
地址空间修饰符
__global 或者global
__local  或者local
__constant 或者constant
__private 或者private

如果一个变量由一个地址空间修饰符限定，那么
这个变量就在指定的地址空间分配

*/
#include<CL/cl.h>
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

int main()
{
    //在private地址空间申明一个指针p，指针指向的是一个全局地址空间对象
    //global constant int *p; 
    float x[4];    //在private地址空间申明一个整数数组
}
//src在私有地址空间分配一个指向常量地址空间的一个指针
//v：在私有地址空间申明
/* int my_func_a(constant float *src,int4 v)
{
    float temp;
    //temp分配在私有地址空间
} */