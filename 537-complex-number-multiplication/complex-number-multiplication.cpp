class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        // Function to extract real and imaginary parts
        auto parseComplex = [](string num) {
            int plusPos = num.find('+');
            int real = stoi(num.substr(0, plusPos));
            int imag = stoi(num.substr(plusPos + 1, num.size() - plusPos - 2)); // Ignore 'i'
            return make_pair(real, imag);
        };
        
        // Extract real and imaginary parts
        auto [a, b] = parseComplex(num1);
        auto [c, d] = parseComplex(num2);
        
        // Compute the result
        int realPart = a * c - b * d;
        int imagPart = a * d + b * c;
        
        // Return in "x+yi" format
        return to_string(realPart) + "+" + to_string(imagPart) + "i";
    }
};
