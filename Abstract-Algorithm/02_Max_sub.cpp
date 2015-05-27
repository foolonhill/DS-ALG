/*********
 *
 * problem description : 求连续子序列的最大和
 * 
 */

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

	int max_sofar = 0;
	int max_ending_here = 0;

	for (int i = 1; i < n; i++) {
		// 得到当前元素之前所有元素的最大和，保证每一阶段大于零
		max_sofar += a[i-1];
		max_sofar = max(max_sofar, 0);
		
		// 加上当前元素后，再取较大值
		max_ending_here = max_sofar + a[i];
		max_ending_here = max(max_ending_here, max_sofar);   
	}

	return max_here;
}


/*
** 《programming pearls》 version, O(n)
*/
int MaxSub2(int a[], int n)
{
	int max_sofar = 0;
	int max_ending_here = 0;

	for (int i = 0; i < n; i++) {

		max_ending_here = max(max_ending_here + a[i], 0);

		max_sofar = max(max_sofar, max_ending_here);
	}

	return max_sofar;
}

/***
 * version 3, O(n)
 * 
 */
int MaxSub3(int a[], int n)
{
	int max_sum = 0;
	int max_before = 0;

	for (int i = 0; i < n; i++) {
		max_before += a[i];
		if (max_before <= 0)
			max_before = 0;

		if (max_before > max_sum)
			max_sum = max_before;
	}

	return max_sum;
}
