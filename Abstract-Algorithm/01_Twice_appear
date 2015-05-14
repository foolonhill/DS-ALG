/*
* corpiright @ Luo yuyang, 2015
*
* Problem description:
*         an array, only one element appears twice, others all once. Find the twice one.
*/

int main()
{
    int a[] = {1, 2, 2, 3, 4, 5, 6, 7,  8, 9, 10};
    
    int ret = Twice(a, 11);
    
    std::cout << ret << '\n';
}

// direct solution, time consuming O(n^2)
int Twice(int a[], int size)
{
    int twice = 0;
    for (int i = 0; i < size; i++) {
        for (int j = i - 1; j >= 0; j-- ) {
            if (a[i] == a[j]) {
                twice = j;
                break;
            }
        }
    }
    
    return a[twice];
}

