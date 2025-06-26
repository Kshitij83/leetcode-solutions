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
    ListNode* kthNode(ListNode* temp, int k){
        while(k>1 && temp!=NULL){
            temp = temp->next;
            k--;
        }
        return temp;
    }
    ListNode* reverseNode(ListNode* temp){
        if(temp->next == NULL){
            return temp;
        }
        
        struct ListNode* front = reverseNode(temp->next);
        front->next = temp;
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        //if(k==1) return head;
        int head_change = 0; //for storing new head
        struct ListNode* temp = head;  //always make a pointer to head
        struct ListNode* newNode;     //initialize a new Node and prev node to null
        struct ListNode* prevNode = NULL;   
        while(temp!=NULL){
            struct ListNode* kNode = kthNode(temp,k); //finds the kth node
            if(kNode!=NULL){
                if(head_change == 0){
                    head = kNode;           //the kth node found on first call would always be the head
                    head_change = 1;
                }
                newNode = kNode->next;     //save the node after kth node as new node and make next node to kth node as null
                kNode->next = NULL;  //so that we can pass nodes from temp to knode in reverse function
                if(prevNode!=NULL) prevNode->next = kNode; //at start prev node will be null but on second time we would want that the prevnode points to the new kth node for example 1->2->3->4 becomes 2->1 and on next iteration we have kth node as 4 so this ensures we get 2->1->4
                prevNode = reverseNode(temp);  //prevNode stores the last node after reversal that will be temp
                prevNode->next = newNode;    //connects previous node to newnode
                temp = newNode;             // temp becomes the new node
            }
            else{
                temp = NULL;   //make temp null because there wont be any changes if there is no kth node
            }
        }
        return head;
    }
};