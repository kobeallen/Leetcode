#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;

struct node
{
	int val;
	node *left;
	node *right;
	node(int x = 0)
	{
		val = x;
		left = NULL;
		right = NULL;
	}
};

node *Construct()
{
	int value;
	scanf("%d", &value);
	if(value == 0)
		return NULL;
	node *now = new node(value);
	now->left = Construct();
	now->right = Construct();
	return now;
}

void Pre_Order_Traversal(node *root)
{
	stack<node *> S;
	node *now = root;
	while(!S.empty() || now != NULL)
	{
		if(now != NULL)
		{
			printf("%d ", now->val);
			S.push(now);
			now = now->left;
		}
		else
		{
			now = S.top();
			S.pop();
			now = now->right;
		}
	}
	printf("\n");
}

void In_Order_Traversal(node *root)
{
	stack<node *> S;
	node *now = root;
	while(!S.empty() || now != NULL)
	{
		if(now != NULL)
		{
			S.push(now);
			now = now->left;
		}
		else
		{
			now = S.top();
			S.pop();
			printf("%d ", now->val);
			now = now->right;
		}
	}
	printf("\n");
}

void Post_Order_Traversal(node *root)
{
	
}

int main(int argc, char *argv[])
{
	node *root = Construct();
	printf("Pre-Order Traversal:\n");
	Pre_Order_Traversal(root);
	printf("In-Order Traversal:\n");
	In_Order_Traversal(root);
	printf("Post-Order Traversal:\n");
	Post_Order_Traversal(root);
	return 0;
}
