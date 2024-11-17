#pragma once
#include "User.h"
#include "Admin.h"
#include "Member.h"
#include "Guest.h"
#include <nlohmann/json.hpp>
#include <msclr/marshal_cppstd.h>
#include "ExceptionHandler.h"

namespace KursovaRobota {

    using namespace System;
    using namespace System::Windows::Forms;
    using namespace nlohmann;

    public ref class AddUserForm : public System::Windows::Forms::Form
    {
    public:
        delegate void UserAddedHandler();
        event UserAddedHandler^ UserAdded;

        AddUserForm();

    protected:
        ~AddUserForm();

    private:
        System::Windows::Forms::TextBox^ txtName;
        System::Windows::Forms::TextBox^ txtEmail;
        System::Windows::Forms::ComboBox^ cmbRole;
        System::Windows::Forms::Button^ btnSave;

        System::ComponentModel::Container^ components;

        void InitializeComponent();
        System::Void btnSave_Click(System::Object^ sender, System::EventArgs^ e);
        void OnUserAdded();
    };
}





