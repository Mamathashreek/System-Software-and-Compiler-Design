//3. Write a C program to implement producer-consumer problem using semaphores.
#include<stdio.h>
#include<stdlib.h>
int mutex=1,full=0,empty=3,x=0;
void consumer();
int wait(int);
int signal(int);
void producer();
int main()
{
int ch;
printf("\n 1.producer\n 2.consumer\n 3.exit\n");
while(1)
{
printf("\n enter the choice :\n");
scanf("%d",&ch);
switch(ch)
{
case 1: if((mutex==1)&&(empty!=0))
producer();
else
printf("\n buffer is full\n");
break;
case 2: if((mutex==1)&&(full!=0))
consumer();
else
printf("buffer is empty \n");
break;
case 3:exit(0);
break;}
}
return 0;
}
int wait(int s)
{
return(--s);
}
int signal(int s)
{
return(++s);
}
void producer()
{
mutex=wait(mutex);
full=signal(full);
empty=wait(empty);
x++;
printf("\n producer produces the item %d",x);
mutex=signal(mutex);
}
void consumer()
{
mutex=wait(mutex);
full=wait(full);
empty=signal(empty);
x--;
printf("\n consumer consumes the item %d",x+1);
mutex=signal(mutex);
}
