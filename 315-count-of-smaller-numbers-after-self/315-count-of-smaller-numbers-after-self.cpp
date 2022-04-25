class Solution {
public:
    struct Node{
        Node* left;
        Node* right;
        int count = 1;
        int val;
        
        Node(int num){
            left = nullptr; right = nullptr; val = num; count = 1;
        }
    };
    
    int addnode(Node* root, int target){
        int smallnumber = 0;
        
        Node* newnode = new Node(target);
        
        while(1){
            if(target <= root->val){
                root->count += 1;
                if(root->left == nullptr){
                    root->left = newnode;
                    break;
                }
                else{
                    root = root->left;
                }
            }
            else{
                smallnumber += root->count;
                if(root->right == nullptr){
                    root->right = newnode;
                    break;
                }
                else{
                    root = root->right;
                }
            }
        }
        
        return smallnumber;
    }
    
    vector<int> asc, desc;
    
    bool isAscending(vector<int> &nums){
        asc.push_back(0);
        
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] >= nums[i-1]){
                asc.push_back(0);
            }
            else{
                return false;
            }
        }
        
        return true;
    }
    
    bool isDescending(vector<int> &nums){
        int n = nums.size();
        int temp = 1;
        desc.push_back(0);
        
        for(int i = n-2; i >= 0; i--){
            if(nums[i] > nums[i+1]){
                desc.push_back(temp++);
            }
            else if(nums[i] == nums[i+1]){
                int t = desc[desc.size()-1];
                desc.push_back(t);
                temp++;
            }
            else{
                return false;
            }
        }
        
        reverse(desc.begin(), desc.end());
        
        return true;
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        //problem solved using BST
        
        vector<int> res;
        int n = nums.size();
        
        if(nums.size() == 0) return res;
        
        //to handle skewed trees, have to check if the given array is ascending or descending
        if(isAscending(nums)){
            return asc;
        }
        
        if(isDescending(nums)){
            //cout << "here3";
            return desc;
        }
        
        //for the last elemet in the array, the answer should always be zero
        res.push_back(0);
        Node* root = new Node(nums[n-1]);
        
        for(int i = n-2; i >= 0; i--){
            res.push_back(addnode(root, nums[i]));
        }
        
        reverse(res.begin(), res.end());
        
        return res;
        
    }
};