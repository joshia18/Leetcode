// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    Node* reverse(Node* root){
        if(root == NULL) return NULL;
        
        Node* p = root; Node* q = nullptr; Node* r = nullptr;
        
        while(p){
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
        
        return q;
    }
    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        Node* dummy = new Node(0);
        Node* temp = dummy;
        
        first = reverse(first);
        second = reverse(second);
        
        int carry =0;
        
        while(first || second || carry){
            int sum = 0;
            
            if(first){
                sum += first->data;
                first = first->next;
            }
            
            if(second){
                sum += second->data;
                second = second->next;
            }
            
            //this is important here
            sum += carry;
            
            Node* newnode = new Node(sum%10);
            
            carry = sum / 10;
            
            temp->next = newnode;
            temp = newnode;
        }
        
        return reverse(dummy->next);
        
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends