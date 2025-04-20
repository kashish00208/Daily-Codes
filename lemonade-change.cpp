class Solution {
    public:
        bool lemonadeChange(vector<int>& bills) {
            int five = 0 , ten = 0 ;
            for(int i=0;i<bills.size();i++){
                if(bills[i]==5){
                    five++;
                }
                if(bills[i]==10){
                    if(five){
                        five--;
                        ten++;
                    }else{
                        return false;
                    }
                }
                if(bills[i]==20){
                    if(five && ten){
                        five--;
                        ten--;
                    }else if(five>=3){
                        five = five-3;
                    }else{
                        return false;
                    }
                }
            }
            return true;
        }
    }; //Greedy algorithm