/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
       ListNode* first = head;
       ListNode* slow = head;
       ListNode* fast = head;

       while(slow!=NULL && fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;

       }
       
       ListNode* second = slow->next;
       slow->next = NULL;

       ListNode* prev=NULL;
       ListNode* next;
       
       while(second!=NULL){
            next = second->next;
            second->next = prev;
            prev = second;
            second = next;
       }
       second = prev;


       ListNode* temp1;
       ListNode* temp2;
       while(second!=NULL){
            temp1 = first->next;
            temp2 = second->next;
            first->next = second;
            second->next =temp1;
            first =temp1;
            second = temp2;

       }

       //return head;

    }
};
