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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
       
    TreeNode* helper(ListNode* head, ListNode* tail){
        
        if(head == tail) return nullptr;
        
        ListNode* slow = head; ListNode* fast = head;
        
        while(fast != tail && fast->next != tail){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* lnode = slow;
        
        TreeNode* tnode = new TreeNode(lnode->val);
        
        tnode->left = helper(head, slow);
        tnode->right = helper(slow->next, tail);
        
        return tnode;
        
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        
        return helper(head, NULL);
        
    }
};