#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node{
  int info;
  node *link;
 };
 node *start=NULL;
 void instbeg(node *np,int item)
 {
  node *newnode=new node;
  newnode->info=item;
  if(start==NULL)
  start=newnode;
  else
  newnode->link=start;
  start=newnode;
  cout<<"Insertion succesfull";
 }
 void instmid(node *np,int item)
 { 
  int pos;
  node *newnode=new node;
  cout<<"Enter the pos after which the item should be inserted=";
  cin>>pos;
  if(start==NULL)
  {
   cout<<"There is no node present in the linklist";
   return;
  }
 else if(start->link==NULL)
  {
    cout<<"Only single node is present";
    return;
  }
  
  newnode->info=item;
  node *ptr=start;
  for(int i=1;i<pos;i++)
  ptr=ptr->link;
  node *tmp=ptr->link;
  ptr->link=newnode;
  newnode->link=tmp;
  cout<<"Insertion successfull";
  }
 void instlast(node *np,int item)
 {
  node *newnode=new node;
  newnode->info=item;
  if(start==NULL)
  {
   start=newnode;
   return;
  }
  newnode->link=NULL;
  node *ptr=start;
  while(ptr->link!=NULL)
  ptr=ptr->link;
  ptr->link=newnode;
 cout<<"Insertion successfull";
 }  
 void delbeg(node *np)
 {
  if(start==NULL)
  {
   cout<<"list is empty";
   return;
  }
  node *ptr=start;
  start=start->link;
  delete ptr;
 cout<<"Deletion successfull";
 }
 void delend(node *np)
 {
  node *tmp,*ptr;
  if(start==NULL)
  {
   cout<<"List is empty";
   return ;
  }
  else if(start->link==NULL)
  {
   tmp=start;
   start=NULL;
  }
  else
  {
   ptr=start;
   tmp=ptr->link;
   while(tmp->link!=NULL)
   {
    ptr=ptr->link;
    tmp=ptr->link;
   }
   ptr->link=NULL;
  } 
 delete tmp;
 cout<<"Deletion successfull";
 }
 void delmid(node *np)
 {
  int pos;
  node *tmp,*ptr;
  cout<<"Enter the position of node=";
  cin>>pos;
  if(start==NULL)
  {
   cout<<"List is empty";
   return;
  }
  else if(start->link==NULL)
  {
   cout<<"Only single node is present";
   return;
  }
  else
  { 
   ptr=start;
   tmp=ptr->link;
  for(int i=1;i<pos;i++)
  {
   ptr=ptr->link;
   tmp=ptr->link;
  }
  ptr->link=tmp->link;
  }
  delete tmp;
  cout<<"Deletion successfull";
 }
 void display(node n)
 {
  if(start==NULL)
  {
   cout<<"List is empty";
   return;
  }
  node *ptr;
  ptr=start;
  while(ptr)
  {
   cout<<ptr->info;
   ptr=ptr->link;
  }
 }
 int main()
 {
 node n,pos;
 int ch,item;
 
 while(1)
 {
  cout<<"\n1-Insert beg\n";
  cout<<"2-Insert mid\n";
  cout<<"3-Insert end\n";
  cout<<"4-Display\n";
  cout<<"5-Del beg\n";
  cout<<"6-Del end\n";
  cout<<"7-Del mid\n";
  cout<<"8-Exit\n";
  cout<<"Enter your choice=";
  cin>>ch;
   switch(ch)
   {
     case 1:
     cout<<"Enter the item to be inserted=";
     cin>>item;
     instbeg(&n,item);
     break;
     case 2:
     cout<<"Enter the item to be inserted=";
     cin>>item;
     instmid(&n,item);
     break;
     case 3:
     cout<<"Enter the item to be inserted=";
     cin>>item;
     instlast(&n,item);
     break;
     case 4:
     display(n);
     break;
     case 5:
     delbeg(&n);
     break;
     case 6:
     delend(&n);
     break;
     case 7:
     delmid(&n);
     break;
     case 8:
     exit(0);
   }
  }
  return 0;
 }
    
