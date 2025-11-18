/*#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << setw(10) << "Hello" << endl;          // width = 10
    cout << setfill('*') << setw(10) << "Hi" << endl;  // fill with *

    cout << fixed << setprecision(2);
    cout << "Value = " << 12.34567 << endl;       // 12.35

    cout << boolalpha;
    cout << "Is coding fun? " << true << endl;    // true

    return 0;
}
*/
/*
#include <iostream>
using namespace std;

class Student {
public:
    Student() { cout << "Constructor Called\n"; }
    ~Student() { cout << "Destructor Called\n"; }
};

int main() {
    int n = 3;
    Student *arr = new Student[n];   // dynamic array of objectsx

    delete[] arr;                    // destructor is called for each object
    return 0;
}
*/
/*
#include <iostream>
using namespace std;

class A {
public:
    void show() { cout << "Base show\n"; }

    void show(int x) { cout << "Overloaded show: " << x << endl; }
};

class B : public A {
public:
    void show() { cout << "Overridden show in derived\n"; }
};

int main() {
    A obj1;
    obj1.show();         // base
    obj1.show(10);       // overloaded

    B obj2;
    obj2.show();         // overridden

    return 0;
}
*/


/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
using namespace std;

int main() {
    vector<int> v = {5, 3, 8, 1, 3};
    sort(v.begin(), v.end());
    cout << "Sorted: ";
    for (int x : v) cout << x << " ";
    cout << endl;

    cout << "Count of 3 = " << count(v.begin(), v.end(), 3) << endl;

    auto it = find(v.begin(), v.end(), 8);
    if (it != v.end()) cout << "8 found\n";

    reverse(v.begin(), v.end());
    cout << "Reversed: ";
    for (int x : v) cout << x << " ";
    cout << endl;

    list<int> l = {10, 20, 10, 30};
    replace(l.begin(), l.end(), 10, 99);

    map<int, string> mp;
    mp[1] = "Apple";
    mp[2] = "Mango";

    cout << "Map element: " << mp[1] << endl;

    return 0;
}





#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string, int> um;

    um["Apple"] = 100;
    um["Banana"] = 40;

    cout << um["Apple"] << endl;

    if (um.count("Banana"))
        cout << "Banana found\n";

    um.erase("Apple");

    return 0;
}*/





/*
#include <iostream>
using namespace std;

// Template function to add two values
template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    cout << add<int>(5, 7) << '\n';         // 12
    cout << add<double>(3.2, 4.8) << '\n';  // 8.0
    cout << add<string>("Hi, ", "You") << '\n'; // "Hi, You"
    return 0;
}
*/
/*
#include <iostream>
using namespace std;

template <typename T>
class Box {
private:
    T value;
public:
    Box() : value(T()) {}           
    Box(T v) : value(v) {}         
    void set(T v) { value = v; }
    T get() const { return value; }

    void show() const { cout << "Value = " << value << '\n'; }
};

int main() {
    Box<int> b1(10);
    b1.show();         
    Box<string> b2("Hello");
    b2.show();            

    Box<double> b3;
    b3.set(3.14);
    cout << b3.get() << '\n';

    return 0;
}*/



























// Program: Custom Exception for Bank Withdrawal
#include <iostream>
#include <exception>
using namespace std;

class LowBalance : public exception {
public:
    const char* what() const throw() {
        return "Balance Too Low!";
    }
};

int main() {
    int balance = 500, withdraw;

    cout << "Enter amount to withdraw: ";
    cin >> withdraw;

    try {
        if (withdraw > balance)
            throw LowBalance();

        cout << "Withdrawal Successful!";
    }
    catch (LowBalance &e) {
        cout << "Exception: " << e.what();
    }

    return 0;
}