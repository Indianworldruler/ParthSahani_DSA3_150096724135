class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> visited(numCourses, 0);

        for (auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0 && !dfs(i, adj, visited))
                return false;
        }

        return true;
    }

    bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited) {
        if (visited[node] == 1)
            return false;  // Cycle detected

        if (visited[node] == 2)
            return true;   // Already processed

        visited[node] = 1; // Currently visiting

        for (int next : adj[node]) {
            if (!dfs(next, adj, visited))
                return false;
        }

        visited[node] = 2; // Fully processed
        return true;
    }
};