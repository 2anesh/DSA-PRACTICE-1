class MyCalendarTwo {
private:
    vector<pair<int, int>> bookings;
    vector<pair<int, int>> overlaps;
public:
    MyCalendarTwo() {        
    }    
    bool book(int start, int end) {
        for (const auto& [s, e] : overlaps) {
            if (start < e && end > s) {
                return false;
            }
        }
        for (const auto& [s, e] : bookings) {
            if (start < e && end > s) {
                overlaps.push_back({max(start, s), min(end, e)});
            }
        }
        bookings.push_back({start, end});
        return true;
    }
};
