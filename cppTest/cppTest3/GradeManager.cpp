#include "Student.h"
#include "Grade.h"
#include "iostream"    //��"Student.h"��ʹ�������ֿռ�std


struct GradeManager
{
	void showOperateInfo()
	{
		cout << "��ӭʹ�ø�ϵͳ������ѡ�����²���֮һ��" << endl;
		cout << "1: ���һ��ѧ�������ṩѧ�š���������" << endl;
		cout << "2: ɾ��һ��ѧ�������ṩѧ�ţ���" << endl;
		cout << "3: ¼��һ��ѧ���ĳɼ������ṩѧ�ż�Ӣ���ѧ���������C++���ſεĳɼ�����" << endl;
		cout << "4: ��ʾһ��ѧ������Ϣ�����ṩѧ�ţ���" << endl;
		cout << "5: ��ʾ����ÿ�ſε�ƽ���ɼ���" << endl;
		cout << "6: ��ʾ����ƽ������ߵ�ѧ������Ϣ��" << endl;
		cout << "7: ��ʾ����ѧ������Ϣ��" << endl;
		cout << "8: ��ʾ���Ʋ������ѧ��������" << endl;
		cout << "9: ��ʾ������һ���ųɼ��������ѧ����Ϣ��" << endl;
		cout << "0: �˳���" << endl;
		cout << "��ѡ�����Ĳ���(1-7��0): ";
	}

	void addStudent(Grade& grade)  //��ΪҪ�޸�grade������������
	{
		cout << "������ѧ����ѧ�ţ�";
		string stuNumber;
		cin >> stuNumber;
		cout << "������ѧ����������";
		string stuName;
		cin >> stuName;
		Student stu(stuNumber, stuName);
		if (grade.addStudent(stu) == true)
		{
			cout << "���ѧ���ɹ���" << endl;
		}
		else
		{
			cout << "�༶�Ѿ���Ա���������ѧ���ˣ�" << endl;
		}
	}

	void deleteStudent(Grade& grade)  //��ΪҪ�޸�grade������������
	{
		cout << "������Ҫɾ����ѧ����ѧ�ţ�";
		string stuNumber;
		cin >> stuNumber;
		if (grade.deleteStudent(stuNumber) == true)
		{
			cout << "ѧ��Ϊ" << stuNumber << "��ѧ���Ѿ���ɾ����" << endl;
		}
		else
		{
			cout << "�Ҳ�����ѧ����ɾ������ʧ�ܣ�" << endl;
		}
	}

	void enterScores(Grade& grade)  //��ΪҪ�޸�grade������������
	{
		cout << "������Ҫɾ����ѧ����ѧ�ţ�";
		string stuNumber;
		cin >> stuNumber;
		int index = grade.findStudent(stuNumber);
		if (index == -1)   //�˴����߼��ǣ����ѧ�Ų����ڣ���ʾ���˳�������������θĳɡ�������������ѧ�ŵĲ�������
		{
			cout << "��ѧ�������ڣ���ȷ��ѧ���Ƿ���ȷ��" << endl;
		}
		else
		{
			double e, m, c, cpp;  //δ������ɼ��ĺ��������ж�
			cout << "������Ӣ��ɼ���";
			cin >> e;
			cout << "��������ѧ�ɼ���";
			cin >> m;
			cout << "�����������ɼ���";
			cin >> c;
			cout << "������C++�ɼ���";
			cin >> cpp;
			Student* stu = grade.getStudent(index);   //stuָ��grade�е�ѧ�Ŷ����������������ﵽ�޸ĵ�Ч����
			stu->enterScore(e, m, c, cpp);
		}
	}

	void showStudentInfo(Grade grade)
	{
		cout << "������Ҫɾ����ѧ����ѧ�ţ�";
		string stuNumber;
		cin >> stuNumber;
		int index = grade.findStudent(stuNumber);
		if (index == -1)
		{
			cout << "��ѧ�������ڣ���ȷ��ѧ���Ƿ���ȷ��" << endl;
		}
		else
		{
			Student* stu = grade.getStudent(index);
			stu->show();
		}
	}

