#include <stdio.h>
#include <stdlib.h>

double fac(int x)
{
   double y = 1;

   while (x>0)
   {
       y = y*x--;
   }

   return y;
}

double pow(double b, int ex)
{
    double out = 1;
    for (int i = 0;i<ex;i++)
    {
        out = b*out;
    }

    return out;
}

double exp(double x, int order)
{
    double y = 0;

    for (int i = 0; i <=order; i++)
    {
        y = y + pow(x,i)/fac(i);
    }

    return y;
}

double cos(double x, int order)
{
    double y = 0;
    int sign = 1

    for (int i = 0; i <=order; i = i+2)
    {
        y = y + sign*pow(x,i)/fac(i);
        sign = -sign;
    }

    return y;
}

int main()
{
    double x = exp(-8.3,26);
    printf("%le", x);
}
