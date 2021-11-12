// https://leetcode.com/problems/my-calendar-i/

Solution 1: Check every existed book for overlap
overlap of 2 interval a b is (max(a0, b0), min(a1, b1))
detail is in: https://discuss.leetcode.com/topic/111198
Java

class MyCalendar {
    private List<int[]> books = new ArrayList<>();
    public boolean book(int start, int end) {
        for (int[] b : books)
            if (Math.max(b[0], start) < Math.min(b[1], end)) return false;
        books.add(new int[]{ start, end });
        return true;
    }
}
C++

class MyCalendar {
    vector<pair<int, int>> books;
public:    
    bool book(int start, int end) {
        for (pair<int, int> p : books)
            if (max(p.first, start) < min(end, p.second)) return false;
        books.push_back({start, end});
        return true;
    }
};
Solution 2: Keep existing books sorted and only check 2 books start right before & after the new book starts
Another way to check overlap of 2 intervals is a started with b, or, b started within a.

Keep the intervals sorted,
if the interval started right before the new interval contains the start, or
if the interval started right after the new interval started within the new interval.

   floor      ceiling
... |----| ... |----| ...
       |---------|
      s         e
if s < floor.end or e > ceiling.start, there is an overlap.

Another way to think of it:
If there is an interval start within the new book (must be the ceilingEntry) at all, or
books: |----|   |--|
            s |------| e

books: |----|   |----|
            s |----| e
If the new book start within an interval (must be the floorEntry) at all
books: |-------|   |--|
       s |---| e

books: |----|   |----|
        s |----| e
There is a overlap 

Java
TreeSet

class MyCalendar {
    TreeSet<int[]> books = new TreeSet<int[]>((int[] a, int[] b) -> a[0] - b[0]);

    public boolean book(int s, int e) {
        int[] book = new int[] { s, e }, floor = books.floor(book), ceiling = books.ceiling(book);
        if (floor != null && s < floor[1]) return false; // (s, e) start within floor
        if (ceiling != null && ceiling[0] < e) return false; // ceiling start within (s, e)
        books.add(book);
        return true;
    }
}
TreeMap

class MyCalendar {
    TreeMap<Integer, Integer> books = new TreeMap<>();

    public boolean book(int s, int e) {
        java.util.Map.Entry<Integer, Integer> floor = books.floorEntry(s), ceiling = books.ceilingEntry(s);
        if (floor != null && s < floor.getValue()) return false; // (s, e) start within floor
        if (ceiling != null && ceiling.getKey() < e) return false; // ceiling start within (s, e)
        books.put(s, e);
        return true;
    }
}
C++
ordered set

class MyCalendar {
    set<pair<int, int>> books;
public:
    bool book(int s, int e) {
        auto next = books.lower_bound({s, e}); // first element with key not go before k (i.e., either it is equivalent or goes after).
        if (next != books.end() && next->first < e) return false; // a existing book started within the new book (next)
        if (next != books.begin() && s < (--next)->second) return false; // new book started within a existing book (prev)
        books.insert({ s, e });
        return true;
    }
};
ordered map

class MyCalendar {
    map<int, int> books;
public:
    bool book(int s, int e) {
        auto next = books.lower_bound(s); // first element with key not go before k (i.e., either it is equivalent or goes after).
        if (next != books.end() && next->first < e) return false; // a existing book started within the new book (next)
        if (next != books.begin() && s < (--next)->second) return false; // new book started within a existing book (prev)
        books[s] = e;
        return true;
    }
};