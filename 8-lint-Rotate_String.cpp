
class Solution {
public:
    /**
     * @param str: An array of char
     * @param offset: An integer
     * @return: nothing
     */
    void rotateString(string &str, int offset) { // 三步翻转法
        int length = str.size();
        if(length == 0) return;
        
        offset = offset % length;
        
        // hard part
        reverse(str, length - offset, length - 1);
        reverse(str, 0, length - offset - 1);
        reverse(str, 0, length - 1);
    }
    
private:
    void reverse(string &input, int start, int end){
        while(start < end){
            char temp = input[start];
            input[start] = input[end];
            input[end] = temp;
            start++;
            end--;
        }
    }
};
