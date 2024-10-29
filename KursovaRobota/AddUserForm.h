#pragma once
#include "User.h"
#include "Admin.h"
#include "Member.h"
#include "Guest.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include <msclr/marshal_cppstd.h>

namespace KursovaRobota {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace nlohmann;

    public ref class AddUserForm : public System::Windows::Forms::Form
    {
    public:
        // Определение делегата и события для оповещения об успешном добавлении пользователя
        delegate void UserAddedHandler();
        event UserAddedHandler^ UserAdded;

        AddUserForm(void)
        {
            InitializeComponent();
        }

    protected:
        ~AddUserForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::TextBox^ txtName;
        System::Windows::Forms::TextBox^ txtEmail;
        System::Windows::Forms::ComboBox^ cmbRole;
        System::Windows::Forms::Button^ btnSave;

        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AddUserForm::typeid));
            this->txtName = (gcnew System::Windows::Forms::TextBox());
            this->txtEmail = (gcnew System::Windows::Forms::TextBox());
            this->cmbRole = (gcnew System::Windows::Forms::ComboBox());
            this->btnSave = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // txtName
            // 
            this->txtName->Location = System::Drawing::Point(25, 25);
            this->txtName->Name = L"txtName";
            this->txtName->Size = System::Drawing::Size(200, 20);
            this->txtName->TabIndex = 0;
            this->txtName->Text = L"Ім\'я";
            // 
            // txtEmail
            // 
            this->txtEmail->Location = System::Drawing::Point(25, 60);
            this->txtEmail->Name = L"txtEmail";
            this->txtEmail->Size = System::Drawing::Size(200, 20);
            this->txtEmail->TabIndex = 1;
            this->txtEmail->Text = L"Email";
            // 
            // cmbRole
            // 
            this->cmbRole->FormattingEnabled = true;
            this->cmbRole->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Admin", L"Member", L"Guest" });
            this->cmbRole->Location = System::Drawing::Point(25, 95);
            this->cmbRole->Name = L"cmbRole";
            this->cmbRole->Size = System::Drawing::Size(200, 21);
            this->cmbRole->TabIndex = 2;
            // 
            // btnSave
            // 
            this->btnSave->BackColor = System::Drawing::Color::White;
            this->btnSave->FlatAppearance->BorderColor = System::Drawing::SystemColors::ActiveCaptionText;
            this->btnSave->Location = System::Drawing::Point(25, 130);
            this->btnSave->Name = L"btnSave";
            this->btnSave->Size = System::Drawing::Size(75, 24);
            this->btnSave->TabIndex = 3;
            this->btnSave->Text = L"Зберегти";
            this->btnSave->UseVisualStyleBackColor = false;
            this->btnSave->Click += gcnew System::EventHandler(this, &AddUserForm::btnSave_Click);
            // 
            // AddUserForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(284, 181);
            this->Controls->Add(this->btnSave);
            this->Controls->Add(this->cmbRole);
            this->Controls->Add(this->txtEmail);
            this->Controls->Add(this->txtName);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->MaximizeBox = false;
            this->Name = L"AddUserForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Додавання користувача - Система керування бібліотекою";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private:
        System::Void btnSave_Click(System::Object^ sender, System::EventArgs^ e)
        {
            // Получаем данные из полей
            System::String^ name = txtName->Text;
            System::String^ email = txtEmail->Text;
            System::String^ role = cmbRole->SelectedItem->ToString();

            User^ user;

            // Создаем пользователя на основе выбранной роли
            if (role == "Admin")
                user = gcnew Admin(name, email);
            else if (role == "Member")
                user = gcnew Member(name, email);
            else
                user = gcnew Guest(name, email);

            // Попытка открыть существующий файл
            std::ifstream inputFile("users.json");
            json users;

            if (inputFile.is_open()) {
                // Чтение существующих данных
                inputFile >> users;
                inputFile.close();
            }
            else {
                // Если файл не существует или пуст, создаем новый массив
                users = json::array();
            }

            // Создание JSON объекта для нового пользователя
            json newUser;
            newUser["name"] = msclr::interop::marshal_as<std::string>(user->getName());
            newUser["email"] = msclr::interop::marshal_as<std::string>(user->getEmail());
            newUser["role"] = msclr::interop::marshal_as<std::string>(user->getRole());

            // Добавление нового пользователя в массив
            users.push_back(newUser);

            // Сохранение обновленных данных в файл
            std::ofstream outputFile("users.json");
            outputFile << users.dump(4) << std::endl;
            outputFile.close();

            // Вызов метода для сигнала события
            OnUserAdded();

            // Закрытие формы после добавления пользователя
            this->DialogResult = System::Windows::Forms::DialogResult::OK;
            this->Close();

            MessageBox::Show("User data saved to users.json");
        }

        // Метод для безопасного вызова события UserAdded
        void OnUserAdded() {
            UserAdded();  // Вызов события с использованием синтаксиса вызова в классе
        }
    };
}




