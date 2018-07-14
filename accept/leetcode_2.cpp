/* Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
   Output: 7 -> 0 -> 8
   Explanation: 342 + 465 = 807. */
#include <iostream>
#include <vector>

using namespace std;


typedef struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
}ListNode;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = (ListNode *)malloc(sizeof(ListNode));
        head->next = NULL;
        ListNode *p = head;
        int flag = 0;
        int val =0;
        while(l1!=NULL&&l2!=NULL)
        {
            ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
            temp->next = NULL;
            val = l1->val + l2->val +flag;
            if(val >=10)
            {
                temp->val = val%10;
                flag = 1;
            }else
            {
                temp->val = val;
                flag = 0;
            }
            p->next = temp;
            p = p->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1!=NULL)
        {
            ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
            temp->next = NULL;
            val = l1->val + flag;
            if(val >=10)
            {
                temp->val = val%10;
                flag = 1;
            }else
            {
                temp->val = val;
                flag = 0;
            }
            p->next = temp;
            p = p->next;
            l1 = l1->next;
        }
        while(l2!=NULL)
        {
            ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
            temp->next = NULL;
            val = l2->val + flag;
            if(val >=10)
            {
                temp->val = val%10;
                flag = 1;
            }else
            {
                temp->val = val;
                flag = 0;
            }
            p->next = temp;
            p = p->next;
            l2 = l2->next;
        }
        if(flag ==1 )
        {
            ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
            temp->next = NULL;
            temp->val = 1;
            p->next = temp;
            p = p->next;
            flag = 0;
        }
        head = head->next;
        p =head;
        while(p!=NULL)
        {
            printf("%d",p->val);
            if(p->next!=NULL)
            {
                printf(" -> ");
            }
            
            p = p->next;
        }
       return head;
    }
    
};

int main()
{
    Solution s;
    ListNode *head1,*head2;
    head1 = (ListNode *)malloc(sizeof(ListNode));
    head2 = (ListNode *)malloc(sizeof(ListNode));
    
    ListNode n1 = ListNode(2);
    ListNode n2 = ListNode(4);
    ListNode n3 = ListNode(3);
    ListNode n4 = ListNode(5);  
    ListNode n5 = ListNode(6);
    ListNode n6 = ListNode(4);
    head1 = &n1;
    head1->next=&n2;
    head1->next->next=&n3;


    head2 =&n4;
    head2->next=&n5;
    head2->next->next=&n6;
    

    
    
    s.addTwoNumbers(head1,head2);
    return 0;
}