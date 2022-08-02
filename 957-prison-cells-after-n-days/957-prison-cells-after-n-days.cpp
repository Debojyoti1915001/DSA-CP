class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        for (n = (n - 1) % 14 + 1; n > 0; --n) {
            vector<int> cells2(8, 0);
            for (int i = 1; i < 7; ++i)
                cells2[i] = cells[i - 1] == cells[i + 1] ? 1 : 0;
            cells = cells2;
        }
        return cells;
    }
};