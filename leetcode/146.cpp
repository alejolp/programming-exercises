struct DoubleListNode {
    int key;
    int value;
    DoubleListNode* next;
    DoubleListNode* prev;
    DoubleListNode(int k, int v) : key(k), value(v), next(0), prev(0) {}
};

class LRUCache{
    typedef map<int, DoubleListNode*> MIL;
    DoubleListNode* head;
    DoubleListNode* tail;
    MIL index;
    int max_capacity;
    
    void remove_node(DoubleListNode* n) {
        if (n == head) {
            head = head->next;
            if (head) {
                head->prev = 0;
            }
        }
        if (n == tail) {
            tail = tail->prev;
            if (tail) {
                tail->next = 0;
            }
        }
        if (n->prev) {
            n->prev->next = n->next;
        }
        if (n->next) {
            n->next->prev = n->prev;
        }
    }
    
    void add_node(DoubleListNode* n) {
        if (head == 0) {
            head = tail = n;
            n->next = n->prev = 0;
        } else {
            n->prev = tail;
            n->next = 0;
            tail->next = n;
            tail = n;
        }
    }
    
public:
    LRUCache(int capacity) {
        head = tail = 0;
        max_capacity = capacity;
    }
    
    int get(int key) {
        MIL::iterator it = index.find(key);
        if (it == index.end()) {
            return -1;
        } else {
            DoubleListNode* p = it->second;
            remove_node(p);
            add_node(p);
            return it->second->value;
        }
    }
    
    void set(int key, int value) {
        MIL::iterator it = index.find(key);
        if (it == index.end()) {
            DoubleListNode* p = new DoubleListNode(key, value);
            if (index.size() == max_capacity) {
                index.erase(head->key);
                remove_node(head);
            }
            index[key] = p;
            add_node(p);
        } else {
            DoubleListNode* p = it->second;
            p->value = value;
            remove_node(p);
            add_node(p);
        }
    }
};