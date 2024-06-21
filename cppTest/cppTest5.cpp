#include<iostream>
#include<string>
using namespace std;

class Rectangle   //矩形类
{
protected:
	int length;   //矩形的长
protected:
	int width;    //矩形的宽
public:
	Rectangle(int l = 10, int w = 10):length(l), width(w)
	{
	}
	virtual int calArea()
	{
		return length * width;
	}
};

class Cuboid : public Rectangle  //长方体类，从Rectangle公有派生
{
private:
	int height;    //长方体的高
public:
	Cuboid(int l = 10, int w = 10, int h = 10){
		length = l;
		width = w;
		height = h;
	}

	//计算长方体的表面积
	int calArea(){
		return 2*(length*height+length*width+width*height);
	}
	int calVolume()
	{
		return calArea() * height;
	}
};

//车类
class vehicle{
public:
	//带参构造
	vehicle(int MaxSpeed,int Weight):_MaxSpeed(MaxSpeed),_Weight(Weight){
		cout<<"基类构造函数被调用\n";
	}
	void Run(){
		cout<<"行驶中\n";
	}
	void Stop(){
		cout<<"停车\n";
	}
	//析构函数
	~vehicle(){
		cout<<"基类析构函数被调用"<<endl;
	}
protected:
	int _MaxSpeed;
	int _Weight;
};
//汽车
class motorcar : public vehicle{
public:
	//带参构造
	motorcar(int MaxSpeed,int Weight,int SeatNum):vehicle(MaxSpeed,Weight),_SeatNum(SeatNum){
		cout<<"子类带参构造函数被调用\n";
	}
	//析构函数
	~motorcar(){
		cout<<"子类析构函数被调用"<<endl;
	}
protected:
	int _SeatNum;
};
//人
class Person{
public:
	Person(string name,string sex):_name(name),_sex(sex){}
protected:
	string _name;
	string _sex;
};
//老师
class Teacher:virtual public Person{
public:
	Teacher(string name,string sex,string course):Person(name,sex),_course(course){}
protected:
	string _course;
};
//学生
class Student:virtual public Person{
public:
	Student(string name,string sex,string sno):Person(name,sex),_sno(sno){}
protected:
	string _sno;
};
//Master
class Master:public Teacher,public Student{
public:
	Master(string name,string sex,string course,string sno,string honor):Person(name,sex),Teacher(name,sex,course),Student(name,sex,sno),_honor(honor){}
	void Print(){
		cout<<"姓名："<<_name<<endl;
		cout<<"性别:"<<_sex<<endl;
		cout<<"教授课程:"<<_course<<endl;
		cout<<"学号:"<<_sno<<endl;
		cout<<"所获荣誉："<<_honor<<endl;
	}
protected:
	string _honor;
};
void test1(){
	motorcar M(120,600,4);
}
void test2(){
	Master ma("hihi","男","语文","32220302","年度优秀讲师");
	ma.Print();
}
void main(void)
{
	/*Cuboid test(10, 20, 30);
	cout<<"长方体的长宽高依次为：10，20，30"<<endl;
	cout<<"长方体的表面积为："<<test.calArea()<<endl;
	cout << test.calVolume() << endl;*/
	
	//cout<<"\n";
	test2();
	system("pause");
}