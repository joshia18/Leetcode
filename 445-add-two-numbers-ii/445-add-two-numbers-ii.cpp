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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //here we do not reverse the given lists for addition and that is the brute force method
        //we use stack instead, it stores the list in reverse order starting from top
        
        stack<int> num1;
        stack<int> num2;
        
        ListNode* head = nullptr; ListNode* oldhead = nullptr;
        
        while(l1){
            num1.push(l1->val);
            l1 = l1->next;
        }
        
        while(l2){
            num2.push(l2->val);
            l2 = l2->next;
        }
        
        int carry = 0;
        
        while(!num1.empty() || !num2.empty() || carry){
            int sum = 0;
            
            if(!num1.empty()){
                sum += num1.top();
                num1.pop();
            }
            
            if(!num2.empty()){
                sum += num2.top();
                num2.pop();
            }
            
            sum += carry;
            
            ListNode* newnode = new ListNode(sum%10);
            
            carry = sum/10;
            
            if(head == nullptr){
                head = newnode;
                oldhead = newnode;
            }
            else{
                head = newnode;
                head->next = oldhead;
                oldhead = head;
            }
            
        }
        
        return head;
    }
};