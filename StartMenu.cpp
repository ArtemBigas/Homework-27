#include "User.h"
void User::StartMenu(vector<User>& A, string name, string& login, string& password, vector<User::Message>& B, const string& _sender, string& _receiver, string& _text)
{
    char operat = '0';
    while (operat != '3')
    {
        cout << "Good day" << endl << "Choose the number: " << endl << "1 - Registration" << endl << "2-Personal account" << endl << "3 - Exit" << endl;

        cin >> operat;
        switch (operat)
        {
        case '1':

            Registration(A, name, login, password);
            break;
        case '2':
            Login(A, name, login, password, B, _sender, _receiver, _text);

            break;
        case '3':cout << "До свидания!" << endl; break;
        default:

            std::cout << "Вы ввели неверную команду!" << std::endl;
            std::cout << std::endl;
            break;

        };
    }
}