#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
#include<fstream>
#define FILENAME "empFile.txt"


/*管理类：
    1.与用户沟通菜单界面
    2.对职工增删改查等功能
    3.对文件进行写入，读取
*/ 



class WorkManager{
    public:
         int m_EmpNum;

         bool m_FileIsEmpty;

         int get_EmpNum();

         void init_Emp();

         void Show_Emp();

         void Del_Emp();

        void Sort_Emp();

         int IsExist(int id);

         Worker** m_EmpArray;

        WorkManager();

        void AddEmp();
        
        void ShowMenu();

        void exitSystem();

        void save();
        
        ~WorkManager();


};