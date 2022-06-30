#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

main()
{
int fd; 
char buf[80];
fd = open("myfifo",O_WRONLY);
printf("\n Write:");
scanf("%[^\n]",buf);
write(fd, buf, sizeof(buf));
}