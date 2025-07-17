class Node {
    Node* links[2];
    public :
    bool containsKey(int b) {
        return links[b]!=NULL;
    }
    void put(int b, Node* node) {
        links[b] = node;
    }
    Node* get(int b) {
        return links[b];
    }
};

class Trie {
    Node* root;
    public : 
    Trie() {
        root = new Node();
    }
    void insert(int num) {
        Node* node = root;
        for(int i=30;i>=0;i--) {
            int bit = (num>>i) & 1;
            if(!node->containsKey(bit)) {
                node->put(bit,new Node());
            }
            node = node->get(bit);
        }
    }
    int getMax(int num) {
        Node* node = root;
        if(node->get(0)==NULL && node->get(1)==NULL) return -1;
        int x = 0;
        for(int i=30;i>=0;i--) {
            int bit = (num>>i) & 1;
            int inv_bit = bit^1;
            if(node->containsKey(inv_bit)) {
                node = node->get(inv_bit);
                x = x | (inv_bit<<i);
            }
            else if(node->containsKey(bit)) {
                node = node->get(bit);
                x = x | (bit<<i);
            }
            else break;
        }
        return num ^ x;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(),nums.end());
        vector<pair<int,pair<int,int>>> oQ;
        for(int i=0;i<queries.size();i++) {
            oQ.push_back({queries[i][1],{queries[i][0],i}});
        }
        sort(oQ.begin(),oQ.end());
        vector<int> ans(queries.size(),0);
        Trie* t = new Trie();
        int j = 0;
        for(int i=0;i<queries.size();i++) {
            int comp = oQ[i].first;
            int num = oQ[i].second.first;
            int ind = oQ[i].second.second;
            while(j<nums.size() && nums[j]<=comp) {
                t->insert(nums[j]);
                j++;
            }
            ans[ind] = t->getMax(num);
        }
        return ans;
    }
};