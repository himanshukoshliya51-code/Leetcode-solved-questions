class Solution {
public:

int atmost(vector<int>&nums,int k){
    int n = nums.size();
        int l=0;
        int r=0;
        int cnt = 0;
        int sum =0;
        while(r<n){
            sum =sum + nums[r];
             r++;
           
                while(sum>k){
                    sum = sum -nums[l];
                    l++;
            }
            
            cnt+=(r-l+1);
            
        }
        return cnt;

}
    int numberOfSubarrays(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int>ans(n);

        for(int i=0;i<n;i++){
            if((nums[i]%2) == 0){
                ans[i]=0;
            }
            else{
                ans[i]=1;
            }
        }
        int ans1 = atmost(ans,k)-atmost(ans,k-1);
        return ans1;
        
    }
};