#include "MatrixMultiplication.h"
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> multiply(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int x = A.size();
    int y = A[0].size();
    int z = B[0].size();

    vector<vector<int>> C(x, vector<int>(z, 0));

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < z; j++) {
            for (int k = 0; k < y; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}
