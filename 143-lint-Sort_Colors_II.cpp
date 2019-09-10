class Solution {
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */
    void sortColors2(vector<int> &colors, int k) { // rainbow sort
        rainbow_sort(colors, 0, colors.size()-1, 1, k);
        return;
    }
    
private:
    void rainbow_sort(vector<int> &colors, int start, int end, int color_s, int color_e){
        if(color_s>=color_e)    return;
        if(start>=end)  return;
        
        int left = start;
        int right = end;
        int color_m = color_s + (color_e - color_s)/2; // this is pivot
        
        while(left<=right){
            while(left<=right && colors[left]<=color_m)  left++;// carefull for <= part
            while(left<=right && colors[right]>color_m)  right--;
            
            if(left<=right){
                swap(colors[left], colors[right]);
                left++;
                right--;
            }
        }
        
        rainbow_sort(colors, start, right, color_s, color_m);
        rainbow_sort(colors, left, end, color_m+1, color_e);
    }
};
