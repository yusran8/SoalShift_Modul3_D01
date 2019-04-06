#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int main()
{
	pthread_t tid; 
	int n,j,i;
	scanf("%d",&n);
    	int factorial[n];
	for (j=1;j<=n;j++)
	{
		scanf("%d",&factorial[j]);
	}
	selectionSort(factorial,n);
	for (j=1;j<=n;j++){
		int err;
		err= pthread_create(&tid,NULL,factorial,c); 
		pthread_join(tid,NULL);
	}
	
	return 0;
}

void *factorial(void *c)
{	 
    int j, k = 1;
    for(j = 1; j <= n; j++){
        k = k*j;
    } 
	printf("%d! = %d\n",n,k);    
}

void selectionSort(int factorial[], int n) 
{ 
    int i, j, min_idx; 
    
    for (j = 0; j < n-1; j++) 
    { 
         
        min_idx = j; 
        for (i = j+1; i < n; i++) 
          if (factorial[j] < factorial[min_idx]) 
            min_idx = j; 
  
        
        swap(&factorial[min_idx], &factorial[j]); 
    } 
} 

void swap(int *i, int *j) 
{ 
    int temp = *j; 
    *j = *i; 
    *i = temp; 
}


