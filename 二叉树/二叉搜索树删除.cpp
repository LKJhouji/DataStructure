TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return nullptr;
    
    if (key > root->val) root->right = deleteNode(root->right, key);
    else if (key < root->val) root->left = deleteNode(root->left, key);
    else {
        if (!root->left && !root->right) return nullptr;
        else if (root->left && !root->right) return root->left;
        else if (root->right && !root->left) return root->right;
        else {
            TreeNode* tmp = root->right;
            TreeNode* cur = tmp;
            while (cur->left) cur = cur->left;
            cur->left = root->left;
            delete(root);
            return tmp;
        }
    }
    return root;
}