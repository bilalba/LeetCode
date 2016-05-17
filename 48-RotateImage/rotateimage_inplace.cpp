class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int j = 0; j < n/2; j++) {
            for (int i = j; i < n-1-j; i++) {
                int top = matrix[j][i];
                int p = n-i-1;
                int t = n-j-1;
                matrix[j][i] = matrix[p][j]; // replacing top with left.
                matrix[p][j] = matrix[t][p]; // replacing left with bottom.
                matrix[t][p] = matrix[i][t]; // replacing botom with right.
                matrix[i][t] = top;
            }
        }
        
    }
};