#include<iostream>

using namespace std;
class Person
{
protected:
	
	char Name[20];//姓名
	string ph;//电话号码
	string addr;//住址
	string email；//电子邮件
	string qq;//QQ号
	
	//int BaSalary;//基本工资
	//int DuSalary;//职务工资
	//int Allowance;//岗位津贴
	//int MeInsurance;//医疗保险
	//int AcFund;//公积金
	//int AllSalary;//总工资
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