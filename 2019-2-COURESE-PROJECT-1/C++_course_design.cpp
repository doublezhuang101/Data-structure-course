#include<iostream>
#include"C++_course_design.h"
#include<cctype>
#include<string>
#include<Windows.h>
#include<vector>
#include<list>

void menu(void);//�˵�
void exit_system(void);//�˳�

int main()
{
	std::cout << STARS << STARS << std::endl << "       ��ӭʹ��ѧ����Ϣ����ϵͳ" << std::endl;
	menu();
	std::cin.get();
	return 0;
}

void menu(void)
{
	char choice;
	bool test;
	std::cout << STARS << STARS << std::endl;
	std::cout << "       ����������ѡ���ܣ�" << std::endl;
	std::cout << "       1)ѧ����Ϣ¼��" << std::endl;//Debug Success
	std::cout << "       2)ѧ����Ϣ¼�루�����ã�" << std::endl;//Debug Success
	std::cout << "       3)��ʾѧ����Ϣ" << std::endl;//Debug Success
	std::cout << "       4)�༭ѧ����Ϣ" << std::endl;//Debug Success
	std::cout << "       5)ɾ��ѧ����Ϣ" << std::endl;//Debug Success
	std::cout << "       6)ѧ����Ϣ����" << std::endl;//Debug Success
	std::cout << "       7)����ѧ����Ϣ" << std::endl;//Debug Success
	std::cout << "       8)����ѧ����Ϣ" << std::endl;//Debug Success
	std::cout << "       9)��������" << std::endl;//Debug Success
	std::cout << "       0)�˳�ϵͳ" << std::endl;//Debug Success
	std::cout << STARS << STARS << std::endl;
	std::cout << "����������ѡ��";
	std::cin >> choice;
	test = isdigit(choice);
	while (test != true)//��ɫ����-ʹ��cctype��������ͼ��
	{
		std::cout << "��ʽ��������������" << std::endl;
		std::cin >> choice;
		test = isdigit(choice);
	}
	switch (atoi(&choice))//ǿ������ת��
	{
	case 1:
		student_message_add();
		getchar();
		menu();
		break;
	case 2:
		student_message_typein();
		menu();
		break;
	case 3:
		student_message_print();
		getchar();
		menu();
		break;
	case 4:
		student_message_edit();
		menu();
		break;
	case 5:
		student_message_delete();
		menu();
		break;
	case 6:
		student_message_sort();
		menu();
		break;
	case 7:
		student_message_search();
		menu();
		break;
	case 8:
		student_message_sort_add();
		menu();
		break;
	case 9:
		student_message_export();
		menu();
		break;
	case 0:
		exit_system();
		return;
	default:
		std::cout << "�����������������" << std::endl;
		menu();
	}
	std::cin.clear();
}
void exit_system(void)
{
	std::cout << STARS << STARS << std::endl;
	con.clear();
	std::cout << "       ��лʹ�ñ�ѧ���ɼ�����ϵͳ" << std::endl;
	std::cin.get();
	exit(0);
}
