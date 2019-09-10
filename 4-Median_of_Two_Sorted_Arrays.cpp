class Solution { // transfer to find Kth element due to time O(log (m+n))
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int length = nums1.size() + nums2.size();
        
        if(length%2 != 0)
            return find_kth(nums1, 0, nums2, 0, length/2+1);
        else
            return 0.5* (find_kth(nums1, 0, nums2, 0, length/2) + find_kth(nums1, 0, nums2, 0, length/2+1));
    }
    
private:
    double find_kth (vector<int>& nums1, int A_start, vector<int>& nums2, int B_start, int k){ 
        // k th is start from 1 not 0
        if(A_start>=nums1.size())   return nums2[B_start+k-1];
        if(B_start>=nums2.size())   return nums1[A_start+k-1];
        
        if(k==1)    return min(nums1[A_start], nums2[B_start]);
        
        int A_key = A_start + k/2 -1 >= nums1.size() ? INT_MAX : nums1[A_start+k/2-1];
        int B_key = B_start + k/2 -1 >= nums2.size() ? INT_MAX : nums2[B_start+k/2-1];
        
        if(A_key>B_key)
            return find_kth(nums1,A_start,nums2, B_start+k/2, k-k/2); 
        //(k-k/2) is hard for odd number !!
        else
            return find_kth(nums1,A_start+k/2, nums2, B_start, k-k/2);
    }
};
