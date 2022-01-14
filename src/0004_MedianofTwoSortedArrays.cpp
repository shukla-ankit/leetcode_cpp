//LeetCode Problem 4 - Median of Two Sorted Arrays
/*
method 1: Easier way is merge two sorted arrays and then take the median. 
Time complexity will be O(m + n)

method 2: 
https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/2471/Very-concise-O(log(min(MN)))-iterative-solution-with-detailed-explanation

nums1 has n1 elements, nums2 has n2 elements
there are 2n1 + 1 possible ways to cut nums1 and 2n1 + 1 possible ways to cut nums2 for median
after cut, there will be n1 + n1 possible cuts on both sides
also any number on left will be smaller than any other number on right, so

L1 <= R1, L2 <= R2 (default ensured as array sorted)
L2 <= R1, L1 <= R2 (needs to be checked)

0. low = 0, high = n2 -1         (when  n2 < n1)
1. start with mid2 = (low + high)/2
2. mid1 = N1 + N2 - mid2

3.  L1 = (mid1 -1)/2, L2 = (mid2 -1)/2, R1 = mid1/2, R2 = mid2/2
4.  if L1 > R2, low = mid2 + 1
    or if L2 > R1, high = mid2 - 1
    else if L1 <= R2 and L2 <= R1, return ( max(L1,L2) + min(R1, R2) )/2 
5. repeat from step 0 

*/

#include "everything.h"

struct Test{
    vector<int> nums1;
    vector<int> nums2;
    double output;
};
class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int N1 = nums1.size();
            int N2 = nums2.size();
            if (N1 < N2) return findMedianSortedArrays(nums2, nums1);	// Make sure A2 is the shorter one.
            
            int lo = 0, hi = N2 * 2;
            while (lo <= hi) {
                int mid2 = (lo + hi) / 2;   // Try Cut 2 
                int mid1 = N1 + N2 - mid2;  // Calculate Cut 1 accordingly
                
                double L1 = (mid1 == 0) ? INT_MIN : nums1[(mid1-1)/2];	// Get L1, R1, L2, R2 respectively
                double L2 = (mid2 == 0) ? INT_MIN : nums2[(mid2-1)/2];
                double R1 = (mid1 == N1 * 2) ? INT_MAX : nums1[(mid1)/2];
                double R2 = (mid2 == N2 * 2) ? INT_MAX : nums2[(mid2)/2];
                
                if (L1 > R2) lo = mid2 + 1;		// A1's lower half is too big; need to move mid1 left (mid2 right)
                else if (L2 > R1) hi = mid2 - 1;	// A2's lower half too big; need to move mid2 left.
                else return (max(L1,L2) + min(R1, R2)) / 2;	// Otherwise, that's the right cut.
            }
            return -1;
        } 
};
int main() {
    vector<Test> vecTests = {
         {.nums1= {1, 3}, .nums2 = {2}, .output=2.0},
         {.nums1= {1, 2}, .nums2 = {3, 4}, .output=2.5},
         {.nums1= {0, 0}, .nums2 = {0, 0}, .output=0.0},
         {.nums1= {}, .nums2 = {1}, .output=1.0},
         {.nums1= {2}, .nums2 = {}, .output=2.0},
         {.nums1= {1, 3}, .nums2 = {2, 7}, .output=2.5},
         {.nums1= {1}, .nums2 = {1}, .output=1.0},
         {.nums1= {2}, .nums2 = {1, 3, 4}, .output=2.5}
    };
    Solution sol;
    for(auto t: vecTests){
        cout << sol.findMedianSortedArrays(t.nums1, t.nums2) << endl;
    }    
	return 0;
}
/*
-----------------------------------------------------------------------------------------------------------
method1: <<>>
-----------------------------------------------------------------------------------------------------------
Leetcode Method:

-----------------------------------------------------------------------------------------------------------
*/

