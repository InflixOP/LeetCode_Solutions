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
    int ans = 0;

    pair<int,int> rec(TreeNode* root){
        if(root == NULL)   return {-1,-1};
        
        pair<int,int> l = rec(root->left);
        pair<int,int> r = rec(root->right);

        ans = max({ans,l.first,l.second,r.first,r.second});

        return {1+l.second,1+r.first};

    }


    int longestZigZag(TreeNode* root) {
        pair<int,int> s = rec(root);
        return max({ans,s.first,s.second});
    }
};