class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size() ;
        long long sum = 0; 
        stack<int>st;
        vector<int>prevSmall(n,-1),nextSmall(n,n),prevBig(n,-1),nextBig(n,n);
        //finding previous smaller element store it in array prevSmall(n,-1)
        for(int i=0;i<n;i++){
            while(!st.empty()&&nums[st.top()]>=nums[i]){st.pop();}
            if(!st.empty()){prevSmall[i] = st.top();}
            st.push(i);
        }
        //finding previous smaller element store it in array nextSmall(n,n)
        while(!st.empty()){st.pop();}
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&nums[st.top()]>nums[i]){st.pop();}
            if(!st.empty()){nextSmall[i] = st.top();}
            st.push(i);
        }
        //finding previous max element store it in array prevbig(n,-1)
        for(int i=0;i<n;i++){
            while(!st.empty()&&nums[st.top()]<=nums[i]){st.pop();}
            if(!st.empty()){prevBig[i] = st.top();}
            st.push(i);
        }
        //finding previous max element store it in array nextbig(n,n)
        while(!st.empty()){st.pop();}
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&nums[st.top()]<nums[i]){st.pop();}
            if(!st.empty()){nextBig[i] = st.top();}
            st.push(i);
        }
        for(int i=0;i<n;i++){
            long long leftMin = i - prevSmall[i] , rightMin = nextSmall[i] - i;
            long long leftBig = i - prevBig[i] , rightBig = nextBig[i] - i;

            sum += (leftBig*rightBig - leftMin*rightMin)*nums[i];
        }
        return sum;
    }
};