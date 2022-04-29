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
    
    int helper(TreeNode* root, int maxval, int minval){
        //in each path of the binary tree we have to find the minvalue and maxvalue in that path
        if(root == NULL){
            return maxval - minval;
        }
        
        maxval = max(maxval, root->val);
        minval = min(minval, root->val);
        
        //answer for left subtree paths
        int left = helper(root->left, maxval, minval);
        int right = helper(root->right, maxval, minval);
        
        return max(left, right);
        
    }
    
    int maxAncestorDiff(TreeNode* root) {
        return helper(root, root->val, root->val);
        
        //return ans;
    }
};