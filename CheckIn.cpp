#include "User.h"
void  User::Registration(vector<User>& A, string name, string& login, string& password)
{
 
    cout << "Registration" << endl;
    cout << "Enter the Login: ";
    cin >> login;
    cout << endl;
    try
    {
        cout << "Enter the Name: ";
        cin >> name;
        cout << endl;
        cout << "Enter the Password: ";
        cin >> password;
        cout << endl;
        A.emplace_back(name, login, password);
        Write_to_users(name, login, password);
    }
    catch (const char* exception)
    {
        std::cout << std::endl;
        std::cout << exception << std::endl;
        std::cout << std::endl;
    }

}