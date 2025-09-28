#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int id;
    string name;
    string department;

public:
    void getData() {
        cout <<"Enter ID: ";
        cin >> id;
        cin.ignore();

        cout <<"Enter Name: ";
        getline(cin, name);

        cout << "Enter Department: ";
        getline(cin, department);
    }

    void showData(){
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Department: " << department << endl;
    }

    int getId(){
        return id;
    }
};

void searchById(Student st[], int searchId) {
    int flag = 0;
    for (int i = 0; i < 5; i++) {
        if (st[i].getId() == searchId) {
            cout << "\nStudent Found:\n";
            st[i].showData();
            flag = 1;
            break;
        }
    }
    if (!flag) {
        cout << "\nStudent with ID " << searchId << " not found.\n";
    }
}

int main() {
    Student st[5];
    
    for (int i = 0; i < 5; i++) {
        cout << "\nEnter details for Student " << i + 1 << ":\n";
        st[i].getData();
    }

    int searchId;
    cout << "\nEnter ID to search: ";
    cin >> searchId;
    searchById(st,searchId);

    return 0;
}
