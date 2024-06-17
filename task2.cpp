#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool isUserExists(const string& username) {
    ifstream file("database.txt");
    string line;
    while (getline(file, line)) {
        if (line.substr(0, line.find(' ')) == username) {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

// register a new user
void registerUser() {
    string username, password;

    cout<<endl;

    cout << "Enter a username: ";
    cin >> username;
    cout<<endl;
    cout << "Enter a password: ";
    cin >> password;
    cout<<endl;

    if (isUserExists(username)) {
        cout << "Username already exists. Please choose a different username." << endl;
        return;
    }

    ofstream file("database.txt", ios::app);
    file << username << " " << password << endl;
    file.close();
    
    cout<<endl;
    cout << "Register successful!" << endl;
}

//  login an existing user
bool loginUser() {
    string username, password;

    cout << "Enter your username: ";
    cin >> username;
    cout<<endl;
    cout << "Enter your password: ";
    cin >> password;
    cout<<endl;

    ifstream file("database.txt");
    string line;
    while (getline(file, line)) {
        string storedUsername = line.substr(0, line.find(' '));
        string storedPassword = line.substr(line.find(' ') + 1);

        if (storedUsername == username && storedPassword == password) {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

int main() {
    int choose;

    while (true) {
        cout<<endl;
        cout << "1. Register"<<endl;
        cout<<"2. Login"<<endl;
        cout<<"3. Exit"<<endl;
        cout<<endl;
        cout<<"choose option : ";
        cin >> choose;
        cout<<endl;

        switch (choose) {
            case 1:
                registerUser();
                break;
            case 2:
                if (loginUser()) {
                    cout<<endl;
                    cout << "Login successful!" << endl;
                } else {
                    cout<<endl;
                    cout << "Invalid username or password." << endl;
                }
                break;
            case 3:
                cout<<endl;
                cout << "Exiting program." << endl;
                return 0;
            default:
            cout<<endl;
                cout << "Invalid choice.Try again." << endl;
        }
    }

    return 0;
}
