struct node{
    //node_count stores the frequency of that node
    int key, value, node_count;
    node* prev;
    node* next;
    
    node(int key,int  value) : key(key), value(value), node_count(1), prev(nullptr), next(nullptr) {}
};

struct List{
    int size = 0;
    node* head;
    node* tail;
    
    List(){
        //don't forget these things here
        head = new node(-1, -1);
        tail = new node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(node* newnode){
        node* temp = head->next;
        head->next = newnode;
        temp->prev = newnode;
        newnode->prev = head;
        newnode->next = temp;
        size++;
    }
    
    void deleteNode(node* delnode){
        node* prevnode = delnode->prev;
        node* nextnode = delnode->next;
        prevnode->next = nextnode;
        nextnode->prev = prevnode;
        size--;
    }
};

class LFUCache {
public:
    unordered_map<int, node*> mp;
    unordered_map<int, List*> freqlistmap;
    int minfreq;
    int currentsize;
    int cachecapacity;
    
    LFUCache(int capacity) {
        cachecapacity = capacity;
        minfreq = 0;
        currentsize = 0;
    }
    
    void updatefreqlist(node* Node){
        node* p = Node;
        mp.erase(p->key);
        freqlistmap[p->node_count]->deleteNode(Node);
        
        //if the current minfreq doesn't contain any elements then delete that list which means increment it
        if(p->node_count == minfreq && freqlistmap[minfreq]->size == 0){
            minfreq++;
        }
        
        List* nextlist = new List();
        
        if(freqlistmap.find(p->node_count + 1) != freqlistmap.end()){
            nextlist = freqlistmap[p->node_count + 1];
        }
        
        p->node_count += 1;
        nextlist->addNode(p);
        //don't forget to update both the freqlistmap and the key map with the newly updated list and node
        freqlistmap[p->node_count] = nextlist;
        mp[p->key] = p;
        
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            int res = mp[key]->value;
            //if a node gets accessed it needs to move to the next frequency list
            updatefreqlist(mp[key]);
            return res;
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        if(cachecapacity == 0){
            return;
        }
        
        if(mp.find(key) != mp.end()){
            node* temp = mp[key];
            temp->value = value;
            updatefreqlist(temp);
        }
        else{
            if(currentsize == cachecapacity){
                //in this case as in LRU, remove the last recently used eleemnt in the minfrequency's DLL
                List* list = freqlistmap[minfreq];
                mp.erase(list->tail->prev->key);
                list->deleteNode(list->tail->prev);
                currentsize--;
            }
            
            //whenever we insert a new node, it should inserted in the lowest frequency's DLL (minfreq = 1)
            minfreq = 1;
            currentsize++;
            
            node* temp = new node(key, value);
            List* list = new List();
            
            if(freqlistmap.find(minfreq) != freqlistmap.end()){
                list = freqlistmap[minfreq];
            }
            
            list->addNode(temp);
            //don't forget to update both the freqlistmap and the key map with the newly updated list and node
            freqlistmap[minfreq] = list;
            mp[key] = temp;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */