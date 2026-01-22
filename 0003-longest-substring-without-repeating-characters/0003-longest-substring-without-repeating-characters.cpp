class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int r = 0;
        int l = 0;
        int maxcnt = 0;
         int hashvalue = 256;
         int hash[hashvalue];

         for(int i=0;i<hashvalue;i++){
            hash[i]=-1;
         }
         

         while(r<n){
            if(hash[s[r]] == -1){
               
                maxcnt = max(maxcnt , (r-l+1));
                hash[s[r]] = r;
                r++;

            }
            else{
               l = max(hash[s[r]] + 1, l);
                maxcnt = max(maxcnt , (r-l+1));
                hash[s[r]] = r;
                r++;

            }
              }
              return maxcnt;
         
        
    }
};