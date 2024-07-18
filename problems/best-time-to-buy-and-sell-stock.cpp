class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int buy = prices[0];
        for(int sell=0;sell<prices.size();sell++){
            if(buy>prices[sell]){
                buy = prices[sell];
            }
            else if(prices[sell]-buy > ans){
                ans = prices[sell] - buy;
            }
        }
        return ans;
    }
};