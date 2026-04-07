 class Node {
public: 
    int key;  // CRITICAL: Need key stored in node to remove from map during eviction
    int val;
    Node* prev;
    Node* next;
    Node(int k, int v) : key(k), val(v), next(nullptr), prev(nullptr) {}
};

class LRUCache {
public:
    unordered_map<int, Node*> mp;
    int cap;
    Node* head;
    Node* tail;

    void deleteNode(Node* node){
        // Only unlink from list, DON'T delete the node
        Node* before = node->prev;
        Node* after = node->next;
        before->next = after;
        after->prev = before;
    }

    void insertAfterHead(Node* node){
        Node* first = head->next;
        head->next = node;
        node->prev = head;
        node->next = first;
        first->prev = node;  // Must update both directions
    }

    LRUCache(int capacity) {
        cap = capacity;
        mp.clear();  // Missing parentheses
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            Node* node = mp[key];
            deleteNode(node);
            insertAfterHead(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* node = mp[key];
            deleteNode(node);
            node->val = value;  // Update value
            insertAfterHead(node);
        }
        else {
            // New key - check capacity
            if(mp.size() == cap){
                // Remove LRU (node before tail)
                Node* lru = tail->prev;
                deleteNode(lru);
                mp.erase(lru->key);  // Remove from map
                delete lru;  // Free memory
            }
            // Insert new node
            Node* newNode = new Node(key, value);
            insertAfterHead(newNode);
            mp[key] = newNode;
        }
    }
};