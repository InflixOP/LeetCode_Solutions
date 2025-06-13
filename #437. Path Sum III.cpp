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
void fun(TreeNode* root,int t,int &c,long long int s){
    if(!root){
        return;
    }
    s+=root->val;
    if(s==t){
        c++;
    }
    fun(root->left,t,c,s);
    fun(root->right,t,c,s);
}
void pre(TreeNode* root,int ta,int&c){
    if(!root){
        return;
    }
    fun(root,ta,c,0);
    pre(root->right,ta,c);
    pre(root->left,ta,c);
}
    int pathSum(TreeNode* root, int targetSum) {
        int c=0;
        pre(root,targetSum,c);
        return c;
    }
};