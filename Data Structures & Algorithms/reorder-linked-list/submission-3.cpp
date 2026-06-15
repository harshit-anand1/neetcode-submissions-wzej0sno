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
    ListNode* reverseList(ListNode* head){
        if(!head || !head->next)
            return head;
        

        ListNode* newHead = reverseList(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next =NULL;

        return newHead;
    }

    
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp = head;

        while(slow!=NULL && fast->next!=NULL && fast->next->next!=NULL){
        slow= slow->next;
        fast= fast->next->next;
        }

        //slow is the middle node and that is also the second head;
        ListNode* secondHead = reverseList(slow->next);
        //terminating the first part of the list
        slow->next = NULL;

        ListNode* temp2 = secondHead;
       
        while(temp2!=NULL){
           ListNode* nextNode1 = temp->next;
           temp->next = temp2;
           temp = temp2;
           ListNode* nextNode2 = temp2->next;
           temp->next = nextNode1;
           temp= temp->next; 
           temp2=nextNode2;
        }

       





        

        
    }
};
