class Solution { //method1: hashset: time: O(m+n), space O(min(m,n))
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        vector<int> res;
        
        for(int i=0; i<nums2.size(); i++){
            if(set1.find(nums2[i])!= set1.end())
                res.push_back(nums2[i]);
            set1.erase(nums2[i]);
        }
        return res;
    }
};

class Solution {// method2: quick sort + merge, time: O(mlogm + nlogn + m + n), space: O(1)
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> res;
        
        int i=0, j=0;
        
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i] == nums2[j])
            {
                if(res.empty() || nums1[i] != res.back() ){ // when using res.back, need to put res.empty in front!
                    res.push_back(nums1[i]);
                }
                i++;
                j++;
                
            }else if(nums1[i] < nums2[j]){
                i++;
            }else{
                j++;
            }
        }
        return res;
    }
};

class Solution { // method 3: sort + binary search: time: O(nlogn + mlogn)
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set;
        vector<int> res;
        if(nums1.empty() || nums2.empty())
            return res;
        
        sort(nums1.begin(), nums1.end());
        
        for(auto j: nums2){
            if(binary_search(nums1, j)){
                set.emplace(j);
            }
        }
        
        for(auto i: set){
            res.push_back(i);
        }
        
        return res;
    }
    
    bool binary_search(vector<int>& nums, int target){
        int start = 0;
        int end = nums.size()-1;
        
        while(start +1 <end){
            int mid = start + (end -start)/2;
            
            if(nums[mid] == target)
                return true;
            else if(nums[mid] > target)
                end = mid;
            else
                start = mid;
        }
        
        if(nums[start] == target || nums[end] == target)
            return true;
        else
            return false;
    }
};
