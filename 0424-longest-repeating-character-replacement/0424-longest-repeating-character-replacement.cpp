class Solution {
public:
    int characterReplacement(string s, int k) {
         int left = 0;
         int right =0;
        int zeros = 0;
        int maxl = 0;
        int maxCount = 0;
        vector<int>freq(26,0);


               while(right < s.size()){
                freq[s[right] - 'A']++;

            maxCount = max(maxCount, freq[s[right] - 'A']);

            while ((right - left + 1) - maxCount > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            maxl = max(maxl, right - left + 1);
             right++;

        }
       
        return maxl;
    }
};