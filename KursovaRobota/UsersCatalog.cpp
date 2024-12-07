#include "UsersCatalog.h"

using namespace KursovaRobota;
using json = nlohmann::json;

UsersCatalog::UsersCatalog(System::Windows::Forms::Form^ form) {
    InitializeComponent();
    mainForm = form;
    loadUsers();
}

UsersCatalog::~UsersCatalog() {
    if (components) {
        delete components;
    }
}

void UsersCatalog::InitializeComponent() {
    System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(UsersCatalog::typeid));
    this->BackButton1 = (gcnew System::Windows::Forms::Button());
    this->listBoxUsers = (gcnew System::Windows::Forms::ListBox());
    this->DeleteButton = (gcnew System::Windows::Forms::Button());
    this->AddButton = (gcnew System::Windows::Forms::Button());
    this->SortButton = (gcnew System::Windows::Forms::Button());
    this->SuspendLayout();
    // 
    // BackButton1
    // 
    this->BackButton1->BackColor = System::Drawing::Color::DeepSkyBlue;
    this->BackButton1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"BackButton1.BackgroundImage")));
    this->BackButton1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
    this->BackButton1->FlatAppearance->BorderColor = System::Drawing::Color::Black;
    this->BackButton1->ForeColor = System::Drawing::SystemColors::ControlText;
    this->BackButton1->Location = System::Drawing::Point(12, 12);
    this->BackButton1->Name = L"BackButton1";
    this->BackButton1->Size = System::Drawing::Size(54, 33);
    this->BackButton1->TabIndex = 0;
    this->BackButton1->UseVisualStyleBackColor = false;
    this->BackButton1->Click += gcnew System::EventHandler(this, &UsersCatalog::button1_Click);
    // 
    // listBoxUsers
    // 
    this->listBoxUsers->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
    this->listBoxUsers->FormattingEnabled = true;
    this->listBoxUsers->Location = System::Drawing::Point(81, 12);
    this->listBoxUsers->Name = L"listBoxUsers";
    this->listBoxUsers->Size = System::Drawing::Size(310, 225);
    this->listBoxUsers->TabIndex = 1;
    // 
    // DeleteButton
    // 
    this->DeleteButton->BackColor = System::Drawing::Color::DeepSkyBlue;
    this->DeleteButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
    this->DeleteButton->Location = System::Drawing::Point(397, 12);
    this->DeleteButton->Name = L"DeleteButton";
    this->DeleteButton->Size = System::Drawing::Size(85, 32);
    this->DeleteButton->TabIndex = 2;
    this->DeleteButton->Text = L"Видалити";
    this->DeleteButton->UseVisualStyleBackColor = false;
    this->DeleteButton->Click += gcnew System::EventHandler(this, &UsersCatalog::button1_Click_1);
    // 
    // AddButton
    // 
    this->AddButton->BackColor = System::Drawing::Color::DeepSkyBlue;
    this->AddButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
    this->AddButton->Location = System::Drawing::Point(397, 50);
    this->AddButton->Name = L"AddButton";
    this->AddButton->Size = System::Drawing::Size(85, 32);
    this->AddButton->TabIndex = 3;
    this->AddButton->Text = L"Додати";
    this->AddButton->UseVisualStyleBackColor = false;
    this->AddButton->Click += gcnew System::EventHandler(this, &UsersCatalog::button1_Click_2);
    // 
    // SortButton
    // 
    this->SortButton->BackColor = System::Drawing::Color::DeepSkyBlue;
    this->SortButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
    this->SortButton->Location = System::Drawing::Point(397, 88);
    this->SortButton->Name = L"SortButton";
    this->SortButton->Size = System::Drawing::Size(85, 38);
    this->SortButton->TabIndex = 4;
    this->SortButton->Text = L"Сортувати за типом";
    this->SortButton->UseVisualStyleBackColor = false;
    this->SortButton->Click += gcnew System::EventHandler(this, &UsersCatalog::SortButton_Click);
    // 
    // UsersCatalog
    // 
    this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
    this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
    this->BackColor = System::Drawing::SystemColors::Control;
    this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
    this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
    this->ClientSize = System::Drawing::Size(494, 272);
    this->Controls->Add(this->SortButton);
    this->Controls->Add(this->AddButton);
    this->Controls->Add(this->DeleteButton);
    this->Controls->Add(this->listBoxUsers);
    this->Controls->Add(this->BackButton1);
    this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
    this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
    this->MaximizeBox = false;
    this->Name = L"UsersCatalog";
    this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
    this->Text = L"Каталог користувачів - Система керування бібліотекою";
    this->ResumeLayout(false);
}

