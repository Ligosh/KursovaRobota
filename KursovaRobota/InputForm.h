#pragma once

namespace KursovaRobota {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class InputForm : public System::Windows::Forms::Form
    {
    public:
        String^ inputText;

        InputForm(String^ title, String^ prompt);

    protected:
        ~InputForm();

    private:
        System::ComponentModel::Container^ components;

        void InitializeComponent(void);
        void okButton_Click(System::Object^ sender, System::EventArgs^ e);
    };
}


