//Name:- Jain Aman
//UID:-22BCS14831
//Section:-637
//Group:-"B"




//Problem:-01


#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Helper function to construct BST
TreeNode* sortedArrayToBSTHelper(vector<int>& nums, int left, int right) {
    if (left > right) return nullptr;
    
    int mid = left + (right - left) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = sortedArrayToBSTHelper(nums, left, mid - 1);
    root->right = sortedArrayToBSTHelper(nums, mid + 1, right);
    
    return root;
}

// Main function to convert sorted array to BST
TreeNode* sortedArrayToBST(vector<int>& nums) {
    return sortedArrayToBSTHelper(nums, 0, nums.size() - 1);
}

// Helper function to print the tree in pre-order
void preOrder(TreeNode* node) {
    if (node == nullptr) return;
    cout << node->val << " ";
    preOrder(node->left);
    preOrder(node->right);
}

int main() {
    vector<int> nums = {-10, -3, 0, 5, 9};
    TreeNode* root = sortedArrayToBST(nums);
    cout << "Preorder Traversal of the BST: ";
    preOrder(root);
    return 0;
}
