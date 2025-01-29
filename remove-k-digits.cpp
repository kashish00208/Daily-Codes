// problem statement : Remove maximum k digits from a number to make the smallest number out of it
// Example Input num = "1432219", k = 3 output = 1219 
// Approach :
// 1. Maintain a monotonic stack to store the digits of num remove highest k numbers from number and return the result.
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st; // store the element of num in monotonic order
        for(char digit : num){
            //remove the number which is greater
            while(!st.empty() && k>0 && st.top()>digit){
                st.pop();
                k--;
            }
            st.push(digit);
        }
        // if k > 0 then remove from top
        while(k>0 && !st.empty()){
            st.pop();
            k--;
        }
        string result = "";
        while(!st.empty()){
            result += st.top();
            st.pop();
        }
        reverse(result.begin(),result.end());
        // remove leading zeros 
        int i = 0;
        while(i<result.size() && result[i]=='0'){
            i++;
        }
        //after removing the leading zeros construct answer and return it
        result = result.substr(i);
        return result.size()==0?"0":result;
    }
};