// method 1: two pointers: 慢指针输出结果，快指针用来统计字符个数和遍历整个数组，遇到新的char每次都要更新，只有count非1时，才要更新次数
// TC:O(2n), SC: O(1)

class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size() == 0 || chars.size() == 1)
            return chars.size();
        
        int slow = 1;
        int count = 1;
        
        for(int i = 0; i < chars.size() - 1; i++){
            if(chars[i] == chars[i + 1]){
                count++;
            }
            else{
                res_update(count, chars, slow);
                chars[slow++] = chars[i + 1]; // need to update new char every times!
                count = 1;
            }
        }
        
        res_update(count, chars, slow);
        return slow;
    }
    
    void res_update(int count, vector<char>& chars, int &slow){
        if(count != 1){
            for(auto item: to_string(count)){
                chars[slow++] = item;
            }
        }
        return;
    }
};

// method2: open O(n) extra space to store new vector
// TC: O(n), SC: O(n)

class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size() == 0 || chars.size() == 1)
            return chars.size();
        
        vector<char> res;
        int count = 1;
        res.push_back(chars[0]);
        
        for(int i = 1; i < chars.size(); i++){
            if(chars[i] == chars[i - 1]){
                count++;
            }
            else{
                update_result(res, count);
                res.push_back(chars[i]);
                count = 1;
            }
        }
        update_result(res, count);
        
        chars = res;
        return chars.size();
    }
    
    void update_result(vector<char> &res, int count){
        if(count == 1)
            return;
        else{
            string count_s = to_string(count);
            for(auto item: count_s){
                res.push_back(item);
            }
        }
        return;
    }
};
