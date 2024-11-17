#include "InputForm.h"

namespace KursovaRobota {

    InputForm::InputForm(String^ title, String^ prompt)
    {
        InitializeComponent();
        this->Text = title;

        Label^ label = gcnew Label();
        label->Text = prompt;
        label->Location = System::Drawing::Point(10, 10);
        label->Size = System::Drawing::Size(200, 20);

        TextBox^ textBox = gcnew TextBox();
        textBox->Location = System::Drawing::Point(10, 40);
        textBox->Size = System::Drawing::Size(200, 20);

        Button^ okButton = gcnew Button();
        okButton->Text = "OK";
        okButton->Location = System::Drawing::Point(10, 70);
        okButton->Click += gcnew EventHandler(this, &InputForm::okButton_Click);

        this->Controls->Add(label);
        this->Controls->Add(textBox);
        this->Controls->Add(okButton);
    }

    InputForm::~InputForm()
    {
        if (components)
        {
            delete components;
        }
    }

    void InputForm::InitializeComponent(void)
    {
        System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(InputForm::typeid));
        this->SuspendLayout();
        // 
        // InputForm
        // 
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->ClientSize = System::Drawing::Size(207, 134);
        this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
        this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
        this->MaximizeBox = false;
        this->Name = L"InputForm";
        this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
        this->Text = L"«м≥на к≥лькост≥";
        this->ResumeLayout(false);
    }

    void InputForm::okButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        TextBox^ textBox = (TextBox^)this->Controls[1];
        inputText = textBox->Text;
        this->DialogResult = System::Windows::Forms::DialogResult::OK;
        this->Close();
    }
}


