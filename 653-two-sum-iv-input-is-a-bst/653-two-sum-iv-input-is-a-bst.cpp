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
    
    bool preorder(TreeNode* root, int k, unordered_set<int> &hashset){
        if(root == NULL) return 0;
        
        if(hashset.find(k - root->val) != hashset.end()){
            return true;
        }
        
        hashset.insert(root->val);
        
        return preorder(root->left, k, hashset) || preorder(root->right, k, hashset);
    }
    
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> st;
        
        return preorder(root, k, st);
    }
};