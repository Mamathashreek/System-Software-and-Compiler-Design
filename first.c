//9. Write a C program to compute FIRST of all Non Terminals of a given grammar.
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int n,m=0,p,i=0,j=0;
char a[10][10],f[10];
void first(char c); //function

 int main()
    {
     int i,z;
     char c,ch;
	printf("Enter the no of prooductions:\n");
	scanf("%d",&n);
	printf("Enter the productions:\n");
	for(i=0;i<n;i++)
	scanf("%s%c",a[i],&ch);
	do
	 {
		m=0;
		printf("Enter the elemets whose fisrt is to be found:");
		scanf("%c",&c);
		first(c); //function call
		printf("First(%c)={",c);
		for(i=0;i<m;i++)
		printf("%c",f[i]);
		printf("}\n");
		strcpy(f," ");
		printf("Continue(0/1)?\n");
		scanf("%d%c",&z,&ch);
	}
	while(z==1);
	return(0)
     }
    void first(char c) //function to find FIRST(NON-TERMINAL) 
     {
	int k;
	if(!isupper(c)) //for NON TERMINAL
	f[m++]=c;
	for(k=0;k<n;k++)
	{
	if(a[k][0]==c)
	{
 	if(islower(a[k][2])) //for terminal
	f[m++]=a[k][2];
	else first(a[k][2]);
	}
     }
   }
