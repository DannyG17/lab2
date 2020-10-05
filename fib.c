#include <pthread.h>
#include <stdio.h>

int sum[500];

void *runner(void *params);

int main(int argc, char *argv[])
{
	pthread_t tid;
	pthread_attr_t attr;
	
	if(argc !=2){
	fprintf(stderr,"usage: a.out <integer value<\n");
	return -1;
	}
	
	if(atoi(argv[1]) <0){
	fprintf(stderr, "Numer : %d must be >= 0\n",atoi(argv[1]));
	return -1;
	}
	

	
	pthread_attr_init(&attr);
	int i=1;
	int count = atoi(argv[1]);
	for(i=0;i<=count;i++){
	pthread_create(&tid,&attr,runner,argv[1]);
	pthread_join(tid,NULL);
	printf("Fib of %d is %d\n",i,sum[i]);
	}

}

void *runner(void *param)
{
	int i, upper = atoi(param);
	sum[0] =0;
	sum[1]=1;
	
	for(i=2; i<=upper; i++){
	
	sum[i]=sum[i-1] +sum[i-2];
}
	
	
	pthread_exit(0);


}
