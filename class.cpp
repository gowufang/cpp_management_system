#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include<Windows.h>
using namespace std;
string ID;//保证ID唯一性
char Display[]="正在载入，请稍候...";
char Display1[]="正在退出程序，请稍候...";
char Display2[]="无效输入，即将退出...";
char Display3[]="未找到该职工...";
int t;
class Person
{
protected:
	string Num;//职工工号
	char Name[20];//职工姓名
	int BaSalary;//基本工资
	int DuSalary;//职务工资
	int Allowance;//岗位津贴
	int MeInsurance;//医疗保险
	int AcFund;//公积金
	int AllSalary;//总工资
	Person *next;
public:
	Person(string ID,char *Name,int BaSalary,int DuSalary,int Allowance,int MeInsurance,int AcFund,int AllSalary)
	{
		this->Num=ID;
		strcpy(this->Name,Name);
		this->BaSalary=BaSalary;
		this->DuSalary=DuSalary;
		this->Allowance=Allowance;
		this->MeInsurance=MeInsurance;
		this->AcFund=AcFund;
		this->AllSalary=AllSalary;
	}
	friend class Manage;
};
class Manage
{
private:
	Person *person;
public:
	Manage()
	{
		person=0;
		Load();
	}
	~Manage()
	{
		Person *p=person;
		while(p)
		{
			p=p->next;
			delete  person;
			person=p;
		}
		person=0;
	}
	void Find(char Name[20]);//按姓名查找
	void Find(string ID);//按编号查找
	void Add(); //添加加信息
	void Delete();//删除信息
	void DeleteID(string ID); //按ID删除信息
	void DeleteName(char Name[]);//按姓名删除
	void ModifyID(string ID); //按ID修改信息
	void Query(); //查询信息
	void Save(); //保存数据
	void Load(); //读入数据
	void Look();//预览
	void Destory();//销毁
	void Statistics();//统计职工工资
	int SumSalary(string ID);//对单个职工工资进行求和
	void Exchange(Person *p,Person *q);//用于交换两个数据元素的值
	int BubbleSort();//对所有对象进行冒泡排序
	void OutputAll(Person *p);//显示所有数据详细信息
	void ModifyName(char Name[]);//按姓名进行修改
	void Modify();//修改信息
};