	void showCourseAverage(Grade grade)
	{
		cout << "the average score of English is: " << grade.calCourseAverage(1) << endl;
		cout << "the average score of math is: " << grade.calCourseAverage(2) << endl;
		cout << "the average score of computer is: " << grade.calCourseAverage(3) << endl;
		cout << "the average score of cpp is: " << grade.calCourseAverage(4) << endl;
	}

	void showMaxScoreStudent(Grade grade)
	{
		cout << "the student with maximise score is: " << endl;
		grade.findMaxScoreStudent().show();
	}

	void showAll(Grade grade)
	{
		int count = grade.getCount();
		//cout << "���Ϲ���" << count << "λѧ����������Ϣ���£�" << endl;
		//system("mode con cols=230 lines=60");
		printf("studendNumber\tstudentName\tEnglishScore\tMathScore\tComputerScore\tCPPScore\taverage\n");
		for (int i = 0; i < count; i++)
		{
			Student* stu = grade.getStudent(i);
			printf("%-13s\t%-11s\t%-12.2llf\t%-9.2llf\t%-13.2llf\t%-8.2llf\t%-7.2llf\n",
				stu->getStudentNumber().c_str(), stu->getStudentName().c_str(), stu->getCourseScore(1), stu->getCourseScore(2), stu->getCourseScore(3), stu->getCourseScore(4), stu->everage());
			//stu->show();
			cout << endl;
		}
	}

	void preAddStudents(Grade& grade)   //Ԥ�Ӽ���ѧ�����������
	{
		Student stu1("bj1601", "yhz");
		stu1.enterScore(80, 90, 95, 25);
		grade.addStudent(stu1);

		Student stu2("bj1603", "abc");
		stu2.enterScore(89, 95, 78, 49);
		grade.addStudent(stu2);

		Student stu3("bj1602", "zhangsan");
		stu3.enterScore(88, 77, 99, 73);
		grade.addStudent(stu3);
	}

	void showNoPass(Grade& grade)      //��ʾÿһ�ſγ�û�м����������
	{
		printf("English\tMath\tComputer\tCPP\n");
		printf("%-7d\t%-4d\t%-8d\t%-3d\n", grade.CountEnglish(), grade.CountMath(), grade.CountComputer(), grade.CountCpp());
	}

	void showOneNoPassStudent(Grade& grade)      //������һ�ſγ̲������ѧ��
	{
		int count = grade.getCount();
		printf("studendNumber\tstudentName\tEnglishScore\tMathScore\tComputerScore\tCPPScore\taverage\n");
		for (int i = 0; i < count; i++)
		{
			Student* stu = grade.getStudent(i);
			if (!grade.Pass(stu->getCourseScore(1)) || !grade.Pass(stu->getCourseScore(2)) || !grade.Pass(stu->getCourseScore(3)) || !grade.Pass(stu->getCourseScore(4))) {
				printf("%-13s\t%-11s\t%-12.2llf\t%-9.2llf\t%-13.2llf\t%-8.2llf\t%-7.2llf\n",
					stu->getStudentNumber().c_str(), stu->getStudentName().c_str(), stu->getCourseScore(1), stu->getCourseScore(2), stu->getCourseScore(3), stu->getCourseScore(4), stu->everage());
			}
			//stu->show();
			cout << endl;
		}
	}
	void menu()
	{
		Grade grade(5);   //����һ���༶���󣬸ð༶����ܹ�����5��ѧ��

		preAddStudents(grade);   //���������
		showOperateInfo();    //��ʾ������ʾ��Ϣ

		while (true)
		{
			int choice;
			cin >> choice;
			switch (choice)
			{
			case 1:
				addStudent(grade);
				break;
			case 2:
				deleteStudent(grade);
				break;
			case 3:
				enterScores(grade);
				break;
			case 4:
				showStudentInfo(grade);
				break;
			case 5:
				showCourseAverage(grade);
				break;
			case 6:
				showMaxScoreStudent(grade);
				break;
			case 7:
				showAll(grade);
				break;
			case 8:
				showNoPass(grade);
				break;
			case 9:
				showOneNoPassStudent(grade);
				break;
			case 0:
				exit(0);
			}

			//system("pause");  //��ͣ�������������...
			//system("cls");   //����
		}
	}
};


int main()
{
	GradeManager G;
	G.menu();
	return 0;
}
