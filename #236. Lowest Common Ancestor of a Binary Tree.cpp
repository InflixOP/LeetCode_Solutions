/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
bool helper(TreeNode* root,vector<TreeNode*>& v,int t){
    if(!root) return false;
    v.push_back(root);
    if(root->val==t)
    return true;
    if(helper(root->left,v,t)||helper(root->right,v,t)) return true;
    v.pop_back();
    return false;
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pp;
        vector<TreeNode*> qq;
        if(root==NULL) return NULL;
        if(p==NULL) return q;
        if(q==NULL) return p;
        helper(root,pp,p->val);
        helper(root,qq,q->val);
        int c=min(pp.size(),qq.size());
        TreeNode* a=NULL;
        for(int i=0;i<c;i++)
        if(pp[i]==qq[i])
        a=pp[i];
        else break;
        return a;
    }
};