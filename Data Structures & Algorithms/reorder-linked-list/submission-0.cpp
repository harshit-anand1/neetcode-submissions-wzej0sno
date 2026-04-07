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
       ListNode* temp = head;
       ListNode* slow = head;
       ListNode* fast = head;

       while(slow!=NULL && fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;

       }
       
       ListNode* secPart = slow->next;
       slow->next = NULL;

       ListNode* prev=NULL;
       ListNode* next;
       
       while(secPart!=NULL){
            next = secPart->next;
            secPart->next = prev;
            prev = secPart;
            secPart = next;
       }
       secPart = prev;


       ListNode* temp2;
       ListNode* temp3;
       while(secPart!=NULL){
            temp2 = temp->next;
            temp3 = secPart->next;
            temp->next = secPart;
            secPart->next =temp2;
            temp =temp2;
            secPart = temp3;

       }

       //return head;

    }
};
