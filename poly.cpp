#include<iostream>
using namespace std;

class poly
{
	private:
		double coefficient;
		double variable;
		double power;
		//double expression;
	public:
		poly(double, double, double);
		~poly();
		void updateCoefficient(double coeff);
		void updateVariable(double var);
		void updatePower(double pow);
		double value();
		double value(double var);		
};
poly::poly(double var = 0.0, double pow = 0.0, double coeff = 0.0)
{
	variable = var;
	power = pow;
	if (coeff == 0.0)
	{
		coefficient = 1.0;
	}
	else
	{
		coefficient = coeff; 
	}
}

poly::~poly()
{
	variable = 0;
	power = 0;
	coefficient = 0;
}

void poly:: updateCoefficient(double coeff)
{
	coefficient = coeff;
}

void poly::updateVariable(double var)
{
	variable = var;
}

void poly::updatePower(double pow)
{
	power = pow;
} 

double poly::value()
{
	double val = 1;
	for(int i = 1; i <= power; i++)
	{
		val *= variable;
	}
	return coefficient * val;
}

double poly::value(double var)
{
	variable = var;
	double val = 1;
	for(int i = 1; i <= power; i++)
	{
		val *= variable;
	}
	return coefficient * val;
}

int main()
{
	poly p(2,3,3.0/2);
	cout<<p.value(3)<<endl;
	
	return 0;
}
