class MyCalendar {
    set<pair<int, int>> bookings;
public:
    MyCalendar() {

    }
    
    bool book(int start, int end) {
        auto slot = bookings.lower_bound({start, end});
        if (slot != bookings.end() && !((*slot).first >= end) || 
            slot != bookings.begin() && !((*prev(slot)).second <= start)){
            return false;
        }
        bookings.insert({start, end});
        return true;
    }
};
