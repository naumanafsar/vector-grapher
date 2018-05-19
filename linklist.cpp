#include<iostream>
#include"func.cpp"
using namespace std;



/////////////////////////////////////////////////////////////////////

typedef long double (func::*f)(double,double);


/////////////////////////////////////////////////////////////////////////

struct Node
{
	f data;
	int change;
	double power;
	double num;
	double denum;
	double angle;
	Node *next;
};


/////////////////////////////////////////////////////////////////////////



class linklist
{
	protected:
		Node *head;
		Node *tail;
	public:
		linklist();
		~linklist();
		void addInTheEnd(f info);
		void addInTheStart(f info);
		void del(f info);
		void display();
		long double get(double num, double specail);
		void updateChange();
		void updatePower(double pow);
		void updateAngle(double ang);
		void updateFraction(double n, double d);
};




/////////////////////////////////////////////////////////////////////////




linklist::linklist()
{
	head = NULL;
	tail = NULL;
}




/////////////////////////////////////////////////////////////////////////




linklist::~linklist()
{
	Node *p;
	Node *q;
	q = head;
	while(q != NULL)
	{
		p = q;
		q = q->next;
		delete p;
	}
}



/////////////////////////////////////////////////////////////////////////




void linklist::addInTheStart(f info)
{
	Node *temp = new Node;
	temp->data = info;
	temp->change = 0;
	temp->power = -1;
	temp->num = -1;
	temp->denum = 0;
	temp->angle = 1;
	temp->next = NULL;
	if(head == NULL)
	{
		head = temp;
		tail = temp;
	}
	else
	{
		temp->next = head;
		head = temp;
	}
	
}


/////////////////////////////////////////////////////////////////////////




void linklist::addInTheEnd(f info)
{
	Node *temp = new Node;
	temp->data = info;
	temp->change = 0;
	temp->power = -1;
	temp->num = -1;
	temp->denum = 0;
	temp->angle = 1;
	temp->next = NULL;
	if(head == NULL)
	{
		head = temp;
		tail = temp;
	}
	else
	{
		tail->next = temp;
		tail = temp;
	}
	
}


/////////////////////////////////////////////////////////////////////////




void linklist::display()
{
	if(head==NULL)
	{
		cout<<"linklist is empty"<<endl;
	}
	else
	{
		int i = 1;
		Node *temp;
		temp = head;
		while(temp != NULL)
		{
			cout<<i<<" : "<<" change : "<<temp->change<<", power : "<<temp->power<<", num/denum : "<<temp->num<<"/"<<temp->denum<<endl;
			temp = temp->next;
			i++;
		}
	}
}


/////////////////////////////////////////////////////////////////////////



void linklist::del(f info)
{
	if(head==NULL)
	{
		cout<<"linklist is empty"<<endl;
	}
	else if(head == tail)
	{
		if(head->data == info)
		{
			delete head;
		}
		else
		{
			cout<<info<<endl;
			cout<<"There is no Node with this data"<<endl;
		}
	}
	else
	{
		Node *q;
		Node *p;
		q = head;		
		if(head->data == info)
		{
			head = head->next;
			delete q;
		}
		else
		{
			while(q != NULL)
			{
				if(q->data == info)
				{
					p->next = q->next;
					delete q;
					return;
				}
				else if(q == tail)
				{
					tail = p;
					delete q;
				}
				else
				{
					p = q;
					q = q->next;
				}
			}
		}
	}
}




/////////////////////////////////////////////////////////////////////////



long double linklist::get(double num, double specail)
{
	long double final_value = 0;
	if(head == NULL)
	{
		cout<<"Invalid Expression "<<endl;
	}
	else
	{
		Node *temp;
		temp = head;
		f function;
		func p;
		long double mul = 1;
		while(temp != NULL)
		{
			if(temp->change == 0)
			{
				if(temp->power != -1)
				{
					function = temp->data;
					mul *= (p.*function)(num,temp->power); 
				}	
				else if(temp->num != -1 && temp->denum != 0)
				{
					function = temp->data;
					mul *= (p.*function)(temp->num, temp->denum);
				}
				else
				{
					function= temp->data;
					mul *= (p.*function)(num*temp->angle,specail);
				}
			}
			if(temp->change == 1)
			{
				if(temp->power != -1)
				{
					function = temp->data;
					mul *= (p.*function)(num,temp->power);
				}	
				else if(temp->num != -1 && temp->denum != 0)
				{
					function = temp->data;
					mul *= (p.*function)(temp->num, temp->denum);
				}
				else
				{
					function= temp->data;
					mul *= (p.*function)(num*temp->angle,specail);
				}
				final_value += mul;
				mul = 1;
			}
			temp = temp->next;
		}
	}
	return final_value;
}


/////////////////////////////////////////////////////////////////////////


void linklist::updateChange()
{
	tail->change = 1;
	return;
}



/////////////////////////////////////////////////////////////////////////




void linklist:: updatePower(double pow)
{
	tail->power = pow;
}


/////////////////////////////////////////////////////////////////////////





void linklist::updateFraction(double n, double d)
{
	tail->num = n;
	tail->denum = d;
}



/////////////////////////////////////////////////////////////////////////



void linklist::updateAngle(double ang)
{
	tail->angle = ang;
}




/////////////////////////////////////////////////////////////////////////
