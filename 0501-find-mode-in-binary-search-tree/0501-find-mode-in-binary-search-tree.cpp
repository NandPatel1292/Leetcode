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

    void solve(TreeNode* root, vector<int>&ans){
        if(root == NULL){
            return;
        }
        // ans.push_back(root->val);
        if(root->left != NULL){
            ans.push_back(root->left->val);
            solve(root->left,ans);
        }
        if(root->right != NULL){
            ans.push_back(root->right->val);
            solve(root->right,ans);
        }
    }
    
    
    vector<int> findMode(TreeNode* root) {
        // vector<int>ans;
        // ans.push_back(root->val);
        // solve(root,ans);
        // unordered_map<int,int>mp;
        // if(ans.size() == 1){
        //     return ans;
        // }
        // else{
        //     for(auto i : ans){
        //         mp[i]++;
        //     }
        //     if(mp.size() == ans.size()){
        //         return ans;
        //     }
        //     else{
        //         int mx = 0;
        //         vector<int>tmp;
        //         for(auto x: mp){
        //             mx = max(mx,x.second);
        //         }
        //         for(auto x : mp){
        //             if(x.second == mx){
        //                 tmp.push_back(x.first);
        //             }
        //         }
        //         return tmp;
        //     }
        // }
        
        unordered_map<int,int>mp;
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            
            mp[x->val]++;
            
            if(x->left != NULL){
                q.push(x->left);
            }
            if(x->right != NULL){
                q.push(x->right);
            }
        }
        
        int mx = 0;
        for(auto i : mp){
            mx = max(mx,i.second);
        }
        vector<int>ans;
        for(auto i : mp){
            if(i.second == mx){
                ans.push_back(i.first);
            }
        }
        
        return ans;
    }
};