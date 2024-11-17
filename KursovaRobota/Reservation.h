#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <msclr/marshal_cppstd.h>
#include <nlohmann/json.hpp>
#include "ExceptionHandler.h"
#include "UserRead.h"

namespace KursovaRobota {
    using namespace System;
    using namespace System::Windows::Forms;
    using namespace System::Drawing;
    using namespace nlohmann;

    public ref class Reservation : public System::Windows::Forms::Form
    {
    public:
        Reservation(Form^ mainForm);
        ~Reservation();

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

        void InitializeComponent(void);
        void BackButton_Click(System::Object^ sender, System::EventArgs^ e);
        void LoadBooks();
        void LoadUsers();
        void LoadReservations();
        void ReservationButton_Click(System::Object^ sender, System::EventArgs^ e);
        void UpdateBookQuantity(const std::string& bookTitle, int change);
        void DeleteButton_Click(System::Object^ sender, System::EventArgs^ e);
        void SortButton_Click(System::Object^ sender, System::EventArgs^ e);
    };
}




