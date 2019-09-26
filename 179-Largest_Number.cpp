bool cmp (string a, string b){
    string c1 = a + b;
    string c2 = b + a;
    return c1 > c2;    
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res = "";
        if(nums.size() == 0)
            return res;
        
        vector<string> num_str;
        for(auto item: nums){
            num_str.push_back(to_string(item));
        }
        
        // when cmp is true, no change for num_str order !
        sort(num_str.begin(), num_str.end(), cmp); 
        
        for(auto item: num_str){
            res = res + item;
        }
        
        if(res[0] == '0') // need to use '0' not "0" !!
            return "0";
        else
            return res;
    }
};
