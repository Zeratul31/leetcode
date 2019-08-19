class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 0)
            return -1;
        else
        {
            int last_num = nums[nums.size() -1];
            int start_index = 0;
            start_index = Find_First_Start_Index(nums,last_num);//function to remove duplicate at beginning
            
            int start = start_index;
            int end = nums.size() - 1;
            
            while (start +1 < end)
            {
                int mid = start + (end - start)/2;
                
                if(Is_Last_Half(nums[mid], last_num)) //function to judge last half
                    end = mid;
                else
                    start = mid;
            }
            
            if(nums[start] < nums[end])
                return nums[start];
            else
                return nums[end];
        }
    }
    
    int Find_First_Start_Index(vector<int>& nums, int last_num)
    {
        int index = 0;
        for(index  = 0; index< nums.size()-1; index++ )
        {
            if(nums[index] != last_num)
                break;
        }
        return index;
    }
    
    bool Is_Last_Half (int input, int last_num)
    {
        if(input <= last_num)
            return true;
        else
            return false;
    }
};
