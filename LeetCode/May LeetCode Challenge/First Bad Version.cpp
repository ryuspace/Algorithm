/*
풀이 : N 제한이 엄청 큰 것 같다. O(n)도 TLE가 난다. 이분탐색으로 현재 수가 true면(무조건 이 전에 bad version이 있다)
right를 줄여주고 false면 left를 늘려준다
*/
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long int left = 1;
        long long int right = n;
        while(left<=right)
        {
            long long int mid = (left+right)/2;
            if(isBadVersion(mid))
            {
                right = mid-1;
            }
            else
            {
                left = mid+1;
            }
        }
        return left;
    }
};
