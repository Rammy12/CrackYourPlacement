/*

problem:- https://www.codingninjas.com/studio/problems/shortest-path-in-an-unweighted-graph_981297?leftPanelTab=0
*/

#include <unordered_map>
#include <list>
#include <queue>

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	unordered_map<int,list<int>>adjlist;
	unordered_map<int,bool>visited;
	unordered_map<int,int>parent;
	//step 1 creat adj list
	for(int i=0; i<edges.size(); i++)
	{
		int u=edges[i].first;
		int v=edges[i].second;


		adjlist[u].push_back(v);
		adjlist[v].push_back(u);
	}
	//step 2 
	queue<int>q;
	q.push(s);
	parent[s]=-1;
	visited[s]=true;
	while(!q.empty())
	{
		int frontNode=q.front();
		q.pop();
		for(auto x:adjlist[frontNode])
		{
			if(!visited[x])
			{
				visited[x]=true;
				parent[x]=frontNode;
				q.push(x);
			}
		}
	}
	//step 3
	vector<int>ans;
	int currentNode=t;
	ans.push_back(t);
	while(currentNode!=s)
	{
		currentNode=parent[currentNode];
		ans.push_back(currentNode);
	}
	reverse(ans.begin(),ans.end());
	return ans;
}
