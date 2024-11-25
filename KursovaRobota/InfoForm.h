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
		InfoForm(Form^ mainForm);
		~InfoForm();

	private:
		System::Windows::Forms::Button^ BackButton;
		Form^ mainForm;
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::Label^ label2;
		System::Windows::Forms::Label^ label3;
		System::Windows::Forms::Label^ label4;
		System::Windows::Forms::Label^ label5;
		System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;

		System::ComponentModel::Container^ components;

		void InitializeComponent(void);
		System::Void BackButton_Click(System::Object^ sender, System::EventArgs^ e);
	};
}

