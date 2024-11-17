#pragma once

namespace KursovaRobota {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class InfoForm : public System::Windows::Forms::Form
	{
	public:
		InfoForm(Form^ mainForm)
		{
			InitializeComponent();
			this->mainForm = mainForm;
		}

	protected:
		~InfoForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ BackButton;
	protected:

	private:
		Form^ mainForm;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(InfoForm::typeid));
			this->BackButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// BackButton
			// 
			this->BackButton->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->BackButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"BackButton.BackgroundImage")));
			this->BackButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->BackButton->Location = System::Drawing::Point(12, 12);
			this->BackButton->Name = L"BackButton";
			this->BackButton->Size = System::Drawing::Size(54, 33);
			this->BackButton->TabIndex = 5;
			this->BackButton->UseVisualStyleBackColor = false;
			this->BackButton->Click += gcnew System::EventHandler(this, &InfoForm::BackButton_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(72, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(218, 16);
			this->label1->TabIndex = 6;
			this->label1->Text = L"���������� ��� ����������";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(9, 66);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(225, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"����������� ����� �� �����������: ";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(12, 116);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(159, 13);
			this->label3->TabIndex = 8;
			this->label3->Text = L"����������� ����������:\r\n";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(12, 168);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(112, 13);
			this->label4->TabIndex = 9;
			this->label4->Text = L"������ � ������:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(12, 220);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(144, 13);
			this->label5->TabIndex = 10;
			this->label5->Text = L"��������� ���������:\r\n";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(12, 276);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(188, 13);
			this->label6->TabIndex = 11;
			this->label6->Text = L"������� ���������� ��������:";
			// 
			// InfoForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(427, 324);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->BackButton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MinimizeBox = false;
			this->Name = L"InfoForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"���������� ��� ����������";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void BackButton_Click(System::Object^ sender, System::EventArgs^ e) {
		mainForm->Show();
		this->Close();
	}
	};
}