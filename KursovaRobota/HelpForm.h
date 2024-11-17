#pragma once

namespace KursovaRobota {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;


    public ref class HelpForm : public System::Windows::Forms::Form
    {
    public:
        HelpForm(Form^ mainForm);

    protected:
        ~HelpForm();

    private:
        Form^ mainForm;
        System::ComponentModel::Container^ components;

        System::Windows::Forms::Label^ label1;
        System::Windows::Forms::Label^ label2;
        System::Windows::Forms::Label^ label3;
        System::Windows::Forms::Label^ label4;
        System::Windows::Forms::Button^ BackButton;

        void InitializeComponent(void);
        void BackButton_Click(System::Object^ sender, System::EventArgs^ e);
    };
}
