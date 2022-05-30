//FCFS C PROGRAM
#include<stdio.h>
#include<stdlib.h>
int n,a[100],b[100],v[100],start[100],stop[100];
void gantt()
{
int min,i,j,ind,dum=0;
for(j=0;j<n;j++)
{
min=999;
for(i=0;i<n;i++)
{
if(!v[i] && a[i]<min)
{
min=a[i];
ind=i;
}
}
v[ind]=1;
if(dum<a[ind])
{
start[ind]=a[ind];
}
else
{
start[ind]=dum;
}
stop[ind]=start[ind]+b[ind];
dum=stop[ind];
}
}
void avgwait()
{
int wait[100],i;
float avg=0;
printf("The waiting times :\n");
for(i=0;i<n;i++)
{
wait[i]=start[i]-a[i];
avg+=wait[i];
printf("P%d : %d ms\n",i+1,wait[i]);
}
avg=avg/n;
printf("Average waiting time = %f\n",avg);
}
void avgtat()
{
int tat[100],i;
float avg=0;
printf("The turn around times :\n");
for(i=0;i<n;i++)
{
tat[i]=stop[i]-a[i];
avg+=tat[i];
printf("P%d : %d ms\n",i+1,tat[i]);
}
avg=avg/n;
printf("Average turn around time = %f\n",avg);
}
int main()
{int i;
printf("Enter the no. of processes : ");
scanf("%d",&n);
printf("Enter the arrival time :\n");
for(i=0;i<n;i++)
{
printf("P%d : ",i+1);
scanf("%d",&a[i]);
v[i]=0;
start[i]=stop[i]=0;
}
printf("Enter the burst time :\n");
for(i=0;i<n;i++)
{
printf("P%d : ",i+1);
scanf("%d",&b[i]);
}
gantt();
avgwait();
avgtat();
return 0;
}
