/*# Intuition
Postorder traversal follows the order: Left → Right → Root.  
For every node, we first recursively traverse its left subtree, then its right subtree, and finally visit the current node.

# Approach
1. Create a helper recursive function `postorder`.
2. If the current node is `NULL`, return.
3. Recursively traverse the left subtree.
4. Recursively traverse the right subtree.
5. Add the current node's value to the result vector.
6. Return the result vector containing the postorder traversal.

# Complexity
- Time complexity:
O(n)

- Space complexity:
O(h) - because of the recursive call stack.

Where:
- n is the number of nodes in the tree.
- h is the height of the tree (recursive call stack). In the worst case, h = n.

# Code
```cpp
*/
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
    void postorder(TreeNode* root, vector<int>& result) {
        if (root == NULL) return;

        postorder(root->left, result);
        postorder(root->right, result);
        result.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postorder(root, result);
        return result;
    }
};
