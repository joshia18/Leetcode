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
    void helper(TreeNode* root, string &s){
        if(root == nullptr) return;
        
        s += '(';
        s += to_string(root->val);
        
        //if left is null and right is not null add empty parantheses
        if(root->left == nullptr && root->right != nullptr){
            s += "()";
        }
        
        helper(root->left, s);
        helper(root->right, s);
        
        s += ')';
    }
    
    string tree2str(TreeNode* root) {
        string s = "";
        helper(root, s);
        s.pop_back();
        
        return string(s.begin()+1, s.end());
    }
};