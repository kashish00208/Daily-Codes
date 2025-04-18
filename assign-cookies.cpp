class Solution {
    public:
        int findContentChildren(vector<int>& greed, vector<int>& size) {
            int n = greed.size() , m = size.size() , l = 0 , r = 0 ;
            sort(greed.begin(),greed.end()); sort(size.begin(),size.end());
            while(l<m && r<n){
                if(greed[r]<=size[l]){
                    r++;
                }
                l++;
            }
            return r;
        }
    };