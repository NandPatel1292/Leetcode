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
    int maxLevelSum(TreeNode* root) {
        int ans = 0;
        int msum = INT_MIN;
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            level++;
            int tmp = 0;
            int x = q.size();
            for(int i = x; i>0; i--){
                TreeNode* t = q.front();
                q.pop();
                tmp += (t->val);
                
                if(t->left){
                    q.push(t->left);
                }
                if(t->right){
                    q.push(t->right);
                }
            }
            
            if(tmp > msum){
                msum = tmp;
                ans = level;
            }
        }
        return ans;
    }
};