class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int p1=0;
        int p2=0;
        int p3=0;
        int p4 =0;
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1])return false;
            if(nums[i]<nums[i+1] && p2==0){
                p1++;
            }
            else if(nums[i]>nums[i+1] && p3==0){
                p2++;
            }
            else if(nums[i]<nums[i+1] && p1!=0 && p2!=0){
                p3++;

            }
            else{
                p4++;
            }
        }

        if(p1!=0 && p2!=0 && p3!=0 && p4 ==0){
            return true;
        }
        else{
            return false;
        }

        
    }
};