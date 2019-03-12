#define MAX 5
int TOP=-1;
#include<stdio.h>
#include<stdlib.h>
void push(int[], int);
void pop(int[]);
void traverse(int []);
 int main()
{
   while (1)
   {
      int choice,item;
      int stack[MAX];
     printf("\n MENU");
     printf("\n1. PUSH");
     printf("\n 2.POP");
     printf("\n 3.TRAVERSE");  
     printf("\n 4.EXIT");
     printf("\nEnter u r choice=");
       scanf("%d",&choice);
         switch(choice)
        {
           case 1:
           printf("\n enter item value=");
             scanf("%d",&item);
             push(stack,item);
         break;
           case 2:
              pop(stack);
            
            break;
           case 3:
           traverse(stack);
           break;
          case 4:
           exit(0);
          }
     }
  }
 void push(int stack[],int item)
  {
        if(TOP==MAX)
       {
         printf("stack is full");
           return ;
       }
    TOP=TOP+1;
    stack[TOP]=item;
 }
void pop(int stack[])
 {
    int item;
   if (TOP==-1)
  {
    printf("stack is empty");
    return ;
  }
  item =stack[TOP];
   TOP=TOP-1;
   printf("Delete item =%d",item);
   }
  void traverse(int stack[])
 {
   int i;
  if (TOP==-1)
 {
   printf("stack is empty");
   return ;
  }
  i=TOP;
  while (i>=0)
 {
   printf("%d",stack[i]);
   i--;
  }
}
