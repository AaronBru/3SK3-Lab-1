#include <stdio.h>
#include <stdlib.h>

//absolute returns the absolute value of the input
double absolute(double x)
{
  if (x<0)
  {
    x=-x;
  }
  return x;
}

//fac returns the factorial of an integer
double fac(int x)
{
   double y = 1;

   while (x>0)
   {
       y = y*x--;
   }

   return y;
}

//returns b^ex
double pow(double b, int ex)
{
    double out = 1;
    for (int i = 0;i<ex;i++)
    {
        out = b*out;
    }

    return out;
}

//using the Taylor expansion of e^x it returns e^x approximated
//by a Taylor polynomial of order n
double exp(double x, int n)
{
    double y = 0;

    for (int i = 0; i <=n; i++)
    {
        y = y + pow(x,i)/fac(i);
    }

    return y;
}

//returns the nth term of the Taylor series expansion of cos
double termcos(double x, int n)
{
    n--;

    double y = pow(-1,n)*pow(x,2*n)/fac(2*n);

    return y;
}

//returns cos(x) evaluated until adding another term would not affect
//the machine's value
double cos(double x)
{
    int i = 1;
    double accum = termcos(x,i);

    while (absolute(termcos(x,i+1))+absolute(accum) > absolute(accum))
    {
        accum = accum + termcos(x,i+1);
        i++;
    }

    return accum;
}

//returns machine precision of a double
double epsilon()
{
    double mach = 1;

    while ((1+mach/2) > 1)
    {
        mach = mach/2;
    }

    return mach;
}

//returns the min value that can be represented by a double
double xmin()
{
    double min = 1;

    while (min/2 > 0)
    {
        min = min/2;
    }

    return min;
}

int main()
{
    double pi = 3.141592653589793;

    double expA = exp(-8.3,25);
    double expB = 1/exp(8.3,25);

    double cosPiBy3 = cos(pi/3);
    double cosPiBy4 = cos(pi/4);

    double mach = epsilon();
    double min = xmin();

    printf("e^(-8.3) = %le\n",expA);
    printf("1/e^(8.3) = %le\n\n",expB);
    printf("cos(pi/3) = %le\n", cosPiBy3);
    printf("cos(pi/4) = %le\n\n", cosPiBy4);
    printf("Machine Precision = %le\n",mach);
    printf("xmin = %le",min);
}
