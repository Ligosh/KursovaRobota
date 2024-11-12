#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <msclr/marshal_cppstd.h>
#include <nlohmann/json.hpp>

namespace KursovaRobota {

    using namespace System;
    using namespace System::Windows::Forms;
    using namespace System::Drawing;
    using namespace nlohmann;

    public ref class Reservation : public System::Windows::Forms::Form
    {
    public:
        Reservation(Form^ mainForm)
        {
            InitializeComponent();
            this->mainForm = mainForm;
            LoadBooks();
            LoadUsers();
            LoadReservations();  // Добавляем загрузку забронированных книг при инициализации
        }

    protected:
        ~Reservation()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        Form^ mainForm;
        System::Windows::Forms::ListBox^ BookList;
        System::Windows::Forms::Button^ BackButton;
        System::Windows::Forms::ListBox^ UserList;
        System::Windows::Forms::ListBox^ ReservationList;
        System::Windows::Forms::Button^ ReservationButton;
        System::Windows::Forms::Button^ DeleteButton;
        System::Windows::Forms::Button^ SortButton;

        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
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
            this->BackButton->BackColor = System::Drawing::SystemColors::ControlLightLight;
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
            this->ReservationButton->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->ReservationButton->Location = System::Drawing::Point(71, 258);
            this->ReservationButton->Name = L"ReservationButton";
            this->ReservationButton->Size = System::Drawing::Size(75, 23);
            this->ReservationButton->TabIndex = 4;
            this->ReservationButton->Text = L"Бронювати";
            this->ReservationButton->UseVisualStyleBackColor = false;
            this->ReservationButton->Click += gcnew System::EventHandler(this, &Reservation::ReservationButton_Click);
            // 
            // DeleteButton
            // 
            this->DeleteButton->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->DeleteButton->Location = System::Drawing::Point(267, 157);
            this->DeleteButton->Name = L"DeleteButton";
            this->DeleteButton->Size = System::Drawing::Size(70, 23);
            this->DeleteButton->TabIndex = 5;
            this->DeleteButton->Text = L"Видалити";
            this->DeleteButton->UseVisualStyleBackColor = false;
            this->DeleteButton->Click += gcnew System::EventHandler(this, &Reservation::DeleteButton_Click);
            // 
            // SortButton
            // 
            this->SortButton->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->SortButton->Location = System::Drawing::Point(343, 157);
            this->SortButton->Name = L"SortButton";
            this->SortButton->Size = System::Drawing::Size(72, 23);
            this->SortButton->TabIndex = 6;
            this->SortButton->Text = L"Сортувати";
            this->SortButton->UseVisualStyleBackColor = false;
            this->SortButton->Click += gcnew System::EventHandler(this, &Reservation::SortButton_Click);
            // 
            // Reservation
            // 
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
#pragma endregion

    private:
        void BackButton_Click(System::Object^ sender, System::EventArgs^ e)
        {
            this->Hide();
            mainForm->Show();
        }

        void LoadBooks()
        {
            // Чтение списка книг из файла
            std::ifstream file("books.csv");
            std::string line;

            // Пропускаем первый рядок (заголовок)
            if (std::getline(file, line)) {
                while (std::getline(file, line)) {
                    this->BookList->Items->Add(gcnew String(line.c_str()));
                }
            }

            file.close();
        }


        void LoadUsers()
        {
            // Чтение списка пользователей из JSON файла
            std::ifstream file("users.json");
            json usersJson;
            file >> usersJson;
            file.close();

            for (auto& user : usersJson) {
                String^ userName = gcnew String(user["name"].get<std::string>().c_str());
                this->UserList->Items->Add(userName);
            }
        }

        void LoadReservations()
        {
            // Чтение списка бронирований из файла
            std::ifstream file("reservation.csv");
            std::string line;
            while (std::getline(file, line)) {
                this->ReservationList->Items->Add(gcnew String(line.c_str()));
            }
            file.close();
        }

        void ReservationButton_Click(System::Object^ sender, System::EventArgs^ e)
        {
            // Проверка, выбраны ли книга и пользователь
            if (BookList->SelectedIndex == -1 || UserList->SelectedIndex == -1) {
                MessageBox::Show("Пожалуйста, выберите книгу и пользователя.");
                return;
            }

            String^ selectedBook = BookList->SelectedItem->ToString();
            String^ selectedUser = UserList->SelectedItem->ToString();

            // Извлечение данных из строки книги
            std::string bookEntry = msclr::interop::marshal_as<std::string>(selectedBook);
            std::istringstream ss(bookEntry);
            std::string bookTitle, author;
            std::getline(ss, bookTitle, ',');  // Название книги
            std::getline(ss, author, ',');     // Автор книги

            // Формирование строки бронирования (только название, автор, пользователь)
            String^ reservationEntry = gcnew String(bookTitle.c_str()) + ", " + gcnew String(author.c_str()) + ", " + selectedUser;
            ReservationList->Items->Add(reservationEntry);

            // Запись в файл бронирований
            std::ofstream reservationFile("reservation.csv", std::ios::app);
            reservationFile << bookTitle << "," << author << "," << msclr::interop::marshal_as<std::string>(selectedUser) << "\n";
            reservationFile.close();

            // Обновление количества книг
            UpdateBookQuantity(bookTitle, -1);

            // Очистка и повторное чтение списка книг для обновления
            BookList->Items->Clear();
            LoadBooks();
        }



        void UpdateBookQuantity(const std::string& bookTitle, int change)
        {
            // Обновление количества книг в файле books.csv
            std::ifstream booksFile("books.csv");
            std::ofstream tempFile("temp_books.csv");
            std::string line;

            if (!booksFile.is_open() || !tempFile.is_open()) {
                MessageBox::Show("Ошибка при открытии файла books.csv.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }

            bool found = false;  // Флаг для проверки, обновилось ли количество книг

            while (std::getline(booksFile, line)) {
                std::istringstream ss(line);
                std::string title, author;
                int year, quantity;

                std::getline(ss, title, ',');  // Название книги
                std::getline(ss, author, ','); // Автор книги
                ss >> year;                    // Год
                ss.ignore(1, ',');             // Пропуск запятой
                ss >> quantity;                // Количество

                if (title == bookTitle) {
                    quantity += change;
                    found = true;

                    if (quantity < 0) {
                        MessageBox::Show("Недостаточно экземпляров книги для бронирования.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
                        tempFile << line << "\n";  // Пишем строку без изменений
                        continue;
                    }
                }

                tempFile << title << "," << author << "," << year << "," << quantity << "\n";
            }

            booksFile.close();
            tempFile.close();

            // Перемещение обновленного файла
            if (found) {
                std::remove("books.csv");
                std::rename("temp_books.csv", "books.csv");
            }
            else {
                std::remove("temp_books.csv");
            }
        }


        void DeleteButton_Click(System::Object^ sender, System::EventArgs^ e)
        {
            // Удаление выбранного бронирования
            if (ReservationList->SelectedIndex == -1) {
                MessageBox::Show("Пожалуйста, выберите бронирование для удаления.");
                return;
            }

            String^ selectedReservation = ReservationList->SelectedItem->ToString();
            ReservationList->Items->Remove(selectedReservation);

            // Обновление файла бронирований
            std::ifstream reservationFile("reservation.csv");
            std::ofstream tempFile("temp_reservation.csv");
            std::string lineToDelete = msclr::interop::marshal_as<std::string>(selectedReservation);
            std::string line;

            while (std::getline(reservationFile, line)) {
                if (line != lineToDelete) {
                    tempFile << line << "\n";
                }
            }

            reservationFile.close();
            tempFile.close();

            std::remove("reservation.csv");
            std::rename("temp_reservation.csv", "reservation.csv");
        }

        void SortButton_Click(System::Object^ sender, System::EventArgs^ e)
        {
            // Сортировка бронирований по алфавиту
            std::vector<std::string> reservations;

            for (int i = 0; i < ReservationList->Items->Count; ++i) {
                reservations.push_back(msclr::interop::marshal_as<std::string>(ReservationList->Items[i]->ToString()));
            }

            std::sort(reservations.begin(), reservations.end());

            ReservationList->Items->Clear();

            for (const auto& res : reservations) {
                ReservationList->Items->Add(gcnew String(res.c_str()));
            }
        }
    };
}



