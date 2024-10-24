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

    // Створюємо екземпляр вторинної форми
    KursovaRobota::StartForm^ StartForm = gcnew KursovaRobota::StartForm();

    // Відкриваємо вторинну форму
    Application::Run(StartForm);

    // Після закриття SecondaryForm, створюємо і запускаємо головну форму
    if (StartForm->DialogResult == System::Windows::Forms::DialogResult::OK) {
        KursovaRobota::MainForm^ mainForm = gcnew KursovaRobota::MainForm();
        Application::Run(mainForm);
    }
}
