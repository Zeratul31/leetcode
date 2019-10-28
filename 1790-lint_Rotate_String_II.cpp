class Solution {
public:
    /**
     * @param str: An array of char
     * @param left: a left offset
     * @param right: a right offset
     * @return: return a rotate string
     */
    string RotateString2(string &s, int left, int right) {
        int rotate = left - right;
        int ss = s.size();
        rotate = rotate % ss; // in c++ -1 % 7  = -1
        
        // temp = rotate % int(s.size()); // if we use size(), result is not int is size_t
        
        // cout << "size is " << to_string(ss) <<endl;
        // cout << "sssssize is " << to_string(s.size()) <<endl;
        // cout << "rotate is " << to_string(rotate) <<endl;
        // cout << "temp is " << to_string(temp) <<endl;
        
        string res;
        
        if(rotate > 0)
            res = s.substr(rotate, s.size() - rotate) + s.substr(0, rotate);
        else
            res = s.substr(s.size() - abs(rotate), abs(rotate)) + s.substr(0, s.size() - abs(rotate));
        
        return res;
    }
};
