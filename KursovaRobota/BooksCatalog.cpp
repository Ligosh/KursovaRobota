#include "BooksCatalog.h"

namespace KursovaRobota {

    BooksCatalog::BooksCatalog(Form^ form)
    {
        InitializeComponent();
        mainForm = form;
        loadBooks();
    }

    BooksCatalog::~BooksCatalog()
    {
        if (components)
        {
            delete components;
        }
    }

    void BooksCatalog::InitializeComponent()
    {
        System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(BooksCatalog::typeid));
        this->BackButton1 = (gcnew System::Windows::Forms::Button());
        this->listBoxBooks = (gcnew System::Windows::Forms::ListBox());
        this->DeleteButton = (gcnew System::Windows::Forms::Button());
        this->AddButton = (gcnew System::Windows::Forms::Button());
        this->SortByYearButton = (gcnew System::Windows::Forms::Button());
        this->SortByQuantityButton = (gcnew System::Windows::Forms::Button());
        this->SortByTitleButton = (gcnew System::Windows::Forms::Button());
        this->EditQuantityButton = (gcnew System::Windows::Forms::Button());
        this->SortLabel = (gcnew System::Windows::Forms::Label());
        this->SuspendLayout();
        // 
        // BackButton1
        // 
        this->BackButton1->BackColor = System::Drawing::Color::DeepSkyBlue;
        this->BackButton1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"BackButton1.BackgroundImage")));
        this->BackButton1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
        this->BackButton1->Location = System::Drawing::Point(12, 12);
        this->BackButton1->Name = L"BackButton1";
        this->BackButton1->Size = System::Drawing::Size(54, 33);
        this->BackButton1->TabIndex = 0;
        this->BackButton1->UseVisualStyleBackColor = false;
        this->BackButton1->Click += gcnew System::EventHandler(this, &BooksCatalog::BackButton1_Click);
        // 
        // listBoxBooks
        // 
        this->listBoxBooks->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
        this->listBoxBooks->FormattingEnabled = true;
        this->listBoxBooks->Location = System::Drawing::Point(106, 12);
        this->listBoxBooks->Name = L"listBoxBooks";
        this->listBoxBooks->Size = System::Drawing::Size(449, 264);
        this->listBoxBooks->TabIndex = 1;
        // 
        // DeleteButton
        // 
        this->DeleteButton->BackColor = System::Drawing::Color::DeepSkyBlue;
        this->DeleteButton->Location = System::Drawing::Point(12, 68);
        this->DeleteButton->Name = L"DeleteButton";
        this->DeleteButton->Size = System::Drawing::Size(75, 23);
        this->DeleteButton->TabIndex = 2;
        this->DeleteButton->Text = L"Видалити";
        this->DeleteButton->UseVisualStyleBackColor = false;
        this->DeleteButton->Click += gcnew System::EventHandler(this, &BooksCatalog::DeleteButton_Click);
        // 
        // AddButton
        // 
        this->AddButton->BackColor = System::Drawing::Color::DeepSkyBlue;
        this->AddButton->Location = System::Drawing::Point(12, 97);
        this->AddButton->Name = L"AddButton";
        this->AddButton->Size = System::Drawing::Size(75, 23);
        this->AddButton->TabIndex = 3;
        this->AddButton->Text = L"Додати";
        this->AddButton->UseVisualStyleBackColor = false;
        this->AddButton->Click += gcnew System::EventHandler(this, &BooksCatalog::AddButton_Click);
        // 
        // SortByYearButton
        // 
        this->SortByYearButton->BackColor = System::Drawing::Color::DeepSkyBlue;
        this->SortByYearButton->Location = System::Drawing::Point(275, 289);
        this->SortByYearButton->Name = L"SortByYearButton";
        this->SortByYearButton->Size = System::Drawing::Size(70, 21);
        this->SortByYearButton->TabIndex = 4;
        this->SortByYearButton->Text = L"Роком";
        this->SortByYearButton->UseVisualStyleBackColor = false;
        this->SortByYearButton->Click += gcnew System::EventHandler(this, &BooksCatalog::SortByYear_Click);
        // 
        // SortByQuantityButton
        // 
        this->SortByQuantityButton->BackColor = System::Drawing::Color::DeepSkyBlue;
        this->SortByQuantityButton->Location = System::Drawing::Point(351, 289);
        this->SortByQuantityButton->Name = L"SortByQuantityButton";
        this->SortByQuantityButton->Size = System::Drawing::Size(75, 21);
        this->SortByQuantityButton->TabIndex = 5;
        this->SortByQuantityButton->Text = L"Кількістю";
        this->SortByQuantityButton->UseVisualStyleBackColor = false;
        this->SortByQuantityButton->Click += gcnew System::EventHandler(this, &BooksCatalog::SortByQuantity_Click);
        // 
        // SortByTitleButton
        // 
        this->SortByTitleButton->BackColor = System::Drawing::Color::DeepSkyBlue;
        this->SortByTitleButton->Location = System::Drawing::Point(198, 289);
        this->SortByTitleButton->Name = L"SortByTitleButton";
        this->SortByTitleButton->Size = System::Drawing::Size(71, 21);
        this->SortByTitleButton->TabIndex = 6;
        this->SortByTitleButton->Text = L"Назвою";
        this->SortByTitleButton->UseVisualStyleBackColor = false;
        this->SortByTitleButton->Click += gcnew System::EventHandler(this, &BooksCatalog::SortByTitle_Click);
        // 
        // EditQuantityButton
        // 
        this->EditQuantityButton->BackColor = System::Drawing::Color::DeepSkyBlue;
        this->EditQuantityButton->Location = System::Drawing::Point(12, 126);
        this->EditQuantityButton->Name = L"EditQuantityButton";
        this->EditQuantityButton->Size = System::Drawing::Size(75, 40);
        this->EditQuantityButton->TabIndex = 7;
        this->EditQuantityButton->Text = L"Змінити кількість";
        this->EditQuantityButton->UseVisualStyleBackColor = false;
        this->EditQuantityButton->Click += gcnew System::EventHandler(this, &BooksCatalog::EditQuantityButton_Click);
        // 
        // SortLabel
        // 
        this->SortLabel->AutoSize = true;
        this->SortLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(204)));
        this->SortLabel->Location = System::Drawing::Point(103, 291);
        this->SortLabel->Name = L"SortLabel";
        this->SortLabel->Size = System::Drawing::Size(85, 15);
        this->SortLabel->TabIndex = 8;
        this->SortLabel->Text = L"Сортувати за";
        // 
        // BooksCatalog
        // 
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
        this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
        this->ClientSize = System::Drawing::Size(587, 336);
        this->Controls->Add(this->SortLabel);
        this->Controls->Add(this->EditQuantityButton);
        this->Controls->Add(this->SortByTitleButton);
        this->Controls->Add(this->SortByQuantityButton);
        this->Controls->Add(this->SortByYearButton);
        this->Controls->Add(this->AddButton);
        this->Controls->Add(this->DeleteButton);
        this->Controls->Add(this->listBoxBooks);
        this->Controls->Add(this->BackButton1);
        this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
        this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
        this->MaximizeBox = false;
        this->Name = L"BooksCatalog";
        this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
        this->Text = L"Каталог книг - Система керування бібліотекою";
        this->ResumeLayout(false);
        this->PerformLayout();

    }

    void BooksCatalog::BackButton1_Click(System::Object^ sender, System::EventArgs^ e)
    {
        mainForm->Show();
        this->Close();
    }

    void BooksCatalog::DeleteButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        int index = listBoxBooks->SelectedIndex;
        if (index < 0 || index >= books->Count)
        {
            ExceptionHandler("Будь ласка, виберіть книгу для видалення.", ExceptionType::Warning).showMessage();
            return;
        }

        books->RemoveAt(index);
        saveBooks();
        loadBooks();
    }

    void BooksCatalog::AddButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        AddBookForm^ addBookForm = gcnew AddBookForm();
        addBookForm->BookAdded += gcnew AddBookForm::BookAddedHandler(this, &BooksCatalog::loadBooks);
        addBookForm->ShowDialog();
    }

    void BooksCatalog::SortByYear_Click(System::Object^ sender, System::EventArgs^ e)
    {
        BubbleSortByYear();
        saveBooks();
        loadBooks();
    }

    void BooksCatalog::SortByQuantity_Click(System::Object^ sender, System::EventArgs^ e)
    {
        SelectionSortByQuantity();
        saveBooks();
        loadBooks();
    }

    void BooksCatalog::SortByTitle_Click(System::Object^ sender, System::EventArgs^ e)
    {
        InsertionSortByTitle();
        saveBooks();
        loadBooks();
    }

    void BooksCatalog::EditQuantityButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        int index = listBoxBooks->SelectedIndex;
        if (index < 0 || index >= books->Count)
        {
            ExceptionHandler("Будь ласка, виберіть книгу для зміни кількості.", ExceptionType::Warning).showMessage();
            return;
        }

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
                ExceptionHandler("Некоректне значення кількості", ExceptionType::Warning).showMessage();
            }
        }
    }

    void BooksCatalog::loadBooks()
    {
        listBoxBooks->Items->Clear();
        books = gcnew List<Book^>();

        std::ifstream inputFile("books.csv");
        if (!inputFile.is_open())
        {
            ExceptionHandler("Не вдалося відкрити books.csv", ExceptionType::Error).showMessage();

            std::ofstream outputFile("books.csv");
            if (!outputFile.is_open())
            {
                ExceptionHandler("Не вдалося створити файл books.csv", ExceptionType::Error).showMessage();
                return;
            }
            outputFile << "Title,Author,Year,Quantity\n";
            outputFile.close();
            return;
        }

        std::string line;
        std::getline(inputFile, line); 
        while (std::getline(inputFile, line))
        {
            try
            {
                std::stringstream lineStream(line);
                std::string title, author;
                int year, quantity;

                std::getline(lineStream, title, ',');
                std::getline(lineStream, author, ',');

                if (!(lineStream >> year))
                {
                    throw ExceptionHandler("Помилка при зчитуванні року", ExceptionType::Warning);
                }

                lineStream.ignore(1);
                if (!(lineStream >> quantity))
                {
                    throw ExceptionHandler("Помилка при зчитуванні кількості", ExceptionType::Warning);
                }

                Book^ book = gcnew Book(gcnew String(title.c_str()), gcnew String(author.c_str()), year, quantity);
                books->Add(book);
            }
            catch (const ExceptionHandler& ex)
            {
                ex.showMessage();
            }
        }
        inputFile.close();

        for each (Book ^ book in books)
        {
            listBoxBooks->Items->Add(
                book->getTitle() + " Автор: " + book->getAuthor() + ", Рік: " + book->getYear() + ", Кількість: " + book->getQuantity());
        }
    }


    void BooksCatalog::saveBooks()
    {
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

    void BooksCatalog::BubbleSortByYear()
    {
        for (int i = 0; i < books->Count - 1; i++)
        {
            for (int j = 0; j < books->Count - i - 1; j++)
            {
                if (books[j]->getYear() > books[j + 1]->getYear())
                {
                    Book^ temp = books[j];
                    books[j] = books[j + 1];
                    books[j + 1] = temp;
                }
            }
        }
    }

    void BooksCatalog::SelectionSortByQuantity()
    {
        for (int i = 0; i < books->Count - 1; i++)
        {
            int minIndex = i;
            for (int j = i + 1; j < books->Count; j++)
            {
                if (books[j]->getQuantity() < books[minIndex]->getQuantity())
                {
                    minIndex = j;
                }
            }
            if (minIndex != i)
            {
                Book^ temp = books[i];
                books[i] = books[minIndex];
                books[minIndex] = temp;
            }
        }
    }

    void BooksCatalog::InsertionSortByTitle()
    {
        for (int i = 1; i < books->Count; i++)
        {
            Book^ key = books[i];
            int j = i - 1;
            while (j >= 0 && String::Compare(books[j]->getTitle(), key->getTitle()) > 0)
            {
                books[j + 1] = books[j];
                j--;
            }
            books[j + 1] = key;
        }
    }
}
