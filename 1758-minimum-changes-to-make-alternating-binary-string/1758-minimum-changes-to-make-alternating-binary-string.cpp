class Solution {
public:
    int minOperations(string arr) {
        int n = arr.size();

        int cnt0 = 0, cnt1 = 0;

        // pattern starting with 0 -> "010101"
        for(int i = 0; i < n; i++){
            if(i % 2 == 0 && arr[i] != '0') cnt0++;
            if(i % 2 == 1 && arr[i] != '1') cnt0++;
        }

        // pattern starting with 1 -> "101010"
        for(int i = 0; i < n; i++){
            if(i % 2 == 0 && arr[i] != '1') cnt1++;
            if(i % 2 == 1 && arr[i] != '0') cnt1++;
        }

        return min(cnt0, cnt1);
    }
};