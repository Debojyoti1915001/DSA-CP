class MyCalendarThree {
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        m[start]++;
        m[end]--;
        int res = 0;
        int cur = 0;
        for (auto & event: m)
        {
            cur += event.second;
            if (cur > res)
            {
                res = cur;
            }
        }
        return res;
    }
private:
    map<int, int> m;
};
/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */