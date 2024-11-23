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
#include<utility>

using namespace std;

ostream& operator<<(ostream& os,const vector<int> &arr)
{
    for(int i = 0;i < arr.size();i++)
    {
        os<<arr[i]<<" ";
        if(!os) return os;
    }
    return os;
}

class QUICKSORT
{

public:
    QUICKSORT(vector<int>& arr)
    {
        flagSort = this->isSorted(arr);
        IsAorD = (flagSort) ? (this->ascendOrDescend(arr)) : false ? true : false;
    }

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

      /*判断该数组是升序或降序return:1  升序    return:0    降序*/
    bool ascendOrDescend(const vector<int>&arr3)
    {
        for(int i = 0;i < arr3.size() - 1;i++)
        {
            if(arr3[i] < arr3[i+1]) return 1;
            else if(arr3[i] == arr3[i+1]) continue;
        }
        return 0;
    }

    vector<int> SortBit(vector<int> arr)
    {
        vector<int> tempArr(arr.size());
        while(left_p <= right_p)
        {
            
        }

    }


    ~QUICKSORT()
    {
        if(IsAorD) cout<<"该数组已经排好序:升序"<<endl;
        else if(flagSort || IsAorD) cout<<"该数组已经排好序：降序"<<endl;
        else cout<<"该数组为乱序"<<endl;
    }
private:
    int flagSort = 0;
    int IsAorD = 0;
    int left_p = 0;
    int right_p = 0;
    int Base_bit = 0;
};






int main()
{
    vector<int> arr1 = {1,4,8,4,5,5,7,8,9,12,5,3,2};
    QUICKSORT test(arr1);
    system("pause");
    return 0;
}



