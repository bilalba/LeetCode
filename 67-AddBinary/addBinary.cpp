class Solution {
public:
    string addBinary(string a, string b) {
        long a1 = 0;
        long b1 = 0;
        for (int i = 0; i < a.length(); i++) {
            a1 <<= 1;
            if (a[i] == '1')
                a1 |= 1;
        }
        for (int i = 0; i <b.length(); i++) {
            b1 <<= 1;
            if (b[i] == '1')
                b1 |= 1;
        }
        a1 += b1;
        string c = "";
        if (a1 == 0)
            return "0";
        for (int i = 0; a1 != 0; i++) {
            if (a1%2)
             c= "1" + c;
             else
             c = "0" + c;
             a1 >>= 1;
        }
        return c;
    }
};