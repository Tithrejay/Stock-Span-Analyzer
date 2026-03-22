#include <iostream>
#include <stack>
using namespace std;

// Function to calculate stock span
void calculateSpan(int price[], int n) {
    stack<int> st;
    int span[n];

    // First day span is always 1
    st.push(0);
    span[0] = 1;

    for (int i = 1; i < n; i++) {
        // Pop elements while current price is higher
        while (!st.empty() && price[st.top()] <= price[i]) {
            st.pop();
        }

        // Calculate span
        span[i] = (st.empty()) ? (i + 1) : (i - st.top());

        // Push current index
        st.push(i);
    }

    // Print result
    cout << "Stock Span: ";
    for (int i = 0; i < n; i++) {
        cout << span[i] << " ";
    }
}

// Main function
int main() {
    int price[] = {100, 20, 50, 30, 70, 110, 120};
    int n = sizeof(price) / sizeof(price[0]);

    calculateSpan(price, n);

    return 0;
}
