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
    int maxi;
    int maxSum(TreeNode* root, int &maxi){
        if(root == nullptr) return 0;
        
        //max(0, maxPathSum(root->left)) -> this is to avoid any nodes  with negative values, because negatives only reduces sum
        int leftsum = maxSum(root->left, maxi);
        int rightsum = maxSum(root->right, maxi);
        maxi = max(maxi, leftsum + rightsum + root->val);
        
        return max(0, root->val + max(leftsum, rightsum));
        
    }
    
    int maxPathSum(TreeNode* root) {
        int maxi;
        
        maxi = INT_MIN;
        
        maxSum(root,maxi);
        
        return maxi;
        
        
    }
};