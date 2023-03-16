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
    TreeNode* tree(vector<int>&in,int is, int ie, vector<int>& po, int ps, int pe,map<int,int>&mp){
        if(ps > pe || is > ie){
            return NULL;
        }
        
        TreeNode* root = new TreeNode(po[pe]);
        
        int index = mp[po[pe]];
        
        int num = index - is;
        
        root->left = tree(in,is,index-1,po,ps,ps+num-1,mp);
        root->right = tree(in,index+1,ie,po,ps+num,pe-1,mp);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() != postorder.size()){
            return NULL;
        }
        map<int,int> mp;
        for(int i = 0; i<inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        return tree(inorder, 0, inorder.size()-1, postorder,0, postorder.size()-1,mp);
    }
};