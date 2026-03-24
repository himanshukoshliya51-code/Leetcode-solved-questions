class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int m = bank[0].size();

        vector<int>cnti;
        for(int i=0;i<n;i++){
            int cnt = 0;
            for(auto it  : bank[i]){
                if(it == '1'){
                    cnt++;
                }

            }
            if(cnt!=0){
            cnti.push_back(cnt);}
        }
        int q = cnti.size();
        int sum = 0;
        for(int i=0;i<q-1;i++){
            sum = sum + (cnti[i]*cnti[i+1]);


        }
        return sum;
    }
};