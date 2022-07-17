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
    int helper(TreeNode* root, int temp){
        temp = (temp*10) + root->val;
        
        if(root->left == NULL && root->right == NULL){
            return temp;
        }
        
        int left = 0;
        if(root->left) left = helper(root->left, temp);
        int right = 0;
        if(root->right) right = helper(root->right, temp);
        
        return left + right;
    }
    
    int sumNumbers(TreeNode* root) {
        //trying with pre-order traversal
        
        int temp = 0;
        
        return helper(root, temp);
    }
};