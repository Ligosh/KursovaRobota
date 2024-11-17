#pragma once

#include "UsersCatalog.h"
#include "BooksCatalog.h"
#include "Reservation.h"
#include "HelpForm.h"
#include "InfoForm.h"

namespace KursovaRobota {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void);

	protected:
		~MainForm();

	private:
		System::Windows::Forms::Button^ UsersButton;
		System::Windows::Forms::Button^ button2;
		System::Windows::Forms::Button^ button3;
		System::Windows::Forms::PictureBox^ pictureBox1;
		System::Windows::Forms::PictureBox^ pictureBox2;
		System::Windows::Forms::PictureBox^ pictureBox3;
		System::Windows::Forms::Button^ HelpButton;
		System::Windows::Forms::Button^ InfoButton;

		System::ComponentModel::Container^ components;

		void InitializeComponent(void);
		void button1_Click(System::Object^ sender, System::EventArgs^ e);
		void button2_Click(System::Object^ sender, System::EventArgs^ e);
		void button3_Click(System::Object^ sender, System::EventArgs^ e);
		void HelpButton_Click(System::Object^ sender, System::EventArgs^ e);
		void InfoButton_Click(System::Object^ sender, System::EventArgs^ e);
	};
}

