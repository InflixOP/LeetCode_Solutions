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
unordered_map<int,vector<TreeNode*>> dp;
class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n&1==0){
            return {};
        }
        if(n==1){
            vector<TreeNode*> v={new TreeNode(0)};
            return v;
        }
        if(dp.count(n)) return dp[n];
        vector<TreeNode*> ans;
        for(int i=1;i<n;i+=2){
            auto left=allPossibleFBT(i);
            auto right=allPossibleFBT(n-i-1);
            for(auto& l:left){
                for(auto& r:right){
                    auto node=new TreeNode(0);
                    node->left=l;
                    node->right=r;
                    ans.push_back(node);
                }
            }
        }        
        return dp[n]=ans;
    }
};