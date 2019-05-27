#include<stdio.h>
#include<malloc.h>
#include<memory.h>
#include<CL/cl.h>

int main(){
    cl_uint num_device;
    cl_uint num_platform;
    cl_platform_id *platform;
    cl_device_id *devices;
    cl_int err;
    err=clGetPlatformIDs(0,0,&num_platform);
    platform=(cl_platform_id*)malloc(sizeof(cl_platform_id)*num_platform);
    err=clGetPlatformIDs(num_platform,platform,NULL);
    //获取第一个平台上的设备数量
    err=clGetDeviceIDs(platform[0],CL_DEVICE_TYPE_GPU,0,NULL,&num_device);
    devices=(cl_device_id*)malloc(sizeof(cl_device_id)*num_device);
    //初始化可用设备
    err=clGetDeviceIDs(platform[0],CL_DEVICE_TYPE_GPU,num_device,devices,NULL);
    printf("numer of opencl platform :%d\n",num_platform);
    printf("numer of opencl device :%d\n",num_device);
    return 0;
}