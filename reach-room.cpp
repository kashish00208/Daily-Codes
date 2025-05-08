class Solution {
    public:
        int dirs[5]={1,0,-1,0,1};
        int n,m;
        bool isValid(int x,int y)
        {
            return x>=0 && y>=0 && x<n && y<m;
        }
        int minTimeToReach(vector<vector<int>>& moveTime) 
        {
            priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
            pq.push({0,0,0,1});
            n=moveTime.size(),m=moveTime[0].size();
            vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
            dist[0][0]=0;
            while(!pq.empty())
            {
                int t=pq.top()[0],i=pq.top()[1],j=pq.top()[2],t1=pq.top()[3];
                pq.pop();
                for(int k=0;k<4;k++)
                {
                    int x=i+dirs[k],y=j+dirs[k+1];
                    if(isValid(x,y))
                    {
                        int currt=max(t,moveTime[x][y])+t1;
                        if(dist[x][y]>currt)
                        {
                            dist[x][y]=currt;
                            pq.push({dist[x][y],x,y,(t1==1?2:1)});
                        }
                    }
                }
            }
            return dist[n-1][m-1];
        }
    };