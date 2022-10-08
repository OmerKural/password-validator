#include <iostream>
#include <string>
#include <sstream>
#include <random>
#include <iterator>
#include <algorithm>
using namespace std;

string UI()
{
    string password;
    cout << "Please enter your password -> ";
    getline(cin, password);
    return password;
}

int validate(string password) // -> returns -1, 0, 1
{
    // A strong password is: At least 12 characters long but 14 or more is better.
    // A combination of uppercase letters, lowercase letters, numbers, and symbols.
    int points = 0;

    const int length = password.size();

    // Convert password to digits for easier computation.
    vector<int> digit_password;
    for (int i = 0; i < length; i++)
    {
        digit_password.push_back(int(password[i]));
    }
    

    // size
    if (length < 12)
    {
        return -1;
    }
    else if (12 <= length < 14)
    {
        points += length;
    }
    else
    {
        points += length*2;
    }

    // Uppercase
    int uppercase_count = 0;
    for (int i = 0; i < length; i++)
    {
        if (65 <= digit_password[i] && digit_password[i] <= 90) // uppercase letters are located in [65, 90]
        {
            uppercase_count++;
        }
    }
    if (uppercase_count == 0)
    {
        return -2;
    }
    else if (1 <= uppercase_count <= 3)
    {
        points += uppercase_count;
    }
    else
    {
        points += uppercase_count*2;
    }
    
    // Lowercase
    int lowercase_count = 0;
    for (int i = 0; i < length; i++)
    {
        if (97 <= digit_password[i] && digit_password[i] <= 122) // lowercase letters are located in [97, 122]
        {
            lowercase_count++;
        }
    }
    if (lowercase_count == 0)
    {
        return -3;
    }
    else
    {
        points += lowercase_count;
    }

    // Numbers
    int digits_count = 0;
    for (int i = 0; i < length; i++)
    {
        if (48 <= digit_password[i] && digit_password[i] <= 57) // numbers are located in [48, 57]
        {
            digits_count++;
        }
    }
    if (digits_count == 0)
    {
        return -4;
    }
    else
    {
        points += digits_count*2;
    }

    // Symbols
    int symbols_count = 0;
    for (int i = 0; i < length; i++)
    {
        if (32 <= digit_password[i] && digit_password[i] <= 47 || 
        58 <= digit_password[i] && digit_password[i] <= 64 ||
        91 <= digit_password[i] && digit_password[i] <= 96 ||
        123 <= digit_password[i] && digit_password[i] <= 126) // symbols are located in [33, 47], [58, 64], [91, 96], [123, 126]
        {
            symbols_count++;
        }
    }
    if (symbols_count == 0)
    {
        return -5;
    }
    else
    {
        points += symbols_count*2;
    }
    return points;
}

int main()
{
    int valid = INT_MIN;
    while (valid < 1)
    {
        valid = validate(UI());
        if (valid == -1)
        {
            cout << "Your password must be at least 12 characters long." << endl;
        }
        else if (valid == -2)
        {
            cout << "Your password must contain at least one uppercase character." << endl;
        }
        else if (valid == -3)
        {
            cout << "Your password must contain at least one lowercase character." << endl;
        }
        else if (valid == -4)
        {
            cout << "Your password must contain at least one number." << endl;
        }
        else if (valid == -5)
        {
            cout << "Your password must contain at least one special character." << endl;
        }
    }
    cout << "Password is valid. Password Score : " << valid << endl;
    return 1;
}