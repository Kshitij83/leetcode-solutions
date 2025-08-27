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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;
        for(ListNode* node : lists) {
            if(node) pq.push({node->val,node});
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            ListNode* next = it.second;
            temp->next = next;
            temp = next;
            if(next->next) pq.push({next->next->val,next->next}); 
        }
        return dummy->next;
    }
};