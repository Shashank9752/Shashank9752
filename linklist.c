#include<stdio.h>
#include<stdlib.h>
  void create();
  void display();
  void instbeg();
  void instend();
  void instloc();
  void delbeg();
  void delend();
  void delloc();
 struct node{
int info;
struct node *link;
};
struct node *start=NULL;
int main()
 {
  int choice;
   while(1)
  {
    printf("\n MENU\n");
    printf("1. Insert at the beginning of node\n");
    printf("2. Insert at the end of node\n");
    printf("3. Insert after the given location of the node\n");
    printf("4. Delete from the beginning\n");
    printf("5. Delete from the end\n");
    printf("6. Delete form the given position \n");
    printf("Enter your choice=");
    scanf("%d",&choice);
    printf("\n");
    switch(choice)
    {
     case 1:
     create();
     instbeg();
     display();
     break;
     case 2:
     create();
     instend();
     display();
     break;
     case 3:
     create();
     instloc();
     display();
     break;   
     case 4:
     create();
     delbeg();
     display();
     break;
     case 5:
     create();
     delend();
     display();
     break;
     case 6:
     create();
     delloc();
     display();
     break;
     default :
     printf("Enter any valid number");
    }
  }   
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
     printf("Enter info=");
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
  if(tmp==NULL)
  {
   printf("Overflow");
   return ;
  }
  printf("Enter the item value to be inserted=");
  scanf("%d",&item);
  tmp->info=item;
  tmp->link=start;
  start=tmp;
 }
  void instend ()
{
  struct node *temp,*ptr;
  int item;
  temp=(struct node*)malloc(sizeof(struct node*));
  if(temp==NULL)
  { 
   printf("Overflow");
   return ;
  }
  printf("Enter the item to be inserted at the end=");
  scanf("%d",&item);
  temp->info=item;
  temp->link=NULL;
  if(start==NULL)
  start=temp;
  else
  {
   ptr=start;
   while(ptr->link!=NULL)
   ptr=ptr->link;
   
   ptr->link=temp;
  }
}
 void instloc()
{
  struct node *temp,*ptr;
  int pos,item,i;
  temp=(struct node*)malloc(sizeof(struct node*));
  if(temp==NULL)
  {
    printf("Overflow");
    return ;
  }
  printf("Enter the item to be inserted=");
  scanf("%d",&item);
  printf("Enter the pos of item after which u want to insert=");
  scanf("%d",&pos);
  temp->info=item;
  ptr=start;
  for(i=1;i<pos;i++)
  {
    if(ptr==NULL)
    {
     printf("Enter any valid position");
     return;
    }
  ptr=ptr->link;
  }
  temp->link=ptr->link;
  ptr->link=temp;
 
}
 void delbeg()
{
  struct node *tmp;
  if(start==NULL)
  {
   printf("List is empty");
   return ;
  }
 
   tmp=start;
   start=start->link;
   printf("Deleted item is=%d\n",tmp->info);
  free(tmp);
}
  void delend()
{
  struct node *tmp,*ptr,*prev;
  if(start==NULL)
  {
   printf("List is empty");
   return ;
  }  
  if(start->link==NULL)
  {
    tmp=start;
    start=NULL;//pura dabba ....tmp ko de dena h  
  }
  else
  {
   prev=start;
   ptr=start->link;
   while(ptr->link!=NULL)
   {
    prev=ptr;
    ptr=ptr->link;
   }
   tmp=ptr; 
   prev->link=NULL;
   free(tmp);
  }
}
void delloc()
{
  struct node *tmp,*locp,*loc;
  int pos,i;
  if(start==NULL)
 {
  printf("List is empty");
  return ;
 }
 printf("Enter the position after which u want to delete the node=");
 scanf("%d",&pos);
 if(pos<1)
 {
  printf("Enter any valid position");
  return ;
 }
else
{
 locp=start;
 loc=locp->link;
 for(i=1;i<pos;i++)
 {
  locp=loc;
  loc=loc->link;
  if(locp->link==NULL)
  {
   printf("Enter invalid position");
   return ;
  }
 }
}
  tmp=loc;
  locp->link=tmp->link;
  printf("Deleted node is =%d\n",tmp->info);
  free(tmp);
 }
