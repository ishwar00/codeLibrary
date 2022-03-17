/*
 *
 * problem link: https://leetcode.com/problems/course-schedule/
 *
 * */

using namespace std;

class Solution {
    vector<vector<int>> graph;
public:

    vector<int> get_indegree() {
        vector<int> indegree(graph.size());
        for (auto const& vec : graph) {
            for (int const& neighbour : vec) {
                indegree[neighbour]++;
            }
        }
        return indegree;
    }
    
    bool canFinish(int N, vector<vector<int>> const& prerequisites) {
        graph = vector<vector<int>>(N);
        for (auto const& dependency : prerequisites) {
            graph[dependency[1]].push_back(dependency[0]);
        }

        auto indegree = get_indegree();

        auto find_zero_indegree = [&]() -> int {
            for (int i = 0; i < N; ++i) {
                if (indegree[i] == 0) return i;
            }
            return -1;
        };
        
        for (int i = 0; i < N; ++i) {
            int zero_indegree_node = find_zero_indegree();
            if (zero_indegree_node != -1) {
                indegree[zero_indegree_node] = -1;
                for (int const& neighbour : graph[zero_indegree_node]) {
                    indegree[neighbour] = indegree[neighbour] - 1;
                }
            } else {
                return false;
            }
        }
        return true;
    }
};
