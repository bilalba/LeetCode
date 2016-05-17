#include <limits.h>
#include <string>
using namespace std;
class Solution {
public:
    int myAtoi(string str) {
        int sum = 0;
        bool negative = false;
        bool sign = false;
        bool non_whitespace = false;
        
        int count = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == ' ') {
                if (non_whitespace)
                    return sum;
            } else {
            non_whitespace = true;
                if (str[i] == '+' || str[i] == '-') {
                    if (sign)
                        return 0;
                    if (str[i] == '-')
                        negative = true;
                sign = true;
                } else if (str[i] <= '9' && str[i] >= '0') {
                    count++;
                    if (sum == 0 && str[i] == '0')
                        count--;
                    
                    sum = sum * 10;
                    if (negative)
                        sum = sum - (str[i]-'0');
                    else
                        sum = sum + (str[i]-'0');
                        
                    if (count == 10) { // check overflow.
                        if (str[i-9] -'0' > 2) { // overflow has happend
                            if (negative)
                            return INT_MIN;
                                else 
                            return INT_MAX;
                        } else { // fine check overflow.
                            if (negative && sum > 0)
                                return INT_MIN;
                            else if (!negative && sum < 0)
                                return INT_MAX;
                        }
                    } else if (count > 10 ){ // overflow has happend
                        if (negative)
                            return INT_MIN;
                        else 
                            return INT_MAX;
                    }
                } else {
                    if (negative && sum > 0)
                        return INT_MIN;
                    else if (!negative && sum < 0)
                        return INT_MAX;
                    return sum;
                }
            }
        }
        if (negative && sum > 0)
                        return INT_MIN;
                    else if (!negative && sum < 0)
                        return INT_MAX;
        return sum;
    }
};