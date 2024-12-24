#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq; // Stores indices of array elements
    vector<int> result;

    for (int i = 0; i < nums.size(); ++i) {
        // Remove indices of elements not in the current window
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }

        // Remove indices of smaller elements as they are not useful
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }

        // Add the current element's index
        dq.push_back(i);

        // Add the maximum element of the window to the result
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }

    return result;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> result = maxSlidingWindow(nums, k);

    cout << "Max sliding window: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}