class Solution {
public:
    std::vector<std::vector<int>>
    buildMatrix(int k, std::vector<std::vector<int>>& rowConditions,
                std::vector<std::vector<int>>& colConditions) {
        std::vector<std::vector<int>> rowGraph(k + 1);
        for (const auto& rowCondition : rowConditions) {
            rowGraph[rowCondition[0]].push_back(rowCondition[1]);
        }
        std::vector<std::vector<int>> colGraph(k + 1);
        for (const auto& colCondition : colConditions) {
            colGraph[colCondition[0]].push_back(colCondition[1]);
        }
        std::vector<int> visited(k + 1, 0);
        std::deque<int> queue;
        for (int i = 1; i <= k; ++i) {
            if (!topSort(rowGraph, i, visited, queue)) {
                return {};
            }
        }
        std::vector<int> rowIndexMap(k + 1);
        for (int i = 0; i < k; ++i) {
            int node = queue.back();
            queue.pop_back();
            rowIndexMap[node] = i;
        }
        visited.assign(k + 1, 0);
        queue.clear();
        for (int i = 1; i <= k; ++i) {
            if (!topSort(colGraph, i, visited, queue)) {
                return {};
            }
        }
        std::vector<int> colOrder(k);
        std::vector<int> colIndexMap(k + 1);
        for (int i = 0; i < k; ++i) {
            int node = queue.back();
            queue.pop_back();
            colOrder[i] = node;
            colIndexMap[node] = i;
        }
        std::vector<std::vector<int>> result(k, std::vector<int>(k, 0));
        for (int i = 1; i <= k; ++i) {
            result[rowIndexMap[i]][colIndexMap[i]] = i;
        }
        return result;
    }
private:
    bool topSort(const std::vector<std::vector<int>>& graph, int node,
                 std::vector<int>& visited, std::deque<int>& queue) {
        if (visited[node] == 2)
            return false;
        if (visited[node] == 0) {
            visited[node] = 2;
            for (int child : graph[node]) {
                if (!topSort(graph, child, visited, queue)) {
                    return false;
                }
            }
            visited[node] = 1;
            queue.push_back(node);
        }
        return true;
    }
};
