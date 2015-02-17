/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        TreeLinkNode *now = root;
        while(now != NULL)
        {
            TreeLinkNode *next = NULL;
            TreeLinkNode *previous = NULL;
            while(now != NULL)
            {
                if(next == NULL)
                {
                    if(now->left != NULL)
                        next = now->left;
                    else if(now->right != NULL)
                        next = now->right;
                }
                if(now->left != NULL)
                {
                    if(previous != NULL)
                        previous->next = now->left;
                    previous = now->left;
                }
                if(now->right != NULL)
                {
                    if(previous != NULL)
                        previous->next = now->right;
                    previous = now->right;
                }
                now = now->next;
            }
            now = next;
        }
    }
};

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL)
            return ;
        root->next = NULL;
        TreeLinkNode *current = root;
        while(current != NULL)
        {
            TreeLinkNode *next_level_first = NULL;
            TreeLinkNode *previous = NULL;
            while(current != NULL)
            {
                if(current->left != NULL)
                {
                    if(next_level_first == NULL)
                        next_level_first = current->left;
                    if(previous != NULL)
                        previous->next = current->left;
                    previous = current->left;
                }
                if(current->right != NULL)
                {
                    if(next_level_first == NULL)
                        next_level_first = current->right;
                    if(previous != NULL)
                        previous->next = current->right;
                    previous = current->right;
                }
                current = current->next;
            }
            if(previous != NULL)
                previous->next = NULL;
            current = next_level_first;
        }
    }
};
