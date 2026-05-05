#include<stdio.h>
#include<conio.h>
#include<string.h>
#include"heading.c"
#include"menu.c"
#include "password.c"
void menu();
void main()
{
   int mainopt,b=0;
   clrscr();
   while(1)
   {
	clrscr();
	heading();
	printf("\n\t1. Login\n\t2. Exit");
	printf("\n\t==============================================================\n");
	printf("\n\tEnter your choice : ");
	scanf("%d",&mainopt);
	if(mainopt==1)
		b=password();
	if(mainopt==2)
		exit(0);
	if(b==1)
	menu();
   }

}
