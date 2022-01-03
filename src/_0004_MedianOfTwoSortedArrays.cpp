//LeetCode Problem 4 - Median of Two Sorted Arrays

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // approach 1
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
        return bruteforce(nums1, nums2); // approach 1
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
/*
-----------------------------------------------------------------------------------------------------------
method1: bruteforce


-----------------------------------------------------------------------------------------------------------
method2: Leetcode Method
Solution
Approach 1: Recursive Approach

To solve this problem, we need to understand "What is the use of median". In statistics, the median is used for:

    Dividing a set into two equal length subsets, that one subset is always greater than the other.

If we understand the use of median for dividing, we are very close to the answer.

First let's cut A\text{A}A into two parts at a random position iii:

          left_A             |        right_A
    A[0], A[1], ..., A[i-1]  |  A[i], A[i+1], ..., A[m-1]

Since A\text{A}A has mmm elements, so there are m+1m+1m+1 kinds of cutting (i=0∼mi = 0 \sim mi=0∼m).

And we know:

    len(left_A)=i,len(right_A)=m−i\text{len}(\text{left\_A}) = i, \text{len}(\text{right\_A}) = m - ilen(left_A)=i,len(right_A)=m−i.

    Note: when i=0i = 0i=0, left_A\text{left\_A}left_A is empty, and when i=mi = mi=m, right_A\text{right\_A}right_A is empty.

With the same way, cut B\text{B}B into two parts at a random position jjj:


          left_B             |        right_B
    B[0], B[1], ..., B[j-1]  |  B[j], B[j+1], ..., B[n-1]

Put left_A\text{left\_A}left_A and left_B\text{left\_B}left_B into one set, and put right_A\text{right\_A}right_A and right_B\text{right\_B}right_B into another set. Let's name them left_part\text{left\_part}left_part and right_part\text{right\_part}right_part:

          left_part          |        right_part
    A[0], A[1], ..., A[i-1]  |  A[i], A[i+1], ..., A[m-1]
    B[0], B[1], ..., B[j-1]  |  B[j], B[j+1], ..., B[n-1]

If we can ensure:

        len(left_part)=len(right_part)\text{len}(\text{left\_part}) = \text{len}(\text{right\_part})len(left_part)=len(right_part)
        max⁡(left_part)≤min⁡(right_part)\max(\text{left\_part}) \leq \min(\text{right\_part})max(left_part)≤min(right_part)

then we divide all elements in {A,B}\{\text{A}, \text{B}\}{A,B} into two parts with equal length, and one part is always greater than the other. Then

median=max(left_part)+min(right_part)2 \text{median} = \frac{\text{max}(\text{left}\_\text{part}) + \text{min}(\text{right}\_\text{part})}{2} median=2max(left_part)+min(right_part)​

To ensure these two conditions, we just need to ensure:

        i+j=m−i+n−ji + j = m - i + n - ji+j=m−i+n−j (or: m−i+n−j+1m - i + n - j + 1m−i+n−j+1)
        if n≥mn \geq mn≥m, we just need to set: i=0∼m,j=m+n+12−i i = 0 \sim m, j = \frac{m + n + 1}{2} - i \\i=0∼m,j=2m+n+1​−i

        B[j−1]≤A[i]\text{B}[j-1] \leq \text{A}[i]B[j−1]≤A[i] and A[i−1]≤B[j]\text{A}[i-1] \leq \text{B}[j]A[i−1]≤B[j]

ps.1 For simplicity, I presume A[i−1],B[j−1],A[i],B[j]\text{A}[i-1], \text{B}[j-1], \text{A}[i], \text{B}[j]A[i−1],B[j−1],A[i],B[j] are always valid even if i=0i=0i=0, i=mi=mi=m, j=0j=0j=0, or j=nj=nj=n. I will talk about how to deal with these edge values at last.

ps.2 Why n≥mn \geq mn≥m? Because I have to make sure jjj is non-negative since 0≤i≤m0 \leq i \leq m0≤i≤m and j=m+n+12−ij = \frac{m + n + 1}{2} - ij=2m+n+1​−i. If n<mn < mn<m, then jjj may be negative, that will lead to wrong result.

So, all we need to do is:

    Searching iii in [0,m][0, m][0,m], to find an object iii such that:

    B[j−1]≤A[i]\qquad \text{B}[j-1] \leq \text{A}[i] B[j−1]≤A[i] and  A[i−1]≤B[j],\ \text{A}[i-1] \leq \text{B}[j],  A[i−1]≤B[j], where j=m+n+12−ij = \frac{m + n + 1}{2} - ij=2m+n+1​−i

And we can do a binary search following steps described below:

    Set imin=0\text{imin} = 0imin=0, imax=m\text{imax} = mimax=m, then start searching in [imin,imax][\text{imin}, \text{imax}][imin,imax]

    Set i=imin+imax2i = \frac{\text{imin} + \text{imax}}{2}i=2imin+imax​, j=m+n+12−ij = \frac{m + n + 1}{2} - ij=2m+n+1​−i

    Now we have len(left_part)=len(right_part)\text{len}(\text{left}\_\text{part})=\text{len}(\text{right}\_\text{part})len(left_part)=len(right_part). And there are only 3 situations that we may encounter:

        B[j−1]≤A[i]\text{B}[j-1] \leq \text{A}[i]B[j−1]≤A[i] and A[i−1]≤B[j]\text{A}[i-1] \leq \text{B}[j]A[i−1]≤B[j]
        Means we have found the object iii, so stop searching.

        B[j−1]>A[i]\text{B}[j-1] > \text{A}[i]B[j−1]>A[i]
        Means A[i]\text{A}[i]A[i] is too small. We must adjust iii to get B[j−1]≤A[i]\text{B}[j-1] \leq \text{A}[i]B[j−1]≤A[i].
        Can we increase iii?
              Yes. Because when iii is increased, jjj will be decreased.
              So B[j−1]\text{B}[j-1]B[j−1] is decreased and A[i]\text{A}[i]A[i] is increased, and B[j−1]≤A[i]\text{B}[j-1] \leq \text{A}[i]B[j−1]≤A[i] may
              be satisfied.
        Can we decrease iii?
              No! Because when iii is decreased, jjj will be increased.
              So B[j−1]\text{B}[j-1]B[j−1] is increased and A[i]\text{A}[i]A[i] is decreased, and B[j−1]≤A[i]\text{B}[j-1] \leq \text{A}[i]B[j−1]≤A[i] will
              be never satisfied.
        So we must increase iii. That is, we must adjust the searching range to [i+1,imax][i+1, \text{imax}][i+1,imax].
        So, set imin=i+1\text{imin} = i+1imin=i+1, and goto 2.

        A[i−1]>B[j]\text{A}[i-1] > \text{B}[j]A[i−1]>B[j]:
        Means A[i−1]\text{A}[i-1]A[i−1] is too big. And we must decrease iii to get A[i−1]≤B[j]\text{A}[i-1]\leq \text{B}[j]A[i−1]≤B[j].
        That is, we must adjust the searching range to [imin,i−1][\text{imin}, i-1][imin,i−1].
        So, set imax=i−1\text{imax} = i-1imax=i−1, and goto 2.

When the object iii is found, the median is:

    max⁡(A[i−1],B[j−1]),\max(\text{A}[i-1], \text{B}[j-1]), max(A[i−1],B[j−1]), when m+nm + nm+n is odd

    max⁡(A[i−1],B[j−1])+min⁡(A[i],B[j])2,\frac{\max(\text{A}[i-1], \text{B}[j-1]) + \min(\text{A}[i], \text{B}[j])}{2}, 2max(A[i−1],B[j−1])+min(A[i],B[j])​, when m+nm + nm+n is even

Now let's consider the edges values i=0,i=m,j=0,j=ni=0,i=m,j=0,j=ni=0,i=m,j=0,j=n where A[i−1],B[j−1],A[i],B[j]\text{A}[i-1],\text{B}[j-1],\text{A}[i],\text{B}[j]A[i−1],B[j−1],A[i],B[j] may not exist. Actually this situation is easier than you think.

What we need to do is ensuring that max(left_part)≤min(right_part)\text{max}(\text{left}\_\text{part}) \leq \text{min}(\text{right}\_\text{part})max(left_part)≤min(right_part). So, if iii and jjj are not edges values (means A[i−1],B[j−1],A[i],B[j]\text{A}[i-1], \text{B}[j-1],\text{A}[i],\text{B}[j]A[i−1],B[j−1],A[i],B[j] all exist), then we must check both B[j−1]≤A[i]\text{B}[j-1] \leq \text{A}[i]B[j−1]≤A[i] and A[i−1]≤B[j]\text{A}[i-1] \leq \text{B}[j]A[i−1]≤B[j]. But if some of A[i−1],B[j−1],A[i],B[j]\text{A}[i-1],\text{B}[j-1],\text{A}[i],\text{B}[j]A[i−1],B[j−1],A[i],B[j] don't exist, then we don't need to check one (or both) of these two conditions. For example, if i=0i=0i=0, then A[i−1]\text{A}[i-1]A[i−1] doesn't exist, then we don't need to check A[i−1]≤B[j]\text{A}[i-1] \leq \text{B}[j]A[i−1]≤B[j]. So, what we need to do is:

    Searching iii in [0,m][0, m][0,m], to find an object iii such that:

    (j=0(j = 0(j=0 or i=mi = mi=m or B[j−1]≤A[i])\text{B}[j-1] \leq \text{A}[i])B[j−1]≤A[i]) and
    (i=0(i = 0(i=0 or j=nj = nj=n or A[i−1]≤B[j]),\text{A}[i-1] \leq \text{B}[j]),A[i−1]≤B[j]), where j=m+n+12−ij = \frac{m + n + 1}{2} - ij=2m+n+1​−i

And in a searching loop, we will encounter only three situations:

        (j=0(j = 0(j=0 or i=mi = mi=m or B[j−1]≤A[i])\text{B}[j-1] \leq \text{A}[i])B[j−1]≤A[i]) and
        (i=0(i = 0(i=0 or j=nj = nj=n or A[i−1]≤B[j])\text{A}[i-1] \leq \text{B}[j])A[i−1]≤B[j])
        Means iii is perfect, we can stop searching.
        j>0j > 0j>0 and i<mi < mi<m and B[j−1]>A[i]\text{B}[j - 1] > \text{A}[i]B[j−1]>A[i]
        Means iii is too small, we must increase it.
        i>0i > 0i>0 and j<nj < nj<n and A[i−1]>B[j]\text{A}[i - 1] > \text{B}[j]A[i−1]>B[j]
        Means iii is too big, we must decrease it.

Thanks to @Quentin.chen for pointing out that: i<m  ⟹  j>0i < m \implies j > 0i<m⟹j>0 and i>0  ⟹  j<ni > 0 \implies j < ni>0⟹j<n. Because:

    m≤n,i<m  ⟹  j=m+n+12−i>m+n+12−m≥2m+12−m≥0m \leq n, i < m \implies j = \frac{m+n+1}{2} - i > \frac{m+n+1}{2} - m \geq \frac{2m+1}{2} - m \geq 0m≤n,i<m⟹j=2m+n+1​−i>2m+n+1​−m≥22m+1​−m≥0

    m≤n,i>0  ⟹  j=m+n+12−i<m+n+12≤2n+12≤nm \leq n, i > 0 \implies j = \frac{m+n+1}{2} - i < \frac{m+n+1}{2} \leq \frac{2n+1}{2} \leq nm≤n,i>0⟹j=2m+n+1​−i<2m+n+1​≤22n+1​≤n

So in situation 2. and 3. , we don't need to check whether j>0j > 0j>0 and whether j<nj < nj<n.


////////////////////////////////JAVA/////////////////////////

class Solution {
    public double findMedianSortedArrays(int[] A, int[] B) {
        int m = A.length;
        int n = B.length;
        if (m > n) { // to ensure m<=n
            int[] temp = A; A = B; B = temp;
            int tmp = m; m = n; n = tmp;
        }
        int iMin = 0, iMax = m, halfLen = (m + n + 1) / 2;
        while (iMin <= iMax) {
            int i = (iMin + iMax) / 2;
            int j = halfLen - i;
            if (i < iMax && B[j-1] > A[i]){
                iMin = i + 1; // i is too small
            }
            else if (i > iMin && A[i-1] > B[j]) {
                iMax = i - 1; // i is too big
            }
            else { // i is perfect
                int maxLeft = 0;
                if (i == 0) { maxLeft = B[j-1]; }
                else if (j == 0) { maxLeft = A[i-1]; }
                else { maxLeft = Math.max(A[i-1], B[j-1]); }
                if ( (m + n) % 2 == 1 ) { return maxLeft; }

                int minRight = 0;
                if (i == m) { minRight = B[j]; }
                else if (j == n) { minRight = A[i]; }
                else { minRight = Math.min(B[j], A[i]); }

                return (maxLeft + minRight) / 2.0;
            }
        }
        return 0.0;
    }
}

////////////////////////////////JAVA/////////////////////////

////////////////////////////////Python/////////////////////////
def median(A, B):
    m, n = len(A), len(B)
    if m > n:
        A, B, m, n = B, A, n, m
    if n == 0:
        raise ValueError

    imin, imax, half_len = 0, m, (m + n + 1) / 2
    while imin <= imax:
        i = (imin + imax) / 2
        j = half_len - i
        if i < m and B[j-1] > A[i]:
            # i is too small, must increase it
            imin = i + 1
        elif i > 0 and A[i-1] > B[j]:
            # i is too big, must decrease it
            imax = i - 1
        else:
            # i is perfect

            if i == 0: max_of_left = B[j-1]
            elif j == 0: max_of_left = A[i-1]
            else: max_of_left = max(A[i-1], B[j-1])

            if (m + n) % 2 == 1:
                return max_of_left

            if i == m: min_of_right = B[j]
            elif j == n: min_of_right = A[i]
            else: min_of_right = min(A[i], B[j])

            return (max_of_left + min_of_right) / 2.0
////////////////////////////////Python/////////////////////////
-----------------------------------------------------------------------------------------------------------
*/