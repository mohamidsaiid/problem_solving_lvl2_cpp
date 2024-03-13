// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/description/
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
    void dfs(TreeNode* p, int &sum)
    {
        if(!p) return;
        dfs(p->right, sum);
        sum += p->val;
        p->val = sum;
        cout << p->val << ' ';
        dfs(p->left, sum);
    }
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        dfs(root,sum);
        return root;
    }
};
