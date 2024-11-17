#pragma once
#include "UserRead.h"
#include "AddUserForm.h"
#include <vector>
#include "msclr/marshal_cppstd.h"
#include <fstream>
#include <algorithm>
#include "ExceptionHandler.h"

namespace KursovaRobota {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections::Generic;
    using namespace System::Windows::Forms;

    public ref class UsersCatalog : public System::Windows::Forms::Form {
    private:
        System::Windows::Forms::Form^ mainForm;
        System::Windows::Forms::ListBox^ listBoxUsers;
        System::Windows::Forms::Button^ DeleteButton;
        System::Windows::Forms::Button^ AddButton;
        System::Windows::Forms::Button^ SortButton;
        System::Windows::Forms::Button^ BackButton1;

        List<User^>^ users;
        System::ComponentModel::Container^ components;

    public:
        UsersCatalog(System::Windows::Forms::Form^ form);
        ~UsersCatalog();

    private:
        void InitializeComponent();
        void loadUsers();
        void saveUsersToJSON();
        static bool CompareUsers(const nlohmann::json& user1, const nlohmann::json& user2);
        void sortUsersInFile();

        System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e);
        System::Void button1_Click_2(System::Object^ sender, System::EventArgs^ e);
        void OnUserAdded();
        System::Void SortButton_Click(System::Object^ sender, System::EventArgs^ e);
    };
}






