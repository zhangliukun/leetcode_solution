/* Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.
 */
#include <iostream>
#include <limits>
using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = (ListNode *)malloc(sizeof(ListNode));
        head ->next = NULL;
        ListNode *p = head;
        while(l1!=NULL&&l2!=NULL)
        {
            int min = 0;
            if(l1->val<l2->val)
            {
                min = l1->val;
                l1=l1->next;
            }else{
                min = l2->val;
                l2 = l2->next;
            }
            ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
            temp->val = min;
            temp->next = NULL;
            p->next = temp;
            p=p->next;
        }
        if(l1!=NULL){
            p->next = l1;
        }
        if(l2!=NULL){
            p->next = l2;
        }
        return head->next;
    }
    
};

int main()
{
    ListNode l1(1);
    ListNode la(2);
    ListNode lb(4);
    l1.next = &la;
    la.next = &lb;
    

    ListNode l2(1);
    ListNode lc(3);
    ListNode ld(4);
    l2.next = &lc;
    lc.next = &ld;
    


    Solution s;
    ListNode * result= s.mergeTwoLists(&l1,&l2);
    while(result!=NULL)
    {
        cout<<result->val<<endl;
        result = result->next;
    }
    return 0;
}