//https://www.acmicpc.net/problem/15763
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

bool visit1[27];
bool visit2[27];
char arr[3][3];
vector <char> v;
vector <char> win;
bool bfs1(int i,int j)
{
	win.clear();
	int start_x = 0;
	int start_y = j;
	bool flag = false;
	while (start_x < 3)
	{
		win.push_back(arr[start_x][start_y]);
		start_x++;
	}

	start_x = i;
	start_y=j;
	for (int m = 0; m < win.size(); m++)
	{
		if (win[m] != arr[start_x][start_y])
		{
			flag = true;
			break;
		}
	}
	if (win.size() != 0 && flag == false)
	{
		return true;
	}

	start_x = i;
	start_y = 0;
	win.clear();
	flag = false;
	while (start_y < 3)
	{
		win.push_back(arr[start_x][start_y]);
		start_y++;
	}
	start_x = i;
	start_y = j;
	for (int m = 0; m < win.size(); m++)
	{
		if (win[m] != arr[start_x][start_y])
		{
			flag = true;
			break;
		}
	}
	if (win.size() != 0 && flag == false)
	{
		return true;
	}

	start_x = 0;
	start_y = 0;
	win.clear();
	flag = false;
	while (start_x <3 && start_y <3)
	{
		
		win.push_back(arr[start_x][start_y]);
		start_x++;
		start_y++;
	}
	start_x = i;
	start_y = j;
	for (int m = 0; m < win.size(); m++)
	{
		if (win[m] != arr[start_x][start_y])
		{
			flag = true;
			break;
		}
	}
	if (win.size() != 0 && flag == false)
	{
		return true;
	}
	start_x = 2;
	start_y = 2;
	win.clear();
	flag = false;
	while (start_x >= 0 && start_y >= 0)
	{
		
		win.push_back(arr[start_x][start_y]);
		start_x--;
		start_y--;
	}
	start_x = i;
	start_x = j;
	for (int m = 0; m < win.size(); m++)
	{
		if (win[m] != arr[start_x][start_y])
		{
			flag = true;
			break;
		}
	}
	if (win.size() != 0 && flag == false)
	{
		return true;
	}

	return false;
}

bool bfs2(int i, int j)
{
	win.clear();
	int start_x = 0;
	int start_y = j;
	bool flag = false;
	while (start_x < 3)
	{
		win.push_back(arr[start_x][start_y]);
		start_x++;
	}

	start_x = i;
	start_y = j;
	for (int m = 0; m < win.size(); m++)
	{
		if (win[m] != arr[start_x][start_y])
		{
			flag = true;
			break;
		}
	}
	if (win.size() != 0 && flag == false)
	{
		return true;
	}

	start_x = i;
	start_y = 0;
	win.clear();
	flag = false;
	while (start_y < 3)
	{
		win.push_back(arr[start_x][start_y]);
		start_y++;
	}
	start_x = i;
	start_y = j;
	for (int m = 0; m < win.size(); m++)
	{
		if (win[m] != arr[start_x][start_y])
		{
			flag = true;
			break;
		}
	}
	if (win.size() != 0 && flag == false)
	{
		return true;
	}

	
	return false;
}
vector < pair<char, char> > duet;
void bfs3(int i, int j)
{
	win.clear();
	int start_x = 0;
	int start_y = j;
	while (start_x < 3)
	{
		bool flag2 = false;
		for (int k = 0; k < win.size(); k++)
		{
			if (win[k] == arr[start_x][start_y])
				flag2 = true;
		}
		if (!flag2)
		{
			win.push_back(arr[start_x][start_y]);

		}
		start_x++;
	}

	start_x = i;
	start_y = j;
	if (win.size() == 2)
	{
		bool flag2 = false;
		sort(win.begin(), win.end());

		for (int m = 0; m < duet.size(); m++)
		{
			if (duet[m].first == win[0] && duet[m].second == win[1])
			{
				flag2 = true;
			}
		}
		if (flag2 == false)
		{
			duet.push_back({ win[0],win[1] });
		}
	}


	start_x = i;
	start_y = 0;
	win.clear();
	while (start_y < 3)
	{
		bool flag2 = false;
		for (int k = 0; k < win.size(); k++)
		{
			if (win[k] == arr[start_x][start_y])
				flag2 = true;
		}
		if (!flag2)
		{
			win.push_back(arr[start_x][start_y]);

		}
		start_y++;
	}
	start_x = i;
	start_y = j;
	if (win.size() == 2)
	{
		bool flag2 = false;
		sort(win.begin(), win.end());

		for (int m = 0; m < duet.size(); m++)
		{
			if (duet[m].first == win[0] && duet[m].second == win[1])
			{
				flag2 = true;
			}
		}
		if (flag2 == false)
		{
			duet.push_back({ win[0],win[1] });
		}
	}

	start_x = 0;
	start_y = 0;
	win.clear();

	while (start_x < 3 && start_y < 3)
	{
		bool flag2 = false;
		for (int k = 0; k < win.size(); k++)
		{
			if (win[k] == arr[start_x][start_y])
				flag2 = true;
		}
		if (!flag2)
		{
			win.push_back(arr[start_x][start_y]);

		}
		start_x++;
		start_y++;
	}
	start_x = i;
	start_y = j;
	if (win.size() == 2)
	{
		bool flag2 = false;
		sort(win.begin(), win.end());

		for (int m = 0; m < duet.size(); m++)
		{
			if (duet[m].first == win[0] && duet[m].second == win[1])
			{
				flag2 = true;
			}
		}
		if (flag2 == false)
		{
			duet.push_back({ win[0],win[1] });
		}
	}

	start_x = 2;
	start_y = 2;
	win.clear();

	while (start_x >= 0 && start_y >= 0)
	{
		bool flag2 = false;
		for (int k = 0; k < win.size(); k++)
		{
			if (win[k] == arr[start_x][start_y])
				flag2 = true;
		}
		if (!flag2)
		{
			win.push_back(arr[start_x][start_y]);

		}
		start_x--;
		start_y--;
	}
	start_x = i;
	start_y = j;
	if (win.size() == 2)
	{
		bool flag2 = false;
		sort(win.begin(), win.end());

		for (int m = 0; m < duet.size();m++)
		{
			if (duet[m].first == win[0] && duet[m].second == win[1])
			{
				flag2 = true;
			}
		}
		if (flag2 == false)
		{
			duet.push_back({ win[0],win[1] });
		}
	}
}

