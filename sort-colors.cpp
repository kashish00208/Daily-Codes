class Solution {
public:
    void sortColors(vector<int>& nums) {
        for(int i=1 ; i<nums.size(); i++){
            for(int j=0; j<nums.size(); j++){
                if(nums[i]<nums[j]){
                    swap(nums[i],nums[j]);
                }
            }
        }
    }
};