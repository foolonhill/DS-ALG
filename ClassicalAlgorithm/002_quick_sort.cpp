
/*
** a simple partition function:
*     one direction
*/
int Partition1(int a[], int low, int high)
{
	if (low >= high)
		return -1;

	int rol = a[low];
	int m = low;
	int tmp;
	for (int i = low+1; i <= high; i++) {
		if (a[i] < rol) {
			tmp = a[++m];
			a[m] = a[i];
			a[i] = tmp;
		}
	}

	tmp = a[m];
	a[m] = rol;
	a[low] = tmp;

	return m;
}

/*
** a better(mayebe) partition function:
**       two direction
*/
int Partition2(int a[], int low, int high)
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


/*
** recursive and combined version
*/
void QuickSort2(int a[], int low, int high)
{
	if (low < high) {
		int rol = a[low];
		int i, j;
		i = low;
		j = high;
		while (i < j) {
			while (i < j && a[j] >= rol)
				j--;
			a[i] = a[j];

			while (i < j && a[i] < rol)
				i++;
			a[j] = a[i];
		}

		a[i] = rol;

		QuickSort2(a, low, i-1);
		QuickSort2(a, i+1, high);
	}
}
/*
**  combined and non recursive version
*/
void NonRecursiveQuickSort1(int a[], int low, int high)
{
	stack<int> st;

	if (low < high) {
		st.push(low);
		st.push(high);

		while (!st.empty()) {
			int right = st.top();
			st.pop();
			int left = st.top();
			st.pop();

			int start = left;
			int end = right;
			int pivot = a[start];
			while (start < end) {
				while (start < end && a[end] >= pivot)
					end--;
				a[start] = a[end];

				while (start < end && a[start] < pivot)
					start++;
				a[end] = a[start];
			}
			a[start] = pivot;

			if (left < start -1 ) {
				st.push(left);
				st.push(start-1);
			}

			if (right > start + 1) {
				st.push(start+1);
				st.push(right);
			}
		}
	}
}
