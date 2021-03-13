#include<iostream>

/***
constructer:- 
		- special member function of class.
		- name of constructer is similar to class name.
		- automatic initialization is carried out when an object of Class is created
*/

/***
destructed:-
		- special member function of class.
		- 
*/

using namespace std;
class Rectangle
{
	int length, breadth;
	public:
			Rectangle();// It is a default constructor
			Rectangle(int,int);//It is a parameterized constructer
			int area();
			int perimeter();
			int getlength();
			void setlength(int);
			~Rectangle();//It is a destructor
};
// :: is used to asses the class function member from the outside
Rectangle::Rectangle() // It is a default constructor
{
	length, breadth = 0;
}
Rectangle::Rectangle(int l, int b)//It is a parameterized constructer
{
	length = l;
	breadth = b;
}
int Rectangle::area()
{
	return length*breadth;
}
int Rectangle::perimeter()
{
	return 2*(length + breadth);
}
int Rectangle::getlength()
{
	return length;
}
void Rectangle::setlength(int l)
{
	length = l;
}
Rectangle::~Rectangle()
{
}
int main()
{
	Rectangle r1;
	Rectangle r(10,5);
	cout<<r.area()<<endl;
	cout<<r.perimeter()<<endl;
	r.setlength(20);
	cout<<r.getlength()<<endl;
	return 0;
}
