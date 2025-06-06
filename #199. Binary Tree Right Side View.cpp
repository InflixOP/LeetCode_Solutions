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
        vector<int> ans;
        vector<int> levelOrder(TreeNode* root,vector<int> &ans) {
            queue<TreeNode*> q;
            vector<int> a;
            q.push(root);
            q.push(NULL);
            while(!q.empty()){
                TreeNode* temp=q.front();
                q.pop();
                if(temp==NULL){
                    reverse(a.begin(),a.end());
                    ans.push_back(a[0]);
                    a.clear();
                    if(!q.empty()){
                        q.push(NULL);
                    }
                }
                else{
                    a.push_back(temp->val);
                    if(temp->left) q.push(temp->left);
                    if(temp->right) q.push(temp->right);
                }
            }
          return ans;
        }
        vector<int> rightSideView(TreeNode* root) {
            if(root==NULL){
                return ans;
            }
            levelOrder(root,ans);
            return ans;
        }
    };