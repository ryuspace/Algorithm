//https://www.acmicpc.net/problem/16199
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

struct Date
{
	int year;
	int month;
	int day;
};
int main()
{
	Date last, now;
	char str[2][11];
	cin.getline(str[0], 11);
	cin.getline(str[1], 11);

	last.year = atoi(strtok(str[0], " "));
	last.month = atoi(strtok(NULL, " "));
	last.day = atoi(strtok(NULL, " "));

	now.year = atoi(strtok(str[1], " "));
	now.month = atoi(strtok(NULL, " "));
	now.day = atoi(strtok(NULL, " "));

	if (last.month < now.month)//생일 지남
	{
		cout << now.year - last.year << "\n";
		cout << now.year - last.year + 1 << "\n";
		cout << now.year - last.year << "\n";
	}
	else if (last.month == now.month && last.day <= now.day)//생일 지남
	{
		cout << now.year - last.year << "\n";
		cout << now.year - last.year + 1 << "\n";
		cout << now.year - last.year << "\n";
	}
	else//생일 안지남
	{
		cout << now.year - last.year - 1 << "\n";
		cout << now.year - last.year + 1 << "\n";
		cout << now.year - last.year << "\n";
	}
}
