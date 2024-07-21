class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int profit = 0;
        int buy = prices[0];
        int sell = 0;
        while(sell < prices.size()){
            if(buy>prices[sell]){
                buy = prices[sell];
            }
            else if(prices[sell]-buy > 0 ){
                ans += prices[sell] - buy;
                buy = prices[sell];
            }
            sell++;
        }
        return ans;

    }
};