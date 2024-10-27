#pragma once
#include "UserRead.h"
#include "AddUserForm.h"
#include <vector>
#include "msclr/marshal_cppstd.h"
#include <fstream>
#include <algorithm>

namespace KursovaRobota {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Collections::Generic;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class UsersCatalog : public System::Windows::Forms::Form
    {
    private:
        System::Windows::Forms::Form^ mainForm;
        System::Windows::Forms::ListBox^ listBoxUsers;
        System::Windows::Forms::Button^ DeleteButton;
        System::Windows::Forms::Button^ AddButton;
        System::Windows::Forms::Button^ SortButton;

        List<User^>^ users;

    public:
        UsersCatalog(System::Windows::Forms::Form^ form)
        {
            InitializeComponent();
            mainForm = form;
            loadUsers();
        }

    protected:
        ~UsersCatalog()
        {
            if (components)
            {
                delete components;
            }
        }

    private: System::Windows::Forms::Button^ BackButton1;

    protected:

    private:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->BackButton1 = (gcnew System::Windows::Forms::Button());
            this->listBoxUsers = (gcnew System::Windows::Forms::ListBox());
            this->DeleteButton = (gcnew System::Windows::Forms::Button());
            this->AddButton = (gcnew System::Windows::Forms::Button());
            this->SortButton = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // BackButton1
            // 
            this->BackButton1->Location = System::Drawing::Point(12, 12);
            this->BackButton1->Name = L"BackButton1";
            this->BackButton1->Size = System::Drawing::Size(86, 31);
            this->BackButton1->TabIndex = 0;
            this->BackButton1->Text = L"Повернутися";
            this->BackButton1->UseVisualStyleBackColor = true;
            this->BackButton1->Click += gcnew System::EventHandler(this, &UsersCatalog::button1_Click);
            // 
            // listBoxUsers
            // 
            this->listBoxUsers->FormattingEnabled = true;
            this->listBoxUsers->Location = System::Drawing::Point(116, 12);
            this->listBoxUsers->Name = L"listBoxUsers";
            this->listBoxUsers->Size = System::Drawing::Size(310, 225);
            this->listBoxUsers->TabIndex = 1;
            // 
            // DeleteButton
            // 
            this->DeleteButton->Location = System::Drawing::Point(13, 50);
            this->DeleteButton->Name = L"DeleteButton";
            this->DeleteButton->Size = System::Drawing::Size(85, 32);
            this->DeleteButton->TabIndex = 2;
            this->DeleteButton->Text = L"Видалити";
            this->DeleteButton->UseVisualStyleBackColor = true;
            this->DeleteButton->Click += gcnew System::EventHandler(this, &UsersCatalog::button1_Click_1);
            // 
            // AddButton
            // 
            this->AddButton->Location = System::Drawing::Point(13, 90);
            this->AddButton->Name = L"AddButton";
            this->AddButton->Size = System::Drawing::Size(85, 32);
            this->AddButton->TabIndex = 3;
            this->AddButton->Text = L"Додати";
            this->AddButton->UseVisualStyleBackColor = true;
            this->AddButton->Click += gcnew System::EventHandler(this, &UsersCatalog::button1_Click_2);
            // 
            // SortButton
            // 
            this->SortButton->Location = System::Drawing::Point(13, 130);
            this->SortButton->Name = L"SortButton";
            this->SortButton->Size = System::Drawing::Size(85, 38);
            this->SortButton->TabIndex = 4;
            this->SortButton->Text = L"Сортувати за типом";
            this->SortButton->UseVisualStyleBackColor = true;
            this->SortButton->Click += gcnew System::EventHandler(this, &UsersCatalog::SortButton_Click);
            // 
            // UsersCatalog
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(494, 287);
            this->Controls->Add(this->SortButton);
            this->Controls->Add(this->AddButton);
            this->Controls->Add(this->DeleteButton);
            this->Controls->Add(this->listBoxUsers);
            this->Controls->Add(this->BackButton1);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
            this->MaximizeBox = false;
            this->Name = L"UsersCatalog";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Каталог користувачів";
            this->ResumeLayout(false);

        }

        // Загрузка пользователей из файла JSON
        void loadUsers() {
            users = UserRead::readUsersFromJSON("users.json");

            for each (User ^ user in users) {
                System::String^ info = user->getRole() + ": " + user->getName() + " (Email: " + user->getEmail() + ")";
                this->listBoxUsers->Items->Add(info);
            }
        }

        // Сохранение пользователей обратно в JSON-файл
        void saveUsersToJSON() {
            json j;

            for each (User ^ user in users) {
                json userJson;
                userJson["role"] = msclr::interop::marshal_as<std::string>(user->getRole());
                userJson["name"] = msclr::interop::marshal_as<std::string>(user->getName());
                userJson["email"] = msclr::interop::marshal_as<std::string>(user->getEmail());
                j.push_back(userJson);
            }

            std::ofstream file("users.json");
            file << j.dump(4);
        }

        // Статическая функция для сравнения пользователей по роли
        static bool CompareUsers(const json& user1, const json& user2) {
            std::string role1 = user1["role"];
            std::string role2 = user2["role"];

            // Приоритет ролей: Admin > Member > Guest
            std::map<std::string, int> rolePriority = { {"Admin", 1}, {"Member", 2}, {"Guest", 3} };

            return rolePriority[role1] < rolePriority[role2];
        }

        // Метод для сортировки пользователей в файле JSON
        void sortUsersInFile() {
            // Чтение пользователей из JSON-файла
            std::ifstream inputFile("users.json");
            json usersJson;

            if (inputFile.is_open()) {
                inputFile >> usersJson;
                inputFile.close();
            }

            // Сортировка пользователей по роли
            std::sort(usersJson.begin(), usersJson.end(), CompareUsers);

            // Запись отсортированных пользователей обратно в файл
            std::ofstream outputFile("users.json");
            outputFile << usersJson.dump(4);  // Запись с отступами
            outputFile.close();

            // Перезагружаем отображение пользователей после сортировки
            MessageBox::Show("Користувачі відсортовані за роллю у файлі users.json");
        }

#pragma endregion
    private:
        System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
            this->Close();
            mainForm->Show();
        }

        // Удаление пользователя
        System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
            int selectedIndex = this->listBoxUsers->SelectedIndex;
            if (selectedIndex != -1) {
                users->RemoveAt(selectedIndex);
                listBoxUsers->Items->RemoveAt(selectedIndex);
                saveUsersToJSON();
            }
            else {
                MessageBox::Show("Будь ласка, виберіть користувача для видалення.");
            }
        }

        // Добавление нового пользователя
        System::Void button1_Click_2(System::Object^ sender, System::EventArgs^ e) {
            AddUserForm^ newform = gcnew AddUserForm();
            newform->UserAdded += gcnew AddUserForm::UserAddedHandler(this, &UsersCatalog::OnUserAdded);
            newform->ShowDialog();
        }

        // Обработчик добавления пользователя
        void OnUserAdded() {
            this->listBoxUsers->Items->Clear();
            loadUsers();
        }

        // Сортировка списка пользователей по ролям
        System::Void SortButton_Click(System::Object^ sender, System::EventArgs^ e) {
            sortUsersInFile();  // Сортировка пользователей в файле JSON
            listBoxUsers->Items->Clear();
            loadUsers();  // Перезагрузка списка пользователей
        }
    };
}





