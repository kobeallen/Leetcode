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
        queue<TreeLinkNode*> Q;
        Q.push(root);
        Q.push(NULL);
        while(!Q.empty())
        {
            TreeLinkNode *now = new TreeLinkNode(0);
            now = Q.front();
            if(now==NULL)
                break;
            do
            {
                if(now->left!=NULL)
                    Q.push(now->left);
                if(now->right!=NULL)
                    Q.push(now->right);
                Q.pop();
                TreeLinkNode *next = new TreeLinkNode(0);
                next = Q.front();
                now->next = next;
                now = next;
            }while(now!=NULL);
            Q.pop();
            Q.push(NULL);
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
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(root == NULL)
            return ;
        root->next = NULL;
        TreeLinkNode *now = root;
        while(now != NULL)
        {
            TreeLinkNode *next_level_head = NULL;
            TreeLinkNode *previous = NULL;
            while(now != NULL)
            {
                if(previous == NULL)
                {
                    if(now->left != NULL)
                        next_level_head = now->left;
                }
                else
                    previous->next = now->left;
                if(now->left != NULL)
                    now->left->next = now->right;
                previous = now->right;
                now = now->next;
            }
            now = next_level_head;
        }
    }
};
