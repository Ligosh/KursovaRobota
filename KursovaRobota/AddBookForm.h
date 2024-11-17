#pragma once
#include "Book.h"
#include <fstream>
#include <msclr/marshal_cppstd.h>
#include "ExceptionHandler.h"

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

        AddBookForm(void);

    protected:
        ~AddBookForm();

    private:
        System::Windows::Forms::TextBox^ txtTitle;
        System::Windows::Forms::TextBox^ txtAuthor;
        System::Windows::Forms::TextBox^ txtYear;
        System::Windows::Forms::TextBox^ txtQuantity;
        System::Windows::Forms::Button^ btnSave;

        System::ComponentModel::Container^ components;

        void InitializeComponent(void);
        void btnSave_Click(System::Object^ sender, System::EventArgs^ e);
        void OnBookAdded();
    };
}

