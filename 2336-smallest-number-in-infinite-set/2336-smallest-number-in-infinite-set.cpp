class SmallestInfiniteSet {
public:
    set<int>s;
    int mn=1;
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        if(s.size()&&(*s.begin())<mn){
            int val=*s.begin();
            auto itr=s.begin();
            s.erase(itr);
            return val;
        }
        mn++;
        return mn-1;
        
    }
    
    void addBack(int num) {
        if(!s.count(num)&&mn>num){
            s.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */