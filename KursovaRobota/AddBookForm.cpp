#include "AddBookForm.h"

namespace KursovaRobota {

    AddBookForm::AddBookForm(void)
    {
        InitializeComponent();
    }

    AddBookForm::~AddBookForm()
    {
        if (components)
        {
            delete components;
        }
    }

    void AddBookForm::InitializeComponent(void)
    {
        System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AddBookForm::typeid));
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
        this->txtTitle->Text = L"Назва";
        // 
        // txtAuthor
        // 
        this->txtAuthor->Location = System::Drawing::Point(25, 60);
        this->txtAuthor->Name = L"txtAuthor";
        this->txtAuthor->Size = System::Drawing::Size(200, 20);
        this->txtAuthor->TabIndex = 1;
        this->txtAuthor->Text = L"Автор";
        // 
        // txtYear
        // 
        this->txtYear->Location = System::Drawing::Point(25, 95);
        this->txtYear->Name = L"txtYear";
        this->txtYear->Size = System::Drawing::Size(200, 20);
        this->txtYear->TabIndex = 2;
        this->txtYear->Text = L"Рік";
        // 
        // txtQuantity
        // 
        this->txtQuantity->Location = System::Drawing::Point(25, 130);
        this->txtQuantity->Name = L"txtQuantity";
        this->txtQuantity->Size = System::Drawing::Size(200, 20);
        this->txtQuantity->TabIndex = 3;
        this->txtQuantity->Text = L"Кількість";
        // 
        // btnSave
        // 
        this->btnSave->BackColor = System::Drawing::SystemColors::ControlLightLight;
        this->btnSave->Location = System::Drawing::Point(25, 160);
        this->btnSave->Name = L"btnSave";
        this->btnSave->Size = System::Drawing::Size(75, 23);
        this->btnSave->TabIndex = 4;
        this->btnSave->Text = L"Зберегти";
        this->btnSave->UseVisualStyleBackColor = false;
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
        this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
        this->MaximizeBox = false;
        this->Name = L"AddBookForm";
        this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
        this->Text = L"Додавання книги - Система керування бібліотекою";
        this->ResumeLayout(false);
        this->PerformLayout();
    }

    void AddBookForm::btnSave_Click(System::Object^ sender, System::EventArgs^ e)
    {
        try {
            if (String::IsNullOrWhiteSpace(txtTitle->Text)) {
                throw ExceptionHandler("Назва книги не може бути порожньою.", ExceptionType::Warning);
            }

            if (String::IsNullOrWhiteSpace(txtAuthor->Text)) {
                throw ExceptionHandler("Автор книги не може бути порожнім.", ExceptionType::Warning);
            }

            int year, quantity;
            if (!Int32::TryParse(txtYear->Text, year) || year <= 0) {
                throw ExceptionHandler("Введіть коректний рік.", ExceptionType::Warning);
            }

            if (!Int32::TryParse(txtQuantity->Text, quantity) || quantity < 0) {
                throw ExceptionHandler("Кількість має бути невід'ємним числом.", ExceptionType::Warning);
            }

            std::ofstream outputFile("books.csv", std::ios::app);

            System::String^ title = txtTitle->Text;
            System::String^ author = txtAuthor->Text;
            Book^ book = gcnew Book(title, author, year, quantity);


            outputFile << msclr::interop::marshal_as<std::string>(book->getTitle()) << ","
                << msclr::interop::marshal_as<std::string>(book->getAuthor()) << ","
                << book->getYear() << ","
                << book->getQuantity() << std::endl;
            outputFile.close();

            OnBookAdded();
            this->DialogResult = System::Windows::Forms::DialogResult::OK;
            this->Close();
            MessageBox::Show("Дані книги збережено у файл books.csv");

        }
        catch (const ExceptionHandler& ex) {
            ex.showMessage();
        }
        catch (const std::exception& ex) {
            ExceptionHandler genericException(ex.what(), ExceptionType::Error);
            genericException.showMessage();
        }
    }

    void AddBookForm::OnBookAdded()
    {
        BookAdded();
    }
}
