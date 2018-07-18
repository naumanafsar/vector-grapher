#include<iostream>
using namespace std;

class func
{
	public:
		long double tangent(double valx, double pow);
		long double cosine(double valx, double pow);
		long double sine(double valx, double pow);
		long double cosecent(double valx, double pow);
		long double secent(double valx, double pow);
		long double cotangent(double valx, double pow);
		long double result(double num, double denum);
		long double value(double var, double pow);
		long double factorial(int x);
		long double power(long double num1, int powr);
};


////////////////////////////////////////////////////////////////////////////


long double func:: cosine(double valx, double pow)
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
    return 30*ans;
}





/////////////////////////////////////////////////////////////////////////





long double func::sine(double valx, double pow)
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
    return 30*ans;
}



/////////////////////////////////////////////////////////////////////////



long double func::tangent(double valx, double pow)
{
  return sine(valx,pow)/cosine(valx,pow);

}



//////////////////////////////////////////////////////////////////////////


long double func::cotangent(double valx, double pow)
{
	return 1/tangent(valx,pow);
}







////////////////////////////////////////////////////////////////////////


long double func::cosecent(double valx, double pow)
{
	return 1/sine(valx,pow);
}



/////////////////////////////////////////////////////////////////////////



long double func::secent(double valx, double pow)
{
	return 1/cosine(valx,pow);
}

/////////////////////////////////////////////////////////////////////////




long double func::value(double var, double pow)
{
	int power = pow;
	int val = 1;
	for(int i = 1; i <= power; i++)
	{
		val *= var;
	}
	return 0.1*val;
}




/////////////////////////////////////////////////////////////////////////




long double func::result(double num, double denum)
{
	return num/denum;
} 





/////////////////////////////////////////////////////////////////////////





long double func:: power(long double num1, int powr)
{
  long double ans = 1;
  for (int i = 0; i < powr; i++)
  {
    ans *= num1;
  }
  return ans;
}




/////////////////////////////////////////////////////////////////////////



long double func:: factorial(int x)
{
  long double ans = 1;
  for (size_t i = 1; i <= x; i++)
  {
    ans = ans*i;
  }
  return ans;
}

