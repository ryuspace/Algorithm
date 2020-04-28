//https://www.acmicpc.net/problem/1927
/*풀이 : 최대 힙 구하는 방식에 음수 값을 넣어주면 최소 힙이 된다.*/
#include <iostream>
#include <algorithm>

using namespace std;

int n;
class Heap
{
public:
	int _sz;
	int* heapArr;
	void push_swap(int cur)
	{
		if (cur == 1)
			return;
		int par = cur / 2;
		if (heapArr[cur] > heapArr[par])
		{
			int tmp = heapArr[par];
			heapArr[par] = heapArr[cur];
			heapArr[cur] = tmp;
			push_swap(cur/2);
		}
	}
	void pop_swap(int cur)
	{
		int left, right, child;
		left = (cur * 2 <= _sz ? cur * 2 : -1);
		right = (cur * 2 + 1 <= _sz ? cur * 2 + 1 : -1);
		if (left == -1 && right == -1)
			return;
		else if (left != -1 && right == -1)
		{
			child = left;
		}
		else
		{
			child = (heapArr[left] > heapArr[right] ? left : right);
		}
		if (heapArr[cur] < heapArr[child])
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
		heapArr = new int[n + 1];
	}
	~Heap()
	{
		delete[]heapArr;
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
int main()
{
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	
	cin >> n;
	Heap hi(n);
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		if (tmp == 0)
		{
			if (hi.empty())
			{
				cout << 0 << '\n';
			}
			else
			{
				cout << -hi.last() << '\n';
				hi.pop();
			}
			
		}
		else
		{
			hi.push(-tmp);
		}
	}
	return 0;
}
