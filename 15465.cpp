//https://www.acmicpc.net/problem/15465
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<pair<int, pair<string, int> > > v;
map<string, int> m;
int arr[3];
int main()
{
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	int n;
	cin >> n;
	while (n--)
	{
		int day;
		string name;
		string out;
		string out2 = "";
		int output;
		cin >> day >> name >> out;
		if (out[0] == '-')
		{
			for (int i = 1; i < out.length(); i++)
			{
				out2 += out[i];
			}
			output = -(stoi(out2));
		}
		else
		{
			for (int i = 1; i < out.length(); i++)
			{
				out2 += out[i];
			}
			output = (stoi(out2));
		}
		v.push_back({ day,{ name,output } });
	}
	sort(v.begin(), v.end());

	int cnt = 0;
	string current = "";
	for (int i = 0; i<v.size(); i++)
	{
		if (v[i].second.first == "Bessie")
		{
			arr[0] += v[i].second.second;
		}
		else if (v[i].second.first == "Elsie")
		{
			arr[1] += v[i].second.second;
		}
		else
		{
			arr[2] += v[i].second.second;
		}
		int Max = 0;
		for (int i = 0; i < 3; i++)
		{
			Max = max(arr[i], Max);
		}
		string current2 = "";
		for (int i = 0; i < 3; i++)
		{
			if (arr[i] == Max)
			{
				if (i == 0)
				{
					current2 += "Bessie";
				}
				else if (i == 1)
				{
					current2 += "Elsie";
				}
				else
				{
					current2 += "Mildred";
				}
			}
		}
		if (current != current2)
		{
			cnt++;
		}
		current = current2;
	}
	cout << cnt;

	return 0;
}
