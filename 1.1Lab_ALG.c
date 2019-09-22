#include <stdio.h>
#include <math.h>

double a = 1000000;
double b = 0.00001;
int main()
{
//  printf("%.10e\n",a);
//  printf("%.10lf\n", b);
//  printf("%.10e\n",1);
//  printf("% lf\n", 1);
  //scanf("%f",&a );
  //scanf("%f",&b);
  double  result_1;//result_1 Значення чисельника
  double  result_2;//result_2 Значення знаменника
//  double  result_3;//result_3 Значення виразу
  double final; //Значення для типу double
  float z;//Значення виразу для типу float

  result_1 =(pow(a+b,4)-(pow(a,4)+4*pow(a,3)*b));
  result_2 =(6*pow(a,2)*pow(b,2)+4*a*pow(b,3)+pow(b,4));
  final = (result_1/result_2);
  z = (result_1/result_2);

  printf("result_chis \n");
  printf("%.10lf\n", result_1);
  printf("result_znam \n");
  printf("%.10lf\n", result_2);
  printf("result_dlya_double \n");
  printf("%.10lf\n", final);//вивід даних для типу double
  printf("result_dlya_float \n");
  printf("%.10lf\n", z);//вивід даних для типу float

  return 0;
}
