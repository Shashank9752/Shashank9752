#include<stdio.h>
#include<stdlib.h>
  void create();
  void display();
  void instbeg();
struct node{
int info;
struct node *link;
};
struct node *start=NULL;
int main()
 {
   create();
    instbeg();
   display();
   
 // instend();  
   return 0;
}
 void create()
{
struct node *tmp,*ptr;
int item;
char ch='y';
while(ch=='Y'||ch=='y')
  {
      tmp=(struct node*)malloc(sizeof(struct node));
     if(tmp==NULL)
     {
     printf("Memory overflow");
     exit(0);
    }
     printf("Enter info");
     scanf("%d",&item);
    tmp->info=item;
    tmp->link=NULL;
    if(start==NULL)
    start=tmp;
    else
    {
       ptr=start;
         
       while(ptr->link!=NULL)
           ptr=ptr->link;

       ptr->link=tmp;
    }
   printf("Do u want to add more nodes");
    scanf(" %c",&ch);
  }
}
 
  void display()
   {
        struct node *ptr;
       if(start==NULL)
      {
       printf("List is empty");
        exit(0);
       }
      else
     {
        ptr=start;
       while(ptr!=NULL)
       {
         printf(" \t %d",ptr->info);
           ptr=ptr->link;
        }
     }
  }
 void instbeg()
{
  struct node *tmp;
 int item;
 tmp=(struct node*)malloc(sizeof(struct node*));

 printf("Enter item value=");
  scanf("%d",&item);
  if(start==NULL)
 { 
   start=tmp;
  tmp->info=item;
  tmp->link=NULL;
  start=tmp;
 }
 else
 {
    tmp->info=item;
    tmp->link=start;
   start=tmp;}
}
  //void instend ();

