#include"stdio.h"
#include"unistd.h"
#include"pthread.h"
int i=0,min=0,max=0,avg=0;
int a[100];
void *average()
{
for(int k=0;k<i;k++)
{
avg+=a[k];
}
avg=(int)(avg/i);
}
void *minimum()
{
min=a[0];
for(int k=0;k<i;k++)
{
if(a[k]<min)
{
min=a[k];
}
}
}
void *maximum()
{
max=a[0];
for(int k=0;k<i;k++)
{
if(a[k]>max)
{
max=a[k];
}
}
}
void *par()
{
printf("The average value is %d\n",avg);
printf("The minimum value is %d\n",min);
printf("The maximum value is %d\n",max);
}
void main()
{
pthread_t parent,worker1,worker2,worker3;
printf("Enter how many digits you want to store::");
scanf("%d",&i);
for(int k=0;k<i;k++)
{
scanf("%d",&a[k]);
}
pthread_create(&worker3,NULL,average,NULL);
pthread_join(worker3,NULL);
pthread_create(&worker2,NULL,maximum,NULL);
pthread_join(worker2,NULL);
pthread_create(&worker1,NULL,minimum,NULL);
pthread_join(worker1,NULL);
pthread_create(&parent,NULL,par,NULL);
pthread_join(parent,NULL);
}
