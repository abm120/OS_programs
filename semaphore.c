#include<stdio.h>
#include<sys/types.h>
#include<sys/sem.h>
#include<sys/ipc.h>

union semun
{
int val;
struct semid_ds *buf;
unsigned short *array;
}

main()
{
int key, semid;
union semun arg;
key = ftok("semaphore.c",'d');
printf("\n key = %d",key);
semid = semget(key,1, IPC_CREAT|0644);
printf("\n semid = %d\n", semid);
arg.val =1;
semctl(semid,0,SETVAL,arg);
}

