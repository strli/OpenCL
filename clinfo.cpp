#include<stdio.h>
#include<stdlib.h>

#ifdef _APPLE_
#include <OpenCL/cl.h>
#else
#include<CL/cl.h>
#endif

void checkErr(cl_int err,int num)
{
    if(CL_SUCCESS!=err)
    {
        printf("OpenCL err(%d) at %d\n",err,num-1);

    }
}
int main(int argc,char **argv)
{
    cl_device_id *device;
    cl_platform_id platform;
    cl_int err;
    cl_uint NumDeivce;
    //选择第一个平台
    err=clGetPlatformIDs(1,&platform,NULL);
    checkErr(err,__LINE__);
    err=clGetDeviceIDs(platform,CL_DEVICE_TYPE_GPU,0,NULL,&NumDeivce);
    checkErr(err,__LINE__);
    device=(cl_device_id*)malloc(sizeof(cl_device_id)*NumDeivce);

    //选择GPU设备
    err=clGetDeviceIDs(platform,CL_DEVICE_TYPE_GPU,NumDeivce,device,NULL);
    checkErr(err,__LINE__);
    //printf("Total Platform %d\n Total Gpu Device %d\n",platform,NumDeivce);
    for(int i=0;i<NumDeivce;i++)
    {
        //查询设备名称
        char buffer[100];
        err=clGetDeviceInfo(device[i],CL_DEVICE_NAME,100,buffer,NULL);
        checkErr(err,__LINE__);
        printf("Device name :%s\n",buffer);

        //查询设备计算单元最大数目
        cl_uint UnintNum;
        err=clGetDeviceInfo(device[i],CL_DEVICE_MAX_COMPUTE_UNITS,sizeof(cl_uint),&UnintNum,NULL);
        checkErr(err,__LINE__);
        printf("computer units number:%d\n",UnintNum);

        //查询设备核心频率
        cl_uint frequency;
        err=clGetDeviceInfo(device[i],CL_DEVICE_MAX_CLOCK_FREQUENCY,sizeof(cl_uint),&frequency,NULL);
        printf("Device Frequency:%d(MHz)\n",frequency);

        //查询设备全局内存大小
        cl_ulong GlobalSize;
        err=clGetDeviceInfo(device[i],CL_DEVICE_GLOBAL_MEM_SIZE,sizeof(cl_ulong),&GlobalSize,NULL);
        checkErr(err,__LINE__);
        printf("Device Global Size:%0.0f(MB)\n",(float)GlobalSize/1024/1024);

        //查询设备全局内存缓存行
        cl_uint GlobalCacheLine;
        err=clGetDeviceInfo(device[i],CL_DEVICE_GLOBAL_MEM_CACHELINE_SIZE,sizeof(cl_uint),&GlobalCacheLine,NULL);
        checkErr(err,__LINE__);

        //查询设备支持的OpenCL版本
        char DeviceVersion[100];
        err=clGetDeviceInfo(device[i],CL_DEVICE_VERSION,100,DeviceVersion,NULL);
        checkErr(err,__LINE__);
        printf("Device Version:%s\n",DeviceVersion);

        //查询设备扩展名
       /*  char *DeviceExtensions;
        cl_uint ExtenNum;
        err=clGetDeviceInfo(device[i],CL_DEVICE_EXTENSIONS,0,NULL,&ExtenNum);
        checkErr(err,__LINE__);
        DeviceExtensions=(char*)malloc(ExtenNum);
        err=clGetDeviceInfo(device[i],CL_DEVICE_EXTENSIONS,ExtenNum,DeviceExtensions,NULL);
        checkErr(err,__LINE__);
        printf("Device Extensions:%s\n",DeviceExtensions);
        free(DeviceExtensions);
       */

    }
    free(device);
    return 0;
}
