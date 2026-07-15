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
    

    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* temp = head;
        ListNode* prevNode = NULL;
        ListNode* nextNode = NULL;

        while(temp!=NULL){

            //find kth node
            ListNode* kthNode = getKthNode(temp, k);

            //kth node might be null if no. of elements remaining is less than k
            if(kthNode==NULL){
                if(prevNode)
                    prevNode->next = temp;
                    break;
            }


            nextNode = kthNode->next;
            kthNode->next = NULL;

            reverseList(temp);

            if(temp == head){
                head = kthNode;
            }
            else 
            {
                prevNode->next = kthNode;
            }

            //assign prevNode to temp which was reversed now
            prevNode = temp;
            //we move temp to the nextNode to cater to the next group now
            temp = nextNode;

        }
        return head;
    }
};
