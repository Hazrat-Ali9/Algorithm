// Palindrome Program:
#include <bits/stdc++.h>
using namespace std;
bool is_palindrome(string str)
{
    // base case
    if (str == "" || str.size() == 1)
        return true;
    int n = str.size();
    string small_str = str.substr(1, n - 2);
    return is_palindrome(small_str) && (str[0] == str.back());
}
int main() {
    string str;
    cin >> str;
    if (is_palindrome(str))
        cout << "Palindrome" << endl;
    else
        cout << "Not Palindrome" << endl;
    return 0;
}