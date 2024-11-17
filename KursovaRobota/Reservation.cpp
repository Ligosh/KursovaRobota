#include "Reservation.h"

namespace KursovaRobota {

    Reservation::Reservation(Form^ mainForm)
    {
        InitializeComponent();
        this->mainForm = mainForm;
        LoadBooks();
        LoadUsers();
        LoadReservations();
    }

    Reservation::~Reservation()
    {
        if (components)
        {
            delete components;
        }
    }

    void Reservation::InitializeComponent(void)
    {
        System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Reservation::typeid));
        this->BookList = (gcnew System::Windows::Forms::ListBox());
        this->BackButton = (gcnew System::Windows::Forms::Button());
        this->UserList = (gcnew System::Windows::Forms::ListBox());
        this->ReservationList = (gcnew System::Windows::Forms::ListBox());
        this->ReservationButton = (gcnew System::Windows::Forms::Button());
        this->DeleteButton = (gcnew System::Windows::Forms::Button());
        this->SortButton = (gcnew System::Windows::Forms::Button());
        this->SuspendLayout();
        // 
        // BookList
        // 
        this->BookList->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
        this->BookList->Location = System::Drawing::Point(22, 56);
        this->BookList->Name = L"BookList";
        this->BookList->Size = System::Drawing::Size(177, 95);
        this->BookList->TabIndex = 0;
        // 
        // BackButton
        // 
        this->BackButton->BackColor = System::Drawing::Color::DeepSkyBlue;
        this->BackButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"BackButton.BackgroundImage")));
        this->BackButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
        this->BackButton->Location = System::Drawing::Point(22, 12);
        this->BackButton->Name = L"BackButton";
        this->BackButton->Size = System::Drawing::Size(54, 33);
        this->BackButton->TabIndex = 1;
        this->BackButton->UseVisualStyleBackColor = false;
        this->BackButton->Click += gcnew System::EventHandler(this, &Reservation::BackButton_Click);
        // 
        // UserList
        // 
        this->UserList->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
        this->UserList->Location = System::Drawing::Point(22, 157);
        this->UserList->Name = L"UserList";
        this->UserList->Size = System::Drawing::Size(177, 95);
        this->UserList->TabIndex = 2;
        // 
        // ReservationList
        // 
        this->ReservationList->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
        this->ReservationList->Location = System::Drawing::Point(239, 56);
        this->ReservationList->Name = L"ReservationList";
        this->ReservationList->Size = System::Drawing::Size(207, 95);
        this->ReservationList->TabIndex = 3;
        // 
        // ReservationButton
        // 
        this->ReservationButton->BackColor = System::Drawing::Color::DeepSkyBlue;
        this->ReservationButton->Location = System::Drawing::Point(71, 258);
        this->ReservationButton->Name = L"ReservationButton";
        this->ReservationButton->Size = System::Drawing::Size(79, 28);
        this->ReservationButton->TabIndex = 4;
        this->ReservationButton->Text = L"Бронювати";
        this->ReservationButton->UseVisualStyleBackColor = false;
        this->ReservationButton->Click += gcnew System::EventHandler(this, &Reservation::ReservationButton_Click);
        // 
        // DeleteButton
        // 
        this->DeleteButton->BackColor = System::Drawing::Color::DeepSkyBlue;
        this->DeleteButton->Location = System::Drawing::Point(253, 157);
        this->DeleteButton->Name = L"DeleteButton";
        this->DeleteButton->Size = System::Drawing::Size(78, 23);
        this->DeleteButton->TabIndex = 5;
        this->DeleteButton->Text = L"Видалити";
        this->DeleteButton->UseVisualStyleBackColor = false;
        this->DeleteButton->Click += gcnew System::EventHandler(this, &Reservation::DeleteButton_Click);
        // 
        // SortButton
        // 
        this->SortButton->BackColor = System::Drawing::Color::DeepSkyBlue;
        this->SortButton->Location = System::Drawing::Point(349, 157);
        this->SortButton->Name = L"SortButton";
        this->SortButton->Size = System::Drawing::Size(78, 23);
        this->SortButton->TabIndex = 6;
        this->SortButton->Text = L"Сортувати";
        this->SortButton->UseVisualStyleBackColor = false;
        this->SortButton->Click += gcnew System::EventHandler(this, &Reservation::SortButton_Click);
        // 
        // Reservation
        // 
        this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
        this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
        this->ClientSize = System::Drawing::Size(458, 315);
        this->Controls->Add(this->SortButton);
        this->Controls->Add(this->DeleteButton);
        this->Controls->Add(this->ReservationButton);
        this->Controls->Add(this->ReservationList);
        this->Controls->Add(this->UserList);
        this->Controls->Add(this->BackButton);
        this->Controls->Add(this->BookList);
        this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
        this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
        this->MaximizeBox = false;
        this->Name = L"Reservation";
        this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
        this->Text = L"Reservation";
        this->ResumeLayout(false);

    }

    void Reservation::BackButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->Hide();
        mainForm->Show();
    }

    void Reservation::LoadBooks()
    {
        try {
            std::ifstream file("books.csv");
            if (!file.is_open()) {
                throw ExceptionHandler("Не вдалося відкрити файл books.csv для читання.", ExceptionType::Error);
            }

            std::string line;
            if (std::getline(file, line)) {
                while (std::getline(file, line)) {
                    this->BookList->Items->Add(gcnew String(line.c_str()));
                }
            }
            file.close();
        }
        catch (const ExceptionHandler& ex) {
            ex.showMessage();
        }
    }

    void Reservation::LoadUsers()
    {
        try {
            auto users = UserRead::readUsersFromJSON("users.json");
            for each (User ^ user in users) {
                this->UserList->Items->Add(user->getName());
            }
        }
        catch (const ExceptionHandler& ex) {
            ex.showMessage();
        }
    }

    void Reservation::LoadReservations()
    {
        std::ifstream file("reservation.csv");
        if (!file.is_open()) {
            ExceptionHandler("Не вдалося відкрити файл reservation.csv для читання.", ExceptionType::Error).showMessage();
            return;
        }

        std::string line;
        while (std::getline(file, line)) {
            this->ReservationList->Items->Add(gcnew String(line.c_str()));
        }
        file.close();
    }

    void Reservation::ReservationButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        if (BookList->SelectedIndex == -1 || UserList->SelectedIndex == -1) {
            ExceptionHandler("Будь ласка, виберіть книгу і користувача.", ExceptionType::Warning).showMessage();
            return;
        }

        String^ selectedBook = BookList->SelectedItem->ToString();
        String^ selectedUser = UserList->SelectedItem->ToString();

        std::string bookEntry = msclr::interop::marshal_as<std::string>(selectedBook);
        std::istringstream ss(bookEntry);
        std::string bookTitle, author;
        int year, quantity;

        std::getline(ss, bookTitle, ',');
        std::getline(ss, author, ',');
        ss >> year;
        ss.ignore(1, ',');
        ss >> quantity;

        if (quantity <= 0) {
            ExceptionHandler("Недостатньо примірників книги для резервування.", ExceptionType::Warning).showMessage();
            return;
        }

        String^ reservationEntry = gcnew String(bookTitle.c_str()) + ", " + gcnew String(author.c_str()) + ", " + selectedUser;
        ReservationList->Items->Add(reservationEntry);

        std::ofstream reservationFile("reservation.csv", std::ios::app);
        reservationFile << bookTitle << "," << author << "," << msclr::interop::marshal_as<std::string>(selectedUser) << "\n";
        reservationFile.close();

        UpdateBookQuantity(bookTitle, -1);

        BookList->Items->Clear();
        LoadBooks();
    }

    void Reservation::UpdateBookQuantity(const std::string& bookTitle, int change)
    {
        std::ifstream booksFile("books.csv");
        std::ofstream tempFile("temp_books.csv");
        std::string line;

        if (!booksFile.is_open() || !tempFile.is_open()) {
            ExceptionHandler("Помилка при відкритті файлу books.csv.", ExceptionType::Error).showMessage();
            return;
        }

        bool found = false;

        while (std::getline(booksFile, line)) {
            std::istringstream ss(line);
            std::string title, author;
            int year, quantity;

            std::getline(ss, title, ',');
            std::getline(ss, author, ',');
            ss >> year;
            ss.ignore(1, ',');
            ss >> quantity;

            if (title == bookTitle) {
                quantity += change;
                found = true;

                if (quantity < 0) {
                    ExceptionHandler("Недостатньо примірників книги для резервування.", ExceptionType::Warning).showMessage();
                    tempFile << line << "\n";
                    continue;
                }
            }

            tempFile << title << "," << author << "," << year << "," << quantity << "\n";
        }

        booksFile.close();
        tempFile.close();

        if (found) {
            std::remove("books.csv");
            std::rename("temp_books.csv", "books.csv");
        }
        else {
            std::remove("temp_books.csv");
        }
    }

    void Reservation::DeleteButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        if (ReservationList->SelectedIndex == -1) {
            ExceptionHandler("Будь ласка, виберіть резервування для видалення.", ExceptionType::Warning).showMessage();
            return;
        }

        String^ selectedReservation = ReservationList->SelectedItem->ToString();
        ReservationList->Items->Remove(selectedReservation);

        std::string reservationEntry = msclr::interop::marshal_as<std::string>(selectedReservation);

        std::istringstream ss(reservationEntry);
        std::string bookTitle, author, user;
        std::getline(ss, bookTitle, ',');
        std::getline(ss, author, ',');
        std::getline(ss, user);

        std::ifstream reservationFile("reservation.csv");
        std::ofstream tempFile("temp_reservation.csv");
        std::string line;

        while (std::getline(reservationFile, line)) {
            if (line != reservationEntry) {
                tempFile << line << "\n";
            }
        }

        reservationFile.close();
        tempFile.close();

        std::remove("reservation.csv");
        std::rename("temp_reservation.csv", "reservation.csv");

        UpdateBookQuantity(bookTitle, 1);

        BookList->Items->Clear();
        LoadBooks();
    }



    void Reservation::SortButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        std::vector<std::string> reservations;

        for (int i = 0; i < ReservationList->Items->Count; ++i) {
            reservations.push_back(msclr::interop::marshal_as<std::string>(ReservationList->Items[i]->ToString()));
        }

        std::sort(reservations.begin(), reservations.end());

        ReservationList->Items->Clear();

        std::ofstream reservationFile("reservation.csv", std::ios::trunc);
        for (const auto& res : reservations) {
            ReservationList->Items->Add(gcnew String(res.c_str()));
            reservationFile << res << "\n";
        }
        reservationFile.close();
    }
}


