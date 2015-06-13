void Manage::Modify()
{
	system("cls");
	string Num;
	int a;
	char Name[20],choice[10],choice1[10]="1",choice2[10]="2",choice3[10]="3";
	char display[]="1. 按ID号进行查找修改  2. 按姓名进行查找修改  3. 退出\n\n您的选择(请选择1、2、或者3)：";
	cout<<"\n\t\t\t***删除职工***"<<endl;
	cout<<endl;
	//cout<<"\n1. 按ID号进行查找修改  2. 按姓名进行查找修改  3. 退出"<<endl;
	//cout<<"\n您的选择(请选择1、2、或者3)：";
	for(a=0;a<strlen(display);a++)
	{
		Sleep(5);
		cout<<display[a];
	}
	cin.sync();
	cin.getline(choice,10,'\n');
	if(strcmp(choice,choice1)==0)
	{
		cout<<"\n请输入职工ID：";
		cin>>Num;
		ModifyID(Num);
		return;
	}
	else if(strcmp(choice,choice2)==0)
	{
		cout<<"\n请输入职工姓名：";
		cin.sync();
		cin.getline(Name,20,'\n');
		ModifyName(Name);
		return;
	}
	else if(strcmp(choice,choice3)==0)
	{
		return;
	}
	else
	{
		//cout<<"\n无效输入，即将退出...";Sleep(1000);
		system("cls");
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"\t\t\t\t";
		for(t=0;t<strlen(Display2);t++)
		{
		    Sleep(20);
			cout<<Display2[t];
		}
		Sleep(1500);
		return;
	}
}
void Manage::OutputAll(Person *p)//显示所有数据详细信息
{
	Sleep(30);
	cout<<"\n职工ID："<<p->Num;Sleep(20);
	cout<<"\n职工姓名："<<p->Name;Sleep(20);
	cout<<"\n职工基本工资："<<p->BaSalary;Sleep(20);
	cout<<"\n职工职务工资："<<p->DuSalary;Sleep(20);
	cout<<"\n职工岗位津贴："<<p->Allowance;Sleep(20);
	cout<<"\n职工医疗保险："<<p->MeInsurance;Sleep(20);
	cout<<"\n职工公积金："<<p->AcFund;Sleep(20);
	cout<<"\n职工总工资："<<p->AllSalary;Sleep(20);
	cout<<endl;
}
//冒泡排序
int Manage::BubbleSort()
{
	Person *p,*q=person;
	int flag=0;//用于判断是否有交换
	system("cls");
	if(!person)//若表空，则返回
	{
		cout<<"\n当前没有任何数据...";
		return 0;
	}
	while(q)
	{
		p=person;//重新对指针p进行赋值
		flag=0;
		while(p->next)
		{
			if((p->Num)>(p->next->Num))
			{
				Exchange(p,p->next);//调用交换功能函数
				flag=1;//若交换，flag的值改变
			}
			p=p->next;
		}
		if(!flag) break;
		q=q->next;
	}
	return 1;
}
//交换两个对象的值
void Manage::Exchange(Person *p,Person *q)
{
	char elem[20];
	string elem1;
	int elem2;
	strcpy(elem,p->Name);strcpy(p->Name,q->Name);strcpy(q->Name,elem);
	elem1=p->Num;p->Num=q->Num;q->Num=elem1;//交换ID
	elem2=p->BaSalary;p->BaSalary=q->BaSalary;q->BaSalary=elem2;//交换基本工资的值
	elem2=p->DuSalary;p->DuSalary=q->DuSalary;q->DuSalary=elem2;//交换职务工资的值
	elem2=p->Allowance;p->Allowance=q->Allowance;q->Allowance=elem2;//交换津贴的值
	elem2=p->MeInsurance;p->MeInsurance=q->MeInsurance;q->MeInsurance=elem2;//交换医疗保险值
	elem2=p->AcFund;p->AcFund=q->AcFund;q->AcFund=elem2;//交换公积金的值
}
//对职工工资进行求和
int Manage::SumSalary(string ID)
{
	Person *p1=person;
	int Salary=0;
	while(p1)
	{
		if(p1->Num==ID)
			break;
		else
		{
			p1=p1->next;
		}
	}
	if(p1!=NULL)
	{
		Salary=(p1->BaSalary+p1->DuSalary+p1->Allowance+p1->MeInsurance+p1->AcFund);
	}
	return Salary;
}
//统计职工工资
void Manage::Statistics()
{
	Person *p=person,*s,*q;
	int Sum=0,count=0,Max,Min;
	system("cls");
	if(!person)
	{
		cout<<"\n当前没有任何职工的数据...";
		return;
	}
	while(p)
	{
		p=p->next;
	}
	p=person;
	cout<<"\n职工ID |  "<<"职工姓名|   "<<"职工总工资";
	cout<<"\n       |  "<<"        |   "<<endl;
	Max=SumSalary(person->Num);//把第一个员工的总工资赋值给Max
	Min=Max;
	while(p)
	{
		Sleep(30);
		cout<<p->Num<<"   |   "<<p->Name<<"   |     "<<p->AllSalary<<endl;
		Sum=Sum+p->AllSalary;
		if(Max<p->AllSalary)
		{
			Max=p->AllSalary;
			s=p;//把最大值的地址赋值给指针s
		}
		if(Min>p->AllSalary)
		{
			Min=p->AllSalary;
			q=p;
		}
		count++;
		p=p->next;
	}
	cout<<"\n全体员工的工资之和为："<<Sum<<endl;Sleep(30);
	cout<<"\n平均工资为："<<Sum/count<<endl;Sleep(30);
	cout<<"\n总工资最多的职工为："<<"ID："<<s->Num<<"   姓名："<<s->Name<<"   总工资："<<s->AllSalary<<endl;Sleep(30);
	cout<<"\n总工资最少的职工为："<<"ID："<<q->Num<<"   姓名："<<q->Name<<"   总工资："<<q->AllSalary<<endl;
	cout<<endl;
}
//按姓名进行修改
void Manage::ModifyName(char Name[])
{
	Person *p1=person;
	int flag=0,a;
	char c;
	char choice[10],choice1[10]="1",choice2[10]="2",choice3[10]="3",choice4[10]="4";
	char choice5[10]="5",choice6[10]="6",choice7[10]="7";
	char display[]="1. 修改姓名  2. 修改基本工资  3. 修改职务工资 4. 修改岗位津贴\n5. 修改医疗保险  6. 修改公积金  7. 退出\n\n您的选择：";
	char displaya[]="修改成功...";
	while(p1)
	{
		if(strcmp(p1->Name,Name)==0)
			break;
		else
		{
			p1=p1->next;
		}
	}
	if(p1!=NULL)//若找到结点
	{
		system("cls");
		cout<<"\n所要修改的职工的信息如下:"<<endl;
		OutputAll(p1);
			//cout<<"\n1. 修改姓名  2. 修改基本工资  3. 修改职务工资 4. 修改岗位津贴  ";
			//cout<<"\n5. 修改医疗保险  6. 修改公积金  7. 退出";
			//cout<<"\n请选择：";
		for(a=0;a<strlen(display);a++)
		{
			Sleep(5);
			cout<<display[a];
		}
			cin.sync();
			cin.getline(choice,10,'\n');
			if(strcmp(choice,choice1)==0)
			{
				cout<<"\n请输入新的姓名( 四个字母 ):  ";
				cin.sync();
				cin.getline(p1->Name,20,'\n');
			}
			else if(strcmp(choice,choice2)==0)
			{
				cout<<"\n请输入新的基本工资( 数字 ):  ";
				cin>>p1->BaSalary;
			}
			else if(strcmp(choice,choice3)==0)
			{
				cout<<"\n请输入新的职务工资( 数字 ):  ";
				cin>>p1->DuSalary;
			}
			else if(strcmp(choice,choice4)==0)
			{
				cout<<"\n请输入新的岗位津贴( 数字 ):  ";
				cin>>p1->Allowance;
			}
			else if(strcmp(choice,choice5)==0)
			{
				cout<<"\n请输入新的医疗保险金( 数字 ):  ";
				cin>>p1->MeInsurance;
			}
			else if(strcmp(choice,choice6)==0)
			{
				cout<<"\n请输入新的公积金( 数字 ):  ";
				cin>>p1->AcFund;
			}
			else if(strcmp(choice,choice7)==0)
			{
				return;
			}
			else
			{
				flag=1;
				system("cls");
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"\t\t\t\t";
		for(t=0;t<strlen(Display2);t++)
		{
		    Sleep(20);
			cout<<Display2[t];
		}
		Sleep(1500);
				//cout<<"\n\t无效输入...";
			}
			system("cls");
			if(!flag)
			{
				//cout<<"\t  修改成功..."<<endl;
				cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
			    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"\t\t\t\t";
			    for(t=0;t<strlen(displaya);t++)
				{
			        Sleep(20);
			        cout<<displaya[t];
				}
				Sleep(2000);
			}
			system("cls");
	cout<<"是否继续修改(Y/N):  ";
	cin>>c;
	if(toupper(c)=='Y')
	{
		cout<<"请输入要修改人员的ID:  ";
		cin>>ID;
		cout<<endl;
		ModifyID(ID);
		return ;
	}
	else
		return ;
	}
	else //未找到结点
	{
		system("cls");
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"\t\t\t\t";
		for(t=0;t<strlen(Display3);t++)
		{
		    Sleep(20);
			cout<<Display3[t];
		}
		Sleep(1500);
		//cout<<"\n未找到该职工...";
	}
}
//按ID修改信息
void Manage::ModifyID(string ID)
{
	Person *p1=person;
	int flag=0,a;
	char c;
	char choice[10],choice1[10]="1",choice2[10]="2",choice3[10]="3",choice4[10]="4";
	char choice5[10]="5",choice6[10]="6",choice7[10]="7";
	char display[]="1. 修改姓名  2. 修改基本工资  3. 修改职务工资 4. 修改岗位津贴\n5. 修改医疗保险  6. 修改公积金  7. 退出\n\n您的选择：";
	char displaya[]="修改成功...";
	while(p1)
	{
		if(p1->Num==ID)
			break;
		else
		{
			p1=p1->next;
		}
	}
	if(p1!=NULL)//若找到结点
	{
		system("cls");
		cout<<"\n所要修改的职工的信息如下:"<<endl;
		OutputAll(p1);
			//cout<<"\n1. 修改姓名  2. 修改基本工资  3. 修改职务工资 4. 修改岗位津贴  ";
			//cout<<"\n5. 修改医疗保险  6. 修改公积金  7. 退出";
			//cout<<"\n您的选择：";
		for(a=0;a<strlen(display);a++)
		{
			Sleep(5);
			cout<<display[a];
		}
			cin.sync();
			cin.getline(choice,10,'\n');
			if(strcmp(choice,choice1)==0)
			{
				cout<<"\n请输入新的姓名( 四个字母 ):  ";
				cin.sync();
				cin.getline(p1->Name,20,'\n');
			}
			else if(strcmp(choice,choice2)==0)
			{
				cout<<"\n请输入新的基本工资( 数字 ):  ";
				cin>>p1->BaSalary;
			}
			else if(strcmp(choice,choice3)==0)
			{
				cout<<"\n请输入新的职务工资( 数字 ):  ";
				cin>>p1->DuSalary;
			}
			else if(strcmp(choice,choice4)==0)
			{
				cout<<"\n请输入新的岗位津贴( 数字 ):  ";
				cin>>p1->Allowance;
			}
			else if(strcmp(choice,choice5)==0)
			{
				cout<<"\n请输入新的医疗保险金( 数字 ):  ";
				cin>>p1->MeInsurance;
			}
			else if(strcmp(choice,choice6)==0)
			{
				cout<<"\n请输入新的公积金( 数字 ):  ";
				cin>>p1->AcFund;
			}
			else if(strcmp(choice,choice7)==0)
			{
				return;
			}
			else
			{
				flag=1;
				system("cls");
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"\t\t\t\t";
		for(t=0;t<strlen(Display2);t++)
		{
		    Sleep(20);
			cout<<Display2[t];
		}
		Sleep(1500);
				//cout<<"\n\t无效输入...";Sleep(3000);
			}
			system("cls");
			if(!flag)
			{
				//cout<<"修改成功...";
				cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
			    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"\t\t\t\t";
			    for(t=0;t<strlen(displaya);t++)
				{
			        Sleep(20);
			        cout<<displaya[t];
				}
				Sleep(2000);
			}
			system("cls");
	cout<<"是否继续修改(Y/N):  ";
	cin>>c;
	if(toupper(c)=='Y')
	{
		cout<<"请输入要修改人员的ID:  ";
		cin>>ID;
		cout<<endl;
		ModifyID(ID);
		return ;
	}
	else
		return ;
	}
	else //未找到结点
	{
		system("cls");
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"\t\t\t\t";
		for(t=0;t<strlen(Display3);t++)
		{
		    Sleep(20);
			cout<<Display3[t];
		}
		Sleep(1500);
		//cout<<"\n未找到该职工...";
	}
}
//按工号查找职工
void Manage::Find(string ID)
{
	Person *p1=person;
	while(p1)
	{
		if(p1->Num==ID)
			break;
		else
		{
			p1=p1->next;
		}
	}
	if(p1!=NULL)
	{
		OutputAll(p1);
		system("pause");
	}
	else
	{
		system("cls");
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"\t\t\t\t";
		for(t=0;t<strlen(Display3);t++)
		{
		    Sleep(20);
			cout<<Display3[t];
		}
		Sleep(1500);
		//cout<<"\n未找到该职工..."<<endl;
	}
}
//按姓名查找职工
void Manage::Find(char Name[])
{
	Person *p1;
	int count=0;
	p1=person;
	while(p1)
	{
		if(strcmp(p1->Name,Name)==0)
		{
			count++;
			OutputAll(p1);
		}
		p1=p1->next;
	}
	if(count)
	{
		cout<<"\n共找到 "<<count<<" 个名字为 ★"<<Name<<"★ 的职工\n"<<endl;
		system("pause");
	}
	else
	{
		//cout<<"\n未找到该职工..."<<endl;
		system("cls");
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"\t\t\t\t";
		for(t=0;t<strlen(Display3);t++)
		{
		    Sleep(20);
			cout<<Display3[t];
		}
		Sleep(1500);
	}
}
//查询信息
void Manage::Query()
{
	char c,choice[10],choice1[10]="1",choice2[10]="2",choice3[10]="3",Name[20];
	char display[]="1. 按学号查找   2. 按名字查找  3↑. 退出查找\n\n您的选择：";
	string ID;
	int flag=0,a;
	system("cls");
	cout<<endl;
	//cout<<"\t1. 按学号查找   2. 按名字查找  3↑. 退出查找"<<endl;
	for(a=0;a<strlen(display);a++)
	{
		Sleep(5);
		cout<<display[a];
	}
	cin.sync();
	cin.getline(choice,10,'\n');
	if(strcmp(choice,choice1)==0)
	{
		cout<<"输入学号 ID:  ";
		cin>>ID;
		Find(ID);
	}
	else if(strcmp(choice,choice2)==0)
	{
		cout<<"输入姓名 Name:  ";
		cin>>Name;
		Find(Name);
	}
	else if(strcmp(choice,choice3)==0)
	{
		return;
	}
	else
	{
		//cout<<"\n无效输入，即将退出...";
		//Sleep(2000);
		system("cls");
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"\t\t\t\t";
		for(t=0;t<strlen(Display2);t++)
		{
		    Sleep(20);
			cout<<Display2[t];
		}
		Sleep(1500);
		return;
	}
	system("cls");
	cout<<"\n是否继续查找(Y/N)：";
	cin>>c;
	if(toupper(c)=='Y')
			{
				Query();
				return ;
			}
	else
		return ;
}
//销毁所有数据
void Manage::Destory()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |
            FOREGROUND_RED);//设置字体为红色
	char c,displaya[]="销毁成功...";
	system("cls");
	if(!person)
	{
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"\t\t\t\t";
		cout<<"当期没有任何数据...";Sleep(1500);
		return;
	}
	cout<<"\n\t\t\t** 销毁所有数据 **\n";
	cout<<"警告:\n这会销毁所有的数据信息!!!"<<endl;
	cout<<"\n★是否决定清除通讯录信息(Y/N):  ";
	cin>>c;
	if(toupper(c)!='Y')
		return;
	cout<<"\n★请再次确认(Y/N)：";
	cin>>c;
	if(toupper(c)!='Y')
		return;
	else
	{
		Person *p;
		p=person;
		while(p)
		{
			p=p->next;
			delete person;
			person=p;
		}
		person=0;
	//	ofstream fPerson("E:\\person.txt");
	//	fPerson.close();
	}
	system("cls");
	//cout<<"\n\n\t销毁成功...";
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"\t\t\t\t";
	for(t=0;t<strlen(displaya);t++)
	{
	    Sleep(20);
		cout<<displaya[t];
	}
	Sleep(2000);
}
//按ID删除职工数据
void Manage::DeleteID(string ID)
{
	//查找要删除的结点
	Person *p1=person,*p2;
	char c,displaya[]="删除成功...";
	while(p1)
	{
		if(p1->Num==ID)
			break;
		else
		{
			p2=p1;
			p1=p1->next;
		}
	}
	//删除结点
	if(p1!=NULL)//若找到结点，则删除
	{
		cout<<"\n所要删除的职工的信息如下:\n"<<endl;
		OutputAll(p1);
		cout<<"\n确定是否删除(Y/N): ";
		cin>>c;
		if(toupper(c)!='Y')
			return;
	//	system("pause");
		if(p1==person) //若要删除的结点是第一个结点
		{
			person=p1->next;
			delete p1;
		}
		else //若要删除的结点是后续结点
		{
			p2->next=p1->next;
			delete p1;
		}
		system("cls");
		//cout<<"删除成功..."<<endl;
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"\t\t\t\t";
	for(t=0;t<strlen(displaya);t++)
	{
	    Sleep(20);
		cout<<displaya[t];
	}
	Sleep(2000);
	system("cls");
		cout<<"\n是否继续删除(Y/N)：";
		cin>>c;
		if(toupper(c)=='Y')
			{
				Delete();
				return ;
			}
		else
			return ;
	}
	else //未找到结点
	{
		system("cls");
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"\t\t\t\t";
		for(t=0;t<strlen(Display3);t++)
		{
		    Sleep(20);
			cout<<Display3[t];
		}
		Sleep(1500);
	}
	//getch();
}
//按姓名删除职工信息
void Manage::DeleteName(char Name[])
{
	//查找要删除的结点
	Person *p1=person,*p2;
	char c,displaya[]="删除成功...";
	while(p1)
	{
		if(strcmp(p1->Name,Name)==0)
			break;
		else
		{
			p2=p1;
			p1=p1->next;
		}
	}
	//删除结点
	if(p1!=NULL)//若找到结点，则删除
	{
		cout<<"所要删除的职工的信息如下:\n"<<endl;
		OutputAll(p1);
		cout<<"确定是否删除(Y/N): ";
		cin>>c;
		if(toupper(c)!='Y')
			return;
	//	system("pause");
		if(p1==person) //若要删除的结点是第一个结点
		{
			person=p1->next;
			delete p1;
		}
		else //若要删除的结点是后续结点
		{
			p2->next=p1->next;
			delete p1;
		}
		system("cls");
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"\t\t\t\t";
	for(t=0;t<strlen(displaya);t++)
	{
	    Sleep(20);
		cout<<displaya[t];
	}
	Sleep(2000);
	system("cls");
		cout<<"\n是否继续删除(Y/N)：";
		cin>>c;
		if(toupper(c)=='Y')
			{
				Delete();
				return ;
			}
		else
			return ;
	}
	else //未找到结点
	{
		system("cls");
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"\t\t\t\t";
		for(t=0;t<strlen(Display3);t++)
		{
		    Sleep(20);
			cout<<Display3[t];
		}
		Sleep(1500);
	}
	//cout<<"\n未找到该职工...";
	//getch();
}
//删除职工信息
void Manage::Delete()
{
	system("cls");
	string Num;
	int a;
	char Name[20],choice[10],choice1[10]="1",choice2[10]="2",choice3[10]="3";
	char display[]="1. 按ID号进行查找删除  2. 按姓名进行查找删除  3. 退出\n\n您的选择(请选择1、2、或者3)：";
	cout<<"\n\t\t\t***删除职工***"<<endl;
	cout<<endl;
	//cout<<"\n1. 按ID号进行查找删除  2. 按姓名进行查找删除  3. 退出"<<endl;
	//cout<<"\n您的选择(请选择1、2、或者3)：";
	for(a=0;a<strlen(display);a++)
	{
		Sleep(2);
		cout<<display[a];
	}
	cin.sync();
	cin.getline(choice,10,'\n');
	if(strcmp(choice,choice1)==0)
	{
		cout<<"\n请输入职工ID：";
		cin>>Num;
		DeleteID(Num);
		return;
	}
	else if(strcmp(choice,choice2)==0)
	{
		cout<<"\n请输入职工姓名：";
		cin.sync();
		cin.getline(Name,20,'\n');
		DeleteName(Name);
		return;
	}
	else if(strcmp(choice,choice3)==0) return;
	else
	{
		//cout<<"\n无效输入，即将退出...";Sleep(2000);
		system("cls");
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"\t\t\t\t";
		for(t=0;t<strlen(Display2);t++)
		{
		    Sleep(20);
			cout<<Display2[t];
		}
		Sleep(1500);
		return;
	}
}








