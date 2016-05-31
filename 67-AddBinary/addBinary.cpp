class Solution {
public:
    string addBinary(string a, string b) {
        int a_length = a.length();
        int b_length = b.length();
        int min;
        int max;
        string longer;
        string shorter;
        if (a_length > b_length) {
            max = a_length; longer = a;
            min= b_length; shorter = b;
        } else {
            min = a_length; shorter = a;
            max = b_length; longer = b;
        }
        bool carry = false;
        string c = "";
        for (int i = 0; i < min; i++) {
            int min_i = min -1-i;
            int max_i = max -1-i;
            if ((shorter[min_i] == '1') && (longer[max_i] == '1')) {
                if (carry)
                    c = '1' + c;
                else
                 c = '0' + c;
                 carry = true;
            } else if((shorter[min_i] == '1') || (longer[max_i] == '1')) {
                if (carry) {
                    c = '0' + c;
                    carry = true;
                } else {
                     c = '1' + c;
                     carry = false;
                }
                    
            } else {
                if (carry)
                    c = '1' + c;
                else
                 c = '0' + c;
                carry = false;
            }
        }
        
        for (int i = 0; i < max -min; i++) {
            int index = max-min -1 - i;
            if (longer[index] == '1') {
                if (carry) {
                    c = '0' + c;
                    // carry = true;
                } else {
                    c = '1' + c;
                    carry = false;
                }

