#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

main()
{
int fd; 
char buf[80];
fd = open("myfifo",O_RDONLY);
read(fd, buf, sizeof(buf));
printf("data read = %s\n",buf);
}