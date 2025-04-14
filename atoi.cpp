class Solution {
    public:
        long rec(int i, long value, int size, string &s) {
            if (i >= size || !isdigit(s[i])) {
                return value;
            }
    
            value = value * 10 + (s[i] - '0');
    
            if (value > INT_MAX) return value;
    
            return rec(i + 1, value, size, s);
        }
    
        int myAtoi(string s) {
            int i = 0;
            int sign = 1;
            int size = s.size();
    
            while (i < size && s[i] == ' ') i++;
    
            if (i < size && (s[i] == '-' || s[i] == '+')) {
                sign = (s[i] == '-') ? -1 : 1;
                i++;
            }
    
            long value = rec(i, 0, size, s);
            value *= sign;
    
            if (value > INT_MAX) return INT_MAX;
            if (value < INT_MIN) return INT_MIN;
    
            return (int)value;
        }
    };