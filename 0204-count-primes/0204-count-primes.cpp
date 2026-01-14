class Solution {
public:
    int countPrimes(int n) {
       //Sieve of Eratosthenes
       int arr[n+1];
       int cnt = 0;
       for(int i=2;i<n+1;i++){
        arr[i]=1;
       }

       for(int i=2;i*i<n;i++){
        if(arr[i]==1){
            for(int j= i*i;j<n;j=j+i){
                arr[j]=0;
            }
        }
       }
       for(int i =2;i<n;i++){
        if(arr[i]==1){
            cnt++;
        }
       }
       return cnt;
       
        
    }
};