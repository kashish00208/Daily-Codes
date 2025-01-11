class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size(); //size of array
        vector<int>ans(n,-1); //vector to store next greater element

        stack<int>st; //storing element in monotonic order
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums2[i]>=st.top()){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top();
            }else{
                ans[i] = -1;
            }
            st.push(nums2[i]);
        }
        for(int i=0;i<nums1.size();i++){
            auto it = find(nums2.begin(),nums2.end(),nums1[i]);
            int k = distance(nums2.begin(), it);
            nums1[i] =ans[k];
        }
        return nums1;
    }
};