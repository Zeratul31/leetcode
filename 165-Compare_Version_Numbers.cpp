class Solution {
public:
    int compareVersion(string version1, string version2) {
        
        vector<string> res1 = splitt(version1, ".");
        vector<string> res2 = splitt(version2, ".");
        
        int max_length= max(res1.size(), res2.size());
        for(int i=0; i<max_length; i++){
            int v1, v2;
            if(i>=res1.size())
                v1=0;
            else{
                v1=stoi(res1[i], NULL);
                // cout<< "v1 is " <<to_string(v1) <<endl;
            }
            
            if(i>=res2.size())
                v2=0;
            else{
                v2=stoi(res2[i], NULL);
                cout<< "v2 is " <<to_string(v2) <<endl;
            }
            if(v1==v2)  continue;
            
            if(v1>v2)   return 1;
            else    return -1;
        }
        return 0;
    }
    
    vector<string> splitt(string input, string spliter){
        vector<string> res;
        if(input == "") return res;
        
        string strs = input + spliter;
        int pos = strs.find(spliter);
        int size = input.size();
        while(pos!= strs.nops){
            string x = strs.substr(0, pos);
            res.push_back(x);
            strs = strs.substr(pos+1, size);
            pos = strs.find(spliter);
        }
        return res;
    }
};
