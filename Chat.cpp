#include "User.h"
User::Message::Message(const string& namefrom, string& nameto, string& message)
{
    _sender = namefrom;
    _receiver = nameto;
    _text = message;
}
fstream& operator >>(fstream& is, User::Message& obj)
{

    is >> obj._sender;
    is >> obj._receiver;
    is >> obj._text;
    return is;
}
ostream& operator <<(ostream& os, const User::Message& obj)
{
    os << obj._sender;
    os << ' ';
    os << obj._receiver;
    os << ' ';
    os << obj._text;
    return os;
}

void User::ChatMenu(vector<User >& A, vector<User::Message>& B, string name, string& login, const string& Namefrom, string& Nameto, string& Message)
{
    char operat = '0';

    string NamefromUser = login;
    cout << "Your name: " << NamefromUser << endl;

    string NametoUser;

    bool k = false;//счетчик наличия введеного пользователя в списке зарегистрированных
    bool n = false;//счетчик наличия сообщений в истории

    while (operat != '3')
    {
        cout << "Choose number: " << endl << "1 - Write the text" << endl << "2 - History" << endl << "3 - Exit to Main menu" << endl;
        cin >> operat;
        
        switch (operat)
        {
        case '1':
            cout << "Choose receiver:" << endl;
            for (int i = 0; i < A.size(); ++i)
            {
                cout << A[i]._login << endl;
            }
            cin >> NametoUser;
                     
                    cout << "Enter the text: ";
                    cin >> Message;
                    B.emplace_back(NamefromUser, NametoUser, Message);
                    Write_to_messages(NamefromUser, NametoUser, Message);
                   
            if (k == false) cout << "This receiver is not register" << endl;
            k = false;
            break;
        case '2':
            cout << "Text's history:" << endl;
            Find_in_messages(NamefromUser);
            break;
        default:

            std::cout << "You chose the wrong number!" << std::endl;
            std::cout << std::endl;
            break;

        };


    };
};