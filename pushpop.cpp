#include<iostream>
#define MAX 5
#include<bits/stdc++.h>
using namespace std;
 struct stack
 {
  int a[MAX];
  int top;
 };
void push(stack *pu,int item)
 {
  if(pu->top==MAX-1)
   {
    cout<<"Overflow";
    return;
   }
  pu->a[pu->top+1]=item;
  pu->top=pu->top+1;
 }
 void pop( stack *po)
 {
  int item;
  if(po->top==-1)
  {
   cout<<"Underflow";
   return ;
  }
  item=po->a[po->top];
  po->top=po->top-1;
  cout<<"Deleted item is="<<item;
 }
 void display( stack dp)
 {
  if(dp.top==-1)
  {
   cout<<"underflow";
   return ;
  }
 for(int i=dp.top;i<=0;i--)
  cout<<"\n"<<dp.a[i];
 } 
 int main()
 {
    stack s;
   int item,ch;
   s.top=-1;
  while(1)
  {
   cout<<"Stack operation \n";
   cout<<"1.PUSH\n";
   cout<<"2.POP\n";
   cout<<"3.DISPLAY\n";
   cout<<"4.EXIT\n";
   cout<<"Enter your choice=";
   cin>>ch;
    switch(ch)
    {
      case 1:
      cout<<"Enter the item to be inserted=";
      cin>>item;
      push(&s,item);
      break;
      case 2:
      pop(&s);
      break;
      case 3:
      display(s);
      break;
      case 4:
      exit(0);
      default:
      cout<<"Enter a valid chioce";
    }
   }
  }
 
