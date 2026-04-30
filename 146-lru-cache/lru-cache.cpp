
struct Node {
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int key, int val){
        this->key = key;
        this->val = val;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
private:
    unordered_map<int,Node*> mp;
    int SIZE;
    Node* head;
    Node* tail;

    void removeNode(Node* node){
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void insertAtFront(Node* node){
        Node* firstNode = head->next;
        head->next = node;
        node->prev = head;

        node->next = firstNode;
        firstNode->prev = node;
    }

public:
    LRUCache(int capacity) {
        SIZE = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }
        Node* node = mp[key];
        removeNode(node);
        insertAtFront(node);

        return node->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* existing = mp[key];
            existing->val = value;
            removeNode(existing);
            insertAtFront(existing);
            return;
        }
        if(mp.size() == SIZE){
            Node* lru = tail->prev;
            removeNode(lru);
            mp.erase(lru->key);
            delete lru;
        }
        Node* newNode = new Node(key,value);
        insertAtFront(newNode);
        mp[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */