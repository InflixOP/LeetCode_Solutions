/**
 * Definition for a binary tree TreeNode.
 * struct TreeTreeNode {
 *     int val;
 *     TreeTreeNode *left;
 *     TreeTreeNode *right;
 *     TreeTreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeTreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeTreeNode(int x, TreeTreeNode *left, TreeTreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
TreeNode* deleteTreeNodeHelper(TreeNode* curr){

    // 0 child
    if(!curr->left && !curr->right){
        delete curr;
        return NULL;
    }

    // 1 child
    else if(!curr->left && curr->right){
        // right child
        TreeNode* temp = curr->right;
        delete curr;
        return temp;
    }

    else if(curr->left && !curr->right){
        // left child
        TreeNode* temp = curr->left;
        delete curr;
        return temp;
    }

    // 2 child
    else{
        TreeNode* temp = curr->right;
        if(!temp->left){
            curr->val = temp->val;
            curr->right = deleteTreeNodeHelper(temp);
            return curr;
        }

        TreeNode* parent = NULL;
        while(temp->left){
            parent = temp;
            temp = temp->left;
        }
        curr->val = temp->val;
        parent->left = deleteTreeNodeHelper(temp);

        return curr;
    }


}

TreeNode* deleteTreeNode(TreeNode* root, int key) {

    if(root == NULL){
        return NULL;
    }

    if(root->val == key){
        root = deleteTreeNodeHelper(root);
    }

    else if(root->val > key){
        root->left = deleteTreeNode(root->left, key);
    }

    else{
        root->right = deleteTreeNode(root->right, key);
    }

    return root;

}
    TreeNode* deleteNode(TreeNode* root, int key) {
        return deleteTreeNode(root, key);
    }
};