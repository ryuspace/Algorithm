int lowerBound(int target) //찾는 수가 없으면 n번째 인덱스 가리킴 배열 범위는 (0~n-1)
{
	int le = 0;
	int ri = n;
	while (le < ri)
	{
		int mid = (le + ri) / 2;
		if (arr[mid] >= target)
			ri = mid;
		else
			le = mid + 1;
	}
	return ri;
}
