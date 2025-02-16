class Solution {
    public:
        bool possible(int num , int target){
            if(target<0 ||num<target ){
                return false;
            }
            if(target==num){
                return true;
            }
            return possible(num/10, target-num%10) || possible(num/100, target-num%100) || possible(num/1000, target-num%1000);
        }
        int punishmentNumber(int n) {
            int sum = 0;
            for(int target=1;target<=n;target++){
                int num = target*target;
                if(possible(num,target)){
                    sum += num;
                }
            }
            return sum;
        }
    };