class Solution {
public:
	/**
	 * O(m + n) time complexity
	 *
	 */
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        size_t len1 = nums1.size();
        size_t len2 = nums2.size();
        size_t len = len1 + len2;
        vector<int> comb(len, 0);
        
        size_t i = 0, j = 0, k = 0;
        for (k = 0; k < len && i < len1 && j < len2; ++k) {
            if (nums1[i] < nums2[j]) {
                comb[k] = nums1[i];
                i++;
            } else {
                comb[k] = nums2[j];
                j++;
            }
        }
        if (i < len1) {
            for (;k < len && i < len1; ++k)
                comb[k] = nums1[i++];
        }
        if (j < len2) {
            for (;k < len && j < len2; ++k)
                comb[k] = nums2[j++];
        }
        
        /*if ((len) % 2 != 0 )
            return comb[(len) / 2];
        else
            return (comb[len / 2] + comb[len/2 -1]) / 2.0;*/    // use 2.0 is very important
        
        // a alternative method
        return ( comb[(len-1) / 2] + comb[len/2] ) / 2.0;
        
    }
};


class Solution {
public:
	// O ( log(m+n) ) method
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        size_t len1 = nums1.size();
        size_t len2 = nums2.size();
        size_t k = (len1 + len2) / 2;
        
        int res1 = getKth(nums1.begin(), len1, nums2.begin(), len2, k + 1);
        if ((len1 + len2) % 2 == 0) {
            int res2 = getKth(nums1.begin(), len1, nums2.begin(), len2, k);   
            return (res1 + res2) / 2.0;     // use 2.0 is very important
        }
        return res1;
    }
    
private:
    
    typedef vector<int>::iterator Iter;
    int getKth(Iter n1, int len1, Iter n2, int len2, int k) {
        if (len1 < len2)
            return getKth(n2, len2, n1, len1, k);
        if (len2 == 0)
            return *(n1 + k - 1);
        if (k == 1)
            return min(*n1, *n2);
            
        int j = min(len2, k/2);
        int i = k - j;
        if (*(n1 + i - 1) > *(n2 + j - 1))
            return getKth(n1, len1, n2+j, len2-j, k-j);
        else
            return getKth(n1+i, len1-i, n2, len2, k-i);
    }
};

