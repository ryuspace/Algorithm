//반드시 다시 익히자. return으로 주소를 하나하나 넘겨줘야 연결상태가 유지가 된다.
#include <stdio.h>
#ifndef NULL
#define NULL 0
#endif
const int SIZE = 100010;
struct Node {
	int data;
	Node *lch, *rch;
	Node*alloc(int nd) {
		data = nd, lch = rch = NULL;
		return this;
	}
}buf[SIZE];
int bcnt;

struct Tree {
	Node*root;
	int nodeCnt;
}tree;

Tree* newTree() {
	bcnt = 0;
	tree = Tree();
	return &tree;
}


void delTree(Tree*tree) {
	tree = NULL;
}

// 트리의 노드수를 반환한다.
int getTreeSize(Tree*tree) {
	return tree->nodeCnt;
}

// 트리에 data가 있다면 1을 없다면 0을 반환한다.
Node *searchNode(Node *now, int tg)
{
	if (now == NULL || now->data == tg)
		return now;
	if (tg < now->data)
		return searchNode(now->lch, tg);
	return searchNode(now->rch, tg);
}
int search(int data) {
	return !!searchNode(tree.root, data);
}

// 트리에 data가 존재한다면 아무일도 하지 않는다.
// 그렇지 않은경우 트리에 data를 추가한다.

Node *insertNode(Node *now, int nd)
{
	if (now == NULL)
	{
		return buf[bcnt++].alloc(nd);
	}

	if (nd < now->data)
	{
		now->lch = insertNode(now->lch, nd);
	}
	else
	{
		now->rch = insertNode(now->rch, nd);
	}
	return now;
}
void insert(int data) {
	
	if (search(data))
		return;
	tree.nodeCnt++;
	tree.root = insertNode(tree.root, data);
}

// data를 찾을 수 없다면 아무일도 하지 않는다.
// 트리에서 data를 찾아 삭제한다.
// [노드 now를 삭제하는  프로세스]
// 1. child 노드가 없다면 삭제한다.
// 2. child가 하나뿐이라면 now자리를 child가 대신한다.
// 3. child가 lch, rch 두 개라면 now->data보다 크고
//    now->data에 가장 가까운 노드(이를 target이라 하자)를 삭제하고
//    target->data가 now->data 자리를 채운다.


int findMin(Node *p)
{
	for (; p->lch; p = p->lch);
	return p->data;
}

Node *eraseNode(Node *now, int tg)
{
	if (now->data == tg)
	{
		if (now->lch && now->rch)
		{
			int minValue = findMin(now->rch);
			now->data = minValue;
			now->rch = eraseNode(now->rch, minValue);
			return now;
		}
		if (now->lch)
			return now->lch;
		return now->rch;
	}

	if (tg < now->data)
	{
		now->lch = eraseNode(now->lch, tg);
	}
	else
	{
		now->rch = eraseNode(now->rch, tg);
	}
	return now;
}
void erase(int data) {
	if (search(data) == 0)
		return;
	tree.nodeCnt--;
	tree.root = eraseNode(tree.root, data);
}

int *ap, idx, cmd;

void traverse(Node *now) {
	
	if (now == NULL)
		return;
	if (cmd == 4)
		ap[idx++] = now->data;
	traverse(now->lch);
	if (cmd == 5)
		ap[idx++] = now->data;
	traverse(now->rch);
	if (cmd == 6)
		ap[idx++] = now->data;
}


// tree를 전위순회한 결과를 arr에 담는다.
void preorder(Tree*tree, int*arr) {

	ap = arr, idx = 0, cmd = 4;
	traverse(tree->root);

}

// tree를 중위순회한 결과를 arr에 담는다.
void inorder(Tree*tree, int*arr) {

	ap = arr, idx = 0, cmd = 5;
	traverse(tree->root);
}

// tree를 후위순회한 결과를 arr에 담는다.
void postorder(Tree*tree, int*arr) {
	ap = arr, idx = 0, cmd = 6;
	traverse(tree->root);
}
