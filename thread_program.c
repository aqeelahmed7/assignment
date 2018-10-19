#include <stdio.h>
#include <pthread.h>
void * TestThread(void * arg)
{
    int array[1000];
	int start=(int)arg;	
	int sum=0;
	for (int i=start;i<arg+100;i++)
		sum=sum+array[i];
		
	return ((void*)sum);
}
int main()
{
    int array[1000];
	pthread_t thread_t1,thread_t2,thread_t3,thread_t4,thread_t5,thread_t6,thread_t7,thread_t8,thread_t9,thread_t10;
	int sum1,sum2,sum3,sum4,sum5,sum6,sum7,sum8,sum9,sum10,sum;
	for (int i=1;i<=1000;i++)
		array[i]=i;
		
	pthread_create(&thread_t1,NULL,TestThread,(void*)(0));
	pthread_create(&thread_t2,NULL,TestThread,(void*)(100));
	pthread_create(&thread_t3,NULL,TestThread,(void*)(200));
	pthread_create(&thread_t4,NULL,TestThread,(void*)(300));
	pthread_create(&thread_t5,NULL,TestThread,(void*)(400));
	pthread_create(&thread_t6,NULL,TestThread,(void*)(500));
	pthread_create(&thread_t7,NULL,TestThread,(void*)(600));
	pthread_create(&thread_t8,NULL,TestThread,(void*)(700));
	pthread_create(&thread_t9,NULL,TestThread,(void*)(800));
	pthread_create(&thread_t10,NULL,TestThread,(void*)(900));
	pthread_join(thread_t1,(void **) &sum1); 
	pthread_join(thread_t2,(void **) &sum2);
	pthread_join(thread_t3,(void **) &sum3);
	pthread_join(thread_t4,(void **) &sum4);
	pthread_join(thread_t5,(void **) &sum5);
	pthread_join(thread_t6,(void **) &sum6);
	pthread_join(thread_t7,(void **) &sum7);
	pthread_join(thread_t8,(void **) &sum8);
	pthread_join(thread_t9,(void **) &sum9);
	pthread_join(thread_t10,(void **)&sum10);
	
	sum=sum1+sum2+sum3+sum4+sum5+sum6+sum7+sum8+sum9+sum10;
	
	printf("Total sum : %d\n",sum);
	return 0;
}
