class Solution {
public:
    vector<string> generateParenthesis(int n) {
        return recursion(n,n,"");
    }
    
    vector<string> recursion(int open, int closed,string str) {
        vector<string> a, b;
        if (closed == 0){
            a.push_back(str);
            return a;
        }
        if (open == closed) {
            str += "(";
            open--;
        }
        
        if (closed > open) {
            if (open > 0)
                b =recursion( open-1, closed, str+"(");
            a = recursion(open, closed-1, str+")");
            
                
        }
        for (int i = 0; i < a.size(); i++) {
            b.push_back(a[i]);
        }
        return b;
        
        
    }
};