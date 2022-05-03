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
    
    unordered_map<TreeNode*, int> mp;
        
    int rob(TreeNode* root) {
        if(root == nullptr) return 0;
        
        //if we rob the root we cannot rob the houses connected to it, so we have to rob the houses connected to root->left and root->right
        //as for every node we make two calls, the time complexity is o(2^n) exponential
        //as there is repeating subproblems for each node, we can do memoizaton
        
        if(mp.find(root) != mp.end()) return mp[root];
        
        int val = 0;
        
        //root is selected go rob the houses connected to root's left and right
        if(root->left) val += rob(root->left->left) + rob(root->left->right);
        if(root->right) val += rob(root->right->left) + rob(root->right->right);
        
        //max of root is selected, root is not selected
        return mp[root] = max(root->val + val , rob(root->left) + rob(root->right));
    }
};