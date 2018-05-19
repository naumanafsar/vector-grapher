#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<regex>
#include"linklist.cpp"
using namespace std;
	


/////////////////////////////////////////////////////////////////////////

class point
{
	private:
		linklist l;
	public:
		void generateLinkList(string str);
		long double getFinalValue(double start, double end);
		void show();
		string string_to_subString(string str, int start );
		int string_to_int(string str);
		string int_to_string(int num);
		double angle(string str, int start);
};

/////////////////////////////////////////////////////////////////////////


void point:: generateLinkList(string str)
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
				l.addInTheEnd(&func::sine);
				l.updateAngle(angle(newStr,3));
			} 
			else if(regex_search(newStr ,reg2))
			{
				l.addInTheEnd(&func::cosine);
				l.updateAngle(angle(newStr,3));
			} 
			else if(regex_search(newStr ,reg3))
			{
				l.addInTheEnd(&func::tangent);
				l.updateAngle(angle(newStr,3));
			}
	
			else if(regex_search(newStr, reg5))
			{
				l.addInTheEnd(&func::value);
				l.updatePower(angle(newStr,2));
			}
	
			else if(regex_match(newStr, reg4))
			{
				double numerator = string_to_int(newStr);
				double denumerator = string_to_int(string_to_subString(newStr,((int_to_string(string_to_int(newStr))).length())+1));
				if(denumerator == 0)
					cout<<"Enter a valid "<<endl;
				else
					l.addInTheEnd(&func::result);
					l.updateFraction(numerator,denumerator);
			
			}
		}
		filex.close();
		l.updateChange();
	}
	infile.close();
}



/////////////////////////////////////////////////////////////////////////




long double point::getFinalValue(double start, double end = 0)
{
	return l.get(start,end);
}



/////////////////////////////////////////////////////////////////////////


void point::show()
{
	l.display();
}




/////////////////////////////////////////////////////////////////////////

string point:: string_to_subString(string str, int start )
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


int point:: string_to_int(string str)
{
	stringstream geek(str);
	int num;
	geek >> num;
	return num;
}



/////////////////////////////////////////////////////////////////////////




string point:: int_to_string(int num)
{
	stringstream ss;
	ss << num;
	string s = ss.str();
	return s;
}




/////////////////////////////////////////////////////////////////////////




double point:: angle(string str, int start)
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




//double string_to_decimal(string str)

int main()
{
	point x;
	point y;
	point z;
	x.generateLinkList("sin(t)");
	y.generateLinkList("cos(t)");
	z.generateLinkList("x^1");
	//f.show();
	cout<<x.getFinalValue(2)<<endl;
	cout<<y.getFinalValue(2)<<endl;
	cout<<z.getFinalValue(2)<<endl;
	return 0;
}
