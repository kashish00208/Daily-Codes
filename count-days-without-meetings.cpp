class Solution {
    public:
        int countDays(int days, vector<vector<int>>& meetings) {
            sort(meetings.begin(), meetings.end());
    
            int busyDays = 0;
            int prevEnd = 0;
    
            for (auto& meeting : meetings) {
                int start = meeting[0], end = meeting[1];
    
                if (start > prevEnd + 1) {
                    busyDays += (end - start + 1);
                } else {
                    busyDays += max(0, end - prevEnd);
                }
    
                prevEnd = max(prevEnd, end);
            }
            return days - busyDays;
        }
    };
    