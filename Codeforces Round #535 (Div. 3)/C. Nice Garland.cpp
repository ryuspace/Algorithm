#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	int n;
	string name;
	cin >> n >> name;
	if (n == 1)
	{
		cout << 0 << '\n';
		cout << name;
		exit(0);
	}
	if (n == 2)
	{
		if (name[0] == name[1])
		{
			if (name[0] == 'R')
			{
				name[1] = 'G';
			}
			else if (name[0] == 'G')
			{
				name[1] = 'B';
			}
			else
			{
				name[1] = 'R';
			}
			cout << 1 << '\n';
			cout << name;
			exit(0);

		}
		else
		{
			cout << 0 << '\n';
			cout << name;
			exit(0);
		}
	}
	else
	{
		string tmp1 = "RGB";
		string tmp2 = "RBG";
		string tmp3 = "GRB";
		string tmp4 = "GBR";
		string tmp5 = "BRG";
		string tmp6 = "BGR";


		int cnt = 0;
		int Max = 1e9;
		int Max_idx = 0;
		int idx = 1;
		string name2 = "";
		for (int i = 0; i < (n / 3)*3; i++)
		{
			name2 += tmp1[i%3];
		}
		if (n % 3 == 1)
		{
			name2 += tmp1[0];
		}
		else if (n % 3 == 2)
		{
			name2 += tmp1[0];
			name2 += tmp1[1];
		}
		for (int i = 0; i < n; i++)
		{
			if (name[i] != name2[i])
			{
				cnt++;
			}
		}
		if (cnt < Max)
		{
			Max = cnt;
			Max_idx = idx;
		}
		idx++;
		cnt = 0;

		name2 = "";
		for (int i = 0; i < (n / 3) * 3; i++)
		{
			name2 += tmp2[i % 3];
		}
		if (n % 3 == 1)
		{
			name2 += tmp2[0];
		}
		else if (n % 3 == 2)
		{
			name2 += tmp2[0];
			name2 += tmp2[1];
		}
		for (int i = 0; i <  n; i++)
		{
			if (name[i] != name2[i])
			{
				cnt++;
			}
		}
		if (cnt < Max)
		{
			Max = cnt;
			Max_idx = idx;
		}
		idx++;
		cnt = 0;
		name2 = "";
		for (int i = 0; i < (n / 3) * 3; i++)
		{
			name2 += tmp3[i % 3];
		}
		if (n % 3 == 1)
		{
			name2 += tmp3[0];
		}
		else if (n % 3 == 2)
		{
			name2 += tmp3[0];
			name2 += tmp3[1];
		}
		for (int i = 0; i <  n; i++)
		{
			if (name[i] != name2[i])
			{
				cnt++;
			}
		}
		if (cnt <= Max)
		{
			Max = cnt;
			Max_idx = idx;
		}
		idx++;
		cnt = 0;

		name2 = "";
		for (int i = 0; i < (n / 3) * 3; i++)
		{
			name2 += tmp4[i % 3];
		}
		if (n % 3 == 1)
		{
			name2 += tmp4[0];
		}
		else if (n % 3 == 2)
		{
			name2 += tmp4[0];
			name2 += tmp4[1];
		}
		for (int i = 0; i <  n; i++)
		{
			if (name[i] != name2[i])
			{
				cnt++;
			}
		}
		if (cnt < Max)
		{
			Max = cnt;
			Max_idx = idx;
		}
		idx++;
		cnt = 0;
		name2 = "";
		for (int i = 0; i < (n / 3) * 3; i++)
		{
			name2 += tmp5[i % 3];
		}
		if (n % 3 == 1)
		{
			name2 += tmp5[0];
		}
		else if (n % 3 == 2)
		{
			name2 += tmp5[0];
			name2 += tmp5[1];
		}
		for (int i = 0; i <  n; i++)
		{
			if (name[i] != name2[i])
			{
				cnt++;
			}
		}
		if (cnt < Max)
		{
			Max = cnt;
			Max_idx = idx;
		}
		idx++;
		cnt = 0;
		name2 = "";
		for (int i = 0; i < (n / 3) * 3; i++)
		{
			name2 += tmp6[i % 3];
		}
		if (n % 3 == 1)
		{
			name2 += tmp6[0];
		}
		else if (n % 3 == 2)
		{
			name2 += tmp6[0];
			name2 += tmp6[1];
		}
		for (int i = 0; i <  n; i++)
		{
			if (name[i] != name2[i])
			{
				cnt++;
			}
		}
		if (cnt < Max)
		{
			Max = cnt;
			Max_idx = idx;
		}
		cnt = 0;

		if (Max_idx == 1)
		{
			name2 = "";
			for (int i = 0; i < (n / 3) * 3; i++)
			{
				name2 += tmp1[i % 3];
			}
			if (n % 3 == 1)
			{
				name2 += tmp1[0];
			}
			else if (n % 3 == 2)
			{
				name2 += tmp1[0];
				name2 += tmp1[1];
			}
		}
		else if (Max_idx == 2)
		{
			name2 = "";
			for (int i = 0; i < (n / 3) * 3; i++)
			{
				name2 += tmp2[i % 3];
			}
			if (n % 3 == 1)
			{
				name2 += tmp2[0];
			}
			else if (n % 3 == 2)
			{
				name2 += tmp2[0];
				name2 += tmp2[1];
			}
		}
		else if (Max_idx == 3)
		{
			name2 = "";
			for (int i = 0; i < (n / 3) * 3; i++)
			{
				name2 += tmp3[i % 3];
			}
			if (n % 3 == 1)
			{
				name2 += tmp3[0];
			}
			else if (n % 3 == 2)
			{
				name2 += tmp3[0];
				name2 += tmp3[1];
			}
		}
		else if (Max_idx == 4)
		{
			name2 = "";
			for (int i = 0; i < (n / 3) * 3; i++)
			{
				name2 += tmp4[i % 3];
			}
			if (n % 3 == 1)
			{
				name2 += tmp4[0];
			}
			else if (n % 3 == 2)
			{
				name2 += tmp4[0];
				name2 += tmp4[1];
			}
		}
		else if (Max_idx == 5)
		{
			name2 = "";
			for (int i = 0; i < (n / 3) * 3; i++)
			{
				name2 += tmp5[i % 3];
			}
			if (n % 3 == 1)
			{
				name2 += tmp5[0];
			}
			else if (n % 3 == 2)
			{
				name2 += tmp5[0];
				name2 += tmp5[1];
			}
		}
		else if (Max_idx == 6)
		{
			name2 = "";
			for (int i = 0; i < (n / 3) * 3; i++)
			{
				name2 += tmp6[i % 3];
			}
			if (n % 3 == 1)
			{
				name2 += tmp6[0];
			}
			else if (n % 3 == 2)
			{
				name2 += tmp6[0];
				name2 += tmp6[1];
			}
		}

		cout << Max << '\n';
		cout<< name2;
	}
	return 0;
}
