class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s2==s1)return true;
        int i = 0 , j = s1.size();
        vector<int>diff;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                diff.push_back(i);
            }
        }
        if(diff.size()==2){
            int i = diff[0] , j = diff[1];
            swap(s1[i],s1[j]);
            return s1==s2;
        }
        return false;
    }
};