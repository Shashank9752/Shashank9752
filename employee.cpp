#include<iostream>
 using namespace std;
  class employee
   {
      int empno;
     char name[20];
     float salary;
      public:
   //   int empno;
      void readdata();
      void dispdata();
      void heading();
   };
 void employee::readdata()
  {
    cout<<"Enter employee number,name and salary";
     cin>>empno;
      
     cin<<name;
     cin>>salary;
     cout<<endl;
   }
 void employee::heading()
{
  cout.width(10);
  cout.setf(ios::left,ios::adjustfield);
  cout<<"empno";
  cout.width(20);
  cout<<"name";
  cout.width(10);
  cout<<"salary";
  cout<<endl;
  }
  void employee::dispdata()
{
  cout.width(10);
  cout<<empno;
  cout.width(20);
  cout<<name;
  cout.width(10);
  cout<<salary;
  cout<<endl;
 }
 int main()
{
   employee e[5];
  for(int i=0;i<=2;i++)
    e[i].readdata();
   e[0].heading();
   for( int i=0;i<=2;i++)
     e[i].dispdata();
  //cout<<e[0].empno;
return 0;
}  
      
