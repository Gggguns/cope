#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//CPU
class CPU {
public:
	CPU(int rank = 0, int frequency = 0, double voltage = 0) :_rank(rank), _frequency(frequency), _voltage(voltage) {
		cout << "CPU�Ĺ��캯��������\n";
	}
	void run() {
		cout << "CPU��ʼ��������\n";
	}
	void stop() {
		cout << "CPU�����������\n";
	}

	//��ȡ����ֵ
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
		cout << "CPU����������������\n";
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
		cout << "RAM�Ĺ��캯��������\n";
	}
	void run() {
		cout << "�ڴ�����ݽ��м�����\n";
	}
	void stop() {
		cout << "�ڴ�����ݼ������\n";
	}
	~RAM() {
		cout << "RAM����������������\n";
	}
private:
	int _size;
};
//CDROM
class CDROM {
public:
	CDROM() {
		cout << "CDROM�Ĺ��캯��������\n";
	}
	void run() {
		cout << "�������ڱ�����\n";
	}
	void stop() {
		cout << "�������������\n";
	}
	~CDROM() {
		cout << "CDROM����������������\n";
	}
};
//Computer
class Computer {
public:
	Computer(int rank=1, int frequency=0, double voltage=8, int size=10) :_c(rank, frequency, voltage), _r(size), _cd(){
		cout << "Computer�Ĺ��캯��������\n";
	}
	void run() {
		cout << "�ü�������й�����\n";
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
		cout << "�ü����ֹͣ����\n";
	}
	~Computer() {
		cout << "Computer����������������\n";
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
	cout <<"CPU�ĵȼ�Ϊ��" << c.getRank() << endl;
	cout << "CPU��Ƶ��Ϊ��" << c.getFrequency() << endl;
	cout << "CPU�ĵ�ѹΪ��" << c.getVoltage() << endl;*/
	Computer Com;
	Com.run();
	Com.stop();
	return 0;
}