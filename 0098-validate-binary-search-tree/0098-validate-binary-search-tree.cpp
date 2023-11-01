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
    void solve(TreeNode* root,vector<int>&ans){
        if(root == NULL){
            return;
        }
        
        solve(root->left,ans);
        ans.push_back(root->val);
        solve(root->right,ans);
    }
    
    bool valid(TreeNode* root, long mi, long mx){
        if(root == NULL){
            return true;
        }
        
        if(root->val <= mi || root->val >= mx){
            return false;
        }
        
        return valid(root->left,mi,root->val) && valid(root->right,root->val,mx);
    }
    
    bool isValidBST(TreeNode* root) {
//         vector<int>ans;
//         solve(root,ans);
//         unordered_map<int,int>mp;
//         for(auto i : ans){
//             mp[i]++;
//         }
//         for(auto x : mp){
//             if(x.second > 1){
//                 return false;
//             }
//         }
        
//         return is_sorted(ans.begin(),ans.end());
        
        return valid(root,LONG_MIN,LONG_MAX);
        
    }
};