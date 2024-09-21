class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i; // Map value to its index for quick access
        }
        
        return recur(postorder, inorderMap, 0, postorder.size() - 1, 0);
    }

private:
    TreeNode* recur(vector<int>& post, unordered_map<int, int>& map, int postStart, int postEnd, int inStart) {
        if (postStart > postEnd) return nullptr; // Base case
        
        int rootVal = post[postEnd];
        TreeNode* root = new TreeNode(rootVal);
        
        int inRootIndex = map[rootVal];
        int leftSize = inRootIndex - inStart;

        root->right = recur(post, map, postStart + leftSize, postEnd - 1, inRootIndex + 1);
        root->left = recur(post, map, postStart, postStart + leftSize - 1, inStart);
        
        return root;
    }
};
