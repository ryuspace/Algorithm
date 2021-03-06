//https://codeforces.com/contest/1100/problem/C
#include <iostream>
#include <algorithm>
#include <math.h>
#define pi 3.14159265359
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	double n, r;
	cin >> n >> r;
	double value = (((360 / n) / 2) * (pi / 180));
	double rad = (sin(value) / (1 - sin(value)))*r;
	cout.precision(7);
	cout << rad;

	return 0;
}
