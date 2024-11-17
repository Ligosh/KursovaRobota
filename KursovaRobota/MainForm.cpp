#include "MainForm.h"

namespace KursovaRobota {

	MainForm::MainForm(void)
	{
		InitializeComponent();
	}

	MainForm::~MainForm()
	{
		if (components)
		{
			delete components;
		}
	}

	void MainForm::InitializeComponent(void)
	{
		System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
		this->UsersButton = (gcnew System::Windows::Forms::Button());
		this->button2 = (gcnew System::Windows::Forms::Button());
		this->button3 = (gcnew System::Windows::Forms::Button());
		this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
		this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
		this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
		this->HelpButton = (gcnew System::Windows::Forms::Button());
		this->InfoButton = (gcnew System::Windows::Forms::Button());
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
		this->SuspendLayout();
		// 
		// UsersButton
		// 
		this->UsersButton->BackColor = System::Drawing::Color::DeepSkyBlue;
		this->UsersButton->FlatAppearance->BorderSize = 5;
		this->UsersButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
		this->UsersButton->Location = System::Drawing::Point(86, 211);
		this->UsersButton->Name = L"UsersButton";
		this->UsersButton->Size = System::Drawing::Size(98, 44);
		this->UsersButton->TabIndex = 0;
		this->UsersButton->Text = L"Список користувачів";
		this->UsersButton->UseVisualStyleBackColor = false;
		this->UsersButton->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
		// 
		// button2
		// 
		this->button2->BackColor = System::Drawing::Color::DeepSkyBlue;
		this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
		this->button2->Location = System::Drawing::Point(275, 211);
		this->button2->Name = L"button2";
		this->button2->Size = System::Drawing::Size(99, 44);
		this->button2->TabIndex = 1;
		this->button2->Text = L"Каталог книг";
		this->button2->UseVisualStyleBackColor = false;
		this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
		// 
		// button3
		// 
		this->button3->BackColor = System::Drawing::Color::DeepSkyBlue;
		this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
		this->button3->Location = System::Drawing::Point(473, 211);
		this->button3->Name = L"button3";
		this->button3->Size = System::Drawing::Size(104, 44);
		this->button3->TabIndex = 2;
		this->button3->Text = L"Бронювання";
		this->button3->UseVisualStyleBackColor = false;
		this->button3->Click += gcnew System::EventHandler(this, &MainForm::button3_Click);
		// 
		// pictureBox1
		// 
		this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
		this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
		this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
		this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
		this->pictureBox1->Location = System::Drawing::Point(75, 86);
		this->pictureBox1->Name = L"pictureBox1";
		this->pictureBox1->Size = System::Drawing::Size(120, 108);
		this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
		this->pictureBox1->TabIndex = 3;
		this->pictureBox1->TabStop = false;
		// 
		// pictureBox2
		// 
		this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
		this->pictureBox2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
		this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
		this->pictureBox2->Location = System::Drawing::Point(266, 86);
		this->pictureBox2->Name = L"pictureBox2";
		this->pictureBox2->Size = System::Drawing::Size(120, 108);
		this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
		this->pictureBox2->TabIndex = 4;
		this->pictureBox2->TabStop = false;
		// 
		// pictureBox3
		// 
		this->pictureBox3->BackColor = System::Drawing::Color::Transparent;
		this->pictureBox3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
		this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
		this->pictureBox3->Location = System::Drawing::Point(473, 86);
		this->pictureBox3->Name = L"pictureBox3";
		this->pictureBox3->Size = System::Drawing::Size(104, 108);
		this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
		this->pictureBox3->TabIndex = 5;
		this->pictureBox3->TabStop = false;
		// 
		// HelpButton
		// 
		this->HelpButton->BackColor = System::Drawing::Color::DeepSkyBlue;
		this->HelpButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
		this->HelpButton->Location = System::Drawing::Point(605, 12);
		this->HelpButton->Name = L"HelpButton";
		this->HelpButton->Size = System::Drawing::Size(32, 32);
		this->HelpButton->TabIndex = 6;
		this->HelpButton->Text = L"\?";
		this->HelpButton->UseVisualStyleBackColor = false;
		this->HelpButton->Click += gcnew System::EventHandler(this, &MainForm::HelpButton_Click);
		// 
		// InfoButton
		// 
		this->InfoButton->BackColor = System::Drawing::Color::DeepSkyBlue;
		this->InfoButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
		this->InfoButton->Location = System::Drawing::Point(567, 12);
		this->InfoButton->Name = L"InfoButton";
		this->InfoButton->Size = System::Drawing::Size(32, 32);
		this->InfoButton->TabIndex = 7;
		this->InfoButton->Text = L"i";
		this->InfoButton->UseVisualStyleBackColor = false;
		this->InfoButton->Click += gcnew System::EventHandler(this, &MainForm::InfoButton_Click);
		// 
		// MainForm
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
		this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
		this->ClientSize = System::Drawing::Size(649, 286);
		this->Controls->Add(this->InfoButton);
		this->Controls->Add(this->HelpButton);
		this->Controls->Add(this->pictureBox3);
		this->Controls->Add(this->pictureBox2);
		this->Controls->Add(this->pictureBox1);
		this->Controls->Add(this->button3);
		this->Controls->Add(this->button2);
		this->Controls->Add(this->UsersButton);
		this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
		this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
		this->MaximizeBox = false;
		this->Name = L"MainForm";
		this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
		this->Text = L"Головна - Система керування бібліотекою";
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();

		this->ResumeLayout(false);
	}

	void MainForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		UsersCatalog^ newForm = gcnew UsersCatalog(this);
		this->Hide();
		newForm->Show();
	}

	void MainForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		BooksCatalog^ newForm = gcnew BooksCatalog(this);
		this->Hide();
		newForm->Show();
	}

	void MainForm::button3_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Reservation^ newForm = gcnew Reservation(this);
		this->Hide();
		newForm->Show();
	}

	void MainForm::HelpButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		HelpForm^ newForm = gcnew HelpForm(this);
		this->Hide();
		newForm->Show();
	}

	void MainForm::InfoButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		InfoForm^ newForm = gcnew InfoForm(this);
		this->Hide();
		newForm->Show();
	}
}
