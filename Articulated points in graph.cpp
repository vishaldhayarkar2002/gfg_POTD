/* Hard problem :
Implementation :
Do DFS traversal of the given graph. In DFS traversal, maintain a parent[] array where parent[u] stores the parent of vertex u.
To check if u is the root of the DFS tree and it has at least two children. For every vertex, count children.
 If the currently visited vertex u is root (parent[u] is NULL) and has more than two children, print it. 
To handle a second case where u is not the root of the DFS tree and it has a child v such that no vertex in the subtree
 rooted with v has a back edge to one of the ancestors in DFS tree of u maintain an array disc[] to store the discovery time of vertices.
For every node u, find out the earliest visited vertex (the vertex with minimum discovery time) 
that can be reached from the subtree rooted with u. So we maintain an additional array low[] such that
low[u] = min(disc[u], disc[w]) , Here w is an ancestor of u and there is a back edge from some descendant of u to w.*/

class Solution {

public:
    void APUtil(vector<int> adj[], int u, bool visited[],
                int disc[], int low[], int &time, int parent,
                bool isAP[])
    {
        // Count of children in DFS Tree
        int children = 0;

        // Mark the current node as visited
        visited[u] = true;

        // Initialize discovery time and low value
        disc[u] = low[u] = ++time;

        // Go through all vertices aadjacent to this
        for (auto v : adj[u])
        {
            // If v is not visited yet, then make it a child of u
            // in DFS tree and recur for it
            if (!visited[v])
            {
                children++;
                APUtil(adj, v, visited, disc, low, time, u, isAP);

                // Check if the subtree rooted with v has
                // a connection to one of the ancestors of u
                low[u]  = min(low[u], low[v]);

                // If u is not root and low value of one of
                // its child is more than discovery value of u.
                if (parent != -1 && low[v] >= disc[u])
                    isAP[u] = true;
            }

            // Update low value of u for parent function calls.
            else if (v != parent)
                low[u]  = min(low[u], disc[v]);
        }


        // If u is root of DFS tree and has two or more chilren.
        if (parent == -1 && children > 1)
            isAP[u] = true;
    }

    vector<int> articulationPoints(int V, vector<int>adj[]) {

        vector<int> ans;  // vector to store the articulatipon points


        int disc[V] = {0};
        int low[V];
        bool visited[V] = {false};
        bool isAP[V] = {false};
        int time = 0, par = -1;


        APUtil(adj, 0, visited, disc, low,
               time, par, isAP);

        // Printing the APs
        for (int u = 0; u < V; u++)
            if (isAP[u] == true)
                ans.push_back(u);

        //  for(int i=0; i<N; i++) {
        //      if(arti[i])     // if ith node is an articulation point
        //          ans.push_back(i);
        //  }

        if (ans.size() == 0)
            ans.push_back(-1);

        return ans;
    }
};