#pragma once
#include "Book.h"
#include "AddBookForm.h"
#include <vector>
#include "msclr/marshal_cppstd.h"
#include <fstream>
#include <algorithm>
#include "InputForm.h"
#include <sstream>

namespace KursovaRobota {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Collections::Generic;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class BooksCatalog : public System::Windows::Forms::Form
    {
    private:
        System::Windows::Forms::Form^ mainForm;
        System::Windows::Forms::ListBox^ listBoxBooks;
        System::Windows::Forms::Button^ DeleteButton;
        System::Windows::Forms::Button^ AddButton;
        System::Windows::Forms::Button^ SortByYearButton;
        System::Windows::Forms::Button^ SortByQuantityButton;
        System::Windows::Forms::Button^ SortByTitleButton;
        System::Windows::Forms::Button^ EditQuantityButton;
    private: System::Windows::Forms::Label^ label1;

        List<Book^>^ books;

    public:
        BooksCatalog(System::Windows::Forms::Form^ form)
        {
            InitializeComponent();
            mainForm = form;
            loadBooks();
        }

    protected:
        ~BooksCatalog()
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
            this->listBoxBooks = (gcnew System::Windows::Forms::ListBox());
            this->DeleteButton = (gcnew System::Windows::Forms::Button());
            this->AddButton = (gcnew System::Windows::Forms::Button());
            this->SortByYearButton = (gcnew System::Windows::Forms::Button());
            this->SortByQuantityButton = (gcnew System::Windows::Forms::Button());
            this->SortByTitleButton = (gcnew System::Windows::Forms::Button());
            this->EditQuantityButton = (gcnew System::Windows::Forms::Button());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // BackButton1
            // 
            this->BackButton1->Location = System::Drawing::Point(12, 12);
            this->BackButton1->Name = L"BackButton1";
            this->BackButton1->Size = System::Drawing::Size(88, 23);
            this->BackButton1->TabIndex = 0;
            this->BackButton1->Text = L"Повернутися";
            this->BackButton1->UseVisualStyleBackColor = true;
            this->BackButton1->Click += gcnew System::EventHandler(this, &BooksCatalog::BackButton1_Click);
            // 
            // listBoxBooks
            // 
            this->listBoxBooks->FormattingEnabled = true;
            this->listBoxBooks->Location = System::Drawing::Point(106, 32);
            this->listBoxBooks->Name = L"listBoxBooks";
            this->listBoxBooks->Size = System::Drawing::Size(300, 264);
            this->listBoxBooks->TabIndex = 1;
            // 
            // DeleteButton
            // 
            this->DeleteButton->Location = System::Drawing::Point(12, 52);
            this->DeleteButton->Name = L"DeleteButton";
            this->DeleteButton->Size = System::Drawing::Size(75, 23);
            this->DeleteButton->TabIndex = 2;
            this->DeleteButton->Text = L"Видалити";
            this->DeleteButton->UseVisualStyleBackColor = true;
            this->DeleteButton->Click += gcnew System::EventHandler(this, &BooksCatalog::DeleteButton_Click);
            // 
            // AddButton
            // 
            this->AddButton->Location = System::Drawing::Point(12, 81);
            this->AddButton->Name = L"AddButton";
            this->AddButton->Size = System::Drawing::Size(75, 23);
            this->AddButton->TabIndex = 3;
            this->AddButton->Text = L"Додати";
            this->AddButton->UseVisualStyleBackColor = true;
            this->AddButton->Click += gcnew System::EventHandler(this, &BooksCatalog::AddButton_Click);
            // 
            // SortByYearButton
            // 
            this->SortByYearButton->Location = System::Drawing::Point(255, 304);
            this->SortByYearButton->Name = L"SortByYearButton";
            this->SortByYearButton->Size = System::Drawing::Size(70, 21);
            this->SortByYearButton->TabIndex = 4;
            this->SortByYearButton->Text = L"Роком";
            this->SortByYearButton->UseVisualStyleBackColor = true;
            this->SortByYearButton->Click += gcnew System::EventHandler(this, &BooksCatalog::SortByYear_Click);
            // 
            // SortByQuantityButton
            // 
            this->SortByQuantityButton->Location = System::Drawing::Point(331, 304);
            this->SortByQuantityButton->Name = L"SortByQuantityButton";
            this->SortByQuantityButton->Size = System::Drawing::Size(75, 21);
            this->SortByQuantityButton->TabIndex = 5;
            this->SortByQuantityButton->Text = L"Кількістю";
            this->SortByQuantityButton->UseVisualStyleBackColor = true;
            this->SortByQuantityButton->Click += gcnew System::EventHandler(this, &BooksCatalog::SortByQuantity_Click);
            // 
            // SortByTitleButton
            // 
            this->SortByTitleButton->Location = System::Drawing::Point(178, 304);
            this->SortByTitleButton->Name = L"SortByTitleButton";
            this->SortByTitleButton->Size = System::Drawing::Size(71, 21);
            this->SortByTitleButton->TabIndex = 6;
            this->SortByTitleButton->Text = L"Назвою";
            this->SortByTitleButton->UseVisualStyleBackColor = true;
            this->SortByTitleButton->Click += gcnew System::EventHandler(this, &BooksCatalog::SortByTitle_Click);
            // 
            // EditQuantityButton
            // 
            this->EditQuantityButton->Location = System::Drawing::Point(12, 110);
            this->EditQuantityButton->Name = L"EditQuantityButton";
            this->EditQuantityButton->Size = System::Drawing::Size(75, 40);
            this->EditQuantityButton->TabIndex = 7;
            this->EditQuantityButton->Text = L"Змінити кількість";
            this->EditQuantityButton->UseVisualStyleBackColor = true;
            this->EditQuantityButton->Click += gcnew System::EventHandler(this, &BooksCatalog::EditQuantityButton_Click);
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label1->Location = System::Drawing::Point(87, 306);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(85, 15);
            this->label1->TabIndex = 8;
            this->label1->Text = L"Сортувати за";
            // 
            // BooksCatalog
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(425, 336);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->EditQuantityButton);
            this->Controls->Add(this->SortByTitleButton);
            this->Controls->Add(this->SortByQuantityButton);
            this->Controls->Add(this->SortByYearButton);
            this->Controls->Add(this->AddButton);
            this->Controls->Add(this->DeleteButton);
            this->Controls->Add(this->listBoxBooks);
            this->Controls->Add(this->BackButton1);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
            this->MaximizeBox = false;
            this->Name = L"BooksCatalog";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Каталог книг";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private: System::Void BackButton1_Click(System::Object^ sender, System::EventArgs^ e) {
        mainForm->Show();
        this->Close();
    }

    private: System::Void DeleteButton_Click(System::Object^ sender, System::EventArgs^ e) {
        int index = listBoxBooks->SelectedIndex;
        if (index >= 0 && index < books->Count)
        {
            books->RemoveAt(index);
            saveBooks();
            loadBooks();
        }
    }

    private: System::Void AddButton_Click(System::Object^ sender, System::EventArgs^ e) {
        AddBookForm^ addBookForm = gcnew AddBookForm();
        addBookForm->BookAdded += gcnew AddBookForm::BookAddedHandler(this, &BooksCatalog::loadBooks);
        addBookForm->ShowDialog();
    }

    private: System::Void SortByYear_Click(System::Object^ sender, System::EventArgs^ e) {
        books->Sort(gcnew Comparison<Book^>(CompareByYear));
        saveBooks();
        loadBooks();
    }

    private: System::Void SortByQuantity_Click(System::Object^ sender, System::EventArgs^ e) {
        books->Sort(gcnew Comparison<Book^>(CompareByQuantity));
        saveBooks();
        loadBooks();
    }

    private: System::Void SortByTitle_Click(System::Object^ sender, System::EventArgs^ e) {
        books->Sort(gcnew Comparison<Book^>(CompareByTitle));
        saveBooks();
        loadBooks();
    }

    private: System::Void EditQuantityButton_Click(System::Object^ sender, System::EventArgs^ e) {
        int index = listBoxBooks->SelectedIndex;
        if (index >= 0 && index < books->Count)
        {
            Book^ book = books[index];
            InputForm^ inputForm = gcnew InputForm("Зміна кількості", "Введіть нову кількість:");
            if (inputForm->ShowDialog() == System::Windows::Forms::DialogResult::OK)
            {
                int newQuantity;
                if (Int32::TryParse(inputForm->inputText, newQuantity))
                {
                    book->setQuantity(newQuantity);
                    saveBooks();
                    loadBooks();
                }
                else
                {
                    MessageBox::Show("Invalid quantity");
                }
            }
        }
    }

    private: void loadBooks() {
        listBoxBooks->Items->Clear();
        books = gcnew List<Book^>();
        std::ifstream inputFile("books.csv");
        if (inputFile.is_open())
        {
            std::string line;
            std::getline(inputFile, line); // Skip header
            while (std::getline(inputFile, line)) {
                std::stringstream lineStream(line);
                std::string title, author;
                int year, quantity;
                std::getline(lineStream, title, ',');
                std::getline(lineStream, author, ',');
                if (!(lineStream >> year)) {
                    System::Diagnostics::Debug::WriteLine("Error reading year");
                    continue;
                }
                lineStream.ignore(1);
                if (!(lineStream >> quantity)) {
                    System::Diagnostics::Debug::WriteLine("Error reading quantity");
                    continue;
                }
                Book^ book = gcnew Book(gcnew String(title.c_str()), gcnew String(author.c_str()), year, quantity);
                books->Add(book);
            }
            inputFile.close();
        }
        else {
            MessageBox::Show("Failed to open books.csv");
        }
        for each (Book ^ book in books)
        {
            listBoxBooks->Items->Add(
                book->getTitle() + " Автор: " + book->getAuthor() + ", Рік: " + book->getYear() + ", Кількість: " + book->getQuantity()
            );
        }
    }

    private: void saveBooks() {
        std::ofstream outputFile("books.csv");
        outputFile << "Title,Author,Year,Quantity\n";
        for each (Book ^ book in books)
        {
            outputFile << msclr::interop::marshal_as<std::string>(book->getTitle()) << ","
                << msclr::interop::marshal_as<std::string>(book->getAuthor()) << ","
                << book->getYear() << ","
                << book->getQuantity() << "\n";
        }
        outputFile.close();
    }

    private:
        static int CompareByYear(Book^ a, Book^ b) {
            return a->getYear() - b->getYear();
        }
        static int CompareByQuantity(Book^ a, Book^ b) {
            return a->getQuantity() - b->getQuantity();
        }
        static int CompareByTitle(Book^ a, Book^ b) {
            return String::Compare(a->getTitle(), b->getTitle());
        }
    };
}


