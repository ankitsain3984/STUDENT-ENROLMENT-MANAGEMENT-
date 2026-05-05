#include<stdio.h>
struct student
{
	long int id;
	char name[15];
	char fname[15];
	char mname[15];
	int age;
	char gender[15];
	char contact[30];
	char address[30];
};

//ADD :-
void addstudent(FILE *fptr , struct student *stu)
{
	fprintf(fptr,"%ld\t %s\t %s\t %s\t %d\t %s\t %s\t %s\n",stu->id,stu->name,stu->fname,stu->mname,stu->age,stu->gender,stu->contact,stu->address);
}


//DISPLAY :-

void displayallstudent(FILE *file)
{
	struct student stu;
	printf("\n\t============>Student Details<============\n");
	printf("================================================================================\n");
	printf("ID \tName \tFNAME \tMNAME \tAGE \tGENDER \tCONTACT \tADDRESS\n");
	printf("================================================================================\n");
	while(!feof(file))
	{
		fscanf(file,"\t%ld \t%s \t%s \t%s \t%d \t%s \t%s \t%s\n",&stu.id,stu.name,stu.fname,stu.mname,&stu.age,stu.gender,stu.contact,stu.address);
		printf("%ld",stu.id);
		printf("\t%s",stu.name);
		printf("\t%s",stu.fname);
		printf("\t%s",stu.mname);
		printf("\t%d",stu.age);
		printf("\t%s",stu.gender);
		printf("\t%s",stu.contact);
		printf("\t%s\n",stu.address);
	}

}
//ID GENRATE :-
int getLastID(FILE *file)
{
	struct student stu;
	int getid=1;

	while(fscanf(file,"\t%ld \t%s \t%s \t%s \t%d \t%s \t%s \t%s\n",&stu.id,stu.name,stu.fname,stu.mname,&stu.age,stu.gender,stu.contact,stu.address)!=EOF)
	{
		getid=stu.id;
	}
	return getid;
}

//SEARCH :-

void searchstudent(FILE *file,char *sname , long int sid)
{
	struct student stu;
	int flag=0;
	printf("\n\t============>Student Details<============\n");
	printf("================================================================================\n");
	printf("ID \tName \tFNAME \tMNAME \tAGE \tGENDER \tCONTACT \tADDRESS\n");
	printf("================================================================================\n");
	while(fscanf(file,"\t%ld \t%s \t%s \t%s \t%d \t%s \t%s \t%s\n",&stu.id,stu.name,stu.fname,stu.mname,&stu.age,stu.gender,stu.contact,stu.address)!=EOF)
	{
		if(strcmpi(stu.name,sname)==0)
		{
			printf("%ld",stu.id);
			printf("\t%s",stu.name);
			printf("\t%s",stu.fname);
			printf("\t%s",stu.mname);
			printf("\t%d",stu.age);
			printf("\t%s",stu.gender);
			printf("\t%s",stu.contact);
			printf("\t%s\n",stu.address);
			flag=1;
		}
		else if(stu.id==sid)
		{
			printf("%ld",stu.id);
			printf("\t%s",stu.name);
			printf("\t%s",stu.fname);
			printf("\t%s",stu.mname);
			printf("\t%d",stu.age);
			printf("\t%s",stu.gender);
			printf("\t%s",stu.contact);
			printf("\t%s\n",stu.address);
			flag=1;
		}
	}
	if(flag==0)
	{
			printf("Record not Exist!!!!!!!!");
	}


}

// EDIT:-

/*void editstudent(FILE *fptr)
{
	struct student stu;
	FILE *newfp;
	int key;
	char newname[30];
	char newfname[30];
	char newmname[30];
	int newage;
	char newgender[30];
	char newcontact[30];
	char newaddress[30];
	int flag=0;
	newfp=fopen("temp.txt","a");
	printf("Enter Student Nwe Name to Update\n");
	scanf("%s",newname);
	fflush(stdin);
	printf("Enter Student Nwe F Name to Update\n");
	scanf("%s",newfname);
	fflush(stdin);
	printf("Enter Student Nwe M Name to Update\n");
	scanf("%s",newmname);
	fflush(stdin);
	printf("Enter Student Nwe Age to Update\n");
	scanf("%d",newage);
	fflush(stdin);
	printf("Enter Student Nwe Gender to Update\n");
	scanf("%s",newgender);
	fflush(stdin);
	printf("Enter Student Nwe contact to Update\n");
	scanf("%s",newcontact);
	fflush(stdin);
	printf("Enter Student Nwe Address to Update\n");
	scanf("%s",newaddress);
	fflush(stdin);
	printf("ID \tName \tFNAME \tMNAME \tAGE \tGENDER \tCONTACT \tADDRESS\n");

} */

