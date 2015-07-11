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


/*
* my second answer. Right!
* uising DP (dynamic programming)
*/
class Solution {
public:
    string longestPalindrome(string str) {
        size_t length = str.size();
        size_t max_len = 1;
        size_t start = 0;
        
        bool p[1000][1000] = {false};
        for (size_t i = 0; i < length; i++) {
            p[i][i] = true;
            
            if (i < length - 1 && str[i] == str[i+1]) {
                p[i][i+1] = true;
                max_len = 2;
                start = i;
            }
        }
        
        for (size_t len = 3; len <= length; len++) {
            for (size_t i = 0; i < length - len + 1; i++) {
                size_t j = i + len - 1;
                
                if (str[i] == str[j] && p[i+1][j-1]) {
                    p[i][j] = true;
                    max_len = len;
                    start = i;
                }
            }
        }
        
        string ret;
        //if (max_len >= 2)
        ret = str.substr(start, max_len);
        
        return ret;    
    }
}
