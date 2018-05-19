#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<regex>
#include"linklist.cpp"
using namespace std;

string string_to_subString(string str, int start );
int string_to_int(string str);
string int_to_string(int num);
long double factorial(int x);
long double power(long double num1, int powr);
double angle(string str, int start);
long double tangent(double valx, double pow);
long double cosine(double valx, double pow);
long double sine(double valx, double pow);
long double result(double num, double denum);
long double value(double var, double pow);


/////////////////////////////////////////////////////////////////////////

class point
{
	private:
		linklist l;
	public:
		void fun(string str);
		long double getFinal(double start, double end);
		void show();
};

/////////////////////////////////////////////////////////////////////////


void point:: fun(string str)
{
	double var = 2;
	long double finalValue = 0;
	regex reg1 ("sin");
	regex reg2 ("cos");
	regex reg3 ("tan");
	regex reg4 ("([0-9]+)[/]([0-9]+)");
	regex reg5 ("([a-z])[^]");
	regex reg6 ("([a-z])[^]([0-9]+)[/]([0-9]+)");
	string newStr = "";
	fstream outfile;
	outfile.open("file.txt", ios::out);
	outfile<<str;
	outfile.close();
	fstream infile;
	infile.open("file.txt", ios::in);
	while(!infile.eof())
	{
		string str1;
		getline(infile,str1,'+');
		fstream file;
		file.open("x.txt",ios::out);
		file<<str1;
		file.close();
		fstream filex;
		filex.open("x.txt",ios::in);
		while(!filex.eof())
		{
			getline(filex,newStr,'*');
			if(regex_search(newStr ,reg1))
			{
				l.addInTheEnd(&sine);
				l.updateAngle(angle(newStr,3));
			} 
			else if(regex_search(newStr ,reg2))
			{
				l.addInTheEnd(&cosine);
				l.updateAngle(angle(newStr,3));
			} 
			else if(regex_search(newStr ,reg3))
			{
				l.addInTheEnd(&tangent);
				l.updateAngle(angle(newStr,3));
			}
	
			else if(regex_search(newStr, reg5))
			{
				l.addInTheEnd(&value);
				l.updatePower(angle(newStr,2));
			}
	
			else if(regex_match(newStr, reg4))
			{
				double numerator = string_to_int(newStr);
				double denumerator = string_to_int(string_to_subString(newStr,((int_to_string(string_to_int(newStr))).length())+1));
				if(denumerator == 0)
					cout<<"Enter a valid "<<endl;
				else
					l.addInTheEnd(&result);
					l.updateFraction(numerator,denumerator);
			
			}
		}
		filex.close();
		l.updateChange();
	}
	infile.close();
}



/////////////////////////////////////////////////////////////////////////




long double point::getFinal(double start, double end)
{
	return l.get(start,end);
}



/////////////////////////////////////////////////////////////////////////


void point::show()
{
	l.display();
}




/////////////////////////////////////////////////////////////////////////

string string_to_subString(string str, int start )
{
	string newstr = "";
	while(str[start] != '\0')
	{
		newstr += str[start];
		start++;
	}
	return newstr;
}

/////////////////////////////////////////////////////////////////////////


int string_to_int(string str)
{
	stringstream geek(str);
	int num;
	geek >> num;
	return num;
}



/////////////////////////////////////////////////////////////////////////




string int_to_string(int num)
{
	stringstream ss;
	ss << num;
	string s = ss.str();
	return s;
}




/////////////////////////////////////////////////////////////////////////




double angle(string str, int start)
{
	int count = 0;
	int i = start;
	string strNum = "";
	while(str[i] != '(' && str[i] !='\0')
	{
		if(str[i] == '/')
		{
			count += 1;
		}
		strNum += str[i];
		i++;
		
	}
	double pow = 1;
	if(strNum.size() > 0)
	{
		double num = string_to_int(strNum);
		pow = num;
		if(count == 1)
		{
			double denum = string_to_int(string_to_subString(strNum,((int_to_string(string_to_int(strNum))).length())+1));
			pow = num / denum;
		}
	}
	return pow;
}





/////////////////////////////////////////////////////////////////////////





long double power(long double num1, int powr)
{
  long double ans = 1;
  for (int i = 0; i < powr; i++)
  {
    ans *= num1;
  }
  //std::cout << num1 << " to the power " << powr << " is " <<ans << '\n';
  return ans;
}




/////////////////////////////////////////////////////////////////////////



long double factorial(int x)
{
  long double ans = 1;
  for (size_t i = 1; i <= x; i++)
  {
    ans = ans*i;
  }
  //std::cout << "factorial is " << ans << '\n';
  return ans;
}




/////////////////////////////////////////////////////////////////////////




long double cosine(double valx, double pow)
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
    // if (ans < 0000.1 && ans > -0000.1)
    // {
    //   ans = 0;
    // }
    return ans;
}





/////////////////////////////////////////////////////////////////////////





long double sine(double valx, double pow)
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
    // if (ans < 0000000.1 && ans > -00000000.1)
    // {
    //   ans = 0;
    // }
    return ans;
}



/////////////////////////////////////////////////////////////////////////



long double tangent(double valx, double pow)
{
  return sine(valx,pow)/cosine(valx,pow);

}




/////////////////////////////////////////////////////////////////////////




long double value(double var, double pow)
{
	int power = pow;
	int val = 1;
	for(int i = 1; i <= power; i++)
	{
		val *= var;
	}
	return  val;
}




/////////////////////////////////////////////////////////////////////////




long double result(double num, double denum)
{
	return num/denum;
} 




/////////////////////////////////////////////////////////////////////


//double string_to_decimal(string str)

int main()
{
	point f;
	f.fun("x^3+cos(t)*tan2(t)+3/2");
	f.show();
	cout<<f.getFinal(2,3)<<endl;
	return 0;
}
