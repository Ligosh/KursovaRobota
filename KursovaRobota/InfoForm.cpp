#include "InfoForm.h"

namespace KursovaRobota {

	InfoForm::InfoForm(Form^ mainForm)
	{
		InitializeComponent();
		this->mainForm = mainForm;
	}

	InfoForm::~InfoForm()
	{
		if (components)
		{
			delete components;
		}
	}

	void InfoForm::InitializeComponent(void)
	{
		System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(InfoForm::typeid));
		this->BackButton = (gcnew System::Windows::Forms::Button());
		this->label1 = (gcnew System::Windows::Forms::Label());
		this->label2 = (gcnew System::Windows::Forms::Label());
		this->label3 = (gcnew System::Windows::Forms::Label());
		this->label4 = (gcnew System::Windows::Forms::Label());
		this->label5 = (gcnew System::Windows::Forms::Label());
		this->label6 = (gcnew System::Windows::Forms::Label());
		this->label7 = (gcnew System::Windows::Forms::Label());
		this->label8 = (gcnew System::Windows::Forms::Label());
		this->label9 = (gcnew System::Windows::Forms::Label());
		this->label10 = (gcnew System::Windows::Forms::Label());
		this->label11 = (gcnew System::Windows::Forms::Label());
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
		this->label1->Text = L"Інформація про розробників";
		// 
		// label2
		// 
		this->label2->AutoSize = true;
		this->label2->BackColor = System::Drawing::Color::DeepSkyBlue;
		this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->label2->Location = System::Drawing::Point(174, 66);
		this->label2->Name = L"label2";
		this->label2->Size = System::Drawing::Size(217, 13);
		this->label2->TabIndex = 7;
		this->label2->Text = L"Розроблення класів та архітектури";
		// 
		// label3
		// 
		this->label3->AutoSize = true;
		this->label3->BackColor = System::Drawing::Color::DeepSkyBlue;
		this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->label3->Location = System::Drawing::Point(174, 119);
		this->label3->Name = L"label3";
		this->label3->Size = System::Drawing::Size(155, 13);
		this->label3->TabIndex = 8;
		this->label3->Text = L"Розроблення інтерфейсу";
		// 
		// label4
		// 
		this->label4->AutoSize = true;
		this->label4->BackColor = System::Drawing::Color::DeepSkyBlue;
		this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->label4->Location = System::Drawing::Point(174, 169);
		this->label4->Name = L"label4";
		this->label4->Size = System::Drawing::Size(108, 13);
		this->label4->TabIndex = 9;
		this->label4->Text = L"Робота з даними";
		// 
		// label5
		// 
		this->label5->AutoSize = true;
		this->label5->BackColor = System::Drawing::Color::DeepSkyBlue;
		this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->label5->Location = System::Drawing::Point(174, 223);
		this->label5->Name = L"label5";
		this->label5->Size = System::Drawing::Size(140, 13);
		this->label5->TabIndex = 10;
		this->label5->Text = L"Реалізація алгоритмів";
		// 
		// label6
		// 
		this->label6->AutoSize = true;
		this->label6->BackColor = System::Drawing::Color::DeepSkyBlue;
		this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->label6->Location = System::Drawing::Point(174, 273);
		this->label6->Name = L"label6";
		this->label6->Size = System::Drawing::Size(184, 13);
		this->label6->TabIndex = 11;
		this->label6->Text = L"Обробка виняткових ситуацій";
		// 
		// label7
		// 
		this->label7->AutoSize = true;
		this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->label7->Location = System::Drawing::Point(12, 66);
		this->label7->Name = L"label7";
		this->label7->Size = System::Drawing::Size(90, 16);
		this->label7->TabIndex = 12;
		this->label7->Text = L"Абрамов В.";
		// 
		// label8
		// 
		this->label8->AutoSize = true;
		this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->label8->Location = System::Drawing::Point(12, 116);
		this->label8->Name = L"label8";
		this->label8->Size = System::Drawing::Size(96, 16);
		this->label8->TabIndex = 13;
		this->label8->Text = L"Онуфрієв К.";
		// 
		// label9
		// 
		this->label9->AutoSize = true;
		this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->label9->Location = System::Drawing::Point(12, 166);
		this->label9->Name = L"label9";
		this->label9->Size = System::Drawing::Size(89, 16);
		this->label9->TabIndex = 14;
		this->label9->Text = L"Причина К.";
		// 
		// label10
		// 
		this->label10->AutoSize = true;
		this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->label10->Location = System::Drawing::Point(12, 220);
		this->label10->Name = L"label10";
		this->label10->Size = System::Drawing::Size(87, 16);
		this->label10->TabIndex = 15;
		this->label10->Text = L"Косачов Т.";
		// 
		// label11
		// 
		this->label11->AutoSize = true;
		this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->label11->Location = System::Drawing::Point(12, 273);
		this->label11->Name = L"label11";
		this->label11->Size = System::Drawing::Size(29, 16);
		this->label11->TabIndex = 16;
		this->label11->Text = L"Всі";
		// 
		// InfoForm
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
		this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
		this->ClientSize = System::Drawing::Size(427, 324);
		this->Controls->Add(this->label11);
		this->Controls->Add(this->label10);
		this->Controls->Add(this->label9);
		this->Controls->Add(this->label8);
		this->Controls->Add(this->label7);
		this->Controls->Add(this->label6);
		this->Controls->Add(this->label5);
		this->Controls->Add(this->label4);
		this->Controls->Add(this->label3);
		this->Controls->Add(this->label2);
		this->Controls->Add(this->label1);
		this->Controls->Add(this->BackButton);
		this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
		this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
		this->MaximizeBox = false;
		this->Name = L"InfoForm";
		this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
		this->Text = L"Інформація про розробників";
		this->ResumeLayout(false);
		this->PerformLayout();

	}

	System::Void InfoForm::BackButton_Click(System::Object^ sender, System::EventArgs^ e) {
		mainForm->Show();
		this->Close();
	}
}


