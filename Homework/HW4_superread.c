//一个用于所有用户读取Unix系统中所有文件的程序，使用方式：程序名 文件名。
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<fcntl.h>
int main (int argc, char *argv[])  
{  

    //降低权限
    seteuid(1000);

    FILE *fp;
    int ch;
  
    //对于高权限读取降权
    if(access(argv[1],R_OK)!=0){       
        seteuid(0);
    }

    fp = fopen(argv[1], "r");

    //得到文件指针后立即降低权限
    seteuid(1000);

	if (fp == NULL)
	{
		printf("open file %s failed", argv[1]);
	}
	else
	{
		printf("open file %s successfully", argv[1]);
	}


  
    fclose(fp);
    
    return 0;  
}  
