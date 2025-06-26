/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> mpp;
        Node* temp = head;
        while(temp!=NULL){
            Node* copy = new Node(temp->val);
            mpp[temp] = copy;
            temp = temp->next;
        }
        temp = head;
        while(temp!=NULL){
            mpp[temp]->next = mpp[temp->next];
            mpp[temp]->random = mpp[temp->random];
            temp = temp->next;
        }
        return mpp[head];
        //better approach with O(3N) complexity but just O(N) space complexity but wont work here
        // Node* temp = head;
        // Node* copyNode;
        // while(temp!=NULL){
        //     copyNode = new Node(temp->val);
        //     copyNode->next = temp->next;
        //     temp->next = copyNode;
        //     temp = temp->next->next;
        // }
        // temp = head;
        // while(temp!=NULL){
        //     copyNode = temp->next;
        //     if(temp->random != NULL){
        //         copyNode->random = temp->random->next;
        //     } 
        //     temp = temp->next->next;
        // }
        // Node* newHead = new Node(-1);
        // Node* newTemp = newHead;
        // temp = head;
        // while(temp!=NULL){
        //     copyNode = temp->next;
        //     newTemp->next = copyNode;
        //     newTemp = copyNode;
        //     temp = temp->next->next;
        // }
        // return newHead->next;
    }
};