#pragma once
#include "Admin.h"
#include "Member.h"
#include "Guest.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include <msclr/marshal_cppstd.h> // ��� ������������ std::string � System::String^
#include <iostream>


using namespace System::Collections::Generic;
using json = nlohmann::json;

public ref class UserRead {
public:
    static System::Collections::Generic::List<User^>^ readUsersFromJSON(System::String^ filename) {
        // ������������ System::String^ � std::string
        msclr::interop::marshal_context context;
        std::string filePath = context.marshal_as<std::string>(filename);

        std::ifstream file(filePath);
        json j;
        file >> j;

        auto users = gcnew System::Collections::Generic::List<User^>();

        for (const auto& item : j) {
            // ������������ �������� � JSON � std::string, � ���� � System::String^
            std::string roleStr = item["role"];
            std::string nameStr = item["name"];
            std::string emailStr = item["email"];

            System::String^ role = msclr::interop::marshal_as<System::String^>(roleStr);
            System::String^ name = msclr::interop::marshal_as<System::String^>(nameStr);
            System::String^ email = msclr::interop::marshal_as<System::String^>(emailStr);
            // ��������� ������� ��'���� �� ����� ���
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
public:
void saveUsersToJSON(List<User^>^ userList, std::string filePath) {
    json jsonArray = json::array();  // ��������� ������� JSON �����

    // ���������� ������� ����������� � JSON ������ � ������ �� ������
    for each (User^ user in userList) {
        json userJson;

        userJson["name"] = msclr::interop::marshal_as<std::string>(user->getName());
        userJson["email"] = msclr::interop::marshal_as<std::string>(user->getEmail());
        userJson["role"] = msclr::interop::marshal_as<std::string>(user->getRole());

        jsonArray.push_back(userJson);  // ������ ����������� �� ������
    }

    // �������� JSON � ����
    std::ofstream file(filePath);
    if (file.is_open()) {
        file << jsonArray.dump(4);  // �������� JSON �� ��������� ��� ������� �������
        file.close();
    }
    else {
        std::cerr << "�� ������� ������� ���� ��� ������!" << std::endl;
    }
}
};


