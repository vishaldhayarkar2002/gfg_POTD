// Solved it using Inorder Morris traversal
// O(n), O(1)


class Solution {
  public:
    int KthSmallestElement(Node *root, int k) {
        Node *cur = root, *pre;

        int ans = -1;

        while (cur != NULL) {
            if (cur->left == NULL) {
                if (k == 1) ans = cur->data;
                k--;
                cur = cur->right;
            } else {
                pre = cur->left;

                while (pre->right != NULL and pre->right != cur)
                    pre = pre->right;

                if (pre->right == NULL) {
                    pre->right = cur;
                    cur = cur->left;
                } else {
                    if (k == 1) ans = cur->data;
                    k--;
                    pre->right = NULL;
                    cur = cur->right;
                }
            }
        }
        return ans;
    }
};