#include "StartForm.h"

namespace KursovaRobota {

	StartForm::StartForm(void)
	{
		InitializeComponent();

	}

	StartForm::~StartForm()
	{
		if (components)
		{
			delete components;
		}
	}

	void StartForm::InitializeComponent(void)
	{
		System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(StartForm::typeid));
		this->StartButton = (gcnew System::Windows::Forms::Button());
		this->label1 = (gcnew System::Windows::Forms::Label());
		this->SuspendLayout();
		// 
		// StartButton
		// 
		this->StartButton->BackColor = System::Drawing::Color::DeepSkyBlue;
		this->StartButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
		this->StartButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->StartButton->Location = System::Drawing::Point(270, 241);
		this->StartButton->Name = L"StartButton";
		this->StartButton->Size = System::Drawing::Size(116, 44);
		this->StartButton->TabIndex = 0;
		this->StartButton->Text = L"��������� ������";
		this->StartButton->UseVisualStyleBackColor = false;
		this->StartButton->Click += gcnew System::EventHandler(this, &StartForm::button1_Click);
		// 
		// label1
		// 
		this->label1->AutoSize = true;
		this->label1->BackColor = System::Drawing::Color::DeepSkyBlue;
		this->label1->Cursor = System::Windows::Forms::Cursors::Default;
		this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->label1->ForeColor = System::Drawing::SystemColors::ControlText;
		this->label1->Location = System::Drawing::Point(100, 84);
		this->label1->Name = L"label1";
		this->label1->Size = System::Drawing::Size(447, 31);
		this->label1->TabIndex = 1;
		this->label1->Text = L"������� ��������� ���������";
		// 
		// StartForm
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
		this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
		this->ClientSize = System::Drawing::Size(653, 352);
		this->Controls->Add(this->label1);
		this->Controls->Add(this->StartButton);
		this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
		this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
		this->MaximizeBox = false;
		this->Name = L"StartForm";
		this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
		this->Text = L"������� - ������� ��������� ���������";
		this->ResumeLayout(false);
		this->PerformLayout();
	}

	void StartForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
		this->Close();
	}
}
