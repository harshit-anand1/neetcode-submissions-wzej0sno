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

    ListNode* reverseList(ListNode* node){
        ListNode* curr = node;
        ListNode* next = NULL;
        ListNode* prev = NULL;

        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp = head;
        ListNode* dummy  = head;

        while(slow!=NULL && fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;

        }

        ListNode* secondHead  = reverseList(slow->next);
        slow->next = NULL;
    
        ListNode* first = head;
        ListNode* second = secondHead;
        //ListNode* dummy = tempA; 
        while(second!=NULL){
            ListNode* nextNode1 = first->next;
            ListNode* nextNode2 = second->next;

            first->next = second;
            second->next = nextNode1;
            first = nextNode1;
            second  = nextNode2;
            
            
        }

        //return dummy->next;
    }
};
