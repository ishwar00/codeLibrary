/*
 *
 *
 * problem link: https://leetcode.com/problems/maximum-width-of-binary-tree/
 *
 * */



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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> working_nodes;
        working_nodes.push({ root, 0 });
        int max_width = 0;
        while (not working_nodes.empty()) {
            auto const [_, first_id] = working_nodes.front();
            int last_id = 0;
            int current_level_size = working_nodes.size();
            for (int i = 0; i < current_level_size; ++i) {
                auto [pointer, id] = working_nodes.front();
                id = id - first_id;
                if (pointer->right != nullptr) working_nodes.push({ pointer->right, 2 * id + 1 });
                if (pointer->left != nullptr)  working_nodes.push({ pointer->left, 2 * id + 2 });
                last_id = id;
                working_nodes.pop();
            }
            max_width = max(max_width, last_id + 1);
        }
        return max_width;
    }
};
