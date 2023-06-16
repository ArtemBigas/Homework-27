#include "User.h"
std::shared_mutex mtx;//индефикатор по умолчанию
void Write_to_users(string name, string login, string password)
{
    mtx.lock();
    fstream user_file = fstream("users.txt", ios::in | ios::out);
    if (!user_file)
    {
        // Для создания файла используем параметр ios::trunc
        user_file = fstream("users.txt", ios::in | ios::out | ios::trunc);//файл для хранения всех данных пользователей
        fs::permissions("users.txt",
            fs::perms::group_all | fs::perms::others_all,
            fs::perm_options::remove);//удаляем все права, кроме владельца
    }
    if (user_file) {
        User obj(name, login, password);
        user_file.seekp(0, std::ios_base::end);
        // Запишем данные по в файл
        user_file << obj << endl;
    }
    else
    {
        cout << "Could not open file users.txt !" << '\n';

    };
    mtx.unlock();
}

void Write_to_messages(string NamefromUser, string NametoUser, string Message)
{
    mtx.lock();
    fstream user_file = fstream("messeges.txt", ios::in | ios::out);
    if (!user_file)
    {
        // Для создания файла используем параметр ios::trunc
        user_file = fstream("messeges.txt", ios::in | ios::out | ios::trunc);//файл для хранения всех данных пользователей
        fs::permissions("messeges.txt",
            fs::perms::group_all | fs::perms::others_all,
            fs::perm_options::remove);//удаляем все права, кроме владельца
    }
    if (user_file) {
        User obj(NamefromUser, NametoUser, Message);
        user_file.seekp(0, std::ios_base::end);
        // Запишем данные по в файл
        user_file << obj << endl;
    }
    else
    {
        cout << "Could not open file users.txt !" << '\n';

    };
    mtx.unlock();
}

void Find_in_messages(string NamefromUser)
{
    mtx.lock_shared();
    std::ifstream message_file("messages.txt"); // открываем файл для чтения
    std::string line;
    while (std::getline(message_file, line)) { // читаем файл построчно
        if (line.find(NamefromUser) != std::string::npos) { // если в строке найдено слово "name"
            std::cout << line << std::endl; // выводим эту строку на экран
        }
    }
    message_file.close(); // закрываем файл
    mtx.unlock_shared();
};
