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
int binary_search_by_id( int beg , int end , int id);
int binary_search_by_name( int beg , int end , char l[20]);
void merge_sort (int low , int high);
void merge(int low , int mid , int high);
void bubble_sort(int low, int high);

 int main()
   {
     int i,po,num,key;
     char n[20]={0};
     clrscr();
     for(i=0;i<4;i++)
     {
       ar[i]=fill_student();
     }

    // clrscr();
     printf("\n1.Search by ID");
     printf("\n2.Search by Name\n");
     do
     {
       key = getch();

       switch(key)
       {
	case 49 : printf("\nPlease Enter Student ID:");
		  scanf("%d" ,&num);
		  po=binary_search_by_id(0,3,num);
		  printf("\nLocation of ID:%d" , po+1);
		  break;
	case 50 :
		  printf("\nPlease Enter Student Name:");
		  scanf("%s" ,n);
		  po=binary_search_by_name(0,3,n);
		  printf("\nLocation of ID:%d" , po+1);
		  break;
       }




     } while(key!=27);

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

  int binary_search_by_id ( int beg , int end , int id)

    {
      int loc =-1;
      int lower = beg;
      int upper = end;
      int middle;
	merge_sort(beg , end );
      if (lower <= upper)

	{
	  middle=( lower + upper ) /2;

	   if(ar[middle].id == id)

	    {
	      loc = middle;
	    }

	   else if(ar[middle].id>id)

	    {
	      loc = binary_search_by_id ( beg , middle -1 , id);

	    }

	   else

	    {
	      loc = binary_search_by_id( middle + 1 , end ,id);

	    }

	 }


       return loc;

    }

     int binary_search_by_name ( int beg , int end , char l[])

    {
      int loc =-1;
      int lower = beg;
      int upper = end;
      int middle;
	bubble_sort(beg , end );
      if (lower <= upper)

	{
	  middle=( lower + upper ) /2;

	   if(strcmp(ar[middle].name,l)==0)

	    {
	      loc = middle;
	    }

	   else if(strcmp(ar[middle].name,l)<0)

	    {
	      loc = binary_search_by_name ( beg , middle -1 ,l);

	    }

	   else

	    {
	      loc = binary_search_by_name ( middle + 1 , end ,l);

	    }

	 }


       return loc;

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





