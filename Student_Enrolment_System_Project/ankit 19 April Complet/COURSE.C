#include<stdio.h>
struct course
{
	long int id;
	char name[50];
	long int fees;
	int duration;
};
//ADD :-

void  addcourse(FILE *fptr , struct course cor)
{
	fprintf(fptr, "%ld\t%s\t%ld\t%d\n",cor.id,cor.name,cor.fees,cor.duration);
}

//DISPLAY :-

void displayallcourse(FILE *file , struct course cor)
{
	printf("\n\t============>Course Details<============\n");
	printf("\t==============================================================\n");
	printf("\n\tID\tNAME\tFEES\tDURATION(Year)\n");
	printf("\t==============================================================\n");
	while(fscanf(file,"%ld%s%ld%d",&cor.id,cor.name,&cor.fees,&cor.duration)!=EOF)
	{
		printf("\t%ld\t%s\t%ld\t%d\n",cor.id,cor.name,cor.fees,cor.duration);
	}
}

//ID GENRATE :-

int getLastcID(FILE *file)
{
	struct course cor;
	int getid;
	while(fscanf(file,"%d\t%s\t%ld\t%d\n",&cor.id,cor.name,&cor.fees,&cor.duration)!=EOF)
	{
		getid=cor.id;
	}
	return getid;

}

//SEARCH :-

void searchcourse(FILE *file,char *cname , long int cid)
{
	struct course cor;
	int flag=0;
	printf("\n\t============>Course Details<============\n");
	printf("\t==============================================================\n");
	printf("\n\tID\tNAME\tFEES\tDURATION(Year)\n");
	printf("\t==============================================================\n");
	while(fscanf(file,"\t%ld\t%s\t%ld\t%d\n",&cor.id,cor.name,&cor.fees,&cor.duration)!=EOF)
	{
		if(strcmpi(cor.name,cname)==0)
		{
			printf("\t%ld\t%s\t%ld\t%d\n",cor.id,cor.name,cor.fees,cor.duration);
			flag=1;
		}
		else if(cor.id==cid)
		{
			printf("\t%ld\t%s\t%ld\t%d\n",cor.id,cor.name,cor.fees,cor.duration);
			flag=1;
		}
	}
	if(flag==0)
	{
		printf("Record not Exist!!!!!!!!");
	}
}

// EDIT:-

/*void editcourse(FILE *fptr)
{
	struct course cor;
	FILE *newfp;
	char newname[50];
	long int newfees;
	int newduration;
	int flag=0;
	newfp=fopen("temp.txt","a");
	printf("\tEnter Course Nwe Name to Update : ");
	scanf("%s",newname);
	fflush(stdin);
	printf("\tEnter Course Nwe Fees to Update : ");
	scanf("%ld",newfees);
	fflush(stdin);
	printf("\tEnter Course Nwe Duration to Update : ");
	scanf("%d",newduration);
	fflush(stdin);
	printf("\n\tID\tNAME\tFEES\tDURATION(Year)\n");
	printf("%s\t%ld\t%d\n",newname,newfees,newduration);
	while(fscanf(fptr,"\t%ld\t%s\t%ld\t%d\n",&cor.id,cor.name,&cor.fees,&cor.duration)!=EOF)
	{
		if(newname==cor.name)
		{
			printf("\nFound\n");
			fprintf(newfp,"\t%ld\t%s\t%ld\t%d\n",cor.id,newname,&cor.fees,&cor.duration);
			flag=1;
		}
		else
		{
			fprintf(newfp,"\t%ld\t%s\t%ld\t%d\n",&cor.id,cor.name,&cor.fees,&cor.duration);
		}
	}
	remove("course.txt");
	fclose(newfp);
	rename("temp.txt","course.txt");
} */