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
    
    pair<int, int> helper(TreeNode* root){
        if(root == nullptr) return {0,0};
        
        pair<int, int> left = helper(root->left);
        pair<int, int> right = helper(root->right);
        pair<int, int> result;
        
        //for current node
        //result.first not including the current node, take the sum of maximum answer of left and right subtree
        result.first = max(left.first, left.second) + max(right.first, right.second);
        //result.second including the root
        result.second = root->val + left.first + right.first;
        
        return result;
    }
    
    
        
    int rob(TreeNode* root) {
        
        
        //if we rob the root we cannot rob the houses connected to it, so we have to rob the houses connected to root->left and root->right
        //as for every node we make two calls, the time complexity is o(2^n) exponential
        //as there is repeating subproblems for each node, we can do memoizaton, so we'll visit each node only once so, TC is o(n)
        //implementing dp solution
        
        pair<int, int> res = helper(root);
        
        //first is the ans without including the root and second is the answer which includes the root
        return max(res.first, res.second);
    }
};