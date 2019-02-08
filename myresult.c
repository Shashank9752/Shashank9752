#include<stdio.h>
  int main()
{
  float eng,math,hnd,EVS,total,per;
  char result,div; 
  printf("\n\n\t ********RESULT*********");
  printf("\n\n\t Enter the marks of English=");
  scanf("%f",&eng);
  printf("\n\n\t Enter the marks of Maths=");
  scanf("%f",&math);
  printf("\n\n\t Enter the marks of Hindi=");
  scanf("%f",&hnd);
  printf("\n\n\t Enter the marks of EVS=");
  scanf("%f",&EVS);
  total=eng+math+hnd+EVS;
  if(eng>=33 && math>=33 && hnd>=33 && EVS>=33)
    {
        result = 'P';
    }
  else 
    {
       result = 'F';
    }
   
    if (result == 'P')
      {
        per=total/4;
      }
     else 
       {
         per=0;
       }
         if(per !=0 )
          {   
               if(per>=60)
                  {
                     div='1';
                   }
                else if (per>=50) 
                   {
                      div='2';
                   }
                 else if (per>=33)
                   {
                      div='3';
                    }
           
                  else 
                    {
                       div='F';

                     }
        }
     else
        {
           div='F';
        }

  printf("\n\n\t Total marks obtained in all subject=%f",total);
  printf("\n\n\t Result (Pass or Fail) = %c",result);
  printf("\n\n\t Percentage obtaind = %f",per);
  printf("\n\n\t Division = %c",div);
   return 0;
} 

 
                  
