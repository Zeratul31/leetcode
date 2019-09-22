class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        dfs(num, target, 0, "", 0, 0, res);
        return res;
    }
    
private:
    void dfs(string &num, int target, int start, string str, long int sum, long int last, vector<string> &res){ // need to use long int
        // cout<<"start: " <<to_string(start)<< " str: "<<str<< " sum: "<<to_string(sum)<<" last: " << to_string(last) << endl;
        if(start == num.size()){
            if(sum==target)
                res.push_back(str);
            
            return;
        }
        
        for(int i=start; i<num.size(); i++){
            long int x = stol(num.substr(start, (i+1-start) ), NULL);//stol for long int
            // cout<<"x is " <<to_string(x) << " stoi: "<< num.substr(start, i+1) << endl;
            
            if(start==0){
                dfs(num, target, i+1, to_string(x), x, x, res);
            }else{
                dfs(num, target, i+1, str + "*" + to_string(x), sum-last+(last*x), last*x, res);
                dfs(num, target, i+1, str + "+" + to_string(x), sum+x, x, res);
                dfs(num, target, i+1, str + "-" + to_string(x), sum-x, -x, res);
            }
            if(x==0){// value can be 0 but prefix cannot be 0 !!!    
                // cout<<"x ??  " <<to_string(x) << " stoi: "<< num.substr(start, i+1) << endl;
                break;
            }
        }
    }
};
