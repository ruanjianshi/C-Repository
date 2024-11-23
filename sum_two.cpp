#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<functional>
#include<algorithm>


using namespace std;

struct ListNode {
    int val;
    ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        // 反转链表 l1
        ListNode* mid1 = l1;
        while(mid1) {
            ListNode* temp = mid1->next;
            mid1->next = head;
            head = mid1;
            mid1 = temp;
        }
        l1 = head;

        // 反转链表 l2
        head = nullptr;
        mid1 = l2;
        while(mid1) {
            ListNode* temp = mid1->next;
            mid1->next = head;
            head = mid1;
            mid1 = temp;
        }
        l2 = head;

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        int carry = 0;

        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }

        return dummy->next; // 返回结果链表的头
    }
};

class Solution_s {
public:
    int lengthOfLongestSubstring(string s) {
        int count = 0;
        int ar[s.size()]={};
        char s_l = s.at(0);
        priority_queue<int,vector<int>,less<int>> pq;
        for(int i = 0;i<s.size();i++)
        {
         for(int j=i+1;j != '\0';j++)
         {
            if(s_l != s.at(j))
            {
                count++;
            }
            else if(s_l == s.at(j))
            {
                break;
            }
        
         }
            pq.push(count) ;
            count = 0;
     
        }
        return pq.top();

    }
};

int main() {
    Solution st;
    Solution_s ss;
    int a1 = ss.lengthOfLongestSubstring("abcabc");
    cout<<a1<<endl;
    ListNode* a,*b,*c;
    a = new ListNode(2);
    a->next = new ListNode(8);

    b = new ListNode(8);
    b->next = new ListNode(5);

    c = st.addTwoNumbers(a, b);

    // 打印结果链表
    while (c) {
        cout << c->val << " ";
        c = c->next;
    }
    cout << endl;

    system("pause");
    return 0;
}
