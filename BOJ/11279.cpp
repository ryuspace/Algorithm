//https://www.acmicpc.net/problem/11279
//참고 주소 : http://crocus.co.kr/1184
/*풀이 : 힙을 직접 배열로 구현해봤다. 구현 자세한 부분 설명은 주석으로 표시해놓겠습니다.*/
#include <iostream>
#include <algorithm>

using namespace std;

class Heap
{
public:
	int _sz;
	int* heapArr;

	void push_swap(int cur)
	{
		if (cur == 1)//루트에 도착했으므로 바꿀게 없다!
		{
			return;

		}
		int par = cur / 2; //부모로 거슬러 올라가자..
		if (heapArr[par] < heapArr[cur])//자식이 더 크므로 위로 올리자.
		{
			int tmp = heapArr[par];
			heapArr[par] = heapArr[cur];
			heapArr[cur] = tmp;

			push_swap(cur / 2);
		}
	}
	void pop_swap(int cur)//cur은 트리의 마지막 값이겠지, 루트를 제거했으니까 규칙에 맞게 swap 해주자.
	{
		int left, right, child;
		left = (cur * 2 <= _sz ? cur * 2 : -1);
		right = (cur * 2 + 1 <= _sz ? cur * 2 + 1 : -1);
		if (left == -1 && right == -1)//자식이 하나도 없다.
		{
			return;
		}
		else if (left != -1 && right == -1)
			child = left;
		else
			child = (heapArr[left] > heapArr[right] ? left : right);
		if (heapArr[child] > heapArr[cur])
		{
			int tmp = heapArr[child];
			heapArr[child] = heapArr[cur];
			heapArr[cur] = tmp;
			pop_swap(child);
		}
	}
	Heap(int n)
	{
		_sz = 0;
		heapArr = new int[n + 1];//N만큼의 사이즈의 힙을 만든다.
	}
	~Heap()
	{
		delete[] heapArr;
	}
	void push(int val)
	{
		heapArr[++_sz] = val;
		push_swap(_sz);
	}
	void pop()
	{
		heapArr[1] = heapArr[_sz--];
		pop_swap(1);
	}
	int empty()
	{
		return !_sz;
	}
	int last()
	{
		return heapArr[1];
	}

};

int n;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	Heap hi(n);
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		if (num == 0)
		{
			if (hi.empty())
			{
				cout << 0 << '\n';
			}
			else
			{
				cout << hi.last() << '\n';
				hi.pop();
			}
		}
		else
		{
			hi.push(num);
		}
	}
	return 0;
}
