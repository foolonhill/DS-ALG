#include <iostream>

int main()
{    
    int a[] = {2, 5, 4, 8, 1, 3, 6, 7, 9};
    
    InsertSort2(a, 9);
    
    for (int i = 0; i < 9; i++ )
        std::cout << a[i] << std::endl;
}

/**
/* my first version:
/*    a direct solution, 
*/
void InsertSort(int a[], int n)
{
    int tmp;
    for (int i = 1; i < n; i++) {
        for (int j = i-1; j >= 0; j--) {
            if (a[j+1] < a[j]) {
                tmp = a[j+1];
                a[j+1] = a[j];
                a[j] = tmp;
            }
        }
    }
}


/**
/* an improved version:
/*      when a[j+1] > a[j], we should break the inner loop
*/
void InsertSort1(int a[], int n)
{
    int tmp;
    for (int i = 1; i < n; i++) {
        for (int j = i-1; j >= 0; j--) {
            if (a[j+1] < a[j]) {
                tmp = a[j+1];
                a[j+1] = a[j];
                a[j] = tmp;
            } else
                break;
        }
    }
}

/**
/* a better solution:
/*     we needn't swap each time, because we find tmp is 
/*  assigned the same value: a[i], so we put it outer the
/*  inner loop, where we just move the value
*/ 
void InsertSort2(int a[], int n)
{
    int i, j;
    for (i = 1; i < n; i++) {
	int tmp = a[i];
	for (j = i; j > 0; j--) {
            if (tmp < a[j-1])
		a[j] = a[j-1];
	    else
		break;
	}
	/*  an alternative way for the inner loop
	//for (j = i; j > 0 && tmp < a[j-1]; j--)
        //    a[j] = a[j-1];
	*/    
	    
	a[j] = tmp;
    }
}
