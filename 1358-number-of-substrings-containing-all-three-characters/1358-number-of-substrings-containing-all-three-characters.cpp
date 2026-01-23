class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        map<char,int>store;
       
        int l=0;
        int r =0;
        int cnt = 0;

        while(r<n){
            store[s[r]]++;
            while(store.size()==3){
                cnt = cnt+(n-r);
                store[s[l]]--;
                if(store[s[l]]==0){
                    store.erase(s[l]);
                }
                l++;
                
               
            }

             r++;
            

        }
        return cnt;
    }
};