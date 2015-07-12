/*
* Source: https://leetcode.com/problems/search-in-rotated-sorted-array/
*
*
*/


class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Note!!!
        // -- right, left, mid must be definied as "int" type, not "size_t" because they may be negative when the input is 
        // -- bad such as "[3, 1], 2"
        int right = nums.size() - 1;                   
        int left = 0;
        int mid;
        
        if (nums[left] > nums[right]) {                // rotated
            while (left <= right) {
                mid = (right + left) / 2;
            
                if (nums[mid] == target)
                    return mid;
                else if ( (nums[mid] > target && target > nums[right]) || (nums[mid] < nums[right] && nums[right] < target) ||
                            (target < nums[mid] && nums[mid] < nums[right]) )
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        } else {                                       // normal
            while (left <= right) {
                mid = (right + left) / 2;
                
                if (nums[mid] == target)
                    return mid;
                else if (nums[mid] > target)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
        
        return -1;
    }
};
