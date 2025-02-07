class solution{
    public:
    int totalElements(vector<int> &arr) {
        int left = 0, right = 0, ans = 0;
        unordered_map<int, int> freqMap; 

        while (right < arr.size()) {
        freqMap[arr[right]]++;
        while (freqMap.size() > 2) {
            freqMap[arr[left]]--;
            if (freqMap[arr[left]] == 0) {
                freqMap.erase(arr[left]); 
            }
            left++; 
        }

        ans = max(ans, right - left + 1);
        right++;
    }

    return ans;
};
