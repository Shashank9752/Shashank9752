#include<iostream>
 using namespace std;
  class tim
  {
   
     int hr;
     int min;
     public:
     void readdata();
     void dispdata();
     void sumtime(tim,tim);
   };
   void tim::sumtime(tim a,tim b)
   {
     min=a.min+b.min;
     hr=a.hr+b.hr+(min/60);
     min=min%60;
    } 
   void tim::readdata()
   {
    cout<<"Enter hour and min=";
    cin>>hr>>min;
    }
    void tim::dispdata()
    {
     cout<<"Hour="<<hr;
     cout<<"Minute="<<min;
     
     }
   
     
  int main()
  {
   tim t1,t2,t3;
   t1.readdata();
   t2.readdata();
   t1.dispdata();
   t2.dispdata();
   t3.sumtime(t1,t2);
   t3.dispdata();
   return 0;
   }
