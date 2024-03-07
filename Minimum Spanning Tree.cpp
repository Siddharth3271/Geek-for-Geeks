/*Let EE denote the total number of edges in the graph, and VV denote the number of vertices. In the worst case, each edge is considered twice (once for each incident vertex) in the for loop inside the while loop. Therefore, the time complexity is O(Elog⁡V)O(ElogV), where log⁡VlogV represents the complexity of priority queue operations.

The space complexity mainly comes from the priority queue, the inMst vector, and any additional space used to represent the graph. The priority queue can store at most EE elements. The inMst vector has VV elements. The space complexity is O(E+V)O(E+V).*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  typedef pair<int,int>p;
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<p,vector<p>,greater<p>>pq;
        //weight,node,parent
        //but for sum need only weight and node;
        //{wt,node}
        pq.push({0,0});
        vector<bool>inMst(V,false);
        int sum=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int wt=it.first;
            int node=it.second;
            if(inMst[node]==true){
                continue;
            }
            inMst[node]=true;   //added in mst
            sum+=wt;
            
            //iss node se aur kaha kaha jaa sakta hoon
            for(auto &tmp: adj[node]){
                int neighbour=tmp[0];
                int neighbour_weight=tmp[1];
                
                //priority queue mey kab dalenge
                if(inMst[neighbour]==false){
                    pq.push({neighbour_weight,neighbour});
                }
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
