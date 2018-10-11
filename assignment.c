#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
    int arr[1000];
    int fd[2];
    int status=0;
    for(int i=0;i<1000;i++)
    {
        arr[i]=i+1;
    }
    int pid=fork();
    if(pid==0)
    {
        close(fd[0]);
        for(int j=0;j<100;j++)
        {
            status=status+arr[j] ;
        }   
    }
    else
    {
    	for(int j=100;j<200;j++)
	   {
            status=status+arr[j] ;
        }
      	for(int j=200;j<300;j++)
		{
            status = status+arr[j];
        }
                    
		for(int j=300;j<400;j++)
		{
        	status = status+arr[j];
        }
             
       for(int j=400;j<500;j++)
		{
           status = status+arr[j];
    	}
        for(int j=500;j<600;j++)
        {
        	status = status+arr[j];
        }  
        for(int j=600;j<700;j++)
		{
       	sum=sum+arr[j];
       	}
        for(int j=700;j<800;j++)
		{
       		sum=sum+arr[j];
       	}
        for(int j=800;j<900;j++)
           {
            status = status+arr[j];
           }
        for(int j=900;j<1000;j++)
        {
          	status = status+arr[j];
        }                   
	wait(&status);                                          
	printf("Sum is:",status);   
}
    return 0;
}

