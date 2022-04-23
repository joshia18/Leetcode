/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //optimal way without using any space
        
        if(head == NULL) return NULL;
        
        Node* temp = head;
        
        //placing new deep copied nodes right next to the original nodes
        while(temp != NULL){
            Node* p = temp;
            Node* newnode = new Node(temp->val);
            newnode->next = p->next;
            p->next = newnode;
            temp = newnode->next;
        }
        
        Node* iter = head;
        
        //setting the deep copied random pointers to the new deep copied nodes
        while(iter != NULL){
            if(iter->random){
                iter->next->random = iter->random->next;
            }
            else{
                iter->next->random = NULL;
            }
            
            iter = iter->next->next;
        }
        
        Node* original = head;
        Node* dcopy = head->next;
        Node* res = dcopy;
        
        //separating the original list and deep copied list
        while(original){
            original->next = original->next->next;
            dcopy->next = dcopy->next != NULL ? dcopy->next->next : dcopy->next;
            original = original->next;
            dcopy = dcopy->next;
        }
         
        
        return res;
        
    }
};