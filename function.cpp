#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<regex>
#include"poly.cpp"
//#include"trignometric.cpp"
using namespace std;

string string_to_subString(string str, int start );
double string_to_int(string str);
string reverseString(string s);
string int_to_string(int num);
long double tangent(double valx);
long double cosine(double valx);
long double sine(double valx);
long double factorial(int x);
long double power(long double num1, int powr);

//use match regex
void fun(string str)
{
	double var = 2;
	long double finalValue = 0;
	long double multiply = 1;
	long double sinValue = 0;
	long double cosValue = 0;
	long double tanValue = 0;
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
			cout<<newStr<<endl;
			if(regex_search(newStr ,reg1))
			{
				int i = 3;
				string strnum = "";
				while(newStr[i] != '(')
				{
					strnum = newStr[i];
					i++;
					
				}
				double num = 1; 
				num = string_to_int(strnum);
				//trignometric t;
				sinValue = sine(var);
				cout<<"sinvalue : "<<sinValue<<endl;
				multiply *= sinValue;
			} 
			else if(regex_search(newStr ,reg2))
			{
				int i = 3;
				string strnum = "";
				while(newStr[i] != '(')
				{
					strnum = newStr[i];
					i++;
					
				}
				double num = 1;
				num = string_to_int(strnum);
				//trignometric t;
				cosValue = cosine(var);
				cout<<"cosValue = "<<cosValue<<endl;
				multiply *= cosValue;
			} 
			else if(regex_search(newStr ,reg3))
			{
				int i = 3;
				string strNum = "";
				while(newStr[i] != '(')
				{
					strNum = newStr[i];
					i++;
					
				}
				double num = 1;
				num = string_to_int(strNum);
				//trignometric t;
				tanValue = tangent(var);
				cout<<"tanValue = "<<tanValue<<endl;
				multiply *= tanValue; 
			}
			
			else if(regex_search(newStr, reg5))
			{
				int count = 0;
				if(regex_match(newStr,reg6))
				{
					count += 1;
				}
				int i = 2;
				string strNum = "";
				while(newStr[i] != '\0')
				{
					strNum += newStr[i];
					i++;
				}
				double num = string_to_int(strNum);
				double pow = num;
				if(count == 1)
				{
					//22/100
					double denum = string_to_int(string_to_subString(strNum,((int_to_string(string_to_int(strNum))).length())+1));
					pow = num / denum;
				}
				poly p(var,pow);
				multiply *= p.value(var);	
			}
			
			else if(regex_match(newStr, reg4))
			{
				double numerator = string_to_int(newStr);
				double denumerator = string_to_int(string_to_subString(newStr,((int_to_string(string_to_int(newStr))).length())+1));
				if(denumerator == 0)
					cout<<"Enter a valid "<<endl;
				else
					cout<<"div"<<numerator / denumerator<<endl;
					multiply *= numerator / denumerator;
					
			}
		}
		cout<<multiply<<endl;
		finalValue += multiply;
		cout<<"in : "<<finalValue<<endl;
		multiply = 1;
	}
	cout<<"final = "<<finalValue<<endl;
	infile.close();
}


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


double string_to_int(string str)
{
	stringstream geek(str);
	double num;
	geek >> num;
	return num;
}

string int_to_string(int num)
{
	stringstream ss;
	ss << num;
	string s = ss.str();
	return s;
}

string reverseString(string s)
{
	string rs = "";
	int len = s.length();
	for(int i = len - 1; i >= 0; i--)
	{
		rs += s[i];
		 
	}
	return rs;
}

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

long double cosine(double valx)
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
long double sine(double valx)
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
long double tangent(double valx)
{
  return sine(valx)/cosine(valx);

}




//double string_to_decimal(string str)

int main()
{
	fun("3/2+5/2*x^2+sin(t)*cos(t)+tan(t)");
	return 0;
}
