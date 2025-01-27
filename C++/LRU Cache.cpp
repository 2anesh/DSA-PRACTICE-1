class Node {
    public:
    int key, value;
    Node *next;
    Node *prev;
    
    Node(int _key, int _value) {
        key = _key;
        value = _value;
        next = NULL;
        prev = NULL;
    }
};
class LRUCache {
  int cap;
  Node *cache;
  unordered_map<int, Node *> mp;
  public:
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int _cap) {
        cap = _cap;
        cache = new Node(-1, -1);
        cache -> next = cache;
        cache -> prev = cache;
    }
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        Node *node = mp[key];
        Node *prev = node -> prev, *next = node -> next;
        prev -> next = next;
        next -> prev = prev;
        
        Node *temp = cache -> next;
        cache -> next = node;
        node -> next = temp;
        
        temp -> prev = node;
        node -> prev = cache;
        
        
        return node -> value;
    }
    void put(int key, int value) {
        
        Node *newNode = NULL;
        
        if(mp.find(key) != mp.end()) {
            mp[key] -> value = value;
            newNode = mp[key];
            
            Node *prev = newNode -> prev, *next = newNode -> next;
            prev -> next = next;
            next -> prev = prev;
            
        } else {
            newNode = new Node(key, value);
            if(mp.size() == cap) {
                Node *rem = cache -> prev;
                rem -> prev -> next = cache;
                cache -> prev = rem -> prev;
                
                rem -> prev = NULL; rem -> next = NULL;
                mp.erase(rem -> key);
                
                delete rem;
                
            }
            
            mp[key] = newNode;
        }
        
        Node *next = cache -> next;
        
        cache -> next = newNode;
        newNode -> prev = cache;
        
        newNode -> next = next;
        next -> prev = newNode;
        
        
        return;
    }
};
