class Solution {
    public:
        int digitSum(int n){
            int sum = 0;
            while(n>0){
                sum += n % 10;
                n /= 10;
            }
            return sum;
        } 
        int maximumSum(vector<int>& nums) {
            unordered_map<int,int>hash;
            int ans = -1;
            for(int num : nums){
                int key = digitSum(num);
                if(hash.find(key) != hash.end()){
                    ans = max(ans,hash[key]+num);
                    hash[key]  = max(hash[key],num);
                }else{
                    hash[key] = num;
                }
            }
            return ans;
    
        }
    };