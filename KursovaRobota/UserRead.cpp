#include "UserRead.h"

List<User^>^ UserRead::readUsersFromJSON(System::String^ filename) {
    msclr::interop::marshal_context context;
    std::string filePath = context.marshal_as<std::string>(filename);

    std::ifstream file(filePath);
    if (!file.is_open()) {
        throw gcnew System::IO::FileNotFoundException("Файл не найден: " + filename);
    }

    json j;
    file >> j;
    file.close();

    auto users = gcnew List<User^>();

    for (const auto& item : j) {
        std::string roleStr = item.at("role").get<std::string>();
        std::string nameStr = item.at("name").get<std::string>();
        std::string emailStr = item.at("email").get<std::string>();

        System::String^ role = gcnew System::String(roleStr.c_str());
        System::String^ name = gcnew System::String(nameStr.c_str());
        System::String^ email = gcnew System::String(emailStr.c_str());

        if (role == "Admin") {
            users->Add(gcnew Admin(name, email));
        }
        else if (role == "Member") {
            users->Add(gcnew Member(name, email));
        }
        else if (role == "Guest") {
            users->Add(gcnew Guest(name, email));
        }
    }

    return users;
}

