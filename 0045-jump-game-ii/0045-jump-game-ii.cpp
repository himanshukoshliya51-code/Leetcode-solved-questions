class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return 0;
        }
        int index=n-1;
        int cnt = 0;
        
        while(index!=0){
            for(int i=0;i<n;i++){
            if(nums[i]+i >= index){
                cnt++;
                 index =i;
                break;
            }
        }

        }

        return cnt;

        
    }
};