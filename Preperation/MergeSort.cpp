void mergeSort(int s, int e)
{
	if (s >= e)
		return;

	int m = (s + e) / 2;
	
	mergeSort(s, m);
	mergeSort(m + 1, e);

	int i = s, j = m + 1;
	int idx = s;
	while (i <= m && j <= e)
	{
		if (arr[i] < arr[j])
		{
			tmp[idx++] = arr[i++];
		}
		else
		{
			tmp[idx++] = arr[j++];
		}
	}

	while (i <= m)
	{
		tmp[idx++] = arr[i++];
	}
	while (j <= e)
	{
		tmp[idx++] = arr[j++];
	}

	for (int i = s; i <= e; i++)
	{
		arr[i] = tmp[i];
	}
}
