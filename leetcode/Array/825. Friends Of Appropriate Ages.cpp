// Write a sub function request(a, b) to check if age a will friend requests age b.
// I just copy it from description:
// return !(condition1 || condition2 || condition3)

// Count nunmber of all ages to a map.
// Because we have at most 20000 ages but only in range [1, 120].

// For each age a and each age b != a, if request(a, b), we will make count[a] * count[b] requests.

// For each age a, if request(a, a), we will make count[a] * (count[a] - 1) requests.

C++:

    int numFriendRequests(vector<int>& ages) {
        unordered_map<int, int> count;
        for (int &age : ages)
            count[age]++;
        int res = 0;
        for (auto &a : count)
            for (auto &b : count)
                if (request(a.first, b.first))
                    res += a.second * (b.second - (a.first == b.first ? 1 : 0));
        return res;
    }

    bool request(int a, int b) {
        return !(b <= 0.5 * a + 7 || b > a || (b > 100 && a < 100));
    }