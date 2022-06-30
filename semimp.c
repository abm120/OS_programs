#include<stdio.h>
#include<sys/types.h>
#include<sys/sem.h>
#include<sys/ipc.h>

main()
{
int key,semid;
key = ftok('semaphore.c", 'd');
printf(" key = %d", key);
struct sembuf buf = {0,-1,0};
semid = semget(key,1,0);
printf("\n before entering into critical section\n");
semop(semid, &buf, 1);  /*lock*/
printf("\n Inside the critical section\n");
getchar();
buf.sem_op = 1;
semop(semid, &buf, 1);  /*unlock*/
}
