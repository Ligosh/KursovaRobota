#pragma once
#include "UsersCatalog.h"
namespace KursovaRobota {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ UsersButton;
	protected:

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->UsersButton = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// UsersButton
			// 
			this->UsersButton->Location = System::Drawing::Point(75, 145);
			this->UsersButton->Name = L"UsersButton";
			this->UsersButton->Size = System::Drawing::Size(88, 87);
			this->UsersButton->TabIndex = 0;
			this->UsersButton->Text = L"Список користувачів";
			this->UsersButton->UseVisualStyleBackColor = true;
			this->UsersButton->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(267, 145);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(91, 87);
			this->button2->TabIndex = 1;
			this->button2->Text = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(477, 145);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(86, 87);
			this->button3->TabIndex = 2;
			this->button3->Text = L"button3";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(649, 286);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->UsersButton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MainForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		// Створюємо нову форму
		UsersCatalog^ newForm = gcnew UsersCatalog(this);
		this->Hide();  // Приховуємо поточну (головну) форму
		newForm->Show();  // Відкриваємо нову форму
	}
	};
	};
