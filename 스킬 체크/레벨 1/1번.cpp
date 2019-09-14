#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    long long minn=min(a,b);
    long long maxx=max(a,b);
    for(long long i=minn;i<=maxx;i++)
    {
        answer+=i;
    }
    return answer;
}
