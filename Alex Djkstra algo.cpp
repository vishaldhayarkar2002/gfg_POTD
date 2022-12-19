/*
Implementation
Step 1: Create a weighted directed graph from the flights vector. 
Step 2: Create a container to store the cost to visit i’th city, initialy filled with INT_MAX.
Step 3: Run Dijkstra from k’th city.
Step 4: Find the maximum cost among all the cities and return it. 
If the maximum cost is INT_MAX it means there is a city, which can’t be visited from k’th city, then return -1.

In the Dijkstra funtion
Step 1: Create a min priority queue of pair<int, int> type, where we will push {cost, city} pair.
Step 2: Push {0, source} in the priority queue. Here source is k and cost to visit k’th city is 0
 because we are already in k’th city. Update cost to reach k’th city equal to 0.
Step 3: Run a loop until the queue becomes empty.
 inside the loop
 Step 4: take the top element of the queue, set currNodeCost = queue.top().first and 
 currNode = queue.top().second. Then pop that element.
 Step 5: If the cost to reach current city is greater than currNodeCost, skip the iteration.
 Step 6: else visit all the neighboring cities and calculate how much cost it takes visti neighboring cities.
 If the cost of visiting a neighboring city is less than the previous cost then update the cost and 
 push the cost to visit that city and the city in the queue.
loop end*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<pair<int, int>> adj[501];

    void dijkstra(vector<int>& costToReach, int source, int n) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;
        pq.push({0, source});

        // Time for starting node is 0
        costToReach[source] = 0;

        while (!pq.empty()) {
            int currNodeCost = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();

            if (currNodeCost > costToReach[currNode]) {
                continue;
            }

            // Broadcast the signal to adjacent nodes
            for (pair<int, int> edge : adj[currNode]) {
                int cost = edge.first;
                int neighborNode = edge.second;

                // Fastest signal cost for neighborNode so far
                // costToReach[currNode] + cost :
                // cost when signal reaches neighborNode
                if (costToReach[neighborNode] > currNodeCost + cost) {
                    costToReach[neighborNode] = currNodeCost + cost;
                    pq.push({costToReach[neighborNode], neighborNode});
                }
            }
        }
    }
    int minimumCost(vector<vector<int>>& flights, int n, int k) {
        for (vector<int> f : flights) {
            int source = f[0];
            int dest = f[1];
            int travelCost = f[2];

            adj[source].push_back({travelCost, dest});
        }

        vector<int> costToReach(n + 1, INT_MAX);
        dijkstra(costToReach, k, n);

        int answer = INT_MIN;
        for (int i = 1; i <= n; i++) {
            answer = max(answer, costToReach[i]);
        }

        // INT_MAX signifies atleat one node is unreachable
        return answer == INT_MAX ? -1 : answer;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int size;
        cin >> size;
        vector<vector<int>> flights(size,vector<int>(3));
        for (int i = 0; i < size; i++) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights[i]=temp;
        }

        Solution ob;
        cout << ob.minimumCost(flights, n, k) << "\n";
    }
}
