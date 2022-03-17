/*
 *
 *
 * problem link: https://practice.geeksforgeeks.org/problems/check-mirror-in-n-ary-tree1528/1#
 *
 * */



class Solution {
public:
    int checkMirrorTree(int N, int E, int A[], int B[]) {

        vector<stack<int>> st_vec(N + 1);
        for (int i = 0; i < E * 2; i += 2) {
            st_vec[A[i]].push(A[i + 1]);
        }

        for (int i = 0; i < E * 2; i += 2) {
            if (st_vec[B[i]].top() != B[i + 1]) {
                return false;
            } else {
                st_vec[B[i]].pop();
            }
        }
        return true;
    }
};

