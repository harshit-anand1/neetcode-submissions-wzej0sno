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
    ListNode* reverseList(ListNode* node) {
        ListNode* curr = node;
        ListNode* prev = NULL;
        ListNode* next = NULL;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* leftNode = NULL;
        ListNode* rightNode = NULL;
        ListNode* prevNode = NULL;
        ListNode* nextNode = NULL;
        ListNode* temp = head;

        int count = 1;

        if (left == 1) {
            leftNode = head;

        }

        while (temp != NULL) {
            if (count + 1 == left) {
                prevNode = temp;
                leftNode = temp->next;
            }
            if (count == right) {
                rightNode = temp;
                nextNode = temp->next;
            }
            temp = temp->next;
            count++;
        }

        rightNode->next = NULL;
        //prevNode->next = NULL;

        ListNode* newHead = reverseList(leftNode);

        
        if(prevNode) prevNode->next = newHead;
        leftNode->next = nextNode;
        if(!prevNode) return newHead;
        return head;
    }
};