#include<iostream>
#include<string>
#include"trignometric.h"
using namespace std;

long double trignomeric::power(long double num1, int powr)
{
  long double ans = 1;
  for (int i = 0; i < powr; i++)
  {
    ans *= num1;
  }
  std::cout << num1 << " to the power " << powr << " is " <<ans << '\n';
  return ans;
}
long double trignomeric::factorial(int x)
{
  long double ans = 1;
  for (size_t i = 1; i <= x; i++)
  {
    ans = ans*i;
  }
  std::cout << "factorial is " << ans << '\n';
  return ans;
}

long double trignomeric::sin(double valx)
{
  double sign = 1;
  while (valx > 360)
  {
    valx -= 360;
  }
  long double x = valx*3.14159265358979323846/180;
  long double qoutient;
  long double denomenator;
  long double ans = 0;
  for(int n = 0; n <= 60; n++)
  {
      qoutient = power(-1,n)*power(x,2*n+1);
      denomenator = factorial((2*n)+1);
      ans += qoutient/denomenator;
    }
    if (ans < 0000.1 && ans > -0000.1)
    {
      ans = 0;
    }
    return ans;
}
long double trignomeric::cos(double valx)
{
  double sign = 1;
  while (valx > 360)
  {
    valx -= 360;
  }
  long double x = valx*3.14159265358979323846/180;
  long double qoutient;
  long double denomenator;
  long double ans = 0;
  for(int n = 0; n <= 60; n++)
    {
      qoutient = power(-1,n)*power(x,2*n);
      denomenator = factorial(2*n);
      ans += qoutient/denomenator;
    }
    if (ans < 0000.1 && ans > -0000.1)
    {
      ans = 0;
    }
    return ans;
}
long double trignomeric::tan(double valx)
{
  return sin(valx)/cos(valx);

}
