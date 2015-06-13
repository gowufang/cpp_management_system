//main函数
int main()
{
	Manage M;
	int a=1,b=1,d=0,i=1;//用于控制一段语句的执行
	char exit='N',c;




	char choice[10],choice1[10]="1",choice2[10]="2",choice3[10]="3",choice4[10]="4";//sehnmeyisi
	char choice5[10]="5",choice6[10]="6",choice7[10]="7",choice8[10]="8",choice9[10]="9";
	char choice10[10]="10",display[]="您的选择( 代码 )：",display2[]="排序成功...";
	char Display[]="正在载入，请稍候...";
    char Display1[]="正在退出程序，请稍候...";






	do
	{
		  //设置字体为绿色
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |
            FOREGROUND_GREEN);
		system("cls");
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		cout<<endl<<endl<<endl<<endl<<endl<<endl;
		for(i=1;a&&i<41;i++)//a确保执行一次
		{
      		Sleep(15);
    		cout<<"> ";
		}
		system("cls");
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		while(a)
		{
			a=0;//确保执行一次
			cout<<"\n\t\t\t\t360小助手提醒您：";
			cout<<endl;
			cout<<"\n\t\t\t\t您此次启动共用时3秒!击败了全国99.99999%的电脑..."<<endl;
			cout<<"\n\t\t\t\t\t    ★★★★★神机!!!"<<endl;
			cout<<"\n\t\t\t\t显示了您平时良好的使用习惯，请继续保持!";
			Sleep(3000);//暂停3秒
			//system("pause");
			/*system("cls");
			cout<<endl;cout<<endl;cout<<endl;cout<<endl;
			cout<<"\n\t\t\t       2B2          B2B2B2B       ";Sleep(50);
			cout<<"\n\t\t\t     2B2B2B2        B2B    B2B    ";Sleep(50);
			cout<<"\n\t\t\t  2B2     2B2       B2B      B2B  ";Sleep(50);
			cout<<"\n\t\t\t            2B2     B2B    B2B    ";Sleep(50);
			cout<<"\n\t\t\t            2B2     B2B B2B       ";Sleep(50);
			cout<<"\n\t\t\t          2B2       B2B2B2B2B     ";Sleep(50);
			cout<<"\n\t\t\t        2B2         B2B    B2B    ";Sleep(50);
			cout<<"\n\t\t\t      2B2           B2B      B2B  ";Sleep(50);
			cout<<"\n\t\t\t    2B2             B2B        B2B";Sleep(50);
			cout<<"\n\t\t\t  2B2               B2B        B2B";Sleep(50);
			cout<<"\n\t\t\t B2                 B2B      B2B  ";Sleep(50);
			cout<<"\n\t\t\t2B2B2B2B2B2B2B2B    B2B    B2B    ";Sleep(50);
			cout<<"\n\t\t\t 2B2B2B2B2B2B2B2B   B2B2B2B2B     ";Sleep(2000);*/
		}
		//system("pause");


		/**
		*****************
		**********************
		*******************************/
		while(!a&&!b&&!d)
		{
		system("cls");
		d=1;//确保执行一次
		cout<<endl;
		cout<<"                                       菜  单                    "<<endl;Sleep(20);
		cout<<endl;
		cout<<"              ========================================================"<<endl;
		cout<<"              ★  ☆\t    1.添加联系人..............<1>    \t☆  ★"<<endl;Sleep(30);
		cout<<"              ★  ☆\t    2.预览联系人信息..........<2>    \t☆  ★"<<endl;Sleep(30);
		cout<<"              ★  ☆\t    3.查询联系人信息..........<3>    \t☆  ★"<<endl;Sleep(30);



		cout<<"              ★  ☆\t    4.修改联系人信息..........<4>    \t☆  ★"<<endl;Sleep(30);
		cout<<"              ★  ☆\t    5.删除联系人数据..........<5>    \t☆  ★"<<endl;Sleep(30);
		//cout<<"              ★  ☆\t    6.统计职工工资..........<6>    \t☆  ★"<<endl;Sleep(30);
		cout<<"              ★  ☆\t    7.保存职工数据..........<7>    \t☆  ★"<<endl;Sleep(30);
		cout<<"              ★  ☆\t    8.销毁所有数据..........<8>    \t☆  ★"<<endl;Sleep(30);
		cout<<"              ★  ☆\t    9.对联系人ID进行排序......<9>    \t☆  ★"<<endl;Sleep(30);//排序方式待修改
		cout<<"              ★  ☆\t    10.退出................<10>    \t☆  ★"<<endl;Sleep(30);
		cout<<"              ========================================================";
		cout<<endl;cout<<endl;
		//cout<<"\n\n请选择操作代码：";
		for(i=0;i<strlen(display);i++)///////
		{
			Sleep(20);
			cout<<display[i];//display[]="您的选择( 代码 )："
		}
		}








		while(b)
		{
		system("cls");
		a=0;//上面的while可以循环
		b=0;//上面的while可以循环
		cout<<endl;
		cout<<"                                       菜  单                    "<<endl;Sleep(20);
		cout<<endl;
		cout<<"              ";
		for(i=1;i<57;i++)
		{
			Sleep(10);
			cout<<"=";
		}
		cout<<endl;
		cout<<"              ★  ☆\t    1.添加联系人..............<1>    \t☆  ★"<<endl;Sleep(30);
		cout<<"              ★  ☆\t    2.预览联系人信息..........<2>    \t☆  ★"<<endl;Sleep(30);
		cout<<"              ★  ☆\t    3.查询联系人信息..........<3>    \t☆  ★"<<endl;Sleep(30);
		cout<<"              ★  ☆\t    4.修改联系人信息..........<4>    \t☆  ★"<<endl;Sleep(30);
		cout<<"              ★  ☆\t    5.删除联系人数据..........<5>    \t☆  ★"<<endl;Sleep(30);
		//cout<<"              ★  ☆\t    6.统计职工工资..........<6>    \t☆  ★"<<endl;Sleep(30);
		cout<<"              ★  ☆\t    7.保存联系人数据..........<7>    \t☆  ★"<<endl;Sleep(30);
		cout<<"              ★  ☆\t    8.销毁所有数据..........<8>    \t☆  ★"<<endl;Sleep(30);
		cout<<"              ★  ☆\t    9.对联系人ID进行排序......<9>    \t☆  ★"<<endl;Sleep(30);
		cout<<"              ★  ☆\t    10.退出................<10>    \t☆  ★"<<endl;Sleep(30);
		cout<<"              ";
		for(i=1;i<57;i++)
		{
			Sleep(5);
			cout<<"=";
		}
		cout<<endl;cout<<endl;
		//cout<<"\n\n请选择操作代码：";
		for(i=0;i<strlen(display);i++)
		{
			Sleep(20);
			cout<<display[i];
		}
		}
		cin.sync();    // cin.sync（）是用来清除缓存区的数据流的。
		cin.getline(choice,10,'\n');//getline()是定义在<string>中的一个行数，用于输入一行string，以enter结束。





		/////*****************************一共有十个选项，choice1到10****************************//////////
		if(strcmp(choice,choice1)==0)//一共有十个选项，choice1到10
		{
			M.Add();
			M.BubbleSort();
			system("cls");
			cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
			cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"\t\t\t\t";
			for(t=0;t<strlen(Display);t++)
			{
			Sleep(20);
			cout<<Display[t];//char Display[]="正在载入，请稍候...";

			}
			Sleep(700);
		}
		else if(strcmp(choice,choice2)==0)
		{
			M.Look();
			system("cls");
			cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
			cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"\t\t\t\t";
			for(t=0;t<strlen(Display);t++)
			{
			Sleep(20);
			cout<<Display[t];
			}
			Sleep(700);
		}
		else if(strcmp(choice,choice3)==0)
		{
			M.Query();
			system("cls");
			cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
			cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"\t\t\t\t";
			for(t=0;t<strlen(Display);t++)
			{
			Sleep(20);
			cout<<Display[t];
			}
			Sleep(700);
		}
		else if(strcmp(choice,choice4)==0)
		{
			M.Modify();
			system("cls");
			cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
			cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"\t\t\t\t";
			for(t=0;t<strlen(Display);t++)
			{
			Sleep(20);
			cout<<Display[t];
			}
			Sleep(700);
		}
		else if(strcmp(choice,choice5)==0)
		{
			M.Delete();
			M.BubbleSort();
			system("cls");
			cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
			cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"\t\t\t\t";
			for(t=0;t<strlen(Display);t++)
			{
			Sleep(20);
			cout<<Display[t];
			}
			Sleep(700);
		}
		else if(strcmp(choice,choice6)==0)
		{
			M.Statistics();
			system("pause");
		}
		else if(strcmp(choice,choice7)==0)
		{
			M.Save();
			system("cls");
			cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
			cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"\t\t\t\t";
			for(t=0;t<strlen(Display);t++)
			{
			Sleep(20);
			cout<<Display[t];
			}
			Sleep(1000);
		}
		else if(strcmp(choice,choice8)==0)
		{
			M.Destory();
			system("cls");
			cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
			cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"\t\t\t\t";
			for(t=0;t<strlen(Display);t++)
			{
			Sleep(20);
			cout<<Display[t];
			}
			Sleep(700);
		}
		else if(strcmp(choice,choice9)==0)
		{
			M.BubbleSort();
			if(M.BubbleSort())
			{
			//cout<<"\n\t排序成功..."<<endl;
				cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
			    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"\t\t\t\t";
				Sleep(500);
				for(t=0;t<strlen(display2);t++)
				{
					Sleep(30);
					cout<<display2[t];
				}
			}
			Sleep(2000);
			system("cls");
			cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
			cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"\t\t\t\t";
			for(t=0;t<strlen(Display);t++)
			{
			Sleep(20);
			cout<<Display[t];
			}
			Sleep(700);
		}
		else if(strcmp(choice,choice10)==0)
		{
			exit='Y';
		}
		else
		{
			system("cls");
			cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"\t\t\t  ";
			cout<<"无效输入，请重新选择...";
			Sleep(2000);
		}
		d=0;//上面的while可以循环????????????
	}while(exit!='Y');












	cout<<"\n保存您所有的操作(Y/N)：";
	cin>>c;
	if(toupper(c)=='Y')//C库函数int toupper(int c)将小写字母转换为大写。
	M.Save();
	system("cls");
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"\t\t\t  ";
    for(t=0;t<23;t++)
	{
		Sleep(20);
		cout<<Display1[t];
	}
	Sleep(2000);
	return 0;
}
