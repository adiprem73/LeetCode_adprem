class Node{
    public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int key=0 , int val =0 ){
        this->key = key;
        this->val = val;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
public:
    unordered_map<int, Node*> mp;
    int capacity;
    Node* head;
    Node* tail;
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end())return -1;
        Node* node = mp[key];
        deleteNode(node);
        insertAfterHead(node);

        return node->val;
    }
    
    void put(int key, int value) {
        // the map already ahs this key and we just need to update the value
        if(mp.find(key) != mp.end()){
            Node* node = mp[key];
            node->val = value;
            deleteNode(node);
            insertAfterHead(node);
        }
        // if the map does not have the key
        else{
            if(mp.size() == capacity){
                Node* node = tail->prev;
                mp.erase(node->key);
                deleteNode(node);
                delete node;
            }

            Node* node = new Node(key, value);
            mp[key] = node;
            insertAfterHead(node);
        }
    }

    void insertAfterHead(Node* node){
        auto currAfterHead = head->next;
        head->next = node;
        node->next = currAfterHead;
        currAfterHead->prev = node;
        node->prev = head;
    }

    void deleteNode(Node* node){
        auto prevNode = node->prev;
        auto nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        node->next = nullptr;
        node->prev = nullptr;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */