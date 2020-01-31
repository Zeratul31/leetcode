// method: use stringstream.
//     1.start with vowel, do nothing.
//     2.start with non-vowel, move first char to end
//     3.add "ma" for all cases
//     4.add a based on count
// 知识点：  stringstream can skip space case!
//     string.substr(2) = string from pos 2 to the end


class Solution {
public:
    string toGoatLatin(string S) {
        string res, temp;
        stringstream ss(S);
        string end = "maa";
        
        unordered_set <char> set;
        set.emplace('a');
        set.emplace('e');
        set.emplace('i');
        set.emplace('o');
        set.emplace('u');
        set.emplace('A');
        set.emplace('E');
        set.emplace('I');
        set.emplace('O');
        set.emplace('U');
        
        while(ss >> temp){ // stringstream can skip space part
            if( set.find(temp[0]) == set.end() ){
                res += " " + temp.substr(1) + temp[0];
            }else{
                res += " " + temp;
            }
            
            res += end;
            end += "a";
        }
        return res.substr(1); // remove first space " "
    }
};
