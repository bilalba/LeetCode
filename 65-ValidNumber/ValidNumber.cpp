#include <string>
using namespace std;
class Solution {
public:
    static bool isNumber(string s) {
        bool dec =false;
        bool exp = false;
        bool exp_dec = false;
        
        bool num_a_dec = false;
        bool num_b_exp = false;
        bool num_a_exp = false;
        
        bool negative = false;
        bool space_occured = false;
        bool exp_sign = false;
        for (int i = 0; i < s.size(); i++) {
            
        
            if (s[i] == ' ') {
                if (num_b_exp || dec || negative) {
                    space_occured = true;
                }
            } else if (s[i] == '-' || s[i] == '+') {
                if (exp) {
                    if (num_a_exp)
                        return false;
                    if (exp_sign)
                        return false;
                    exp_sign = true;
                } else {
                    if (num_b_exp || dec) {
                        return false;
                    }
                    if (negative)
                        return false;
                    negative = true;
                }
            }else if (s[i] == '.') {
                if (space_occured)
                    return false;
                if (exp) {
                    return false;
                } else {
                    if (dec) {
                        return false;
                    } else {
                        dec = true;    
                    }  
                }
            } else if (s[i] == 'e') {
                if (!num_b_exp) {
                    return false;
                }
                if (exp) {
                    return false;
                } else {
                    exp = true;
                } 
            } else if (s[i] <= '9' && s[i] >= '0') {
                if (space_occured)
                    return false;
                if (exp) {
                    num_a_exp = true;
                } else {
                    num_b_exp = true;
                }
                if (dec) {
                    num_a_dec = true;
                }
            } else {
                return false;
            }
            
        }
        
        if (!num_b_exp)
            return false;
        if (exp){
            if (!num_a_exp) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution::isNumber("sds");
}