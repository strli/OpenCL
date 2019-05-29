#include<CL/cl.h>
#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
    cl_platform_id platform;
    cl_int err;
    cl_uint NumDevice;
    err=clGetPlatformIDs(1,&platform,NULL);
    cl_context_properties properties[]={CL_CONTEXT_PLATFORM,(cl_context_properties)platform,0};
    cl_context context=clCreateContextFromType(properties,CL_DEVICE_TYPE_ALL,NULL,NULL,&err);
    NumDevice=0;
    size_t DeviceSize;
    err=clGetContextInfo(context,CL_CONTEXT_NUM_DEVICES,sizeof(cl_uint),&NumDevice,NULL);
    printf("Number of Device in context :%d\n",NumDevice);

    return 0;
}