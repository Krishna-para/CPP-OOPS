// Task: Print time in hh:mm format using overloaded stream operator and friend function

#include <iostream>
using namespace std;

class Time {
    int hours, minutes;

public:
    Time(int h, int m) : hours(h), minutes(m) {}

    // friend so it can access private members hours and minutes
    friend ostream& operator<<(ostream& out, const Time& t);
};

ostream& operator<<(ostream& out, const Time& t) {
    out << (t.hours < 10 ? "0" : "") << t.hours << ":"
        << (t.minutes < 10 ? "0" : "") << t.minutes;
    return out;
}

int main() {
    Time t1(9, 5);
    Time t2(14, 30);
    Time t3(0, 45);

    cout << t1 << "\n";   // 09:05
    cout << t2 << "\n";   // 14:30
    cout << t3 << "\n";   // 00:45
    return 0;
}
