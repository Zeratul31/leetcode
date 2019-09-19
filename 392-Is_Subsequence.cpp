class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size()==0)  return true;
        if(t.size()==0)  return false;
        
        int i=0, j=0;
        while(i<s.size() && j<t.size()){
            if(s[i] == t[j] ){
                i++;
                j++;
            }else{
                j++;
            }
        }
        return (i==s.size());
    }
};

//hard method
class Solution { // for the follow up: if lots of s incoming
public:
    bool isSubsequence(string s, string t) {
        if(s.size()==0)  return true;
        if(t.size()==0)  return false;
        
        unordered_map <char, vector<int> > map; // max is 26 chars
        for(int i=0; i<t.size(); i++){
            // if(map.find(t[i]) != map.end())
            //     map[t[i]].push_back(i);
            // else{
            //     vector<int> temp;
            //     temp.push_back(i);
            //     map.emplace(t[i],temp);
            // }
            map[t[i]].push_back(i);
        }
        
        int pre = -1; // pre index when scaning string s
        
        for(auto ss: s){
            pre = binary_search(map[ss], pre);
            if(pre== -1)    return false;
        }
        return true;
    }
    
    // find first index which is bigger than pre
    int binary_search(vector<int> &input, int pre){
        if(input.size()==0) return -1;
        
        int start = 0;
        int end = input.size()-1;
        
        while(start+1<end){
            int mid = start + (end - start)/2;
            if(input[mid]>pre){
                end = mid;
            }else{
                start = mid;
            }
        }
        if(input[start]>pre)    return input[start];
        if(input[end]>pre)  return input[end];
        return -1;
    }
};
