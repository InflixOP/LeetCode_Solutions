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
        void dfs(TreeNode* root1,vector<int>& ans){
            if(!root1->left&&!root1->right)
            ans.push_back(root1->val);
            else{
                if(root1->left)
                dfs(root1->left,ans);
                if(root1->right)
                dfs(root1->right,ans);
            }
        }
        bool leafSimilar(TreeNode* root1, TreeNode* root2) {
            vector<int> v1;
            vector<int> v2;
            dfs(root1,v1);
            dfs(root2,v2);
            if(v1.size()!=v2.size())
            return false;
            for(int i=0;i<v1.size();i++){
                if(v1[i]!=v2[i])
                return false;
            }
            return true;
        }
    };