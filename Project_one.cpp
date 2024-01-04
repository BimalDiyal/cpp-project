#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class LibraryRecord {
private:
    string date;
    string userName;
    string mobileNumber;
    string bookName;
    int cost;

public:
    void write() {
        cout << "Enter date: ";
        cin >> date;
        cout << "Enter name: ";
        cin >> userName;
        cout << "Enter mobile number: ";
        cin >> mobileNumber;
        cout << "Enter the name of book: ";
        cin >> bookName;
        cout << "Enter cost: ";
        cin >> cost;

        ofstream outFile("book.txt", ios::app);
        outFile << date << " " << userName << " " << mobileNumber << " " << bookName << " " << cost << endl;

        cout << "Data written successfully" << endl;
        outFile.close();
    }

    void display(string searchDate) {
        ifstream inFile("book.txt");
        bool found = false;

        while (inFile >> date >> userName >> mobileNumber >> bookName >> cost) {
            if (date == searchDate) {
                found = true;
                cout << "\n Student name: " << userName << endl;
                cout << " Mobile no: " << mobileNumber << endl;
                cout << " Book name: " << bookName << endl;
                cout << " Book cost: " << cost << endl;
            }
        }

        if (!found) {
            cout << "No record found." << endl;
        }

        inFile.close();
    }
};

int main() {
    LibraryRecord record;
    char choice;
    string inputDate;

    do {
        cout << "\t****WELCOME TO THE SANOTIMI LIBRARY*****\n";
        cout << "Press 1 to create entry for the book\n";
        cout << "Press 2 to display on specific date\n";
        cout << "Press 3 to exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                record.write();
                cout << "Data entered successfully" << endl;
                break;
            case '2':
                cout << "Enter date: ";
                cin >> inputDate;
                record.display(inputDate);
                break;
            case '3':
                exit(0);
            default:
                cout << "Invalid input by the user" << endl;
        }
    } while (choice != '3');

    return 0;
}
