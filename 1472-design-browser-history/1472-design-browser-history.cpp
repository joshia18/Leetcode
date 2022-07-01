struct node{
    string url;
    node* prev;
    node* next;
    node(string url) : url(url), prev(nullptr), next(nullptr) {}
};

class BrowserHistory {
public:
    node* head = new node("head");
    node* tail = new node("tail");
    node* currnode;
    
    BrowserHistory(string homepage) {
        node* newnode = new node(homepage);
        newnode->prev = head;
        newnode->next = tail;
        currnode = newnode;
    }
    
    void visit(string url) {
        node* newnode = new node(url);
        //setting newnode's next and prev
        //connecting newnode to pointer
        newnode->next = tail;
        currnode->next = newnode;
        newnode->prev = currnode;
        currnode = newnode;
    }
    
    string back(int steps) {
        while((currnode->prev) && steps > 0 && currnode->prev != head){
            currnode = currnode->prev;
            steps--;
        }
        
        return currnode->url;
    }
    
    string forward(int steps) {
        while((currnode->next) && steps > 0 && currnode->next != tail){
            currnode = currnode->next;
            steps--;
        }
        
        return currnode->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */