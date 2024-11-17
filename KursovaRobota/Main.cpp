#include "StartForm.h"
#include "MainForm.h"
#include "dependencies/include/nlohmann/json.hpp"

using namespace KursovaRobota;
using namespace System;
using namespace System::Windows::Forms;
using json = nlohmann::json;


[STAThreadAttribute]
int main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    KursovaRobota::StartForm^ startForm = gcnew KursovaRobota::StartForm();

    if (startForm->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
        KursovaRobota::MainForm^ mainForm = gcnew KursovaRobota::MainForm();
        Application::Run(mainForm);
    }

    return 0;
}

