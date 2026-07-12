class Node{
public:
    int key;  //critical : need key stored in node to remove from map during eviction
    // inititalisations
    int val;
    Node* prev;
    Node* next;
    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}

};


class LRUCache {
public:
    unordered_map<int, Node*> mp;
    int cap;
    Node* head;
    Node* tail;
    

    void deleteNode(Node* node){
        Node* before = node->prev;
        Node* after = node->next;
        before->next = after;
        after->prev = before;
    }

    void insertAfterHead(Node* node){
        Node* first = head->next;
        head->next = node;
        node->prev = head;
        node->next  = first;
        first->prev = node; //updated both directions
    }

    LRUCache(int capacity) {
        cap = capacity;
        mp.clear();
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            Node* node = mp[key];
            deleteNode(node);
            insertAfterHead(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* node = mp[key];
            deleteNode(node);
            insertAfterHead(node);
            node->val = value;
        }
        else {
            if(mp.size()==cap){
                Node* lru = tail->prev;
                deleteNode(lru);
                mp.erase(lru->key);
                delete lru; //free memory
            }
            //insert new node
            Node* newNode = new Node(key, value);
            insertAfterHead(newNode);
            mp[key] = newNode;
        }
    }
};
