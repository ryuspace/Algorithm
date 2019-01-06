//https://www.acmicpc.net/problem/14174
#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
using namespace std;

string a[101];
string b[101];

int alpha[1000];

int alpha_acnt[1000];
int alpha_bcnt[1000];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i] >> b[i];
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < a[i].length(); j++)
		{
			alpha_acnt[a[i][j]]++;
		}
		for (int j = 0; j < b[i].length(); j++)
		{
			alpha_bcnt[b[i][j]]++;
		}
		for (int k = 'a'; k <= 'z'; k++)
		{
			alpha[k] +=max(alpha_acnt[k], alpha_bcnt[k]);
		}
		
		for (int r = 0; r < 1000; r++)
		{
			alpha_acnt[r] = 0;
			alpha_bcnt[r] = 0;
		}
	}
	for (int i = 'a'; i <= 'z'; i++)
	{
		cout << alpha[i] << '\n';
	}
	return 0;
}
