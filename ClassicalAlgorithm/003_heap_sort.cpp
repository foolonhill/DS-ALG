// adjust to max heap
void HeapAdjust(int a[], int s, int e)
{
	int tmp = a[s];
	
	for (int j = 2 * s; j <= e; j *= 2) {
		if (j < e && a[j] < a[j+1])
			j++;
		if (tmp > a[j])
			break;
		a[s] = a[j];
		s = j;
	}
	a[s] = tmp;
}


void HeapSort(int a[], int len)
{
	// create the heap
	for (int i = len/2; i >= 1; i--)
		HeapAdjust(a, i, len);

	int tmp;
	// swap the maximum to the end and adjust the heap
	for (int i = len; i >= 2; i--) {
		tmp = a[1];
		a[1] = a[i];
		a[i] = tmp;

		HeapAdjust(a, 1, i-1);
	}
}
 
