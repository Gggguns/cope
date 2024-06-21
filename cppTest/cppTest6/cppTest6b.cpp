#include<iostream>
using namespace std;
class Piont{
public:
	friend ostream& operator<<(ostream& out,Piont& p); 
	//有参构造
	Piont(double x=0,double y=0):_x(x),_y(y){}
	//重载大于运算
	bool operator>(Piont& p){
		return (_x*_x+_y*_y)>(p._x*p._x+p._y*p._y);
	}
	//重载加法
	Piont operator+(Piont& p){
		Piont Res(_x+p._x,_y+p._y);
		return Res;
	}
	//前缀自增
	Piont& operator++(){
		_x++;
		_y++;
		return *this;
	}
private:
	double _x;
	double _y;
};
ostream& operator<<(ostream&out,Piont& p){
	out<<p._x<<','<<p._y<<endl;
	return out;
}
int main(){
	Piont p1(1,2),p2(2,2);
	cout<<"p1: "<<p1<<"p2: "<<p2;
	if(p1>p2)cout<<"p1大\n";
	else cout<<"p2大\n";
	cout<<"p1自增\n";
	++p1;
	cout<<"p1: "<<p1;
	system("pause");
	return 0;
}