#include <stdio.h>
#include<stdlib.h>
#include<time.h>
int array[100];
float timedifference_msec(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}
int main()
{
    struct timeval t0;
    struct timeval t1;
    float elapsed;
    while(1)
    {
		int i,ch,l,m,h;
		long int size,limit,key;
		printf("\n1.Create list size and limit\n2.Generate Random Numbers\n3. Search\n4.Exit\n");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
			{	
				printf("Enter number of Elements: ");
				scanf("%d",&size);
				long int array[size];
				printf("Enter Upper limit in place values: ");
				scanf("%ld",&limit);
				break;
			}
			
			case 2:
			{
				
				int num=size;
				int j,x,y,temp;
				srand( (unsigned) time(NULL) * getpid());
				gettimeofday(&t0, NULL);
				if(array != NULL)
				{
					for(j = 0; j < num; j++)
					{
						array[j] = rand()%limit;
					}
				}
				gettimeofday(&t1, NULL);
        		elapsed = timedifference_msec(t0, t1);
				
				for(x = 0; x < num - 1; x++)
				{       
					for(y = 0; y < num - x - 1; y++)
					{          
						if(array[y] > array[y + 1])
						{               
						    temp = array[y];
						    array[y] = array[y + 1];
						    array[y + 1] = temp;
						}
					}
				}
				
				for(j = 0; j < num; j++)
				{
					printf("%ld\n",array[j]);
				}				
				printf("Random Generation code executed in %f milliseconds.\n", elapsed);
				break;
			}
			
			
				
			case 3:
			{	  	 
				printf("Enter element to search for: ");
				scanf("%ld",&key);
				l=0;h=size-1;m=(h+l)/2;
				gettimeofday(&t0, NULL);
				while (l<=h)
				{
					if(array[m]<key)
						l=m+1;
						
					else if (array[m]==key) 
					{
						printf("%ld found at position %d\n",key,m);
					break;
					}
					
					else
						h=m-1;
						
					m=(l+h)/2;
					}
					gettimeofday(&t1, NULL);
        			elapsed = timedifference_msec(t0, t1);
					
					
					if(l>h)
						printf("%ld not present\n",key);
				
				printf("Binary Search code executed in %f milliseconds.\n", elapsed);
				break;
			}
			
			case 4:
			{
				printf("EXITING\n");
				exit(0);
			}
		}
	}
}
