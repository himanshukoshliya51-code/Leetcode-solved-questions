class Solution {
public:
    int xorOperation(int n, int start) {
        int main = start;
        for(int i=1;i<n;i++){
            start = start^(main+2*i);
        }
        return start;
    }
};