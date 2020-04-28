/*풀이 : 맨 앞에 최대한 작은 숫자가 오는 것이 이득이므로
숫자 배열 마지막 인덱스부터 수를 스왑한다.
*/
#include <iostream>
#include <algorithm>

using namespace std;

int arr[101];
bool visit[101];
int main()
{
	int q, n;
	cin >> q;
	while (q--)
	{
		bool f = false;
		memset(visit, 0, sizeof(visit));
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		do
		{
			f = false;
			for (int i = n - 2; i >= 0; i--)
			{
				if (arr[i] > arr[i + 1] && !visit[i])
				{
					swap(arr[i], arr[i + 1]);
					visit[i] = true;
					f = true;
				}
			}
		} while (f);
		
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
		cout << '\n';
	}
	
	return 0;
}
