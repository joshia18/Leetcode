/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct comparenodes{
    //operator method overloading
    bool operator()(ListNode* l1, ListNode* l2){
        return l1->val > l2->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //using priority queue minheap method
        
        priority_queue<ListNode*, vector<ListNode*>, comparenodes> minheap;
        
        //at a given point of time, we store only the starting address of all the nodes in the prority queue
        for(ListNode* l : lists){
            if(l == NULL) continue;
            minheap.push(l);
            cout << l->val << endl;
        }
        
        ListNode* head = new ListNode();
        ListNode* iter = head;
        
        while(!minheap.empty()){
            ListNode* node = minheap.top();
            minheap.pop();
            
            iter->next = node;
            iter = iter->next;
            
            ListNode* next = node->next;
            
            if(next != NULL){
                minheap.push(next);
            }
            
            
        }
        
        return head->next;
        
    }
};