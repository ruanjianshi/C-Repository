#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;


int a(int b)
{
    return (2);
}

class Person
{
    public:
        Person(string name,int age)
        {
            this->name = name;
            this->age = age;
        }
        string name;
        int age;

};

void myPrint(int val)
{
    cout<<val<<endl;
}

void test01()
{
    vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

 /*    vector<int>::iterator itBegin = v.begin();
    vector<int>::iterator itEnd = v.end();

    while (itBegin!=itEnd)
    {
        cout<<*itBegin<<endl;
        itBegin++;
    } */

   for_each(v.begin(),v.end(),myPrint);

    cout<<*v.begin()<<endl;

    for(vector<int>::iterator itBegin = v.begin();itBegin!= v.end();itBegin++)
    {
        cout<<*itBegin<<endl;
    }
    
}

/* void test02()
{
    vector<Person> v;

    Person p1("aa",10);
    Person p2("bb",20);
    Person p3("cc",30);
    Person p4("dd",40);


    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    for(vector<Person>::iterator itBegin = v.begin();itBegin!=v.end();itBegin++)
    {
        cout<<"姓名："<<(*itBegin).name<<endl;
        cout<<"年龄："<<(*itBegin).age<<endl;
    }
} */

/* void test03()
{
    vector<Person*> v;

    Person p1("aa",10);
    Person p2("bb",20);
    Person p3("cc",30);
    Person p4("dd",40);


    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);

    for(vector<Person*>::iterator itBegin = v.begin();itBegin!=v.end();itBegin++)
    {
        cout<<"姓名："<<(*(*itBegin)).name<<endl;
        cout<<"年龄："<<(*itBegin)->age<<endl;
    }

} */

void test04()
{
    vector<vector<int>> v;

    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;

    for(int i= 0;i<4;i++)
    {
        v1.push_back(i+1);
        v2.push_back(i+2);
        v3.push_back(i+3);
        v4.push_back(i+4);
    }

    v.push_back(v1);
       v.push_back(v2);
          v.push_back(v3);
             v.push_back(v4);

             for(vector<vector<int>>::iterator it = v.begin();it!=v.end();it++)
             {
                for(vector<int>::iterator id = (*it).begin();id!= (*it).end();id++)
                {
                    cout<<*id;
                }
             }
}


void test(int a, int b)
{
    if(a>b) cout<<a;
    else if (a==b)
    {
        cout<<b<<endl;
    }
    
}



int main()
{
    //test01();
   // test02();
   // test03();
    test(3,3);
	string key="123";
	int value=4;
	unordered_map<string, int> unomap;//创建一个key为string类型，value为int类型的unordered_map
	unomap.emplace(key, value);//使用变量方式，插入一个元素
	unomap.emplace("456", 7);//也可以直接写上key和value的值
	cout<<unomap["123"];//通过key值来访问value

	cout<<endl;
	for(auto x:unomap)//遍历整个map，输出key及其对应的value值
		cout<<x.first<<"  "<<x.second<<endl;

	for(auto x:unomap)//遍历整个map，并根据其key值，查看对应的value值
		cout<<unomap[x.first]<<endl;
   test04();
    system("pause");
    return 0;
}