void bfs4(int i, int j)
{
	win.clear();
	int start_x = 0;
	int start_y = j;
	while (start_x < 3)
	{
		bool flag2 = false;
		for (int k = 0; k < win.size(); k++)
		{
			if (win[k] == arr[start_x][start_y])
				flag2 = true;
		}
		if (!flag2)
		{
			win.push_back(arr[start_x][start_y]);

		}
		start_x++;
	}

	start_x = i;
	start_y = j;
	if (win.size() == 2)
	{
		bool flag2 = false;
		sort(win.begin(), win.end());

		for (int m = 0; m < duet.size(); m++)
		{
			if (duet[m].first == win[0] && duet[m].second == win[1])
			{
				flag2 = true;
			}
		}
		if (flag2 == false)
		{
			duet.push_back({ win[0],win[1] });
		}
	}


	start_x = i;
	start_y = 0;
	win.clear();
	while (start_y < 3)
	{
		bool flag2 = false;
		for (int k = 0; k < win.size(); k++)
		{
			if (win[k] == arr[start_x][start_y])
				flag2 = true;
		}
		if (!flag2)
		{
			win.push_back(arr[start_x][start_y]);

		}
		start_y++;
	}
	start_x = i;
	start_y = j;
	if (win.size() == 2)
	{
		bool flag2 = false;
		sort(win.begin(), win.end());

		for (int m = 0; m < duet.size(); m++)
		{
			if (duet[m].first == win[0] && duet[m].second == win[1])
			{
				flag2 = true;
			}
		}
		if (flag2 == false)
		{
			duet.push_back({ win[0],win[1] });
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	for (int i = 0; i < 3; i++)
	{
		string tmp;
		cin >> tmp;
		for (int j = 0; j < 3; j++)
		{
			arr[i][j] = tmp[j];
			if (visit2[arr[i][j] - 'A'] == false)
			{
				v.push_back(arr[i][j]);
				visit2[arr[i][j] - 'A'] = true;
			}
		}
	}
///////////////////////////////////
	int solo= 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (visit1[arr[i][j] - 'A'] == false && (i+j)%2==0)
			{
				if (bfs1(i, j))
				{
					visit1[arr[i][j] - 'A'] = true;
					solo++;
				}
			}
			else if (visit1[arr[i][j] - 'A'] == false && (i + j) % 2 != 0)
			{
				if (bfs2(i, j))
				{
					visit1[arr[i][j] - 'A'] = true;
					solo++;
				}
			}

		}
	}
	cout << solo<<'\n';

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if ((i + j) % 2 == 0)
			{
				bfs3(i, j);
			}
			else if ((i + j) % 2 != 0)
			{
				bfs4(i, j);
			}

		}
	}
	cout << duet.size();
	return 0;
}
