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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        
        map<int, map<int, multiset<int>>> mp;
        queue<tuple<int, int, TreeNode*>> q;
        q.push({0, 0, root});
        
        while(!q.empty()){
            int size = q.size();
            
            for(int i = 0; i < size; i++){
                auto [vertical, level, node] = q.front();
                q.pop();
                
                mp[vertical][level].insert(node->val);
                
                if(node->left){
                    q.push({vertical-1, level+1, node->left});
                }
                if(node->right){
                    q.push({vertical+1, level+1, node->right});
                }
            }
        }
        
        for(auto &i : mp){
            vector<int> temp;
            for(auto &j : i.second){
                for(auto &k : j.second){
                    temp.push_back(k);
                }
            }
            ans.push_back(temp);
        };
        
        return ans;
    }
};