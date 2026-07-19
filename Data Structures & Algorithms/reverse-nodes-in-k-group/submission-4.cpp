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

    //find kth node
    //save next of kth node
    // reverse linked list upto kth node
    //prev node is the node before the current linked list portion which is being reversed.

    ListNode* kthNode;
    ListNode* temp = head;
    ListNode* nextNode=NULL;
    ListNode* prevNode=NULL;

    while(temp!=NULL){

        //find kthNode
        
        ListNode* kthNode = getKthNode(temp, k);

        //in case k length is say 4 and total rem nodes are 2
        if (kthNode == NULL) {
                if (prevNode)
                    prevNode->next = temp;
                break;
            }
        nextNode = kthNode->next;
        kthNode->next = NULL;
        
        reverseList(temp);

        if(temp==head){
            head = kthNode;
        }
        else {
        prevNode->next = kthNode;
        }
        
        //preparation for next iteration
        prevNode = temp;
        temp = nextNode;
   
    }

    return head;
    }
};
