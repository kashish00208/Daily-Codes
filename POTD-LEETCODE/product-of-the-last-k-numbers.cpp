class ProductOfNumbers {
    public:
        vector<int>ans;
        ProductOfNumbers() {
            
        }
        
        void add(int num) {
            ans.push_back(num);
        }
        
        int getProduct(int k) {
            int res = 1 , n = ans.size()-1;
            while(k>0){
                res *= ans[n];
                n-- , k--;
            }
            return res;
        }
    };
    
    /**
     * Your ProductOfNumbers object will be instantiated and called as such:
     * ProductOfNumbers* obj = new ProductOfNumbers();
     * obj->add(num);
     * int param_2 = obj->getProduct(k);
     */