#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


struct student
{
  int id;
  char name[20];
  int grades[3];
};

 struct student fill_student (void);
 void  print_student (struct student st);


  int main()

    {

       struct student* stu;
       int x,c ;
       clrscr();
       printf("Enter Number Of Students:");
       scanf("%d",&c);
       stu = (struct student*)malloc (sizeof(struct student)* c);
       for(x=0;x<c;x++)
	{
	   stu[x]=fill_student();

	}
       for(x=0;x<c;x++)
	{
	   print_student(stu[x]);
	}

      getch();
      return 0 ;


    }


    struct student fill_student ()

    {
      int i;
      struct student s;
      printf("\n");
      printf("\nEnter Student Name:");
      scanf("%s",s.name);
      printf("\nEnter Student ID:");
      scanf("%d",&s.id);

      for(i=0;i<3;i++)
      {
	printf("\nEnter Student grade %d:",i+1);
	scanf("%d",&s.grades[i]);

      }

      return  s;

    }

  void  print_student (struct student st)

    {
      int i;
      printf("\n");
      printf("\nStudent Name: %s",st.name);
      printf("\nStudent ID: %d" , st.id);

      for(i=0;i<3;i++)
       {
	printf("\nStudent Grade %d: %d  " ,i+1 , st.grades[i]);

       }

    }




