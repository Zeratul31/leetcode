
class Solution {
public:
    /**
     * @param A: an integer array
     * @return: nothing
     */
    void sortIntegers(vector<int> &A) {
        // Bubble sort
        if(A.size() == 0 || A.size() == 1)  return;
        
        while(true){
            bool exchanged = false;
            for(int i = 0; i < A.size() - 1; i++){
                if(A[i] > A[i + 1]){
                    int temp = A[i];
                    A[i] = A[i + 1];
                    A[i + 1] = temp;
                    exchanged = true;
                }
            }
            if(exchanged == false)
                break;
        }
    }
};


 // Insertion sort: insert number from remaining part to front part
 // def:  3 2 1 4 5
 //     3  2145
 //     23 145
 //     123 45
 //     1234 5
 //     12345
 if(A.size() == 0 || A.size() == 1)  return;
 
 for(int i = 1; i < A.size(); i++){
 int new_val = A[i];
 int j = i - 1;
 
 while(j >= 0 && A[j] > new_val){ // check for front part and find the pos j
 A[j + 1] = A[j];
 j--;
 }
 // due to j--, right pos is j+1
 A[j + 1] = new_val;
 }
 }
 };



 
 // Selection sort (find a min and put in order)
 // def:3 2 1 4 5
 //     1   3 2 4 5
 //     12  3 4 5
 //     123  4 5
 //     1234  5
 //     12345
 
 if(A.size() == 0)  return;
 
 for(int i = 0; i < A.size(); i++){
 int min_index = i;
 
 for(int j = i; j < A.size(); j++){
 if(A[min_index] > A[j])
 min_index = j;
 }
 // swap min and i number
 int temp = A[min_index];
 A[min_index] = A[i];
 A[i] = temp;
 }
 

