// Last updated: 3/25/2026, 9:04:39 AM
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Step 1: build an adjacency list
        vector<vector<pair<int,int>>> graph(n+1);
        for(auto &t: times) {
            // source, target, weight
            int u = t[0], v = t[1], w = t[2];
            graph[u].push_back({v,w});
        }

        // Step 2: use min-heap to process the nodes with smallest known distance
        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,k});  // source we are given

        // Step 3: Relax all outgoing edges
        while(!pq.empty()) {
            auto[d, u] = pq.top();
            pq.pop();

            if(d > dist[u]) continue; //A shorter path to u was found after we pushed this (d, u) into the queue.
            for(auto &[v, w] : graph[u]) {
                if(dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        // Step 4: After visiting all reachable nodes, check the max distance
        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            // Step 5: If any node is unreachable, return -1
            if(dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};