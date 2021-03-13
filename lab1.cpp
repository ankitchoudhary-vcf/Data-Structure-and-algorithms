#include<iostream>

using namespace std;
class Rectangle
{
	private: //by defaule also they are private
			int length, breadth;
	public:
		void input(int l, int b)
		{
			length = l;
			breadth = b;
		}
		int area()
		{
			return length*breadth;
		}
		int alter(int l)
		{
			return length = l;
		}
};
int main()
{
	Rectangle r;
	r.input(10, 5);
	cout<<r.area()<<endl;
	cout<<r.alter(30);
	return 0;
}
