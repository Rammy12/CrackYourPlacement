/* 
problem:- https://leetcode.com/problems/find-if-path-exists-in-graph/description/
*/

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,list<int>>adjlist;
        for(int i=0; i<edges.size(); i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];

            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }

        vector<int>visited(n,false);

        queue<int>q;
        q.push(source);
        visited[source]=true;
        while(!q.empty())
        {
            int frontNode=q.front();
            q.pop();
            for(auto x:adjlist[frontNode])
            {
                if(!visited[x])
                {
                    q.push(x);
                    visited[x]=true;
                }
            }
        }
        return visited[destination];
    }
};