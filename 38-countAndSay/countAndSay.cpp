#define loop(i,x) for (int i = 0; i < x; i++)
class Solution {
public:
    string countAndSay(int n) {
        string z = "1";
        loop(k, n-1){
            int digits = z.length();
            int last_digit = -1;
            int last_dig_count = 0;
            string next_n = "";
            loop(i, digits+1) {
                int digit = z[i]- '0';
                if (last_digit == digit || last_digit == -1) {
                    last_dig_count++;
                    last_digit = digit;
                }  else {
                    next_n += to_string((last_dig_count) *10 + last_digit);
                    last_dig_count = 1;
                    last_digit = digit;
                    // digit has changed.
                }
            }
            z = next_n;
            next_n = "";   
        }
        return z;
    }
};