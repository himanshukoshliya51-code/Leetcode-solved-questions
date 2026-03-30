class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.size();

        unordered_map<int,int>mp1,mp2,mp3,mp4;

        for(int i=0;i<n;i++){
            if(i%2 == 0){
                mp1[s1[i]]++;
                mp3[s2[i]]++; 
            }
            else{
                mp2[s1[i]]++;
                mp4[s2[i]]++;
            }

        }
        if(mp1 != mp3)return false;
        if(mp2 != mp4)return false;
    return true;
    }
};