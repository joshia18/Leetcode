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
    //easy soln
//     int countNodes(TreeNode* root) {
//         if(root == nullptr){
//             return 0;
//         }
        
//         return 1 + countNodes(root->left) + countNodes(root->right);
//     }
    
    //another sol to reduce time complexity
    int findlheight(TreeNode* node){
        int height = 0;
        
        while(node){
            height++;
            node = node->left;
        }
        return height;
    }
    
    int findrheight(TreeNode* node){
        int height = 0;
        
        while(node){
            height++;
            node = node->right;
        }
        return height;
    }
    
    int countNodes(TreeNode* root){
        if(root == nullptr) return 0;
        
        int lh = findlheight(root);
        int rh = findrheight(root);
        
        //if both heights are same return 2^lh - 1 which is same as 1<<lh - 1
        if(lh == rh) return (1 << lh) -1;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};