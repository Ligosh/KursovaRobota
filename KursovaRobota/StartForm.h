#pragma once

namespace KursovaRobota {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class StartForm : public System::Windows::Forms::Form
	{
	public:
		StartForm(void);

	protected:
		~StartForm();

	private:
		System::Windows::Forms::Button^ StartButton;
		System::Windows::Forms::Label^ label1;

		System::ComponentModel::Container^ components;

		void InitializeComponent(void);

	private:
		System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	};
}

