#include "Student.h"
#include "Grade.h"
#include "iostream"    //在"Student.h"中使用了名字空间std


struct GradeManager
{
	void showOperateInfo()
	{
		cout << "欢迎使用该系统。您能选择以下操作之一：" << endl;
		cout << "1: 添加一个学生（需提供学号、姓名）；" << endl;
		cout << "2: 删除一个学生（需提供学号）；" << endl;
		cout << "3: 录入一个学生的成绩（需提供学号及英语、数学、计算机、C++三门课的成绩）；" << endl;
		cout << "4: 显示一个学生的信息（需提供学号）；" << endl;
		cout << "5: 显示班上每门课的平均成绩；" << endl;
		cout << "6: 显示班上平均分最高的学生的信息；" << endl;
		cout << "7: 显示所有学生的信息；" << endl;
		cout << "8: 显示各科不及格的学生个数；" << endl;
		cout << "9: 显示至少有一课门成绩不及格的学生信息；" << endl;
		cout << "0: 退出。" << endl;
		cout << "请选择您的操作(1-7及0): ";
	}

	void addStudent(Grade& grade)  //因为要修改grade，必须用引用
	{
		cout << "请输入学生的学号：";
		string stuNumber;
		cin >> stuNumber;
		cout << "请输入学生的姓名：";
		string stuName;
		cin >> stuName;
		Student stu(stuNumber, stuName);
		if (grade.addStudent(stu) == true)
		{
			cout << "添加学生成功！" << endl;
		}
		else
		{
			cout << "班级已经满员，不能添加学生了！" << endl;
		}
	}

	void deleteStudent(Grade& grade)  //因为要修改grade，必须用引用
	{
		cout << "请输入要删除的学生的学号：";
		string stuNumber;
		cin >> stuNumber;
		if (grade.deleteStudent(stuNumber) == true)
		{
			cout << "学号为" << stuNumber << "的学生已经被删除！" << endl;
		}
		else
		{
			cout << "找不到该学生，删除操作失败！" << endl;
		}
	}

	void enterScores(Grade& grade)  //因为要修改grade，必须用引用
	{
		cout << "请输入要删除的学生的学号：";
		string stuNumber;
		cin >> stuNumber;
		int index = grade.findStudent(stuNumber);
		if (index == -1)   //此处的逻辑是：如果学号不存在，提示并退出操作。试想如何改成“允许重新输入学号的操作”？
		{
			cout << "该学生不存在，请确认学号是否正确！" << endl;
		}
		else
		{
			double e, m, c, cpp;  //未对输入成绩的合理性作判断
			cout << "请输入英语成绩：";
			cin >> e;
			cout << "请输入数学成绩：";
			cin >> m;
			cout << "请输入计算机成绩：";
			cin >> c;
			cout << "请输入C++成绩：";
			cin >> cpp;
			Student* stu = grade.getStudent(index);   //stu指针grade中的学号对象，这样才能真正达到修改的效果！
			stu->enterScore(e, m, c, cpp);
		}
	}

	void showStudentInfo(Grade grade)
	{
		cout << "请输入要删除的学生的学号：";
		string stuNumber;
		cin >> stuNumber;
		int index = grade.findStudent(stuNumber);
		if (index == -1)
		{
			cout << "该学生不存在，请确认学号是否正确！" << endl;
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
		//cout << "班上共有" << count << "位学生，具体信息如下：" << endl;
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

	void preAddStudents(Grade& grade)   //预加几个学生，方便测试
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

	void showNoPass(Grade& grade)      //显示每一门课程没有及格的总人数
	{
		printf("English\tMath\tComputer\tCPP\n");
		printf("%-7d\t%-4d\t%-8d\t%-3d\n", grade.CountEnglish(), grade.CountMath(), grade.CountComputer(), grade.CountCpp());
	}

	void showOneNoPassStudent(Grade& grade)      //有至少一门课程不及格的学生
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
		Grade grade(5);   //创建一个班级对象，该班级最多能够容纳5名学生

		preAddStudents(grade);   //方便测试用
		showOperateInfo();    //显示操作提示信息

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

			//system("pause");  //暂停，按任意键继续...
			//system("cls");   //清屏
		}
	}
};


int main()
{
	GradeManager G;
	G.menu();
	return 0;
}
