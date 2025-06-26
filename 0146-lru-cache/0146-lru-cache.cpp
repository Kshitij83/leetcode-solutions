class Node{
    public:
    int key, value;
    Node* next;
    Node* prev;
    Node(int key1,int value1){
        key = key1;
        value = value1;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache {
public:
    unordered_map<int,Node*> mpp;
    int cap;
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    LRUCache(int capacity) {
        cap = capacity;
        mpp.clear();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mpp.find(key)==mpp.end()) return -1;
        Node* node = mpp[key];
        deleteNode(node);
        insertAfterHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            Node* node = mpp[key];
            node->value = value;
            deleteNode(node);
            insertAfterHead(node);
        }
        else{
            if(mpp.size()==cap){
                Node* prevTail = tail->prev;
                deleteNode(prevTail);
                mpp.erase(prevTail->key);
            }
            Node* newNode = new Node(key,value);
            mpp[key]=newNode;
            insertAfterHead(newNode);
        }
    }

    void insertAfterHead(Node* node){
        Node* nexttohead = head->next;
        head->next = node;
        node->next = nexttohead;
        node->prev = head;
        nexttohead->prev = node;
    }

    void deleteNode(Node* node){
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */