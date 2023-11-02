class Solution {
public:
    TreeNode* dfs(TreeNode* node){
        if(node == nullptr)
            return nullptr;
        
        //leaf node 
        if(node->left == nullptr && node->right == nullptr)
            return node; 
        
        // dfs left subtree recursively 
        TreeNode* leftTail = dfs(node->left);

        // dfs right subtree recursively 
        TreeNode* rightTail = dfs(node->right);

        // if there was a left subtree, we shuffle the connections around 
        // so that there is nothing on the left side anymore.
        if(leftTail != nullptr){
            leftTail -> right = node -> right;
            node -> right = node -> left;
            node -> left = nullptr;
        }

        // we have to return the "rightmost" node after we are done writing the new connections 
        return rightTail == nullptr ? leftTail : rightTail;
    }

    void flatten(TreeNode* root) {
        dfs(root);
    }
};