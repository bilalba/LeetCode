class Solution {
public:
    string addStrings(string num1, string num2) {
        string big;
        string small;
        string result = "";
        if (num1.length() > num2.length())
            big = num1, small = num2;
        else
            big = num2, small = num1;
        int carry = 0;
        int big_length = big.length();
        int small_length = small.length();
        for (int i =1; i <= small_length; i++) {
            int n1 = small[small_length-i]-'0';
            int n2 = big[big_length-i]-'0';
            result = ((char)((n1 + n2 + carry) % 10 + '0')) +  result; 
            
            if (n1 + n2 + carry > 9)
                carry = true;
            else
                carry = false;
        }
        for (int i =small_length+1; i <= big_length; i++) {
            int n2 = big[big_length-i]-'0';
            result = ((char)((n2 + carry) % 10 + '0')) +  result; 
            if (n2 + carry > 9)
                carry = true;
            else
                carry = false;
        }
        if (carry)
        result = '1' + result;
        return result;
    }
};