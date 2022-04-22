struct node{
    int key;
    int val;
    node* prev;
    node* next;
    node(int key, int val) : key(key), val(val), prev(nullptr), next(nullptr) {}
};

//solved this problem using hashmap doubly linked list(DLL)

class LRUCache {
public:
    int cap;
    
    //we are keeping the head and tail pointers to avoid frequent null checks and it is pretty useful for addnode and deletenode functions
    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);
    
    unordered_map<int, node*> mp;
    
    LRUCache(int capacity) {
        cap = capacity;
        //IMPORTANT: make the head and tail point next to each other at first
        head->next = tail;
        tail->prev = head;
    }
    
    void addnode(node* newnode){
        //IMPORTANT: wheneever we add node it needs to be added rightafter the head as it becomes the most recently used element
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }
    
    void deletenode(node* newnode){
        //cout << mp.size() << " " << cap << endl;
        node* prevnode = newnode->prev;
        node* nextnode = newnode->next;
        prevnode->next = nextnode;
        nextnode->prev = prevnode;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            //when we get the new key, delete that key's entry from both DLL and map and insert new node again after the head with the same key and value
            //update the new node's address in the map also
            node* temp = mp[key];
            int res = temp->val;
            mp.erase(key);
            deletenode(temp);
            addnode(temp);
            mp[key] = temp;
            return res;
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            node* temp = mp[key];
            deletenode(temp);
            mp.erase(key);
        }
        
        if(mp.size() == cap){
            //if the maps's size reaches capapcity of the cache remove the laeat recently used node from both DLL and the map
            //the least recently used node is tail->prev
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        
        node* p = new node(key, value);
        addnode(p);
        mp[key] = p;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */