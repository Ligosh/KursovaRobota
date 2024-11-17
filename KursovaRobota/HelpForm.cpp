#include "HelpForm.h"

namespace KursovaRobota {

    HelpForm::HelpForm(Form^ mainForm)
    {
        InitializeComponent();
        this->mainForm = mainForm;
    }

    HelpForm::~HelpForm()
    {
        if (components)
        {
            delete components;
        }
    }

    void HelpForm::InitializeComponent(void)
    {
        System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(HelpForm::typeid));
        this->label1 = (gcnew System::Windows::Forms::Label());
        this->label2 = (gcnew System::Windows::Forms::Label());
        this->label3 = (gcnew System::Windows::Forms::Label());
        this->label4 = (gcnew System::Windows::Forms::Label());
        this->BackButton = (gcnew System::Windows::Forms::Button());
        this->SuspendLayout();

        // label1
        this->label1->AutoSize = true;
        this->label1->BackColor = System::Drawing::SystemColors::ControlLight;
        this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12));
        this->label1->ForeColor = System::Drawing::SystemColors::ControlText;
        this->label1->Location = System::Drawing::Point(11, 45);
        this->label1->Name = L"label1";
        this->label1->Size = System::Drawing::Size(379, 38);
        this->label1->TabIndex = 0;
        this->label1->Text = L"Головна сторінка програми містить три кнопки,\r\nкожна забезпечує доступ до власного меню керування:";

        // label2
        this->label2->AutoSize = true;
        this->label2->BackColor = System::Drawing::SystemColors::ControlLight;
        this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
        this->label2->Location = System::Drawing::Point(12, 94);
        this->label2->Name = L"label2";
        this->label2->Size = System::Drawing::Size(441, 60);
        this->label2->TabIndex = 1;
        this->label2->Text = resources->GetString(L"label2.Text");

        // label3
        this->label3->AutoSize = true;
        this->label3->BackColor = System::Drawing::SystemColors::ControlLight;
        this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
        this->label3->Location = System::Drawing::Point(12, 164);
        this->label3->Name = L"label3";
        this->label3->Size = System::Drawing::Size(452, 90);
        this->label3->TabIndex = 2;
        this->label3->Text = resources->GetString(L"label3.Text");

        // label4
        this->label4->AutoSize = true;
        this->label4->BackColor = System::Drawing::SystemColors::ControlLight;
        this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
        this->label4->Location = System::Drawing::Point(12, 264);
        this->label4->Name = L"label4";
        this->label4->Size = System::Drawing::Size(446, 90);
        this->label4->TabIndex = 3;
        this->label4->Text = resources->GetString(L"label4.Text");

        // BackButton
        this->BackButton->BackColor = System::Drawing::Color::DeepSkyBlue;
        this->BackButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"BackButton.BackgroundImage")));
        this->BackButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
        this->BackButton->Location = System::Drawing::Point(12, 9);
        this->BackButton->Name = L"BackButton";
        this->BackButton->Size = System::Drawing::Size(54, 33);
        this->BackButton->TabIndex = 4;
        this->BackButton->UseVisualStyleBackColor = false;
        this->BackButton->Click += gcnew System::EventHandler(this, &HelpForm::BackButton_Click);

        // HelpForm
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
        this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
        this->ClientSize = System::Drawing::Size(482, 363);
        this->Controls->Add(this->BackButton);
        this->Controls->Add(this->label4);
        this->Controls->Add(this->label3);
        this->Controls->Add(this->label2);
        this->Controls->Add(this->label1);
        this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
        this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
        this->MaximizeBox = false;
        this->Name = L"HelpForm";
        this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
        this->Text = L"Допомога";
        this->ResumeLayout(false);
        this->PerformLayout();
    }

    void HelpForm::BackButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        mainForm->Show();
        this->Close();
    }
}


