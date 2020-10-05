
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

pthread_mutex_t lock;
pthread_barrier_t barrier;

int SharedVariable =0;

void  *SimpleThread(void *i){
int *p;
p=i;
int num,val;

for(num=0; num<20; num++){
#ifdef PTHREAD_SYNC
pthread_mutex_lock(&lock);
#endif
if(random()>RAND_MAX/2)
usleep(10);

val = SharedVariable;

printf("*** thread %d sees value %d\n",*p,val);
SharedVariable = val+1;

#ifdef PTHREAD_SYNC
pthread_mutex_unlock(&lock);
#endif
}
#ifdef PTHREAD_SYNC
pthread_barrier_wait(&barrier);
#endif
val= SharedVariable;
printf("Thread %d sees final value %d\n",*p,val);

}

int main(int argc,char *argv[]){

pthread_t *tid;
int i;

 


if(argc !=2){

printf("Invalid number of arguments\n");
printf("Usage a.out <n>\n");
return 0;
}
else{

int valid=1;
for(i =0; i<strlen(argv[1]);i++){
if(argv[1][i]<'0'|| argv[1][i] >'9'){

valid=0;
break;
}

}
if(valid==0){
printf("\n Please provide a positive integer as an argument\n");
}
else{

pthread_mutex_init(&lock,NULL);
pthread_barrier_init(&barrier,NULL,atoi(argv[1]));

int n = atoi(argv[1]);
tid= (pthread_t *)malloc(sizeof(pthread_t)* atoi(argv[1]));
int *j= (int *)malloc(sizeof(int)*n);
 for(i=0;i<n;i++)
 j[i]=i;

for(i=0;i<n;i++){
pthread_create(&tid[i],NULL,SimpleThread,&j[i]);
}

for(i=0;i<n;i++){
pthread_join(tid[i],NULL);

}

}
}

exit(0);



}
