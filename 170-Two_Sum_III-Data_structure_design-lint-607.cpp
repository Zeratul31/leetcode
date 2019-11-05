
class TwoSum {
public:
    /**
     * @param number: An integer
     * @return: nothing
     */
    unordered_map <int, int> map_ts; // value and how many times it appears
    void add(int number) {
        if(map_ts.find(number) != map_ts.end())
            map_ts[number]++;
        else
            map_ts.emplace(number, 1);
    }
    
    /**
     * @param value: An integer
     * @return: Find if there exists any pair of numbers which sum is equal to the value.
     */
    bool find(int value) {
        for(auto item: map_ts){
            if(map_ts.find(value - item.first) != map_ts.end())
            {
                if(item.first == value - item.first && item.second < 2)
                    continue; // make sure skip this case
                else
                    return true;
            }
        }
        return false;
    }
};
