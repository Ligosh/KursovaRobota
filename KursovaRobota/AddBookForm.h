#pragma once
#include "Book.h"
#include <fstream>
#include <msclr/marshal_cppstd.h>

namespace KursovaRobota {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class AddBookForm : public System::Windows::Forms::Form
    {
    public:
        delegate void BookAddedHandler();
        event BookAddedHandler^ BookAdded;

        AddBookForm(void)
        {
            InitializeComponent();
        }

    protected:
        ~AddBookForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::TextBox^ txtTitle;
        System::Windows::Forms::TextBox^ txtAuthor;
        System::Windows::Forms::TextBox^ txtYear;
        System::Windows::Forms::TextBox^ txtQuantity;
        System::Windows::Forms::Button^ btnSave;

        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->txtTitle = (gcnew System::Windows::Forms::TextBox());
            this->txtAuthor = (gcnew System::Windows::Forms::TextBox());
            this->txtYear = (gcnew System::Windows::Forms::TextBox());
            this->txtQuantity = (gcnew System::Windows::Forms::TextBox());
            this->btnSave = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // txtTitle
            // 
            this->txtTitle->Location = System::Drawing::Point(25, 25);
            this->txtTitle->Name = L"txtTitle";
            this->txtTitle->Size = System::Drawing::Size(200, 20);
            this->txtTitle->TabIndex = 0;
            this->txtTitle->Text = L"Enter Title";
            // 
            // txtAuthor
            // 
            this->txtAuthor->Location = System::Drawing::Point(25, 60);
            this->txtAuthor->Name = L"txtAuthor";
            this->txtAuthor->Size = System::Drawing::Size(200, 20);
            this->txtAuthor->TabIndex = 1;
            this->txtAuthor->Text = L"Enter Author";
            // 
            // txtYear
            // 
            this->txtYear->Location = System::Drawing::Point(25, 95);
            this->txtYear->Name = L"txtYear";
            this->txtYear->Size = System::Drawing::Size(200, 20);
            this->txtYear->TabIndex = 2;
            this->txtYear->Text = L"Enter Year";
            // 
            // txtQuantity
            // 
            this->txtQuantity->Location = System::Drawing::Point(25, 130);
            this->txtQuantity->Name = L"txtQuantity";
            this->txtQuantity->Size = System::Drawing::Size(200, 20);
            this->txtQuantity->TabIndex = 3;
            this->txtQuantity->Text = L"Enter Quantity";
            // 
            // btnSave
            // 
            this->btnSave->Location = System::Drawing::Point(25, 160);
            this->btnSave->Name = L"btnSave";
            this->btnSave->Size = System::Drawing::Size(75, 23);
            this->btnSave->TabIndex = 4;
            this->btnSave->Text = L"Save";
            this->btnSave->UseVisualStyleBackColor = true;
            this->btnSave->Click += gcnew System::EventHandler(this, &AddBookForm::btnSave_Click);
            // 
            // AddBookForm
            // 
            this->ClientSize = System::Drawing::Size(284, 211);
            this->Controls->Add(this->btnSave);
            this->Controls->Add(this->txtQuantity);
            this->Controls->Add(this->txtYear);
            this->Controls->Add(this->txtAuthor);
            this->Controls->Add(this->txtTitle);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
            this->MaximizeBox = false;
            this->Name = L"AddBookForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private:
        System::Void btnSave_Click(System::Object^ sender, System::EventArgs^ e)
        {
            // Получаем данные из полей
            System::String^ title = txtTitle->Text;
            System::String^ author = txtAuthor->Text;
            int year = Convert::ToInt32(txtYear->Text);
            int quantity = Convert::ToInt32(txtQuantity->Text);

            Book^ book = gcnew Book(title, author, year, quantity);

            // Открываем файл для добавления данных в конец (append)
            std::ofstream outputFile("books.csv", std::ios::app);

            if (!outputFile.is_open()) {
                MessageBox::Show("Failed to open file for saving.");
                return;
            }

            // Сохранение книги в формате CSV
            outputFile << msclr::interop::marshal_as<std::string>(book->getTitle()) << ","
                << msclr::interop::marshal_as<std::string>(book->getAuthor()) << ","
                << book->getYear() << ","
                << book->getQuantity() << std::endl;

            outputFile.close();

            OnBookAdded();
            this->DialogResult = System::Windows::Forms::DialogResult::OK;
            this->Close();

            MessageBox::Show("Book data saved to books.csv");
        }

        void OnBookAdded() {
            BookAdded();
        }
    };
}

