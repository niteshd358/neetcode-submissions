class Node {
    public:
        int key;
        int val;
        Node* prev;
        Node* next;

        Node(int k,int v) {
            key = k;
            val = v;
            prev = nullptr;
            next = nullptr;
        }
        Node() {
            key = -1;
            val = 0;
            prev = nullptr;
            next = nullptr;
        }

};

class LRUCache {
    unordered_map<int,Node*> mpp;
    int capacity;
    Node* head = new Node();
    Node* tail = new Node();

    void deleteNode(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void insertAfterHead(Node* node){
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }


public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        mpp.clear();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mpp.find(key) == mpp.end()){
            return -1;
        }
        else {
            Node* node = mpp[key];
            deleteNode(node);
            insertAfterHead(node);
            return node->val;
        }
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()){
            Node* node = mpp[key];
            node->val = value;
            deleteNode(node);
            insertAfterHead(node);
        }
        else{
            if(mpp.size() == capacity){
                mpp.erase(tail->prev->key);
                deleteNode(tail->prev);
                Node* node = new Node(key,value);
                insertAfterHead(node);
                mpp[key] = node;
            }
            else{
                Node* node = new Node(key,value);
                insertAfterHead(node);
                mpp[key] = node;
            }
        }
    }
};
