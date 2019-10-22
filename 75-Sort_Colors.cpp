class Solution { // use two points method and save space
public:
    void sortColors(vector<int>& nums) {
        int pl = 0; // left point
        int i = 0;
        int pr = nums.size() - 1; // right point
        
        while (i <= pr){ // there are only three cases 0,1,2, so we can use if
            if(nums[i] == 0){
                swapp (nums, i, pl);
                i++;
                pl++;
            }else if(nums[i] == 1){
                i++;
            }else{
                swapp(nums, i, pr);
                pr--;
            }
        }
    }
    
private:
    void swapp (vector<int>& nums, int a, int b){
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }
};


class Solution { // rainbow sort
public:
    void sortColors(vector<int>& nums) {
        rainbow_sort(nums, 0, nums.size()-1, 0, 2);
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
