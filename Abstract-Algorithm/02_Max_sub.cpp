

int max(int a, int b)
{
	return a >= b ? a : b;
}

/*
** my first version, O(n)
*/
int MaxSub1(int a[], int n)
{
	if (n <= 0)
		return 0;
	
	if (n == 1)
		return a[0];

	int max_ending_here = 0;
	int max_here = 0;

	for (int i = 1; i < n; i++) {
		max_ending_here += a[i-1];
		max_ending_here = max(max_ending_here, 0);

		max_here = max_ending_here + a[i];
		max_here = max(max_here, max_ending_here);   
	}

	return max_here;
}
