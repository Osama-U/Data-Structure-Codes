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
void merge(int low , int mid , int high);
void merge_sort (int low , int high);



 int main()

   {
     int i;
     clrscr();
     for(i=0;i<4;i++)
     {
       ar[i]=fill_student();
     }
     merge_sort(0,3);

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

  void merge_sort (int low , int high)

    {
      int middle;
      middle = (low + high)/2 ;

      if(low<high)

       {
	 merge_sort(low , middle);
	 merge_sort(middle+1 , high);
	 merge(low , middle , high);
       }

    }

  void merge(int low , int mid , int high)

    {
      struct student temp[4];
      int loc=low;
      int list1 = low;
      int list2 = (mid+1);
      int i;

      while (list1 <= mid && list2 <= high)

	{
	  if(ar[list1].id<ar[list2].id)
	    {
	      temp[loc] = ar[list1];
	      loc++;
	      list1++;
	    }

	  else
	    {
	      temp[loc] = ar[list2];
	      loc++;
	      list2++;
	    }

	}

       while (list1<=mid)

	   {
	     temp[loc] = ar[list1];
	     loc++;
	     list1++;
	   }

       while (list2 <= high)

	  {
	     temp[loc] = ar[list2];
	     loc++;
	     list2++;

	  }

	for(i=low ; i<=high ; i++)

	  {
	    ar[i] = temp[i];
	  }

    }



