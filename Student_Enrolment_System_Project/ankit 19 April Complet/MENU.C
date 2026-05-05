#include"student.c"
#include"course.c"
#include"enrol.c";
void addcourse();
void menu()
{
	int opt,i=1,c=101,len,e=1001;
	int submenu,stuid,corid;
	int search,search1,edit;
	char *sname,*cname;
	long int sid,cid;
	FILE *fptr,*cptr;
	struct student *stu;
	struct course cor;
	struct enrol *en;
	while(1)
	{
		clrscr();
		heading();
		printf("\t*----Menu----*\n");
		printf("\n\t1. Student\n\t2. Course\n\t3. Enrolment\n\t4. Go to Back");
		printf("\n\t==============================================================\n");
		printf("\n\tEnter the Choice : ");
		scanf("%d",&opt);

		/*STUDENT*/

		if(opt==1)
		{
			while(1)
			{
				clrscr();
				//heading();
				//clrscr();
				printf("\t*----Submenu----*\n");
				printf("\n\t1. Add student\n\t2. View all student\n\t3. Search student\n\t4. Go to Back\n");
				printf("\t==============================================================\n");
				fflush(stdin);
				printf("\tChoice is your : ");
				scanf("%d",&submenu);
				switch(submenu)
				{
					//Add Student:-
					case 1:
					fptr=fopen("student.txt","r");
					i=getLastID(fptr);
					stu->id=i+1;
					printf("\tThis is ID : ");
					printf("%ld",stu->id);
					fclose(fptr);

					fptr=fopen("student.txt","a");
					printf("\n\tEnter the student name : ");
					scanf("%s",stu->name);
					printf("\n\tEnter the Father name : ");
					scanf("%s",stu->fname);
					printf("\n\tEnter the Mother name : ");
					scanf("%s",stu->mname);
					printf("\n\tEnter the age : ");
					scanf("%d",&stu->age);
					printf("\n\tEnter the  gender : ");
					scanf("%s",stu->gender);

					back:
					printf("\n\tEnter the  contact : ");
					scanf("%s",stu->contact);
					len=strlen(stu->contact);
					if(len==10)
					{
						printf("Number is successfull\n");
					}
					else
					{
						printf("Invalid number\n");
						getch();
						goto back;
					}
					printf("\n\tEnter the  address : ");
					scanf("%s",stu->address);
					addstudent(fptr,stu);
					printf("\n\tInserted succesfully!.....");
					fclose(fptr);
					getch();
					break;

					//Display Student:-
					case 2:
					fptr=fopen("student.txt","r");
					displayallstudent(fptr);
					getch();
					fclose(fptr);
					break;

					//Search Student:-
					case 3:
					printf("\t============>Search The student<============\n");
					printf("\t\t1. Search by NAME\n\t\t2. Search By ID\n");
					printf("\t==============================================================\n");
					printf("\t\t\tChoice is your : ");
					scanf("%d",&search);
					printf("\t==============================================================\n");
					switch(search)
					{
						case 1:
						printf("\tEnter the Student Name : ");
						scanf("%s",sname);
						fptr=fopen("student.txt","r");
						searchstudent(fptr,sname,-1);
						getch();
						fclose(fptr);
						break;

						case 2:
						printf("\tEnter the Student ID : ");
						scanf("%ld",&sid);
						fptr=fopen("student.txt","r");
						searchstudent(fptr,"",sid);
						getch();
						fclose(fptr);
						break;
					}
					//Edit Student:-
					/*case 4:
					break;*/

				}
				if(submenu==4)
				{
					break;
				}
			}
		}

		/*COURSE*/
		else if(opt==2)
		{
			while(1)
			{
				clrscr();
				//heading();
				//clrscr();
				printf("\t*----Submenu----*\n");
				printf("\n\t1. Add course\n\t2. View all course\n\t3. Search course\n\t4. Go to Back\n");
				printf("\t==============================================================\n");
				printf("\tChoice is your : ");
				scanf("%d",&submenu);
				switch(submenu)
				{
					//Add Course:-
					case 1:
					fptr=fopen("course.txt","r");
					c=getLastcID(fptr);
					cor.id=c+1;
					fclose(fptr);
					printf("\tThis is ID : ");
					printf("%ld",cor.id);

					fptr=fopen("course.txt","a");
					printf("\n\tEnter the course name : ");
					fflush(stdin);
					scanf("%s",cor.name);
					printf("\n\tEnter the course fees : ");
					scanf("%ld",&cor.fees);
					printf("\n\tEnter the duration : ");
					scanf("%d",&cor.duration);
					addcourse(fptr,cor);
					printf("\n\tInserted succesfully!.....");
					fclose(fptr);
					getch();
					break;

					//Display Course:-
					case 2:
					fptr=fopen("course.txt","r");
					displayallcourse(fptr,cor);
					getch();
					fclose(fptr);
					break;

					//Search Course:-
					case 3:
					printf("\t============>Search The course<============\n");
					printf("\t\t1. Search by NAME\n\t\t2. Search By ID\n");
					printf("\t==============================================================\n");
					printf("\t\t\tChoice is your : ");
					scanf("%d",&search1);
					printf("\n\t==============================================================\n");
					switch(search1)
					{
						case 1:
						printf("\tEnter the Course Name : ");
						scanf("%s",cname);
						fptr=fopen("course.txt","r");
						searchcourse(fptr,cname,-1);
						getch();
						fclose(fptr);
						break;

						case 2:
						printf("\tEnter the Course ID : ");
						scanf("%ld",&cid);
						fptr=fopen("course.txt","r");
						searchcourse(fptr,"",cid);
						getch();
						fclose(fptr);
						break;
					}
					//Edit Course:-
					/*case 4:
					fptr=fopen("course.txt","r");
					displayallcourse(fptr,cor);
					fclose(fptr);
					printf("\t==============================================================\n");
					printf("\tEnter the Course ID : ");
					scanf("%d",&corid);

					//fptr=fopen("course.txt","r");
					//displayallcourse(fptr,cor);
					editcourse(fptr);
					getch();
					//fclose(fptr);
					break;*/
				}
				if(submenu==4)
				{
					break;
				}
			}
		}
		/*ENROLMENT*/

		else if(opt==3)
		{
			while(1)
			{
				clrscr();
				printf("\t*----Submenu----*\n");
				printf("\n\t1. Rejester Enrolment\n\t2. View all Enrolment\n\t3. Go to Back\n");
				printf("\t==============================================================\n");
				printf("\tChoice is your : ");
				scanf("%d",&submenu);
				switch(submenu)
				{
					//Add Enrol:-
					case 1:
					clrscr();
					fptr=fopen("enrol.txt","r");
					e=getLastEnrollID(fptr);
					en->id=e;
					fclose(fptr);
					printf("\tThis is ID : ");
					printf("%ld",en->id);

					//open student list :-
					printf("\n\tStudent list is : \n");
					fptr=fopen("student.txt","r");
					displayallstudent(fptr);
					fclose(fptr);
					printf("================================================================================\n");
					printf("\tEnter the Student ID : ");
					scanf("%d",&stuid);
					clrscr();
					fptr =  fopen("student.txt","r");
					while(fscanf(fptr,"\t%ld \t%s \t%s \t%s \t%d \t%s \t%s \t%s\n",&stu->id,stu->name,stu->fname,stu->mname,&stu->age,stu->gender,stu->contact,stu->address) != EOF)
					{
						if(stu->id == stuid)
						{
							break;
						}
					}
					strcpy(en->sid,stu->name);
					fclose(fptr);
					//open course list :-
					fptr=fopen("course.txt","r");
					displayallcourse(fptr,cor);
					fclose(fptr);
					printf("\t==============================================================\n");
					printf("\tEnter the Course ID : ");
					scanf("%d",&corid);
					fptr=fopen("course.txt","r");
					while(fscanf(fptr,"%ld%s%ld%d",&cor.id,cor.name,&cor.fees,&cor.duration)!=EOF)
					{
						if(cor.id == corid)
						{

							break;
						}
					}
					strcpy(en->coid,cor.name);
					fclose(fptr);

					fptr=fopen("course.txt","r");
					en->fees = searchcoursetofee(fptr,cname,cor);
					fclose(fptr);

					fptr=fopen("enrol.txt","a");
					en->fees=cor.fees;
					addenrol(fptr,en);
					printf("\n\t->Inserted succesfully!.....");
					getch();
					fclose(fptr);
					break;

					//Display Enrol:-
					case 2:
					fptr=fopen("enrol.txt","r");
					displayallenrol(fptr);
					getch();
					fclose(fptr);
					break;

				}
				if(submenu==3)
				{
					break;
				}
			}

		}
		else if(opt==4)
		{
			break;
		}
	}

}