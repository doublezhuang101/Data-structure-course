#include<iostream>
#include"C++_course_design.h"
#include<cctype>
#include<string>
#include<Windows.h>
#include<vector>
#include<list>

void menu(void);//菜单
void exit_system(void);//退出

int main()
{
	std::cout << STARS << STARS << std::endl << "       欢迎使用学生信息管理系统" << std::endl;
	menu();
	std::cin.get();
	return 0;
}

void menu(void)
{
	char choice;
	bool test;
	std::cout << STARS << STARS << std::endl;
	std::cout << "       请输入数字选择功能：" << std::endl;
	std::cout << "       1)学生信息录入" << std::endl;//Debug Success
	std::cout << "       2)学生信息录入（不可用）" << std::endl;//Debug Success
	std::cout << "       3)显示学生信息" << std::endl;//Debug Success
	std::cout << "       4)编辑学生信息" << std::endl;//Debug Success
	std::cout << "       5)删除学生信息" << std::endl;//Debug Success
	std::cout << "       6)学生信息排序" << std::endl;//Debug Success
	std::cout << "       7)查找学生信息" << std::endl;//Debug Success
	std::cout << "       8)插入学生信息" << std::endl;//Debug Success
	std::cout << "       9)导出数据" << std::endl;//Debug Success
	std::cout << "       0)退出系统" << std::endl;//Debug Success
	std::cout << STARS << STARS << std::endl;
	std::cout << "请输入数字选择";
	std::cin >> choice;
	test = isdigit(choice);
	while (test != true)//特色函数-使用cctype库进行类型检测
	{
		std::cout << "格式错误，请重新输入" << std::endl;
		std::cin >> choice;
		test = isdigit(choice);
	}
	switch (atoi(&choice))//强制类型转换
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
		std::cout << "输入错误！请重新输入" << std::endl;
		menu();
	}
	std::cin.clear();
}
void exit_system(void)
{
	std::cout << STARS << STARS << std::endl;
	con.clear();
	std::cout << "       感谢使用本学生成绩管理系统" << std::endl;
	std::cin.get();
	exit(0);
}
