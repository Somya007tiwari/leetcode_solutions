class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int provinces = 0;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(i, isConnected, visited);
                ++provinces;
            }
        }
        return provinces;
    }

private:
    void dfs(int i, const vector<vector<int>>& isConnected, vector<bool>& visited) {
        visited[i] = true;
        for (int j = 0; j < (int)isConnected.size(); ++j) {
            if (isConnected[i][j] == 1 && !visited[j]) {
                dfs(j, isConnected, visited);
            }
        }
    }
};