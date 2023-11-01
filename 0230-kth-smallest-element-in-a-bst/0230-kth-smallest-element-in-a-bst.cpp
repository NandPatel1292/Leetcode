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
    void solve(TreeNode* root,int &ans, int k, int &cnt){
        if(root == NULL){
            return;
        }
        
        solve(root->left,ans,k,cnt);
        // ans.push_back(root->val);
        cnt++;
        if(cnt == k){
            ans = root->val;
            return;
        }
        solve(root->right,ans,k,cnt);
    }
    
    int kthSmallest(TreeNode* root, int k) {
//         vector<int>ans;
//         solve(root,ans);
        
//         return ans[k-1];
        int ans;
        int cnt = 0;
        solve(root,ans,k,cnt);
        
        return ans;
    }
};