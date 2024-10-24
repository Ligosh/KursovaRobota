#pragma once
#include "UserRead.h"
#include "AddUserForm.h"
#include <vector>
#include "msclr/marshal_cppstd.h"


namespace KursovaRobota {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Collections::Generic;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// ������ ��� UsersCatalog
    /// </summary>

    public ref class UsersCatalog : public System::Windows::Forms::Form
    {

    private:
        System::Windows::Forms::Form^ mainForm;
        System::Windows::Forms::ListBox^ listBoxUsers;
        System::Windows::Forms::Button^ DeleteButton;
        System::Windows::Forms::Button^ AddButton;  // ���� ������ ��� ��������� ������������

        List<User^>^ users;    // ������ ������������
    public:
        UsersCatalog(System::Windows::Forms::Form^ form)
        {
            InitializeComponent();
            mainForm = form;  // �������� ��������� �� ������� �����
            loadUsers();      // ����������� ������������
        }

    protected:
        /// <summary>
        /// ���������� ��� ������������ �������.
        /// </summary>
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
        /// <summary>
        /// ������������ ���������� ������������.
        /// </summary>
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        /// <summary>
        /// ��������� ����� ��� ��������� ������������ � �� ��������� 
        /// ���������� ����� ������ � ������� ��������� ����.
        /// </summary>
        void InitializeComponent(void)
        {
            this->BackButton1 = (gcnew System::Windows::Forms::Button());
            this->listBoxUsers = (gcnew System::Windows::Forms::ListBox());
            this->DeleteButton = (gcnew System::Windows::Forms::Button());
            this->AddButton = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // BackButton1
            // 
            this->BackButton1->Location = System::Drawing::Point(12, 12);
            this->BackButton1->Name = L"BackButton1";
            this->BackButton1->Size = System::Drawing::Size(86, 31);
            this->BackButton1->TabIndex = 0;
            this->BackButton1->Text = L"�����������";
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
            this->DeleteButton->Text = L"��������";
            this->DeleteButton->UseVisualStyleBackColor = true;
            this->DeleteButton->Click += gcnew System::EventHandler(this, &UsersCatalog::button1_Click_1);
            // 
            // AddButton
            // 
            this->AddButton->Location = System::Drawing::Point(13, 90);
            this->AddButton->Name = L"AddButton";
            this->AddButton->Size = System::Drawing::Size(85, 32);
            this->AddButton->TabIndex = 3;
            this->AddButton->Text = L"������";
            this->AddButton->UseVisualStyleBackColor = true;
            this->AddButton->Click += gcnew System::EventHandler(this, &UsersCatalog::button1_Click_2);
            // 
            // UsersCatalog
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(548, 328);
            this->Controls->Add(this->AddButton);
            this->Controls->Add(this->DeleteButton);
            this->Controls->Add(this->listBoxUsers);
            this->Controls->Add(this->BackButton1);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
            this->MaximizeBox = false;
            this->Name = L"UsersCatalog";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"������� ������������";
            this->ResumeLayout(false);

        }

        // ������������ ������������ � JSON
        void loadUsers() {
            users = UserRead::readUsersFromJSON("users.json");

            // ������ ������������ � ListBox
            for each (User ^ user in users) {
                System::String^ info = user->getRole() + ": " + user->getName() + " (Email: " + user->getEmail() + ")";
                this->listBoxUsers->Items->Add(info);
            }
        }

        // ����� ��� ���������� ������������ � JSON
        void saveUsersToJSON() {
            json j;

            for each (User ^ user in users) {
                json userJson;
                userJson["role"] = msclr::interop::marshal_as<std::string>(user->getRole());
                userJson["name"] = msclr::interop::marshal_as<std::string>(user->getName());
                userJson["email"] = msclr::interop::marshal_as<std::string>(user->getEmail());  // �������� email
                j.push_back(userJson);
            }

            // �������� JSON-����
            std::ofstream file("users.json");
            file << j.dump(4);  // ������������ JSON
        }

#pragma endregion
    private:
        System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
            this->Close();  // ��������� �����
            mainForm->Show();  // ³��������� ������� �����
        }

        // ��������� �����������
        System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
            int selectedIndex = this->listBoxUsers->SelectedIndex;
            if (selectedIndex != -1) {
                // ��������� ��������� ����������� � ������
                users->RemoveAt(selectedIndex);
                listBoxUsers->Items->RemoveAt(selectedIndex);

                // ��������� JSON ���� ���������
                saveUsersToJSON();
            }
            else {
                MessageBox::Show("���� �����, ������� ����������� ��� ���������.");
            }
        }


// ��������� ������ �����������
        System::Void button1_Click_2(System::Object^ sender, System::EventArgs^ e) {
            AddUserForm^ newform = gcnew AddUserForm();

            // ������������� �� ������� ���������� ������������
            newform->UserAdded += gcnew AddUserForm::UserAddedHandler(this, &UsersCatalog::OnUserAdded);

            // ��������� �����
            newform->ShowDialog();
        }

        // ���������� ������� ���������� ������������
        void OnUserAdded() {
            this->listBoxUsers->Items->Clear();  // �������� ������� ������
            loadUsers();  // ������ ��������� ���� ������������� �� JSON
        }

};
}





