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
        
        if(p->val >= l && p->val <= h) return p->val + preorder(p->left, l, h) + preorder(p->right, l, h);
        
        if(p->val < l) return preorder(p->right, l, h);
        return preorder(p->left, l, h);
        
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        
        return preorder(root, low, high);
    }
};