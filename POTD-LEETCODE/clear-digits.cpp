class Solution {
    public:
        string clearDigits(string s) {
            string res ="";
            for(auto it : s){
                if(isdigit(it)){
                    if(!res.empty()){
                        res.pop_back();
                    }
                }else{
                    res.push_back(it);
                }
            }
            return res;
        }
    };