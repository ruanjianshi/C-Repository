#pragma once
#include<iostream>
using namespace std;
#include "worker.h"

class Employee:public Worker
{
public:
    Employee(int Id,string name,int dId);

    virtual void ShowInfo();

    virtual string GetDeptName();
};