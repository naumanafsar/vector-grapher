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
		void makingPointsFile(point &x, point &y, point &z, double start, double end);
		void generate(point &x, point &y, point &z, string a, string b, string c );
		string string_to_subString(string str, int start );
		int string_to_int(string str);
		string int_to_string(int num);
		double angle(string str, int start);
};

/////////////////////////////////////////////////////////////////////////




void point:: generateLinkList(string str)
{
	regex regSin ("sin");
	regex regCos ("cos");
	regex regTan ("tan");
	regex regCotan("cotan");
	regex regCosecent("cosec");
	regex regSecent("sec");
	regex regNum ("([0-9]+)");
	regex regFract ("([0-9]+)[/]([0-9]+)");
	regex regPoly ("([t])[^]");
	fstream outfile;
	outfile.open("plus.txt", ios::out);
	outfile<<str;
	outfile.close();
	fstream infile;
	infile.open("plus.txt", ios::in);
	while(!infile.eof())
	{
		string str1 = "";
		getline(infile,str1,'+');
		fstream outoutfile;
		outoutfile.open("multiply.txt",ios::out);
		outoutfile<<str1;
		outoutfile.close();
		fstream ininfile;
		ininfile.open("multiply.txt",ios::in);
		while(!ininfile.eof())
		{
			string newStr = "";
			getline(ininfile,newStr,'*');
			if(regex_search(newStr ,regSin))
			{
				l.addInTheEnd(&func::sine);
				l.updateAngle(angle(newStr,3));
			}
			else if(regex_search(newStr ,regCos))
			{
				l.addInTheEnd(&func::cosine);
				l.updateAngle(angle(newStr,3));
			}
			else if(regex_search(newStr ,regTan))
			{
				l.addInTheEnd(&func::tangent);
				l.updateAngle(angle(newStr,3));
			}
			else if(regex_search(newStr ,regCotan))
			{
				l.addInTheEnd(&func::cotangent);
				l.updateAngle(angle(newStr,3));
			}
			
			else if(regex_search(newStr ,regCosecent))
			{
				l.addInTheEnd(&func::cosecent);
				l.updateAngle(angle(newStr,3));
			}
			
			else if(regex_search(newStr ,regSecent))
			{
				l.addInTheEnd(&func::secent);
				l.updateAngle(angle(newStr,3));
			}
			
			else if(regex_search(newStr, regPoly))
			{
				l.addInTheEnd(&func::value);
				l.updatePower(angle(newStr,2));
			}
			else if(regex_match(newStr,regNum))
			{
				double num = string_to_int(newStr);
				double denum = 1;
				l.addInTheEnd(&func::result);
				l.updateFraction(num,denum);
				
			}
			else if(regex_match(newStr, regFract))
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
		ininfile.close();
		l.updateChange();
	}
	infile.close();
}



/////////////////////////////////////////////////////////////////////////




long double point::getFinalValue(double start, double end = 0)
{
	return l.get(start,end);
}








void point::generate(point &x, point &y, point &z, string a, string b, string c )
{
	x.generateLinkList(a);
	y.generateLinkList(b);
	z.generateLinkList(c);
	return;
}

void point::makingPointsFile(point &x, point &y, point &z, double start, double end)
{
	fstream outfile;
	outfile.open("file.txt",ios::out);
	//long double Z = -50;
	for(double i = start; i < end; i += 0.1)
	{
		long double X = x.getFinalValue(i);
		long double Y = y.getFinalValue(i);
		long double Z = z.getFinalValue(i);
		outfile<<X<<" ";
		outfile<<Y<<" ";
		outfile<<Z<<" ";

	}
	return;
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



///////////////////////////////////////////////////////////////////////////


/*
long double point::string_to_float(string str)
{
	int  num = string_to_int(str);
	int point = string_to_subString(str,int_to_string(num).length+1);

}

*/


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

/*

int main()
{
	point x;
	point y;
	point z;
	point p;
	p.generate(x,y,z,"sin(t)","cos(t)","t^1");
	p.makingPointsFile(x,y,z,0,50);
	return 0;
}
*/
