class Node {
    Node* links[2];
    public :
    bool containsKey(int bit) {
        return links[bit]!=NULL;
    }
    void put(int bit, Node* node) {
        links[bit] = node;
    }
    Node* get(int bit) {
        return links[bit];
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
            int bit = num>>i & 1;
            if(!node->containsKey(bit)) {
                node->put(bit,new Node());
            }
            node = node->get(bit);
        }
    }
    int getMax(int num) {
        Node* node = root;
        int x = 0;
        for(int i=30;i>=0;i--) {
            int bit = num>>i & 1;
            int inv_bit = bit^1;
            if(node->containsKey(inv_bit)) {
                node = node->get(inv_bit);
                x = x | inv_bit<<i;
            }
            else if(node->containsKey(bit)) {
                node = node->get(bit);
                x = x | bit<<i;
            }
            else break;
        }
        return x^num;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* t = new Trie();
        for(int i=0;i<nums.size();i++) {
            t->insert(nums[i]);
        }
        int max_xor = 0;
        for(int i=0;i<nums.size();i++) {

            max_xor = max(t->getMax(nums[i]),max_xor);
        }
        return max_xor;
    }
};