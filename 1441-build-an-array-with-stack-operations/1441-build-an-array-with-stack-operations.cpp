class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> result;
        int current = 1; // The current number to be pushed.

        for (int i = 0; i < target.size(); i++) {
            while (current < target[i]) {
                // While the current number is less than the target number,
                // push the current number and generate the "Push" operation.
                result.push_back("Push");
                result.push_back("Pop"); // After pushing, immediately pop.
                current++;
            }

            // The current number matches the target number, so push it.
            result.push_back("Push");

            current++; // Move to the next number to be pushed.
        }
        return result;
    }};