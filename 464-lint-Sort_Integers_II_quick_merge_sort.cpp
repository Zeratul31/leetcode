
class Solution {
public:
    /**
     * @param A: an integer array
     * @return: nothing
     */
    void sortIntegers2(vector<int> &A) {// quick sort
        quicksort(A, 0, A.size() - 1);
    }
    
private:
    void quicksort(vector<int> &A, int start, int end){
        if(start >= end)
            return;
        
        int left = start;
        int right = end;
        int pivot = A[start + (end - start)/2];
        // pivot need to be a value not index! index will change !!
        
        while(left <= right){
            while(left <= right && A[left] < pivot) // <  not <=
                left++;
            
            while(left <= right && A[right] > pivot) // >  not >=
                right--;
            
            if(left <= right){
                int temp = A[left];
                A[left] = A[right];
                A[right] = temp;
                left++;
                right--;
            }
        }
        
        quicksort(A, start, right); // right here not left !!
        quicksort(A, left, end);
    }
    
};

class Solution {
public:
    /**
     * @param A: an integer array
     * @return: nothing
     */
    void sortIntegers2(vector<int> &A) { // merge sort
        // int temp[A.size()]; // array init
        vector<int> temp(A.size()); // vector init !!
        mergesort(A, 0, A.size()-1, temp);
    }
    
private:
    void mergesort(vector<int> &A, int start, int end, vector<int> &temp){
        if(start >= end) // do not forget
            return;
        
        int mid = start + (end - start)/2;
        mergesort(A, start, mid, temp);
        mergesort(A, mid + 1, end, temp);
        merge(A, start, end, temp);
    }
    
    void merge(vector<int> &A, int start, int end, vector<int> &temp){
        int mid = start + (end - start)/2;
        int left = start;
        int right = mid + 1;
        int index = start;
        
        while(left <= mid && right <= end){
            if(A[left] < A[right]){
                temp[index++] = A[left++];
            }else{
                temp[index++] = A[right++];
            }
        }
        
        while(left <= mid){
            temp[index++] = A[left++];
        }
        
        while(right <= end){
            temp[index++] = A[right++];
        }
        
        for(int i = start; i <= end; i++ ){ // carefull for range from start to end !!
            A[i] = temp[i];
        }
    }
};
