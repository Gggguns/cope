#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
void main()
{
	char  name[10];
	int  age;
	cout << "please  input  your  name:";
	cin >> name;
	cout << "How  old  are  you:";
	cin >> age;
	cout << "name  is  " << name << endl;
	cout << "age  is  " << age << endl;
}

//#include<iostream>
//using namespace std;
//class Circle
//{
//    double radius;
//public:
//    void Set_Radius(double r)
//    {
//        radius = r;
//    }
//    double Get_Radius()
//    {
//        return  radius;
//    }
//    double Get_Girth()
//    {
//        return  2 * 3.14f * radius;
//    }
//    double Get_Area()
//    {
//        return  3.14f * radius * radius;
//    }
//};
//int main()
//{
//    Circle A, B;
//    A.Set_Radius(6.23);
//    cout << "A.Radius = " << A.Get_Radius() << endl;
//    cout << "A.Girth = " << A.Get_Girth() << endl;
//    cout << "A.Area = " << A.Get_Area() << endl;
//    B.Set_Radius(10.5);
//    cout << "B.radius = " << B.Get_Radius() << endl;
//    cout << "B.Girth=" << B.Get_Girth() << endl;
//    cout << "B.Area = " << B.Get_Area() << endl;
//}

//#include <iostream>
//using namespace std;
//void main(void)
//{
//    cout << "Hello!\n";
//    cout << "Welcome to C++!\n";
//}
