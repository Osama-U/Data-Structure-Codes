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



struct student ar[10];
int ind;



struct student fill_student (void);
void  print_student (struct student st);
int add ( struct student y);
struct student retrieve (void);

  int main()

    {
     int z;
     char key;
     struct student get;
     clrscr();
     printf("\n1.Add");
     printf("\n2.Retrieve");
     printf("\n3.Exit\n");

     do
       {

	   key=getch();


	   switch(key)
	    {
	      case 49 : get = fill_student();
			z=add(get);
			if(z==1)
			{
			 printf("\nAdd Success");
			}
			else
			{
			 printf("\nAdd Fail");
			}
			break;

	      case 50 : get=retrieve();
			print_student(get);
                        break;


	      case 51 : key = 27;
			break;

	    }

	 }while(key!=27);


     return 0;
    }




  struct student fill_student (void)

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
 int add ( struct student y)

	 {
	   int retval=0;
	   if(ind<10)

	    {
	      ar[ind]=y;

	      ind++;

	      retval=1;
	    }

	   return retval;

	 }

 struct student retrieve(void)

	{
	   struct student temp;
	   int i;
	   temp = ar[0];

	   for(i=0 ; i<ind ; i++)
	    {
	      ar[i]=ar[i+1];
	    }
	    ind--;
	    return temp;

	}


