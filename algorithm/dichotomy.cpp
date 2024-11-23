#include<iostream>
#include<numeric>
#include<string>
#include<functional>
#include<algorithm>
#include<unordered_map>
#include<vector>
#include<queue>
#include<map>
#include<stack>
#include<list>

using namespace std;

#define ascend 1
#define descend 0

ostream& operator<<(ostream& os,const vector<int> &arr)
{
    for(int i = 0;i < arr.size();i++)
    {
        os<<arr[i]<<" ";
        if(!os) return os;
    }
    return os;
}

class DICHOTOMY
{

public:

    /*判断查找数组是否为顺序排序*/
    bool isSorted(const vector<int>&arr)
    {
        bool ascending = true;
        bool descending = true;

        for(int i = 0;i < arr.size() - 1;i++)
        {
            if(arr[i] < arr[i+1]) descending = false;
            if(arr[i+1] < arr[i]) ascending = false;
        }

        return ascending || descending;
    }
    /*（数组排序）参数sortMethodJudgment：1   升序    参数sortMethodJudgment：0   降序*/
    vector<int> sortArray(const vector<int>&arr,bool sortMethodJudgment)
    {
        vector<int> sortedArr = arr;
        if(sortMethodJudgment) sort(sortedArr.begin(),sortedArr.end());
        else sort(sortedArr.begin(),sortedArr.end(),greater<int>());
        return sortedArr;
    }
    /*判断该数组是升序或降序return 1：  升序    return:0    降序*/
    bool ascendOrDescend(const vector<int>&arr3)
    {
        for(int i = 0;i < arr3.size() - 1;i++)
        {
            if(arr3[i] < arr3[i+1]) return 1;
            else if(arr3[i] == arr3[i+1]) continue;
        }
        return 0;
    }
    /*（查找目标值函数）参数orderJudgmentBit:1   升序二分法查找     参数orderJudgmentBit:0   降序二分法查找*/
    bool FindBit(vector<int> arr2,int target,bool orderedJudgmentBit)
    {
        leftBit = 0;
        rightBit = arr2.size() - 1; 
        if(orderedJudgmentBit)  //升序二分法查找
        {    while (leftBit <= rightBit)
            {
                meditope = (leftBit + rightBit)/2;
                if(arr2[meditope] < target) leftBit = meditope + 1;
                else if (arr2[meditope] > target) rightBit = meditope - 1;
                else return 1;
            }
        }
        else    //降序二分法查找
        {
              while (leftBit <= rightBit)
            {
                meditope = (leftBit + rightBit)/2;
                if(arr2[meditope] < target) rightBit = meditope - 1;
                else if (arr2[meditope] > target) leftBit = meditope + 1;
                else return 1;  //找到目标值
            }

        }
        return 0;   //未找到目标值
    }

private:
    int leftBit = 0;
    int meditope = 0;
    int rightBit = 0;


};

void DichotomyWay(vector<int>& arr,int target,bool SelectSort = true)
{
    DICHOTOMY dctmW;
    if(dctmW.isSorted(arr))
    {
        if(dctmW.FindBit(arr,target,dctmW.ascendOrDescend(arr))) cout<<"目标值已找到"<<endl;
        else cout<<"该数组中不存在目标值"<<endl;
    }
    else
    {
        if(dctmW.FindBit(dctmW.sortArray(arr,SelectSort),target,dctmW.ascendOrDescend(dctmW.sortArray(arr,SelectSort)))) cout<<"目标值已找到"<<endl;
        else cout<<"该数组中不存在目标值"<<endl;
    }
    //cout<<dctmW.sortArray(arr,SelectSort)<<endl;
}


int main()
{
    vector<int> arr1 = {1,4,8,4,5,5,7,8,9,12,5,3,2};
    DichotomyWay(arr1,3,ascend);
    system("pause");
    return 0;
}



