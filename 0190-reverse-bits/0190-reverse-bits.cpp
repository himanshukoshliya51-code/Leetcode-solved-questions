class Solution {
public:
    int reverseBits(uint32_t n) {
        int result = 0;

        for (int i = 0; i < 32; i++) {
            result = result << 1;      // make space
            result |= (n & 1);         // take last bit of n
            n = n >> 1;                // shift n right
        }

        return result;
    }
};
