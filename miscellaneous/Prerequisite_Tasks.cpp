/*
 *
 * problem link: https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1/#
 *
 *
 *
 * /
 
 #include<bits/stdc++.h>
using namespace std;

class Solution {
    enum class Color { WHITE, BLACK, GRAY };
    vector<Color> color;
    vector<vector<int>> graph;
public:

    bool DFS(int at) {
        color[at] = Color::GRAY;
        for (int const& a : graph[at]) {
            if (color[a] == Color::GRAY or
                ((color[a] == Color::WHITE and not DFS(a))) 
            {
                return false;
            }
        }
        color[at] = Color::BLACK;
        return true;
    }

    bool isPossible(int const& N, vector<pair<int, int>> const& prerequisites) {
        graph = vector<vector<int>>(N);
        color = vector<Color>(N, Color::WHITE);
        for (auto const& dependency : prerequisites) {
            graph[dependency.second].push_back(dependency.first);
        }

        for (int i = 0; i < N; ++i) {
            if (color[i] != Color::BLACK) {
                if (not DFS(i)) return false;
            }
        }
        return true;
    }

};
