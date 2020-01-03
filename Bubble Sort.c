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



struct student ar[4];

struct student fill_student (void);
void  print_student (struct student st);
void bubble_sort(int low, int high);

 int main()

   {
     int i;
     clrscr();
     for(i=0;i<4;i++)
     {
       ar[i]=fill_student();
     }
     bubble_sort(0,3);

     for(i=0;i<4;i++)
      {
       print_student(ar[i]);
      }

    getch();
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


 void bubble_sort(int low, int high)

  {
    int size = (high - low)+1 ;
    struct student temp;
    int x , y ;

    for(x=0 ; x<size-1 ; x++)

    {
      for(y=low ; y<size-x-1 ; y++)

       {

	 if(strcmp(ar[y].name,ar[y+1].name)>0)

	  {
	    temp = ar[y];
	    ar[y] = ar[y+1];
	    ar[y+1] = temp;

	  }

       }

    }

  }





