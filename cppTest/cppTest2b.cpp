#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//CPU
class CPU {
public:
	CPU(int rank = 0, int frequency = 0, double voltage = 0) :_rank(rank), _frequency(frequency), _voltage(voltage) {
		cout << "CPU的构造函数被调用\n";
	}
	void run() {
		cout << "CPU开始处理数据\n";
	}
	void stop() {
		cout << "CPU处理数据完毕\n";
	}

	//获取属性值
	int getRank() {
		return _rank;
	}
	int getFrequency() {
		return _frequency;
	}
	double getVoltage() {
		return _voltage;
	}
	~CPU(){
		cout << "CPU的析构函数被调用\n";
	}
private:
	int _rank;
	int _frequency;
	double _voltage;
};
//RAM
class RAM {
public:
	RAM(int size=0):_size(size){
		cout << "RAM的构造函数被调用\n";
	}
	void run() {
		cout << "内存的数据进行加载中\n";
	}
	void stop() {
		cout << "内存的数据加载完毕\n";
	}
	~RAM() {
		cout << "RAM的析构函数被调用\n";
	}
private:
	int _size;
};
//CDROM
class CDROM {
public:
	CDROM() {
		cout << "CDROM的构造函数被调用\n";
	}
	void run() {
		cout << "光驱正在被调用\n";
	}
	void stop() {
		cout << "光驱调用用完毕\n";
	}
	~CDROM() {
		cout << "CDROM的析构函数被调用\n";
	}
};
//Computer
class Computer {
public:
	Computer(int rank=1, int frequency=0, double voltage=8, int size=10) :_c(rank, frequency, voltage), _r(size), _cd(){
		cout << "Computer的构造函数被调用\n";
	}
	void run() {
		cout << "该计算机进行工作中\n";
		_cd.run();
		_cd.stop();
		_r.run();
		_r.stop();
		_c.run();
		_c.stop();
		_r.run();
		_r.stop();
		_cd.run();
		_cd.stop();
	}
	void stop() {
		cout << "该计算机停止工作\n";
	}
	~Computer() {
		cout << "Computer的析构函数被调用\n";
	}
private:
	CPU _c;
	RAM _r;
	CDROM _cd;
};
int main() {
	/*CPU c(1,8,9.9);
	c.run();
	c.stop();
	cout <<"CPU的等级为：" << c.getRank() << endl;
	cout << "CPU的频率为：" << c.getFrequency() << endl;
	cout << "CPU的电压为：" << c.getVoltage() << endl;*/
	Computer Com;
	Com.run();
	Com.stop();
	return 0;
}