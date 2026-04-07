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
    ListNode* getKthNode(ListNode* curr, int k) {
        k--;
        //ListNode orig = curr;
        while (curr != NULL && k > 0) {
            curr = curr->next;
            k--;
        }
        return curr;
    }

    ListNode* reverseList(ListNode* h) {

        if (h == NULL || h->next == NULL) {
            return h;
        }
        ListNode* newHead = reverseList(h->next);
        ListNode* front = h->next;
        front->next = h;
        h->next = NULL;

        return newHead;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* nextNode = NULL;
        ListNode* prevNode = NULL;

            while (temp != NULL) {

            ListNode* kthNode = getKthNode(temp, k);

            if (kthNode == NULL) {
                if (prevNode)
                    prevNode->next = temp;
                break;
            }

            nextNode = kthNode->next;
            kthNode->next = NULL;

            reverseList(temp);

            if(temp==head){
                head=kthNode;
            }
            else{
                prevNode->next = kthNode;
            }
            prevNode = temp;
            temp=nextNode;
            
        }

        return head;
    }
};