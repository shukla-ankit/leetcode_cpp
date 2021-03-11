//LeetCode Problem 4 - Median of Two Sorted Arrays

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double medianOfSingleArray(vector<int>& nums){
        int l = nums.size();
        if(l % 2 == 0)
            return 0.5*(nums[l/2-1] + nums[l/2]);
        else
            return nums[l/2];
    }
    double bruteforce(vector<int>& nums1, vector<int>& nums2) {        
        int l1 = nums1.size(), l2 = nums2.size();                
        if(l1 == 0 && l2 ==0)
            return 0.0;
        else if(l1 == 0)
            return medianOfSingleArray(nums2);        
        else if(l2 == 0)
            return medianOfSingleArray(nums1);        
        else
        {
            int l1 = nums1.size(), l2 = nums2.size(), t_len = l1 + l2;
            bool bIsTotalArrayLenOdd = !(t_len % 2 == 0);
            if(nums1[l1 - 1] <= nums2[0]){
                if(bIsTotalArrayLenOdd)                    
                    return l1 > l2 ? nums1[t_len/2] : nums2[t_len/2 - l1];
                else
                    if(l1 == l2)
                        return 0.5*(nums1[l1-1] + nums2[0]);
                    else
                        return l1 > l2 ? 0.5*(nums1[t_len/2 - 1] + nums1[t_len/2]):0.5*(nums2[t_len/2 - 1 - l1] + nums2[t_len/2 - l1]);
            }
            else if(nums1[0] >= nums2[l2 - 1]){
                if(bIsTotalArrayLenOdd)                    
                    return l1 > l2 ? nums1[t_len/2 - l2] : nums2[t_len/2];
                else                    
                    if(l1 == l2)
                        return 0.5*(nums1[0] + nums2[l2-1]);
                    else
                        return l1 > l2 ? 0.5*(nums1[t_len/2 - 1 - l2] + nums1[t_len/2 - l2]):0.5*(nums2[t_len/2 - 1] + nums2[t_len/2]);                    
            }
            else{
                double median = 0.0;
                int i = 0, j = 0;
                while( i + j <= t_len/2){
                    double n = 0.0;
                    if(nums1[i] <= nums2[j] && i < nums1.size()){
                        n = nums1[i++];                    
                    }
                    else if(nums1[i] > nums2[j] && j < nums2.size()){
                        n = nums2[j++];                       
                    }
                    else{
                        cout << "out of bound" ;
                        break;
                    }
                    if(bIsTotalArrayLenOdd && i + j - 1 == t_len/2){
                        median = n;
                        break;
                    }
                    else if (!bIsTotalArrayLenOdd && (i + j - 1 == t_len/2 || i + j -1 == t_len/2-1 )){
                        median += n/2;
                    }                
                }
                return median;
            }
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return bruteforce(nums1, nums2);
    }
};

struct Test{
    vector<int> nums1;
    vector<int> nums2;
};
int main() {
    vector<Test> vecTests = {
         {.nums1= {1, 3}, .nums2 = {2}},
         {.nums1= {1, 2}, .nums2 = {3, 4}},
         {.nums1= {0, 0}, .nums2 = {0, 0}},
         {.nums1= {}, .nums2 = {1}},
         {.nums1= {2}, .nums2 = {}},
         {.nums1= {1, 3}, .nums2 = {2, 7}},
         {.nums1= {1}, .nums2 = {1}},
         {.nums1= {2}, .nums2 = {1, 3, 4}}
    };
    Solution sol;
    for(auto t: vecTests){
        cout << sol.findMedianSortedArrays(t.nums1, t.nums2) << endl;
    }    
	return 0;
}
