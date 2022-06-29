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
    int preorder(TreeNode* p, int l, int h){
        if(p == nullptr) return 0;
        if(p->val < l) preorder(p->right, l, h);
        if(p->val > h) preorder(p->left, l, h);
         
        int sum = 0;
        
        if(p->val >= l && p->val <= h) sum += p->val;
        
        sum += preorder(p->left, l, h);
        sum += preorder(p->right, l, h);
        
        return sum;
        
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        
        return preorder(root, low, high);
    }
};