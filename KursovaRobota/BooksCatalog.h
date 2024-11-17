#pragma once

#include "Book.h"
#include "AddBookForm.h"
#include <vector>
#include "msclr/marshal_cppstd.h"
#include <fstream>
#include <algorithm>
#include "InputForm.h"
#include "ExceptionHandler.h"
#include <sstream>

namespace KursovaRobota {

    using namespace System;
    using namespace System::Windows::Forms;
    using namespace System::Collections::Generic;

    public ref class BooksCatalog : public Form
    {
    private:
        Form^ mainForm;
        ListBox^ listBoxBooks;
        Button^ DeleteButton;
        Button^ AddButton;
        Button^ SortByYearButton;
        Button^ SortByQuantityButton;
        Button^ SortByTitleButton;
        Button^ EditQuantityButton;
        Button^ BackButton1;
        Label^ label1;

        List<Book^>^ books;

        System::ComponentModel::Container^ components;
    private: System::Windows::Forms::Label^ SortLabel;


    public:
        BooksCatalog(Form^ form);
        ~BooksCatalog();

    private:
        void InitializeComponent();
        void BackButton1_Click(System::Object^ sender, System::EventArgs^ e);
        void DeleteButton_Click(System::Object^ sender, System::EventArgs^ e);
        void AddButton_Click(System::Object^ sender, System::EventArgs^ e);
        void SortByYear_Click(System::Object^ sender, System::EventArgs^ e);
        void SortByQuantity_Click(System::Object^ sender, System::EventArgs^ e);
        void SortByTitle_Click(System::Object^ sender, System::EventArgs^ e);
        void EditQuantityButton_Click(System::Object^ sender, System::EventArgs^ e);

        void loadBooks();
        void saveBooks();
        void BubbleSortByYear();
        void SelectionSortByQuantity();
        void InsertionSortByTitle();
    };
}



