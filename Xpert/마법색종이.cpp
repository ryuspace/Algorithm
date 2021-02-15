/*
1 간격으로 수평선과 수직선이 그어진 직사각형 모양의 마법 색종이를

가로 방향과 세로 방향으로 잘라서 작은 직사각형 조각들로 나누려고 한다.

처음에는 흰색 색종이 한 조각이 주어진다.

이 후로 한 점씩 주어질 때마다 아래의 규칙을 따르면서 색종이 조각을 자른다.



(1) 주어진 점이 흰색 색종이 조각에 포함되면, 그 점을 지나는 ‘수평선’을 따라 자른다.

	이때 잘려진 두 조각 모두 ‘검정색’으로 색깔이 변한다.

(2) 주어진 점이 검정색 색종이 조각에 포함되면, 그 점을 지나는 ‘수직선’을 따라 자른다.

	이때 잘려진 두 조각 모두 ‘흰색’으로 색깔이 변한다.



흰색 마법 색종이의 가로 길이와 세로 길이, 그리고 색종이 안에 점들이 순서를 가지고 주어질 때,

위의 규칙을 따라 색종이를 모두 자른 후 만들어지는 색종이 조각들 중에서 넓이가 가장 큰 조각과

넓이가 가장 작은 조각의 넓이를 각각 구하는 프로그램을 작성하시오.



단, 입력으로 주어지는 점들 중 어떤 두 점도 같은 수평선 위에 놓이거나 같은 수직선 위에 놓이지 않는다.

또한 맨 처음 주어진 색종이의 둘레에 위치하는 점들도 입력되지 않는다.



색종이의 가로 길이와 세로 길이는 모두 양의 정수로 주어진다.

그리고 색종이를 자르기 위해서 주어지는 점들의 위치는 자르기 전 색종이의 왼쪽 아래 꼭짓점에서 가로 방향으로 떨어진 거리와

세로 방향으로 떨어진 거리를 나타내는 두개의 정수로 주어진다.



예를 들어 아래 그림들에서 점 1의 위치는 (5,4)이다.



만약 가로의 길이와 세로의 길이가 각각 8과 7인 색종이를 자르기 위한 점들의 위치가

(5,4), (2,3), (3,1), (7,6), (6,2)의 순서로 주어진다고 하자.



먼저 첫째 점에 의해서 색종이는 그림 1과 같이 두 검정색 조각으로 잘려진다.






그림 1




이어서 두 번째 점에 의해서 그림 1의 아래쪽 검정색 조각이 그림 2와 같이 두 흰색 조각으로 나누어진다.






그림 2




나머지 점들에 대해서도 모두 위와 같은 방식으로 색종이를 자르면 그림 3과 같이 된다.

이 경우 가장 큰 색종이 조각의 넓이는 21이고 가장 작은 색종이 조각의 넓이는 3이다.


첫째 줄에는 색종이의 가로의 길이와 세로의 길이를 나타내는 양의 정수가 빈칸을 사이에 두고 주어진다.


가로와 세로의 길이는 모두 40,000 이하이다.


둘째 줄에는 색종이를 자르기 위한 점의 개수를 나타내는 양의 정수 N이 주어진다. N은 30,000 이하이다.


셋째 줄부터 마지막 줄까지 색종이를 자르기 위한 점들의 위치가 한 줄에 하나씩 순서대로 주어진다.



점들의 위치는 빈칸을 사이에 두고 가로 방향의 거리가 주어진 다음 세로 방향의 거리가 주어진다.


첫째 줄에 잘려진 색종이 조각 중에서 가장 넓이가 큰 조각의 넓이와
가장 작은 조각의 넓이가 몇 인지를 빈칸을 사이에 두고 순서대로 출력한다.


https://www.youtube.com/watch?v=tFYKe4T8mGg&feature=youtu.be
*/
/*풀이 :
노드 기준으로 양 옆으로 나뉘는 종이의 정보를 트리 구조로 담는다.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define NULL 0
#define MAXN 30000
int r, c;
int n;
int maxi = 0;
int mini = 1e9;
struct node
{
	int sx, sy, ex, ey, color;
	struct node* left;
	struct node* right;
};

int tmpIdx;
node tmpNode[2 * (MAXN + 10)];
node* tree;
node* alloc(int sx, int sy, int ex, int ey, int color)
{
	node* np = &tmpNode[tmpIdx++];
	np->sx = sx;
	np->sy = sy;
	np->ex = ex;
	np->ey = ey;
	np->color = color;
	np->left = np->right = NULL;

	return np;
}

void findMe(int x, int y)
{
	node* head = tree;
	while (head->left)
	{
		
		node* leftChild = head->left;
		node* rightChild = head->right;

		if (leftChild->sx <= x && leftChild->sy <= y && leftChild->ex >= x && leftChild->ey >= y)
		{
			head = head->left;
		}
		else
		{
			head = head->right;
		}
	}

	if (head->color == 0)
	{
		head->left= alloc(head->sx, head->sy, head->ex, y,1);
		head->right = alloc(head->sx, y, head->ex, head->ey, 1);

	}
	else
	{
		head->left = alloc(head->sx, head->sy, x, head->ey, 0);
		head->right = alloc(x, head->sy, head->ex, head->ey, 0);
	}
}


void findLeaf(node* head)
{
	if (head->left == NULL)
	{
		if (mini > (head->ex - head->sx) * (head->ey - head->sy))
		{
			mini = (head->ex - head->sx) * (head->ey - head->sy);
		}

		if (maxi < (head->ex - head->sx) * (head->ey - head->sy))
		{
			maxi = (head->ex - head->sx) * (head->ey - head->sy);
		}
		return;
	}
	findLeaf(head->left);
	findLeaf(head->right);
}
int main()
{

	scanf("%d %d", &r, &c);
	scanf("%d", &n);

	tree = alloc(0, 0, r, c,0);

	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		findMe(a, b);
	}
	findLeaf(tree);
	printf("%d %d", maxi, mini);
	return 0;
}
