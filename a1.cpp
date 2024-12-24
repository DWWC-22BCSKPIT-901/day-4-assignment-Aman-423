#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> stk; // Stack to store indices

    for (int i = 0; i < 2 * n; ++i) {
        int num = nums[i % n];
        while (!stk.empty() && nums[stk.top()] < num) {
            result[stk.top()] = num;
            stk.pop();
        }
        if (i < n) {
            stk.push(i);
        }
    }

    return result;
}

int main() {
    vector<int> nums = {1, 2, 1};
    vector<int> result = nextGreaterElements(nums);

    cout << "Next greater elements: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}