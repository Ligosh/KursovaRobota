#include "AddUserForm.h"
#include <fstream>
#include <sstream>

namespace KursovaRobota {

    AddUserForm::AddUserForm() {
        InitializeComponent();
    }

    AddUserForm::~AddUserForm() {
        if (components) {
            delete components;
        }
    }

    void AddUserForm::InitializeComponent(void) {
        System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AddUserForm::typeid));
        this->txtName = (gcnew System::Windows::Forms::TextBox());
        this->txtEmail = (gcnew System::Windows::Forms::TextBox());
        this->cmbRole = (gcnew System::Windows::Forms::ComboBox());
        this->btnSave = (gcnew System::Windows::Forms::Button());
        this->SuspendLayout();

        // txtName
        this->txtName->Location = System::Drawing::Point(25, 25);
        this->txtName->Name = L"txtName";
        this->txtName->Size = System::Drawing::Size(200, 20);
        this->txtName->TabIndex = 0;
        this->txtName->Text = L"Ім'я";

        // txtEmail
        this->txtEmail->Location = System::Drawing::Point(25, 60);
        this->txtEmail->Name = L"txtEmail";
        this->txtEmail->Size = System::Drawing::Size(200, 20);
        this->txtEmail->TabIndex = 1;
        this->txtEmail->Text = L"Email";

        // cmbRole
        this->cmbRole->FormattingEnabled = true;
        this->cmbRole->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Admin", L"Member", L"Guest" });
        this->cmbRole->Location = System::Drawing::Point(25, 95);
        this->cmbRole->Name = L"cmbRole";
        this->cmbRole->Size = System::Drawing::Size(200, 21);
        this->cmbRole->TabIndex = 2;

        // btnSave
        this->btnSave->BackColor = System::Drawing::Color::White;
        this->btnSave->Location = System::Drawing::Point(25, 130);
        this->btnSave->Name = L"btnSave";
        this->btnSave->Size = System::Drawing::Size(75, 24);
        this->btnSave->TabIndex = 3;
        this->btnSave->Text = L"Зберегти";
        this->btnSave->UseVisualStyleBackColor = false;
        this->btnSave->Click += gcnew System::EventHandler(this, &AddUserForm::btnSave_Click);

        // AddUserForm
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

    System::Void AddUserForm::btnSave_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            System::String^ name = txtName->Text;
            System::String^ email = txtEmail->Text;
            System::String^ role = cmbRole->SelectedItem ? cmbRole->SelectedItem->ToString() : nullptr;

            if (String::IsNullOrEmpty(name) || String::IsNullOrEmpty(email) || String::IsNullOrEmpty(role)) {
                ExceptionHandler handler("Будь ласка, заповніть усі поля і виберіть роль.", ExceptionType::Warning);
                handler.showMessage();
                return;
            }

            User^ user;
            if (role == "Admin")
                user = gcnew Admin(name, email);
            else if (role == "Member")
                user = gcnew Member(name, email);
            else
                user = gcnew Guest(name, email);

            std::ifstream inputFile("users.json");
            json users;

            if (inputFile.is_open()) {
                if (inputFile.peek() != std::ifstream::traits_type::eof()) {
                    inputFile >> users;
                }
                else {
                    users = json::array();
                }
                inputFile.close();
            }
            else {
                users = json::array();
                std::ofstream outputFile("users.json");
                outputFile << users.dump(4);
                outputFile.close();
            }

            json newUser;
            newUser["name"] = msclr::interop::marshal_as<std::string>(user->getName());
            newUser["email"] = msclr::interop::marshal_as<std::string>(user->getEmail());
            newUser["role"] = msclr::interop::marshal_as<std::string>(user->getRole());

            users.push_back(newUser);

            std::ofstream outputFile("users.json");
            if (!outputFile.is_open()) {
                ExceptionHandler handler("Не вдалося відкрити файл users.json для запису.", ExceptionType::Error);
                handler.showMessage();
                return;
            }
            outputFile << users.dump(4) << std::endl;
            outputFile.close();

            OnUserAdded();
            this->DialogResult = System::Windows::Forms::DialogResult::OK;
            this->Close();

        }
        catch (const std::exception& ex) {
            ExceptionHandler handler(ex.what(), ExceptionType::Error);
            handler.showMessage();
        }
    }

    void AddUserForm::OnUserAdded() {
        UserAdded();
    }
}
