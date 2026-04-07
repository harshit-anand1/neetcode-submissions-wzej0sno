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


    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev=NULL;
        ListNode* next;

        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev=curr;
            curr=next;
        }

        return prev;
        
    }
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* first = head;

        while(slow!=NULL &&fast!=NULL && fast->next!=NULL){
            slow= slow->next;
            fast= fast->next->next;

        }

        ListNode* sec = slow->next;
        

        ListNode* second = reverse(sec);
        slow->next = NULL;
        //ListNode* temp2 = secHead;


        ListNode* temp1;
        ListNode* temp2;
        while(second!=NULL){
            temp1= first->next;
            temp2= second->next;

            first->next = second;
            second->next = temp1;
            first = temp1;
            second = temp2;

        }

        
    }
};
