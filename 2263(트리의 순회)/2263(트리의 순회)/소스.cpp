#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct tree_node {
	int value;
	tree_node* left;
	tree_node* right;
};

int n;
vector<int> inorder;
vector<int> postorder;
tree_node* real_parent;

tree_node* f(int inorder_start, int inorder_end, int preorder_start, int preorder_end) {
	if (inorder_end - inorder_start <= 0) return NULL;
	if (preorder_end - preorder_start <= 0) return NULL;

	if (inorder_end - inorder_start == 1) {
		tree_node* newnode = (tree_node*)malloc(sizeof(tree_node));
		newnode->left = newnode->right = NULL;
		newnode->value = inorder[inorder_start];
		return newnode;
	}

	tree_node* parent = (tree_node*)malloc(sizeof(tree_node));
	parent->left = NULL;
	parent->right = NULL;
	parent->value = postorder[preorder_end - 1];

	int tmp;
	for (int i = inorder_start; i < inorder_end; i++) {
		if (postorder[preorder_end - 1] == inorder[i]) tmp = i;
	}

	parent->left = f(inorder_start, tmp, preorder_start, preorder_start+(tmp-inorder_start));
	parent->right = f(tmp + 1, inorder_end, preorder_end -(inorder_end-tmp),preorder_end-1);

	return parent;
}

void preorder(tree_node* node) {
	if (node) {
		cout << node->value << " ";
		if(node->left)
			preorder(node->left);
		if(node->right)
			preorder(node->right);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		inorder.push_back(a);
	}

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		postorder.push_back(a);
	}

	real_parent = f(0,n,0,n);

//	cout << real_parent->value << endl;

	preorder(real_parent);
}