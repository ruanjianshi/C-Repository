
#include"workerManager.h"
#include"employee.h"
#include"boss.h"
#include"manager.h"

WorkManager::WorkManager()
{
	int num = this->get_EmpNum();
	cout<<"职工个数为："<<num<<endl;
	this->m_EmpNum = num;

	this->m_EmpArray = new Worker*[this->m_EmpNum];

	init_Emp();


	ifstream ifs;
	ifs.open(FILENAME,ios::in);

	if(!ifs.is_open())
	{
		cout<<"文件不存在"<<endl;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;

		this->m_EmpArray = NULL;
		ifs.close();
		return;
	}

		//文件存在，并且没有记录
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空!" << endl;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;
		this->m_EmpArray = NULL;
		ifs.close();
		return;
	}

}

WorkManager::~WorkManager()
{
	if(this->m_EmpArray!=NULL)
	{
		delete[] this->m_EmpArray;
	}

}


void WorkManager::ShowMenu()
{

	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;

}

void WorkManager::exitSystem()
{
	cout<<"欢迎下次使用"<<endl;
	system("pause");
	exit(0);
}

void WorkManager::AddEmp()
{
	cout << "请输入增加职工数量： " << endl;

	int addNum = 0;
	cin >> addNum;


	if(addNum>0)
	{
		int newSize = this->m_EmpNum + addNum;

		Worker** newSpace = new Worker*[newSize];

		if(this->m_EmpArray!=NULL)
		{
			for(int i = 0;i<this->m_EmpNum;i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		for(int i = 0;i<addNum;i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "请输入第 " << i + 1 << " 个新职工编号：" << endl;
			cin >> id;


			cout << "请输入第 " << i + 1 << " 个新职工姓名：" << endl;
			cin >> name;


			cout << "请选择该职工的岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
				case 1:
					worker = new Employee(id,name,1);
				break;
				case 2:
					worker = new Manager(id,name,2);
				break;
				case 3:
					worker = new Boss(id,name,3);
				break;
				default:
				break;
		
			}

			newSpace[this->m_EmpNum + i] = worker;
		
		}

		delete[] this->m_EmpArray;

		this->m_EmpArray = newSpace;

		this->m_EmpNum = newSize;

		this->m_FileIsEmpty = false;

		cout<<"成功添加"<<addNum<<"名新职工"<<endl;

		this->save();
	}	
		else
		{
			cout<<"输入有误"<<endl;
		}

		system("pause");
		system("cls");

	
}

void WorkManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME,ios::out);

	for(int i=0;i<this->m_EmpNum;i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " " 
			<< this->m_EmpArray[i]->m_Name << " " 
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}

	ofs.close();
}

int WorkManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in);

	int id;
	string name;
	int dId;

	int num = 0;

	while (ifs>>id&&ifs>>name&&ifs>>dId)
	{
		num++;
	}

	ifs.close();
	return num;
	
}

void WorkManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in);

	int id;
	string name;
	int dId;

	int index = 0;
	while(ifs>>id&&ifs>>name&&ifs>>dId)
	{
		Worker*worker =NULL;

		if(dId ==1)
		{
			worker = new Employee(id,name,dId);
		}
		else if(dId ==2)
		{
			worker = new Manager(id,name,dId);
		}
		else
		{
			worker = new Boss(id,name,dId);
		}

		this->m_EmpArray[index] = worker;
		index++;
	}
}

void WorkManager::Show_Emp()
{
	if(this->m_FileIsEmpty)
	{
		cout<<"文件不存在或记录为空！"<<endl;

	}
	else
	{
		for(int i=0;i<m_EmpNum;i++)
		{
			this->m_EmpArray[i]->ShowInfo();
		}
	}
	system("pause");
	system("cls");
}

int WorkManager::IsExist(int id)
{
	int index = -1;

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			index = i;

			break;
		}
	}

	return index;
}

//删除职工
void WorkManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		//按职工编号删除
		cout << "请输入想要删除的职工号：" << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);

		if (index != -1)  //说明index上位置数据需要删除
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;

			this->save(); //删除后数据同步到文件中
			cout << "删除成功！" << endl;
		}
		else
		{
			cout << "删除失败，未找到该职工" << endl;
		}
	}
	
	system("pause");
	system("cls");
}

//排序职工
void WorkManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式： " << endl;
		cout << "1、按职工号进行升序" << endl;
		cout << "2、按职工号进行降序" << endl;

		int select = 0;
		cin >> select;


		for (int i = 0; i < m_EmpNum; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; j < m_EmpNum; j++)
			{
				if (select == 1) //升序
				{
					if (m_EmpArray[minOrMax]->m_Id > m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else  //降序
				{
					if (m_EmpArray[minOrMax]->m_Id < m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
			}

			if (i != minOrMax)
			{
				Worker * temp = m_EmpArray[i];
				m_EmpArray[i] = m_EmpArray[minOrMax];
				m_EmpArray[minOrMax] = temp;

			}

		}

		cout << "排序成功,排序后结果为：" << endl;
		this->save();
		this->Show_Emp();
	}

}