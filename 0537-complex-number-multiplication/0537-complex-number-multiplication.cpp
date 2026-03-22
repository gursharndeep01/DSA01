class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int a, a2, b, b2;
        sscanf(num1.c_str(), "%d+%di", &a, &a2);
        sscanf(num2.c_str(), "%d+%di", &b, &b2);

        int f = a*b - a2*b2;
        int f2 = a*b2 + a2*b;

        string s= to_string(f) + "+" + to_string(f2) + "i";
        return s;
    }
};