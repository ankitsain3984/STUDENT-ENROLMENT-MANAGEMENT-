#include<stdio.h>
struct enrol
{
	long int id;
	char sid[40];
	char coid[40];
	long int fees;
};

//ADD

void addenrol(FILE *fptr , struct enrol *en)
{
	fprintf(fptr,"%ld\t %s\t %s\t %ld\n",en->id,en->sid,en->coid,en->fees);
}


//ID GENRATE :-
int getLastEnrollID(FILE *file)
{
	struct enrol en;
	int getid=1001;
	while(fscanf(file,"\t%ld \t%s \t%s \t%ld\n",&en.id,en.sid,en.coid,&en.fees)!=EOF)
	{
		//getid=en.id;
		getid++;
	}
	return getid;
}

//Display
void displayallenrol(FILE *file)
{
	struct enrol en;
	printf("\n\t============>Enrol Details<============\n");
	printf("\t==============================================================\n");
	printf("\n\tID\tSNAME\tCNAME\tFEES\n");
	printf("\t==============================================================\n");
	while(fscanf(file,"%ld%s%s%ld",&en.id,en.sid,en.coid,&en.fees)!=EOF)
	{
		printf("\t%ld\t%s\t%s\t%ld\n",en.id,en.sid,en.coid,en.fees);
		//printf("%ld",cor.fees);
	}
}
//search:-
long int searchcoursetofee(FILE *file, char *cname, struct course cor)
{
	//fptr=fopen("course.txt","r");
	if(file!=NULL)
	{
	      while(fscanf(file,"%ld%s%ld%d",&cor.id,cor.name,&cor.fees,&cor.duration)!=EOF)
	      {
			if(cor.name == cname)
			{
				printf("%ld",cor.fees);
				//getch();
				//break;
			}
			//break;
	      }
	}
	return cor.fees;
}


