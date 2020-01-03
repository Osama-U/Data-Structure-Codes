#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
 int data;
 struct node *pleft;
 struct node *pright;
};
struct node* create_node(int d);
struct node* insert_node(struct node *p , int d);
void pre_order(struct node *ptr);
void post_order(struct node *ptr);
void in_order(struct node *ptr);

  int main()

   {
    struct node *proot=NULL;
    clrscr();
    proot = insert_node(proot , 20);
    insert_node(proot , 15);
    insert_node(proot ,25);
    insert_node(proot ,14);
    insert_node(proot , 18);
    insert_node(proot , 23);
    insert_node(proot , 17);
    insert_node(proot , 19);
    pre_order(proot);
    printf("\n");
    post_order(proot);
    printf("\n");
    in_order(proot);



    getch();
    return 0;
   }

struct node* create_node(int d)

  {
    struct node * ptr;
    ptr = (struct node *) malloc(sizeof (struct node));
    if(ptr)
     {
	ptr ->data = d;
	ptr -> pleft = ptr -> pright = NULL;
     }

     return ptr;

  }


struct node* insert_node(struct node *p , int d)

  {
    if(!p)
     {
       p= create_node(d);
     }

    else if (d < p ->data)
     {
       p -> pleft=insert_node(p -> pleft,d);
     }

    else
     {
      p ->pright=insert_node(p -> pright,d);
     }

    return p;

  }

void pre_order(struct node *ptr)

  {
    if(ptr==NULL)
    {
     return;
    }

    printf("%d ",ptr -> data);

    pre_order(ptr ->pleft);

    pre_order(ptr ->pright);
  }

void post_order(struct node *ptr)

 {
    if(ptr==NULL)
     {
      return;
     }

    post_order(ptr ->pleft);

    post_order(ptr ->pright);

    printf("%d " , ptr ->data);

 }


void in_order(struct node *ptr)

 {
    if(ptr==NULL)
     {
      return;
     }

     in_order(ptr ->pleft);

     printf("%d " , ptr ->data);

     in_order(ptr ->pright);

 }