class MyCalendarThree {
public:
    map<int, int> myMap;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        myMap[start]++;
        myMap[end]--;

        int sum = 0;
        int curSum = 0;
        for (auto it : myMap){
            curSum += it.second;
            sum = max(sum, curSum);
        }

        return sum;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */