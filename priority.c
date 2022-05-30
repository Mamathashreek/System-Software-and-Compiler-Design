//2. Given the list of processes, their burst times, priority and arrival times, Write a C program to implement the
//preemptive priority CPU scheduling algorithm. Display the turnaround time & waiting time for each process. Also
//calculate the average turnaround time and average waiting time.
#include<stdio.h>
#include<stdlib.h>
struct time
{
int bt,at,tat,wt,rt,pt,rtime;
//int p;
};
int main()
{struct time p[10];
int i,j,k,n,ttat=0,twt=0;
int endtime,gant[100];
float awt,atat;
int remain=0,t;
int min,process;
printf("Enter number of processes :");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter the burst time of %d process :",i+1);
scanf("%d",&p[i].bt);
printf("Enter the arrival time of %d process :",i+1);
scanf("%d",&p[i].at);
printf("Enter the priorty of process :");
scanf("%d",&p[i].pt);
//p[i].p=i;
p[i].rtime=p[i].bt;
}
for(t=0;remain!=n;t++)
{
min=999;
for(i=0;i<n;i++)
{
if(p[i].at<=t&&p[i].pt<min&&p[i].rtime>0)
{
gant[t]=i;
min=p[i].pt;
process=i;
}
}
p[process].rtime--;
if(p[process].rtime==0)
{
remain++;
endtime=t+1;
p[process].wt=endtime-p[process].bt-p[process].at;
p[process].tat=endtime-p[process].at;
ttat+=endtime-p[process].at;
twt+=endtime-p[process].bt-p[process].at;
}
}
printf("\n");
for(i=0;i<2*n;i++)
printf("-------------");
printf("\n");
for(i=0;i<t;i++)
printf("P%d\t|",gant[i]);
printf("\n");
for(i=0;i<2*n;i++)
printf("-------------");
printf("\n");
printf("0\t");
for(i=1;i<t+1;i++)
printf("%d\t",i);
printf("\n");
awt=(float)twt/n;
atat=(float)ttat/n;
printf("Average waiting time is: %f\n",awt);
printf("average turn around time is: %f\n",atat);
printf("\n");
return 0;
}
