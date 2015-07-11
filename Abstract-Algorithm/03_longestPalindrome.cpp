#include <iostream>
#include <string>

using namespace std;

/*
 * my first try, a wrong answer
 */
int main()
{
    int N;
    string src;
    
    cin >> N;
    while (N > 0) {
        cin >> src;
        int rlen = 0, llen = 0;
        
        size_t beg = 0;
        size_t end = src.size() - 1;
        
        while (beg != end || beg == end - 1) {
            if (src[beg] == src[end]) {
                beg++;
                end--;
                rlen++;
            } else {
                end--;
                rlen = 0;
            }
        }
        
        beg = 0;
        end = src.size() - 1;
        
        while (beg != end ) {
            if (src[beg] == src[end]) {
                beg++;
                end--;
                llen++;
            } else {
                beg++;
                llen = 0;
            }
        }
        
        if (rlen >= llen)
            cout << 2 * rlen + 1 << endl;
        else
            cout << 2 * llen + 1 << endl;
        
        //cout << src.size() << endl;
        N--;
    }
    
    return 0;
}
