#include <bits/stdc++.h>
using namespace std;


class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        sort(a.begin(),a.end());
        long long int min_ans = INT_MAX;
        int i = 0;
        int j = m-1;
        while(j<n){
            long long int ans = a[j] - a[i];
            min_ans = min(ans,min_ans);
            i++;
            j++;
        }
        return min_ans;
        
    
    
    }   
};

int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}
