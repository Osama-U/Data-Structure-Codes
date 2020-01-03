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


struct Node
{
  struct student data;
  struct Node *pprev;
  struct Node *pnext;

};

struct Node * phead;
struct Node * ptail;


 struct student fill_student (void);
 void  print_student (struct student st);
 struct Node * create_node(struct student d);
 int add_node(struct student data);
 int insert_node(struct student data3,int loc);
 struct student search_by_id(int id);
 struct student search_by_name(char n[]);
 int delete_node(int loc);
 void free_list(void);
 void print_list(void);



  int main()

    {
      char key,n[20]={0};
      int test,id,loc ,l;
      struct student t,b;
      clrscr();




      printf("\n1.add node");
      printf("\n2.insert");
      printf("\n3.search by name");
      printf("\n4.search by id");
      printf("\n5.delete node");
      printf("\n6.free list");
      printf("\n7.print list");
      printf("\n8.exit");
      printf("\n");


      do
	{
	   key=getch();


	   switch(key)
	    {
	      case 49 :
		       t=fill_student();
		       test=add_node(t);
		       if(test==1)
		       {
			 printf("\nNode Added");
		       }
		       break;

	      case 50 :
		       printf("\nEnter Node Location:");
		       scanf("%d",loc);
		       t=fill_student();
		       test=insert_node(t,loc);
		       if(test==1)
		       {
			 printf("\nNode Inserted");
		       }
		       break;

	      case 51 :
			 printf("\n");
			 printf("\nEnter Student Name:");
			 scanf("%s",n);
			 t= search_by_name(n);
			 if(t.id==-1)
			  {
			    printf("\nSearch result=0");
			  }
			 else
			  {
			    print_student(t);
			  }
			 break;

	      case 52 :
			 printf("\n");
			 printf("\nEnter Student ID:");
			 scanf("%d",&id);
			 t= search_by_id(id);
			 if(t.id==-1)
			  {
			    printf("\nSearch result=0");
			  }
			 else
			  {
			    print_student(t);
			  }
			 break;

	      case 53 :
			 printf("\n");
			 printf("\nEnter Node Location:");
			 scanf("%d",loc);
			 test=delete_node(l);
			 if(test==1)
			  {
			    printf("\nNode Deleted");
			  }
			 else
			  {
			     printf("\nWrong Location");
			  }
			 break;

	      case 54 :
			 printf("\n");
			 free_list();
			 printf("\nList is free:");
			 break;

	      case 55 :
			 printf("\n");
			 print_list();
			 break;
	      case 56 :
			 key=27;


	    }



	}while(key!=27);





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


  struct Node * create_node(struct student d)

    {

      struct Node *ptr;
      ptr = (struct Node*)malloc(sizeof (struct Node));

      if(ptr)

       {
	 ptr -> data =d;
	 ptr -> pnext = NULL;
	 ptr -> pprev = NULL;
       }

       return ptr;

    }

  int add_node(struct student data)


   {
      int retval;
      struct Node * ptr;
      ptr = create_node(data);
      if (ptr)
	{
	  if (!phead)

	    {

	      phead = ptail = ptr ;

	    }

	  else


	    {
	      ptail -> pnext=ptr;
	      ptr -> pprev =ptail;
	      ptail = ptr;

	    }

	     retval=1;

	}

	 return retval;


  }


  int insert_node(struct student data3,int loc)

  {

     int retval = 0 , i;
     struct Node *ptr, *temp;

     ptr = create_node(data3);

     if (ptr)

	{
	   if(!phead)// there is no list

	     {
	       phead = ptail = ptr;
	     }

	   else // there is list

	    {
	      if (loc==0) //frist

		{
		  phead -> pprev = ptr ;
		  ptr ->pnext =phead;
		  phead = ptr;
		}

	      else//middle or last

		{
		  temp = phead;

		  for(i=0 ; i < loc && temp ; i++)

		    {
		      temp = temp -> pnext;
		    }


		   if(temp==NULL || temp == ptail)//last node

		    {
		      ptail -> pnext = ptr;
		      ptr -> pprev = ptail;
		      ptail = ptr;
		    }

		   else//middle

		    {
		      (temp -> pnext) -> pprev = ptr;
		      ptr -> pnext = temp -> pnext;
		      ptr -> pprev = temp;
		      temp -> pnext = ptr;

		    }

		}

	    }

	     retval=1;
	}

	    return retval;

  }


  struct student search_by_id(int id)

  {
     struct Node* ptr;

     ptr = phead;
     while (ptr && ptr ->data.id!=id)
       {
	 ptr = ptr -> pnext;

       }
       if (!ptr)
	{
	  ptr -> data.id=-1;
	}

       return ptr -> data;

   }

    struct student search_by_name(char n[])

  {
     struct Node* ptr;

     ptr = phead;
     while (ptr && strcmp(n,ptr->data.name)!=0)
       {
	 ptr = ptr -> pnext;

       }
       if (!ptr)
	{
	  ptr -> data.id=-1;
	}

       return ptr -> data;

   }

   int delete_node(int loc)

   {
     int retval=0 ,i;
     struct Node* ptr ,*temp;
     if(phead)
       {

	   if(loc==0)

	     {
	       ptr = phead;

	       if(phead==ptail) //1 Node

		 {
		   ptr = phead = NULL;
		 }

	       else // Frist Node of List

		 {
		   phead=phead->pnext;
		   phead->pprev=NULL;
		 }

		 free(ptr);
		 retval=1;

	     }

	   else //Middle or Last

	     {
	       temp=phead;

	       for(i=0 ; i < loc && temp ; i++)

		 {
		   temp = temp ->pnext;

		 }


		if(temp) // there is node to be deleted

		 {

		   if ( temp == ptail) //last node

		     {
		       ptail = ptail ->pprev;
		       ptail -> pnext =NULL;

		     }

		   else //in the middle

		     {
		       (temp -> pprev) -> pnext = temp -> pnext;
		       (temp -> pnext) -> pprev =temp ->pprev;

		     }

		   free(temp);
		   retval=1;

	       }

	     }
       }

	return retval ;
   }

   void free_list(void)

   {
     struct Node *temp;

     while(phead)

      {
	temp=phead;
	phead=phead->pnext;
	free(temp);

      }
   }

   void print_list(void)

     {
       struct Node *temp;
       temp=phead;

       while(temp)

	 {
	    print_student(temp->data);
	    temp = temp->pnext;

	 }

      }
