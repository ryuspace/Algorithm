//https://www.acmicpc.net/problem/17176
/*풀이 : 문자열 처리 개념이 없어서 힘들었다 .. string으로 처음에 접근했는데
어떤 문젠지는 모르겠는데 자꾸 틀렸다고 한다 ㅠㅠ 그래서 char로 바꿨더니 된다..!
char이 우선 다루기는 편한거 같다 버퍼나 띄어쓰기 이런 문제였을까*/
#include <iostream>
#include <algorithm>

using namespace std;

int check[53];

int main()
{
	ios_base::sync_with_stdio(0);
	int n;
	char name;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		check[a]++;//숫자 담기
	}
	getchar();
	for (int i = 0; i < n; i++)
	{
		scanf("%c", &name);
		if (name == ' ')
		{
			if (check[0] >= 1)//띄어쓰기는 0번에 있다
			{
				check[0]--;
			}
			else
			{
				printf("n");
				exit(0);
			}
		}
		else if (name >= 'A' && name <= 'Z')
		{
			if (check[name - 'A' + 1] >= 1)//알파벳을 숫자로 대응시킴
			{
				check[name - 'A' + 1]--;
			}
			else
			{
				printf("n");
				exit(0);
			}
		}
		else if (name >= 'a' && name <= 'z')
		{
			if (check[name - 'a' + 27] >= 1)
			{
				check[name - 'a' + 27]--;
			}
			else
			{
				printf("n");
				exit(0);
			}
		}
	}
	printf("y");
	return 0;
}
