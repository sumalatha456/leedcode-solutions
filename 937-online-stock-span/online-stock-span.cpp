#include <stack>
#include <utility> // for std::pair

class StockSpanner {
public:
    // Stack to store pairs of price and its span
    std::stack<std::pair<int, int>> st;

    StockSpanner() {
    }
    
    int next(int price) {
        int span = 1;  // Default span is 1, as it includes the current day
        
        // Pop the stack while the top of the stack's price is less than or equal to the current price
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second; // Add the span of the previous day(s)
            st.pop();  // Remove the pair from the stack
        }
        
        // Push the current price and its span onto the stack
        st.push({price, span});
        
        return span;  // Return the span for the current day
    }
};
