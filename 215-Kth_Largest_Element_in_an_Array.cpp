class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quick_select(nums, 0, nums.size()-1, nums.size() - k); 
        // use length - k to get because our quick select is to find k small element
        // no need to +1 or -1 becuase (length - k) is the element index
    }
    
    int quick_select(vector<int>& nums, int start, int end, int k){
        // this is to find kth small element. k is the index in this algorithm !     
        
        if(start==end)  return nums[start];
        
        int pivot = nums[(start+end)/2];
        int left = start;
        int right = end;
        
        while(left<=right){
            while(left<=right && nums[left]<pivot)  
                left++;
            
            while(left<=right && nums[right]>pivot)  
                right--;
            
            // if(pivot<=nums[left] && pivot>=nums[right]){
            if(left<=right){ // hard part !!
                swapp(nums, left, right);
                left++;
                right--;
            }
        }
        // final stop case is right index, k, left index
        if(k<=right)
            quick_select(nums, start, right, k);
        if(k>=left)
            // else // else is ok, too
            quick_select(nums, left, end, k);
        
        return nums[k];
    }
    
    void swapp(vector<int>& nums, int left, int right){
        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
    }
};
