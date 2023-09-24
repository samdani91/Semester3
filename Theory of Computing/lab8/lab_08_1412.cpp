#include <bits/stdc++.h>
using namespace std;

bool isInLang(string str);
void testPumpingLemma(const string &str);

string temp;

int main()
{
    string input;
    cout << "Input format: 0^n1^n" << endl;
    cin >> input;

    int arr[2], i, j = 0;
    for (i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == '^')
        {
            i++;
            arr[j++] = input[i] - '0';
        }
    }
    if (arr[0] != arr[1])
        return false;

    for (i = 0; i < arr[0]; i++)
    {
        temp += '0';
    }
    for (; i < 2 * arr[0]; i++)
    {
        temp += '1';
    }

    if (isInLang(temp))
    {
        testPumpingLemma(temp);
    }
    else
    {
        cout << "Incorrect Format" << endl;
    }
}

bool isInLang(string str)
{
    
    int n = str.size();
    if (n % 2 != 0)
    {
        return false;
    }
    int mid = n / 2;
    for (int i = 0; i < mid; i++)
    {
        if (str[i] != '0' || str[i + mid] != '1')
        {
            return false;
        }
    }

    return true;
}
void testPumpingLemma(const string &str)
{
    int n = str.length();

    for (int len = 1; len <= n / 2; len++)
    {
        string x = str.substr(0, len);
        cout<<"x:"<<x<<endl;
        string y = str.substr(len, len);
        cout<<"y:"<<y<<endl;
        string z = str.substr(2 * len);
        cout<<"z:"<<z<<endl;
        string pumpedString = x + y + y + z;
        cout<<pumpedString<<endl;

        if (!isInLang(pumpedString))
        {
            cout << "The string " << pumpedString << " is not in the language." << endl;
            return;
        }
    }

}