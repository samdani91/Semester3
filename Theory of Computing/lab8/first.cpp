#include<bits/stdc++.h>
using namespace std;

bool isInLanguage(const string &str);
bool testPumpingLemma(const string &str);


int main() {
    string input;
    cout << "Enter a string in the format '0^n1^n': ";
    cin >> input;

    if (isInLanguage(input)) {
        if (testPumpingLemma(input)) {
            cout << "The language L = {0^n1^n | n >= 1} is not regular using the pumping lemma." << endl;
        } else {
            cout << "The language L = {0^n1^n | n >= 1} might still be regular." << endl;
        }
    } else {
        cout << "The input string is not in the required format." << endl;
    }

    return 0;
}
bool isInLanguage(const string &str) {
    int n = str.length();
    if (n % 2 != 0) {
        return false;
    }

    int mid = n / 2;
    for (int i = 0; i < mid; i++) {
        if (str[i] != '0' || str[i + mid] != '1') {
            return false; 
        }
    }
    return true;
}
bool testPumpingLemma(const string &str) {
    int n = str.length();
    
    for (int len = 1; len <= n / 2; len++) {
        string x = str.substr(0, len);
        string y = str.substr(len, len);
        string z = str.substr(2 * len);
        string pumpedString = x + y + y + z;

        if (!isInLanguage(pumpedString)) {
            cout << "The string " << pumpedString << " is not in the language." << endl;
            return false;
        }
    }

    return true;
}
