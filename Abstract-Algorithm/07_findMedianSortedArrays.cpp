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
