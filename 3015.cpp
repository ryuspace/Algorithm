//https://www.acmicpc.net/problem/3015
/*풀이 : 현재 등장하는 값을 기준으로 이전 값들과 마주볼 수 있는지 체크하는게 관건.
*/
#include<iostream>
#include<stack>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	long long ans = 0;
	stack<pair<long long int, long long int> > st;                        // 키, 그 키를 가지는 인원 

	for (int i = 0; i < n; i++) {
		int high;
		cin >> high;
		pair<int, int> p = make_pair(high, 1);                // 키, 인원 

		while (!st.empty()) {
			if (st.top().first <= high) {                // 자기보다 키가 큰 상대가 나타난 경우 
				ans += st.top().second;        // 우선은 1을 증가시킨다. (키가 같더라도 1 증가 => 서로 마주보기 가능) 
				if (st.top().first == high)            // 같다면 (한 뭉텅이로 만들어 준다. 뒤에 더 큰 놈 나오면 또 마주볼 수 있으니깐) 
					p.second += st.top().second;        // 해당하는 인원을 증가시킨다. 
				st.pop();                    // 자기보다 키가 큰 상대가 나타났기 때문에, 더 이상은 무의미하다. pop 
			}
			else {
				if (!st.empty())                // 자기보다 키가 작은 상대가 나타남 (어깨 너머로 볼 수 있다)
					ans ++;                // 서로 마주보기 가능 
				break;
			}
		}
		st.push(p);                            // 첫 번째 사람, 자기보다 키가 더 작은 사람이 나타나면 push 
	}
	cout << ans;
	return 0;
}
