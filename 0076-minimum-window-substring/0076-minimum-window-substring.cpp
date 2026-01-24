class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        string ans;
        int r=0;
        int l=0;
        int cnt =0;
        int minlength = INT_MAX;
        int sIndex = -1;
        unordered_map<char, int> hash;
        for(int i=0;i<n;i++){
            hash[t[i]]++;
        }
        while(r<m){
           if(hash[s[r]]>0){
            cnt++;
           }
            hash[s[r]]--;
           
           while(cnt==n){
            if(r-l+1 < minlength){
                minlength = r-l+1;  
                sIndex = l;
            }
            hash[s[l]]++;
            if(hash[s[l]]>0) cnt--;
             l++;

           }
           r++;

        } 
        return sIndex == -1 ? "" : s.substr(sIndex,minlength);
        
    }
};