//添加职工
void Manage::Add()
{
	system("cls");
	Person *p,*p2; //新结点指针
	string Num;//职工工号
	char Name[20];//职工姓名
	int BaSalary,DuSalary,Allowance,MeInsurance,AcFund,AllSalary;
	char c;
	cout<<"\n\t\t***添加联系人***";
	cout<<endl;
	cout<<"\n添加后将自动按照ID从小到大排序...";
	cout<<"\n输入职工ID(四位数): ";




	cin>>Num;//输入id
	cout<<endl;





		Person *p1;//新结点指针
		p1=person;//??????
////////////////////查找账号是否存在//////////////////////////////////////
		while(p1)//从第一个账号开始查起
		{
			if(p1->Num==Num)
			{
				break;//如果查到，则退出循环
			}
			else
			{
				p1=p1->next;//若到链表尾还没有找到也退出
			}
		}
		if(p1!=NULL)//???无论怎么样都会执行？
		{
			cout<<"该职工工号已存在,是否修改该职工信息(Y/N)：";
			cin>>c;
			if(toupper(c)=='Y')
			{
				cout<<"该职工信息为："<<endl;
				Find(Num);
				cout<<endl;
				ModifyID(Num);
				return ;
			}
			else
				return ;
		}

////////////////////////////////////////////////////////////////////


		try
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |
            FOREGROUND_RED);//设置字体为红色
	cout<<"输入姓名(四个字母就好)：";
	cin.sync();
	cin.getline(Name,20,'\n');
	cout<<"\n输入基本工资(只能输入整数)：";
	cin.sync();
	cin>>BaSalary;
	cout<<"\n输入职务工资(只能输入整数)：";
	cin>>DuSalary;
	cout<<"\n输入岗位津贴(只能输入整数)：";
	cin>>Allowance;
	cout<<"\n输入医疗保险(只能输入整数)：";
	cin>>MeInsurance;
	cout<<"\n输入公积金(只能输入整数)：";
	cin>>AcFund;
	AllSalary=(BaSalary+DuSalary+Allowance+MeInsurance+AcFund);
	Sleep(50);
	cout<<"\n职工总工资为："<<AllSalary<<endl;
	cout<<endl;
	system("pause");
	p=new Person(Num,Name,BaSalary,DuSalary,Allowance,MeInsurance,AcFund,AllSalary);
	p->next=0;
	//职工信息结点加入链表
	if(person) //若已经存在结点
	{
		p2=person;
		while(p2->next) //查找尾结点
		{
			p2=p2->next;
		}
		p2->next=p; //连接
	}
	else //若不存在结点(表空)
	{
		person=p; //连接
	}
	system("cls");
	cout<<"\t\t\t   ***添加成功***\n"<<endl;
	cout<<"是否继续添加(Y/N)：";
	cin>>c;
	if(toupper(c)=='Y')
			{
				Add();
				return ;
			}
	else
		return ;//return 到哪里？/////////////////////////////////////////////////
		}
		catch(...)/////
		{
			cout<<"\n工资请以数字形式输入...";
			Add();
		}
}
//从磁盘读取数据
void Manage::Load()
{
	ifstream fPerson;
	Person *p;
	string Num;//职工工号
	char Name[20];//职工姓名
	int BaSalary,DuSalary,Allowance,MeInsurance,AcFund,AllSalary;
	fPerson.open("c:\\person.txt",ios::in);
	fPerson>>Num>>Name>>BaSalary>>DuSalary>>Allowance>>MeInsurance>>AcFund>>AllSalary;
	while(fPerson.good())
	{
		p=new Person(Num,Name,BaSalary,DuSalary,Allowance,MeInsurance,AcFund,AllSalary);
		p->next=0;//职工节点加入链表
		if(person)//若节点已经存在
		{
			Person *p1=person;
			while(p1->next) p1=p1->next;//查找尾节点
			p1->next=p;//连接
			//此处的 p1->next 不能换成 p1，只能用 p1->next。否则会出错!
			//若用 p1，则只能读取到首个数据元素，其余的不能读取!
		}
		else //若不存在节点
			person=p;//连接
		fPerson>>Num>>Name>>BaSalary>>DuSalary>>Allowance>>MeInsurance>>AcFund>>AllSalary;
	}
	fPerson.close();
}
//数据写入到磁盘
void Manage::Save()
{
	ofstream fPerson("c:\\Person.txt",ios::out);
	Person *p=person;
	while(p)
	{
		fPerson<<p->Num<<" "<<p->Name<<" "<<p->BaSalary<<" "<<p->DuSalary<<" "<<p->Allowance<<" "<<p->MeInsurance<<" "<<p->AcFund<<" "<<p->AllSalary<<endl;
		//数据内容写入到磁盘
		p=p->next;
	}
	fPerson.close();
	system("cls");
	cout<<"\n\t\t**保存成功**"<<endl;
	cout<<"\n数据保存在( c:\\Person.txt )中...";Sleep(5000);
}
//预览职工信息
void Manage::Look()
{
		//设置字体颜色
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |
            FOREGROUND_RED | FOREGROUND_GREEN);
	system("cls");
	Person *p=person,*q=person;
	int count=0,a;
	char display[]="1.查询详细信息   2.查看全部详细信息  3.退出\n\n您的选择(请选择1、2、或者3)：";
	char display1[]="\n尚未创建职工数据信息，是否创建(Y/N)：";
	char c,choice[10],choice1[10]="1",choice2[10]="2",choice3[10]="3";
	if(p)
	{
		cout<<"\n\t\t**预览**"<<endl<<endl;
	}
	while(p)
	{
		Sleep(50);
		cout<<"ID: "<<p->Num<<"\t姓名: "<<p->Name<<endl;
		count++;
		p=p->next;
	}
	if(count)
	{
		cout<<"\n共计 "<<count<<" 个职工..."<<endl;
		system("pause");system("cls");
		//cout<<"\n1.查询详细信息   2.查看全部详细信息  3.退出"<<endl;
		//cout<<"\n您的选择(请选择1、2、或者3)：";
		cout<<endl;
		for(a=0;a<strlen(display);a++)
		{
			Sleep(5);
			cout<<display[a];
		}
		cin.sync();
		cin.getline(choice,10,'\n');
		if(strcmp(choice,choice1)==0)
		{
			Query();
			return;
		}
		else if(strcmp(choice,choice2)==0)
		{
			system("cls");
			cout<<"ID   |"<<"  姓名  |"<<"基本工资|"<<"职务工资|"<<"岗位津贴|"<<"医疗保险|"<<"公积金|"<<"总工资"<<endl;
			cout<<endl;
			while(q)
			{
				Sleep(50);
				cout<<q->Num<<"\t"<<q->Name<<" \t  "<<q->BaSalary<<"\t  "<<q->DuSalary<<"  \t   "<<q->Allowance<<"\t    "<<q->MeInsurance;
				cout<<"\t    "<<q->AcFund<<"\t    "<<q->AllSalary<<endl;
				cout<<endl;
				//OutputAll(q);
				q=q->next;
			}
			cout<<"\n共计 "<<count<<" 个职工..."<<endl;
			cout<<endl;
			system("pause");
		}
		else if(strcmp(choice,choice3)==0) return;
		else
		{
			//cout<<"\n无效输入，即将退出...";Sleep(1000);
			system("cls");
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"\t\t\t\t";
		for(t=0;t<strlen(Display2);t++)
		{
		    Sleep(20);
			cout<<Display2[t];
		}
		Sleep(1500);
			return;
		}
	}
	else
	{
		//cout<<"\n尚未创建职工数据信息，是否创建(Y/N)：";
		cout<<endl;
		for(a=0;a<strlen(display);a++)
		{
			Sleep(5);
			cout<<display[a];
		}
		cin>>c;
			if(toupper(c)=='Y')
			{
				Add();
				return;
			}
			else
				return ;
	}
}