void UsersCatalog::loadUsers() {
    try {
        std::ifstream inputFile("users.json");

        if (!inputFile.is_open()) {
            ExceptionHandler("Не вдалося відкрити users.json", ExceptionType::Error).showMessage();

            json emptyArray = json::array();
            std::ofstream outputFile("users.json");
            outputFile << emptyArray.dump(4);
            outputFile.close();
            users = gcnew List<User^>();
            return;
        }

        if (inputFile.peek() != std::ifstream::traits_type::eof()) {
            users = UserRead::readUsersFromJSON("users.json");
        }
        else {
            json emptyArray = json::array();
            std::ofstream outputFile("users.json");
            if (!outputFile.is_open()) {
                throw ExceptionHandler("Не вдалося створити новий файл users.json", ExceptionType::Error);
            }
            outputFile << emptyArray.dump(4);
            users = gcnew List<User^>();
        }
        inputFile.close();

        for each (User ^ user in users) {
            System::String^ info = user->getRole() + ": " + user->getName() + " (Email: " + user->getEmail() + ")";
            listBoxUsers->Items->Add(info);
        }
    }
    catch (const ExceptionHandler& ex) {
        ex.showMessage();
    }
    catch (const std::exception& ex) {
        ExceptionHandler handler(ex.what(), ExceptionType::Error);
        handler.showMessage();
    }
}


void UsersCatalog::saveUsersToJSON() {
    try {
        json j;

        for each (User ^ user in users) {
            json userJson;
            userJson["role"] = msclr::interop::marshal_as<std::string>(user->getRole());
            userJson["name"] = msclr::interop::marshal_as<std::string>(user->getName());
            userJson["email"] = msclr::interop::marshal_as<std::string>(user->getEmail());
            j.push_back(userJson);
        }

        std::ofstream file("users.json");
        if (!file.is_open()) {
            throw ExceptionHandler("Не вдалося відкрити файл для запису.", ExceptionType::Error);
        }
        file << j.dump(4);
    }
    catch (const ExceptionHandler& handler) {
        handler.showMessage();
    }
    catch (const std::exception& ex) {
        ExceptionHandler handler(ex.what(), ExceptionType::Error);
        handler.showMessage();
    }
}

bool UsersCatalog::CompareUsers(const json& user1, const json& user2) {
    std::string role1 = user1["role"];
    std::string role2 = user2["role"];

    std::map<std::string, int> rolePriority = { {"Admin", 1}, {"Member", 2}, {"Guest", 3} };
    return rolePriority[role1] < rolePriority[role2];
}

void UsersCatalog::sortUsersInFile() {
    try {
        std::ifstream inputFile("users.json");
        if (!inputFile.is_open()) {
            throw ExceptionHandler("Не вдалося відкрити файл для читання.", ExceptionType::Error);
        }

        json usersJson;
        inputFile >> usersJson;
        inputFile.close();

        std::sort(usersJson.begin(), usersJson.end(), CompareUsers);

        std::ofstream outputFile("users.json");
        if (!outputFile.is_open()) {
            throw ExceptionHandler("Не вдалося відкрити файл для запису.", ExceptionType::Error);
        }
        outputFile << usersJson.dump(4);
        outputFile.close();

    }
    catch (const ExceptionHandler& handler) {
        handler.showMessage();
    }
    catch (const std::exception& ex) {
        ExceptionHandler handler(ex.what(), ExceptionType::Error);
        handler.showMessage();
    }
}

System::Void UsersCatalog::button1_Click(System::Object^ sender, System::EventArgs^ e) {
    this->Close();
    mainForm->Show();
}

System::Void UsersCatalog::button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
    int selectedIndex = listBoxUsers->SelectedIndex;
    if (selectedIndex != -1) {
        users->RemoveAt(selectedIndex);
        listBoxUsers->Items->RemoveAt(selectedIndex);
        saveUsersToJSON();
    }
    else {
        ExceptionHandler handler("Будь ласка, виберіть користувача для видалення.", ExceptionType::Warning);
        handler.showMessage();
    }
}

System::Void UsersCatalog::button1_Click_2(System::Object^ sender, System::EventArgs^ e) {
    AddUserForm^ newform = gcnew AddUserForm();
    newform->UserAdded += gcnew AddUserForm::UserAddedHandler(this, &UsersCatalog::OnUserAdded);
    newform->ShowDialog();
}

void UsersCatalog::OnUserAdded() {
    listBoxUsers->Items->Clear();
    loadUsers();
}

System::Void UsersCatalog::SortButton_Click(System::Object^ sender, System::EventArgs^ e) {
    sortUsersInFile();
    listBoxUsers->Items->Clear();
    loadUsers();
}
