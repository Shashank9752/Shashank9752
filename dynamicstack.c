#include<stdio.h>
#include<stdlib.h>

struct node {
  int info;
 struct node *link;
}*TOP=NULL;
void push();
void pop();
void traverse();
 int main()
{
  
   
      int choice,item;
      while(1)
    {   
    printf("\n MENU");
     printf("\n1. PUSH");
     printf("\n 2.POP");
     printf("\n 3.TRAVERSE");  
     printf("\n 4.EXIT");
     printf("\nEnter u r choice=");
       scanf("%d",&choice);
         switch(choice)
        {
           case 1:push();
         break;
           case 2:
              pop();
            break;
           case 3:
           traverse();
           break;
          case 4:
           exit(0);
          }
     }
  }
 void push()
  {
     struct node *new;
     int item;
  new=(struct node*)malloc(sizeof(struct node));
   if(new==NULL)
   {
     printf("Overflow");
      exit(0);
   }
 printf("Enter the item=");
 scanf("%d",&item);
  new->info=item;
  new->link=TOP;
   TOP=new;
 }
void pop()
 {
   struct node *tmp;
    int item;
if(TOP==NULL)
  {
   printf("Underflow");
    exit(0);
   }
    tmp=TOP;
     TOP=TOP->link;
     printf("Deleted item is %d",tmp->info);
    free(tmp);
   }
  void traverse()
 {
   struct node *ptr;
   if(TOP==NULL)
  {
     printf("Stack is empty");
   exit(0);
  }
  ptr=TOP;
  while(ptr!=NULL)
  {
   printf("%d",ptr->info);
  ptr=ptr->link;
  }
}
