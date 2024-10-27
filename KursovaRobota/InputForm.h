#pragma once

namespace KursovaRobota {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ InputForm
	/// </summary>
	public ref class InputForm : public System::Windows::Forms::Form
	{
	public:
		String^ inputText;

		InputForm(String^ title, String^ prompt)
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

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~InputForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// InputForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(227, 143);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->Name = L"InputForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"«м≥на к≥лькост≥";
			this->ResumeLayout(false);

		}
#pragma endregion

	private:
		System::Void okButton_Click(System::Object^ sender, System::EventArgs^ e)
		{
			TextBox^ textBox = (TextBox^)this->Controls[1];
			inputText = textBox->Text;
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Close();
		}
	};
}


