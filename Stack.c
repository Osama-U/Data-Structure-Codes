#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct student
{
  int id;
  char name[20];
  int grades[3];
};


struct stack
{
  struct student data;
  struct stack *pprev;

};

struct stack * ptail;


struct student fill_student ();
void  print_student (struct student st);
int push (struct student x);
struct student pop(void);

  int main()

    {
     int z;
     char key;
     struct student get;
     clrscr();
     printf("\n1.Push");
     printf("\n2.Pop");
     printf("\n3.Exit\n");

     do
       {

	   key=getch();


	   switch(key)
	    {
	      case 49 : get = fill_student();
			z=push(get);
			if(z==1)
			{
			 printf("\nPush Success");
			}
			else
			{
			 printf("\nPush Fail");
			}
			break;

	      case 50 : get=pop();
			print_student(get);
			break;


	      case 51 : key = 27;
			break;

	    }

	 }while(key!=27);

     return 0;
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



  int push (struct student x)

   {

      int retval=0;
      struct stack *ptr ;

      ptr = (struct stack*)malloc(sizeof (struct stack));

      if (ptr)

       {

	 ptr -> data = x;
	 ptr ->pprev = NULL;

	 if (ptail == NULL ) //no list

	   {
	     ptail = ptr ;

	    }

	 else
	   {
	    ptr -> pprev = ptail;
	    ptail = ptr ;

	   }

	   retval=1;

	}

	return retval;


    }


    struct student pop(void)

    {
       struct stack* ptr;
       struct student backup;
       ptr = ptail ;

       if(ptr) //there is a list

	{

	  ptail = ptr -> pprev;
	  backup=ptr->data;
	  free(ptr);
	}
       else
	 {
	   ptr -> data.id=-1;
	  backup=ptr->data;

	 }


	  return backup;


    }


