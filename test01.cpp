#include<iostream>
#include<vector>
#include<list>
#include <unordered_map>
#include<string>
#include<deque>
#include<functional>
#include<algorithm>


using namespace std;

/* class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end()) {
                return {it->second, i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
}; */
/* class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2) {
            return s;
        }

        int maxLen = 1;
        int begin = 0;
        // dp[i][j] 表示 s[i..j] 是否是回文串
        vector<vector<int>> dp(n, vector<int>(n));
        // 初始化：所有长度为 1 的子串都是回文串
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        // 递推开始
        // 先枚举子串长度
        for (int L = 2; L <= n; L++) {
            // 枚举左边界，左边界的上限设置可以宽松一些
            for (int i = 0; i < n; i++) {
                // 由 L 和 i 可以确定右边界，即 j - i + 1 = L 得
                int j = L + i - 1;
                // 如果右边界越界，就可以退出当前循环
                if (j >= n) {
                    break;
                }

                if (s[i] != s[j]) {
                    dp[i][j] = false;
                } else {
                    if (j - i < 3) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }

                // 只要 dp[i][L] == true 成立，就表示子串 s[i..L] 是回文，此时记录回文长度和起始位置
                if (dp[i][j] && j - i + 1 > maxLen) {
                    maxLen = j - i + 1;
                    begin = i;
                }
            }
        }
        return s.substr(begin, maxLen);
    }
};

 *//* 
class Solution {
public:
    string convert(string s, int numRows) {
        string v1[numRows][s.size()];
        vector<string> v2;
        int i = 0;
        int j = 0;
        int le = 0;
        int count = 0;
        string b = "";
        if(numRows <=1 && s.size() <= 1)
        {
            return s;
        }
        while(s[count])
        {
        for(i;i<numRows;i++)
        {
            if(!s[count]) break;
            v1[i][le] = s[count];
            count++;
            
        }
        le++;
       
        for(i -= 2;i>0;i--)
        {
            if(!s[count]) break;
            v1[i][j+1] = s[count];
            j++;
            count++;
            le++;
        }
        j++;
        }
        for(int i = 0;i<numRows;i++)
        {
            int j = 0;
            int a = le;
            while(a)
            {
                b.append(v1[i][j]);
                j++;
                a--;
            }
        }
        return b;
    }
};
 */
/* class Solution {
public:
    int myAtoi(string s) {
        long int res = 0;
        for(int i = 0;i<s.size();i++)
        {
            cout<<s[i]<<endl;
            cout<<atoi(&s[i])/(10*(s.size()-1))<<endl;
            if(s[i] == '-')
            {res = -res;
            continue;}
            
            if(s[i] != ' ')
            res = res*10+int(s[i]);
            else if(!isdigit(s[i]) && s[i] != ' ')
            return res;
          
        }

      //  if(res > (~(1<<31)))
       // return (~(1<<31));
        //else if(res<-2^31)
        //return -2^31;

        return res;
    }
}; */


class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        deque<int> sum;
        unordered_map<int,int> hash;
        for(int i = 0;i < len;i++)
        {
            hash[i] = i;
        }
        for(int i = 0;i<len;i++)
        {
            for(int j = i+1;j<len;j++)
            {
                auto it = hash.find(height[i]);
                sum.push_back(min(height[i],height[j])*(j-i));
            }
        }
      sort(sum.begin(),sum.end(),greater<int>());
      return sum.at(0);
    }
};
int main(){
 /*     
    vector<int> v1 = {3,5,6,7,4,8},v2;
    
    Solution hash;
    v2 = hash.twoSum(v1,10); 
    vector<int>::iterator it = v2.begin();
    cout<<*it<<" "<<*(it+1)<<endl; */
    Solution sl;
    std::vector<int> heights = {1,8,6,2,5,4,8,3,7};
    cout << sl.maxArea(heights);

    
    system("pause");
    return 0;
}