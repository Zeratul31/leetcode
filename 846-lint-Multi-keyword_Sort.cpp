class Solution {
public:
    /**
     * @param array: the input array
     * @return: the sorted array
     */
    
    static bool mysort(vector<int> a, vector<int> b){// need to have static !!
        if(a[1] == b[1])
            return a[0] < b[0];
        else
            return a[1] > b[1];
    }
    
    vector<vector<int>> multiSort(vector<vector<int>> &array) {
        sort(array.begin(), array.end(), mysort);
        return array;
    }
};

