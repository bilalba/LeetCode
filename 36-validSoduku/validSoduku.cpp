#define loop(i,x) for(int i= 0; i < x; i++)
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        int row[9];
        int col[9];
        int dabba[9];
        
        // check rows.
        loop(i,9) {
            loop(k,9) row[k] = 0, col[k] = 0, dabba[k] = 0;
            loop(j,9) {
                if (board[i][j] != '.')
                    row[board[i][j]-'1']++;
                if (board[j][i] != '.')
                    col[board[j][i]-'1']++;
                if (board[(i/3)*3+j/3][(i%3)*3+j%3] != '.')
                    dabba[board[(i/3)*3+j/3][(i%3)*3+j%3]-'1']++;
            }
            loop(k,9){ if (row[k] > 1) return false; if (col[k] > 1) return false; if (dabba[k] > 1) return false; }
        }
        return true;
        // check cols.
        
        // 
    }
};