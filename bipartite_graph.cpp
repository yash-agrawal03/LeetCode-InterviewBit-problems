class Solution
{
public:
    bool bfs(int i, vector<vector<int>> &graph, vector<int> &visited, vector<int> &color)
    {

        queue<pair<int, int>> q;
        q.push({i, -1});
        visited[0] = 1;
        while (!q.empty())
        {
            auto x = q.front();
            q.pop();
            int parent = x.second;
            int node = x.first;
            for (auto y : graph[node])
            {
                if (!visited[y])
                {
                    visited[y] = 1;
                    color[y] = !color[node];
                    q.push({y, node});
                }
                else
                {
                    if (color[y] == color[node])
                    {
                        return false;
                    }
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> visited(n, 0), color(n, 0);
        int col = 1;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                if (!bfs(i, graph, visited, color))
                {
                    return false;
                }
            }
        }

        return true;
    }
};