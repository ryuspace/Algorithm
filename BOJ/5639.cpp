//https://www.acmicpc.net/problem/5639
/*풀이 : 재귀로 계속 삽입하게 했는데 시간이 너무 많이 걸린다.*/
#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
	int value;
	Node* left, *right;
	Node(int value) :value(value), left(NULL), right(NULL)
	{

	}
	void setLeft(Node* left)
	{
		this->left =left;
	}
	void setRight(Node* right)
	{
		this->right = right;
	}
};
Node* insert(Node* root, Node* node)
{
	if (root == NULL)
		return node;
	if (node->value < root->value)
		root->setLeft(insert(root->left, node));
	else
		root->setRight(insert(root->right, node));
	return root;//계속 이어지는걸 리턴해줘야한다.
}
void printNode(Node* node) {
	if (node->left != NULL)
		printNode(node->left);
	if (node->right != NULL)
		printNode(node->right);
	cout << node->value << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int temp;
	Node* Nodes = NULL;
	while (scanf("%d", &temp) != EOF) {
		Nodes = insert(Nodes, new Node(temp));
	}
	printNode(Nodes);
	return 0;
}
