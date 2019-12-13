#ifndef DESIGN_CLASS_H_
#define DESIGN_CLASS_H_

#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<shlobj.h>
#include<shellapi.h>
#include<iomanip>
#include<Windows.h>
#include<istream>
#include<fstream>
#include<sstream>

const std::string STARS = "*****************";
std::list<class student> con;
std::list<class student>::iterator it;
typedef std::list<class student> list_stu;

class student
{
private:
	std::string student_id;
	std::string student_name;
	int course_computer_vision;
	int course_machine_learning;
	int course_algorithm;
	double course_average;
	bool input_test;
public:
	student(std::string a, std::string b, int c, int d, int e) :student_id(a), student_name(b), course_computer_vision(c), course_machine_learning(d), course_algorithm(e), course_average((c + d + e) / 3.0) {}
	student()
	{
		std::cout << "       ѧ��ѧ��Ϊ";
		std::cin >> student_id;
		std::cout << "       ѧ������Ϊ";
		std::cin >> student_name;
		std::cout << "       ѧ�����ųɼ�Ϊ(1/3)";
		std::cin >> course_computer_vision;
		std::cout << "       ѧ�����ųɼ�Ϊ(2/3)";
		std::cin >> course_machine_learning;
		std::cout << "       ѧ�����ųɼ�Ϊ(3/3)";
		std::cin >> course_algorithm;
		course_average = (course_computer_vision + course_machine_learning + course_algorithm) / 3.0;
		input_test = course_computer_vision >= 0 && course_computer_vision <= 100 &&
			course_machine_learning >= 0 && course_machine_learning <= 100 &&
			course_computer_vision >= 0 && course_computer_vision <= 100;
		if (!input_test)
		{
			std::cout << STARS << STARS << std::endl;
			std::cout << "       �������ݲ��Ϸ�������������" << std::endl;
		}
	}
	const std::string return_student_id() { return student_id; }
	const std::string return_student_name() { return student_name; }
	const int return_course_computer_vision() { return course_computer_vision; }
	const int return_course_machine_learning() { return course_machine_learning; }
	const int return_course_algorithm() { return course_algorithm; }
	const double return_course_average() { return course_average; }
	const bool return_input_test() { return input_test; }
	bool operator<(student &stu) { return course_average < stu.return_course_average(); }
	bool operator==(std::string find) { return student_id == find; }
	friend std::ostream& operator<<(std::ostream& out, const student& stu)
	{
		out << "| " << std::setw(11) << stu.student_id << "| " << std::setw(13) << stu.student_name
			<< "| " << std::setw(9) << stu.course_computer_vision << "| " << std::setw(9) << stu.course_machine_learning
			<< "| " << std::setw(9) << stu.course_algorithm << "| " << std::setw(14) << std::fixed << std::setprecision(2) << stu.course_average << " |";
		return out;
	}
};
void student_message_add() {
	student *transmit = new student;
	if (transmit->return_input_test() == true)//�����Ƿ��๹��Ϲ�
	{
		for (it = con.begin(); it != con.end(); it++)//���������
		{
			if (it->return_student_id() == transmit->return_student_id())
			{
				std::cout << "ѧ�����������ѧ���ɼ��Ѿ����ڣ�" << std::endl;
				
			}
		}
		con.push_back(*transmit);
	}
}
void student_message_typein()
{

}
void student_message_print() {
	if (!con.empty())
	{
		std::cout << "+------------+--------------+----------+----------+----------+----------------+" << std::endl;
		std::cout << "| student_id | student_name | course_1 | course_2 | course_3 | course_average |" << std::endl;
		std::cout << "+------------+--------------+----------+----------+----------+----------------+" << std::endl;
		for (it = con.begin(); it != con.end(); it++)
		{
			std::cout << *it << std::endl;
		}
		std::cout << "+------------+--------------+----------+----------+----------+----------------+" << std::endl;
	}
	else { std::cout << "����������������" << std::endl; }
}
void student_message_edit()
{
	std::string test_number;
	bool check_find = false;
	std::cout << "������Ҫ�޸ĵ�ѧ��ѧ��";
	std::cin >> test_number;
	for (it = con.begin(); it != con.end(); it++)
	{
		if (it->return_student_id() == test_number)
		{
			std::cout << std::endl << "���ҳɹ�!" << std::endl;
			check_find = true;
			student *transmit = new student;
			if (transmit->return_input_test() == true)//�����Ƿ��๹��Ϲ�
			{
				for (std::list<class student>::iterator test = con.begin(); test != con.end(); test++)//���������
				{
					if (test->return_student_id() == transmit->return_student_id())
					{
						std::cout << "ѧ�����������ѧ���ɼ��Ѿ����ڣ�" << std::endl;
						
					}
				}
			}
			*it = *transmit;
		}
	}
	if (check_find == false)
	{
		std::cout << "δ�ҵ�Ҫ���ҵ�ѧ��!" << std::endl;
		
	}
}
void student_message_delete()
{
	std::string test_number;
	std::cout << "������Ҫɾ����ѧ��ѧ��";
	std::cin >> test_number;
	std::list<class student>::iterator it_delete;
	it_delete = find(con.begin(), con.end(), test_number);
	if (it_delete != con.end())
	{
		std::cout << "���ҳɹ�!" << std::endl;
		con.erase(it_delete);
		std::cout << "ɾ���ɹ�!" << std::endl;
	}
	else
	{
		std::cout << "����ʧ��" << std::endl;
		
	}
}
void 	student_message_sort()
{
	con.sort();
	
}
void student_message_search()
{
	/*	student *transmit = new student;
	//	if (transmit->return_input_test() == true)//�����Ƿ��๹��Ϲ�
	//	{
	//		for (std::list<class student>::iterator test = con.begin(); test != con.end(); test++)//���������
	//		{
	//			if (test->return_student_id() == transmit->return_student_id())
	//			{
	//				std::cout << "ѧ�����������ѧ���ɼ��Ѿ����ڣ�" << std::endl;
	//				
	//			}
	//		}
	//	}
	//	student_message_sort();
	//	if (binary_search(con.begin(), con.end(), transmit))
	//	{
	//		std::cout << "���ҳɹ�" << std::endl;
	//		auto pr = equal_range(con.begin(),con.end(), transmit);
	//	}
		//STL���ֲ��ҷ��޷����зǱ�׼������STL�ж���Ķ��ֲ��Һ����޶���std::list<int>�ȸ�ʽ����std::list<class student>����ƥ������ط��ţ����޷�ʹ�ö��ֲ��ң��ʱ�����ѡ�������˳����һ�ȡ
		//�¸��������
			//����	C2672	��operator __surrogate_func�� : δ�ҵ�ƥ������غ���	2019 - 2 - COURESE - PROJECT - 1	c : \program files(x86)\microsoft visual studio\2017\enterprise\vc\tools\msvc\14.16.27023\include\algorithm	3302
			//����	C2672	��operator __surrogate_func�� : δ�ҵ�ƥ������غ���	2019 - 2 - COURESE - PROJECT - 1	c : \program files(x86)\microsoft visual studio\2017\enterprise\vc\tools\msvc\14.16.27023\include\xutility	1108
			//����	C2672	��operator __surrogate_func�� : δ�ҵ�ƥ������غ���	2019 - 2 - COURESE - PROJECT - 1	c : \program files(x86)\microsoft visual studio\2017\enterprise\vc\tools\msvc\14.16.27023\include\algorithm	3267
			//����	C2893	δ��ʹ����ģ�塰unknown - type std::less<void>::operator ()(_Ty1 &&, _Ty2 &&) const��ר�û�	2019 - 2 - COURESE - PROJECT - 1	c:\program files(x86)\microsoft visual studio\2017\enterprise\vc\tools\msvc\14.16.27023\include\algorithm	33
			//����	C2893	δ��ʹ����ģ�塰unknown - type std::less<void>::operator ()(_Ty1 &&, _Ty2 &&) const��ר�û�	2019 - 2 - COURESE - PROJECT - 1	c:\program files(x86)\microsoft visual studio\2017\enterprise\vc\tools\msvc\14.16.27023\include\xutility	1108
			//����	C2893	δ��ʹ����ģ�塰unknown - type std::less<void>::operator ()(_Ty1 &&, _Ty2 &&) const��ר�û�	2019 - 2 - COURESE - PROJECT - 1	c:\program files(x86)\microsoft visual studio\2017\enterprise\vc\tools\msvc\14.16.27023\include\xutility	1108*/
	std::string test_number;
	bool check_find = false;
	std::cout << "������Ҫ���ҵ�ѧ��ѧ��";
	std::cin >> test_number;
	std::list<class student>::iterator it_find;
	it_find = find(con.begin(), con.end(), test_number);
	if (it_find != con.end())
	{
		std::cout << "���ҳɹ�!" << std::endl;
		std::cout << "+------------+--------------+----------+----------+----------+----------------+" << std::endl;
		std::cout << "| student_id | student_name | course_1 | course_2 | course_3 | course_average |" << std::endl;
		std::cout << "+------------+--------------+----------+----------+----------+----------------+" << std::endl;
		std::cout << *it_find << std::endl;
		std::cout << "+------------+--------------+----------+----------+----------+----------------+" << std::endl;
	}
	else
	{
		std::cout << "��ƥ�������ʧ��" << std::endl;
		
	}
}
void student_message_sort_add()
{
	student_message_sort();
	double course_average;
	bool state = false;
	std::cout << "������Ҫ��ӵ�ѧ��ƽ���ɼ�";
	std::cin >> course_average;
	std::list<class student>::iterator it_course = con.begin();
	std::list<class student>::iterator next_student = con.begin();
	for (; it_course != con.end(); it_course++)
	{
		next_student++;
		if (next_student != con.end())
		{
			if (it_course->return_course_average() <= course_average && next_student->return_course_average() >= course_average)
			{
				student *transmit = new student;
				if (transmit->return_input_test() == true)//�����Ƿ��๹��Ϲ�
				{
					for (std::list<class student>::iterator test = con.begin(); test != con.end(); test++)//���������
					{
						if (test->return_student_id() == transmit->return_student_id())
						{
							std::cout << "ѧ�����������ѧ���ɼ��Ѿ����ڣ�" << std::endl;
							state = true;
							
						}
					}
				}
				con.insert(next_student, *transmit);
				
			}
		}
	}
	if (state == false)
	{
		std::cout << "������ֵ����������������ݣ�" << std::endl;
	}
}
void student_message_export()
{
	std::ofstream outFile;
	outFile.open("D:\\score.csv", std::ios::out);
	if (outFile)
	{
		outFile << "ѧ��ѧ��" << ',' << "ѧ������" << ',' << "ѧ���γ�1�ɼ�" << ',' << "ѧ���γ�2�ɼ�" << ',' << "ѧ���γ�3�ɼ�" << ',' << "ѧ���γ�ƽ���ɼ�" << std::endl;
		for (it = con.begin(); it != con.end(); it++)
		{
			outFile << it->return_student_id() << ',' << it->return_student_name() << ',' << it->return_course_computer_vision() << ','
				<< it->return_course_machine_learning() << ',' << it->return_course_algorithm() << ',' << it->return_course_average() << std::endl;
		}
		std::cout << "д�����" << std::endl;
	}
	else { std::cout << "�ļ���ʧ�ܣ�" << std::endl; }
	outFile.close();
}
#endif
