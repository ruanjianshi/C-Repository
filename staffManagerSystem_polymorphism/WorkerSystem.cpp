#include<iostream>
using namespace std;
#include"workerManager.h"
#include"worker.h"
#include"employee.h"



int main()
{
    WorkManager wm;
    wm.ShowMenu();
    int choice =0;
    Employee ee(1,"he",2);
    ee.ShowInfo();
    while(true)
    { 
        cout<<"请输入你的选择："<<endl;
        cin>>choice;
        switch(choice)
        {
            case 0:
            wm.exitSystem();
            break;

            case 1:
            wm.AddEmp();
            break;

            case 2:
            wm.Show_Emp();
            break;

            case 3:
            wm.Del_Emp();
            break;

            case 4:
            wm.ShowMenu();
            break;

            case 5:
            wm.ShowMenu();
            break;

            case 6:
            wm.ShowMenu();
            break;

            case 7:
            wm.ShowMenu();
            break;

            default:
                system("cls");
            break;

        }
    }
    

    system("pause");

    return 0;

}