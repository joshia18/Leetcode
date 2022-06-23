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
    map<tuple<TreeNode*, bool, bool>, int> dp;
    
    int helper(TreeNode* root, bool cam, bool parentcam){
                
        if(root == NULL){
            //if the node previous to null has a cam, it already has a answer so send infinity, else send 0
            //do not send infinity as it might overflow
            if(cam) return 1e6;
            else return 0;
        }
        
        if(root->left == NULL && root->right == NULL){
            if(cam) return 1;
            else{
                //if it does have a parentcam no additional cams needed so send 0
                if(parentcam) return 0;
                else return 1e6;
            }
        }
        
        if(dp.find({root, cam, parentcam}) != dp.end()) return dp[{root, cam, parentcam}];
        
        if(cam){
            //as the current node has a cam, set the parentcam to 1 for the next call
            //don't make mistake here, we want the number of minimum cameras from both left and right children, not the minimum from both
            return dp[{root, cam, parentcam}] = 1 + min(helper(root->left, 0, 1), helper(root->left, 1, 1)) + 
                    min(helper(root->right, 0, 1), helper(root->right, 1, 1));
        }
        else{
            //as the current node does not have a cam, set the parentcam to 0 for the next call
            if(parentcam){
                return dp[{root, cam, parentcam}] = min(helper(root->left, 0, 0), helper(root->left, 1, 0)) +
                       min(helper(root->right, 0, 0), helper(root->right, 1, 0));
            }
            else{
                //as the root does not have a parent cam, either one of the two child nodes should have a cam
                int left = helper(root->left, 1, 0) + min(helper(root->right, 0, 0), helper(root->right, 1, 0));
                int right = helper(root->right, 1, 0) + min(helper(root->left, 0, 0), helper(root->left, 1, 0));
                return dp[{root, cam, parentcam}] = min(left, right);
            }
        }
        
    }
    
    int minCameraCover(TreeNode* root) {
        //place a camera on tehe root or not placea camera on the roor
        //third parameter is parent camera, saying if the parent node has a camera or not
        //if the parent node has a camera, the child node doesn't necessarily need to have a camera
        //but if the parnt does not have a camera, one of the childern should have a camera, as it is a binary tree, two childern here one of them should
        //initially set the parent camera to 0
        return min(helper(root, 0, 0), helper(root, 1, 0));
    }
};