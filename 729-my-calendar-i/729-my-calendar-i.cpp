class MyCalendar {
public:
    set<pair<int,int>>books;
    MyCalendar() {
        
    }
    
    bool book(int s, int e) {
        auto next=books.lower_bound({s,e});
        if(next!=books.end()&&next->first<e)return false;
        if(next!=books.begin()&&s<(--next)->second)return false;
        books.insert({s,e});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */