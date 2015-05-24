

/*
** a simple partition function
*/
int Partition1(int a[], int low, int high)
{
	int rol = a[low];
	
	while (low < high) {
		while (a[high] >= rol && low < high)
			high--;
		a[low] = a[high];

		while (a[low] < rol && low < high)
			low++;
		a[high] = a[low];
	}
	a[low] = rol;
	return low;
}


/*
** recursive version
*/
void QuickSort1(int a[], int low, int high)
{
	if (low < high) {
		int i = Partition1(a, low, high);
		QuickSort1(a, low, i-1);
		QuickSort1(a, i+1, high);
	}
}
