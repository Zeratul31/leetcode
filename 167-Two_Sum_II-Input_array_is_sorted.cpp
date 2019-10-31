class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // opposite direction two points
        vector<int> res;
        if(numbers.size() == 0 || numbers.size() == 1)
            return res;
        
        int start = 0;
        int end = numbers.size() - 1;
        
        while(start < end){
            if(numbers[start] + numbers[end] == target){
                res.push_back(start + 1);
                res.push_back(end + 1);
                break;
            }
            else if(numbers[start] + numbers[end] > target)
                end--;
            else
                start++;            
        }
        return res;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // binary search method
        vector<int> res;
        if(numbers.size() == 0 || numbers.size() == 1)
            return res;
        
        for(int i = 1; i < numbers.size(); i++){
            int temp = binary_search(numbers, 0, i - 1, target - numbers[i]);
            if(temp != -1)
            {
                res.push_back(temp + 1);
                res.push_back(i + 1);
            }
        }
        return res;
    }
    
private:
    int binary_search(vector<int>& numbers, int start, int end, int target)
    {
        while(start + 1 < end){
            int mid = start + (end - start)/2;
            if(numbers[mid] == target)
                return mid;
            else if(numbers[mid] > target)
                end = mid;
            else
                start = mid;
            
        }
        if(numbers[start] == target)
            return start;
        else if(numbers[end] == target)
            return end;
        else
            return -1;
    }
};
