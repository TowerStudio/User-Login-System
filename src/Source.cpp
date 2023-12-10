//Header
#include "../include/user.h"
#include <fstream>
#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>

using namespace std;
//var
bool pass(false);			//是否允许用户通过
char put;					//输入
char pwd[50], usrn[50];		//密码和用户名
COORD c;					//光标位置(坐标)
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);//Windows.h的句柄，为了图省事
user usr;					//用户
int ch = 0;					//输入数量
//func
void Reg();
void Log();

void Reg()//注册
{
	ch = 0;	//清空输入
	pass = false;	//禁止通过
	system("cls");	//清屏，刷新buffer
	cout << "Reg\n";
	cout << "———————\n";
	cout << "|Name     : ";
	cout << "\n|Password : ";
	cout << "\n———————\n";		//打印输入框
	c = { 12,2 };	//初始化坐标
	SetConsoleCursorPosition(h, c);//移动光标
	while (!pass)
	{
		put = _getch();
		switch (put)
		{
		case '\r':
			ch = 0;
			c = { 12,3 };
			SetConsoleCursorPosition(h, c);
			while (!pass)
			{
				put = _getch();
				switch (put)
				{
				case '\r'://When user submit
					ch = 0;
					c = { 0,5 };
					SetConsoleCursorPosition(h, c);
					cout << "Welcome";
					pass = true;	//退出注册并登录
					break;
				case '\b':
					if (ch == 0)
					{
						ch = 0;
					}
					else
					{
						ch--;
						cout << "\b \b";
					}
					break;
				default:
					usr.upwd[ch++] = put;
					putchar(put);
					break;
				}
			}
			break;
		case '\b':
			if (ch == 0)
			{
				ch = 0;//我们必须做出一些限制
			}
			else
			{
				ch--;
				cout << "\b \b";
			}
			break;
		default:
			usr.uname[ch++] = put;
			putchar(put);
			break;
		}
	}
}
void Log()	//登录
{
	pass = false;
	system("cls");
	cout << "Log\n";
	cout << "———————\n";
	cout << "|Name     : " << usr.uname << "\n";
	cout << "|Password : ";
	cout << "\n———————\n";
	c = { 12,3 };
	SetConsoleCursorPosition(h, c);
	while (!pass)
	{
		put = _getch();		//输入密码
		switch (put)
		{
		case '\r':
			if (pwd[ch] == usr.upwd[ch]){
				c = { 0,5 };SetConsoleCursorPosition(h, c);
				cout << "Welcome";pass = true;
			}else{
				c = { 0,5 };SetConsoleCursorPosition(h, c);
				cout << "Password wrong!";pass = false;getchar();Log();
			}break;
		case '\b':
			if (ch == 0){
				ch = 0;
			}else{
				ch--;cout << "\b \b";
			}break;
		default:
			pwd[ch++] = put;
			putchar('*');//输入密码使用*代替，保护用户的密码安全
			break;
		}
	}
}
int main()
{
	//Reg();
	Log();
	return 0;
}
