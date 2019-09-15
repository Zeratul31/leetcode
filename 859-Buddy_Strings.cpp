class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.size()!= B.size())     return false;
        if(A==B){
            unordered_set<char> set;
            for(auto i: A){
                set.emplace(i);
            }
            return set.size()<A.size();
        }
        else
        {
            vector<int> pos;
            for(int i=0; i<A.size();i++){
                if(A[i]!=B[i])
                    pos.push_back(i);
            }
            return (pos.size()==2 && A[pos[0]]==B[pos[1]] && A[pos[1]]==B[pos[0]]);
        }
    }
};
