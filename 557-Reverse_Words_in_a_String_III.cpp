
class Solution {
public:
    string reverseWords(string s) {
        string result = "";
        
        if(s == "")
            return result;
        
        vector<string> split_res = split(s, " ");
        
        for(int i = 0; i <split_res.size(); i++){
            reverse(split_res[i].begin(), split_res[i].end());
            result = result + split_res[i] + " ";
        }
        
        return (result.substr(0, result.size()-1));
    }
    
private:
    vector<string> split (string &input, string splitter){
        vector<string> res;
        
        if(input == "")
            return res;
        
        // if there is more splitter, the res vector will have more "" items but these items will not print out at result since they are all ""
        string str = input + splitter;
        size_t size = str.size(); // size_t
        size_t pos = str.find(splitter);
        
        while(pos != str.npos){
            string tmp = str.substr(0, pos);
            
            if(tmp != "")  // remove "" item, otherwise, we will add more splitter
                res.push_back(tmp);
            
            str = str.substr(pos + 1, size);
            // cout << "cur str is " << str << endl;
            pos = str.find(splitter);
            // cout << "pos is " << to_string(pos) << endl;
        }
        
        return res;
    }
};
