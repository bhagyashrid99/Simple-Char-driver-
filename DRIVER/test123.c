#include<stdio.h> 
#include<fcntl.h> 
#include<errno.h> 
#include<string.h>
#include<stdlib.h>
#define BL 512
extern int errno; 

int main() 
{      
    // if file does not have in directory  
    // then file foo.txt is created. 
char string[BL];
char recive[BL];
memset(string,0,sizeof(recive));
memset(recive,0,sizeof(string)); 
   int fd,ret;
	fd = open("/dev/first_char_device", O_RDWR);  
      
//    printf("fd = %d/n", fd); 
      
    if (fd ==-1) 
    { 
        // print which type of error have in a code 
        printf("Error Number % d\n", errno);             
   	return errno;
    } 
    printf("please enter the string to send");
fgets(string,BL,stdin);
 ret= write(fd,string,strlen(string));

	if(ret < 0)
{	
	printf("\nfile failed to write");
}

printf("\n\npress any key to read from device");
getchar();

ret=read(fd,recive,BL);
printf("\nreading file . . . . . . ");
printf("\n\n %s",recive);


return 0; 
} 
