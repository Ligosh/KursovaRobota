#pragma once
#include <exception>
#include <string>
#include <iostream>

enum class ExceptionType {
    Error,    
    Warning    
};

class ExceptionHandler : public std::exception {
private:
    std::string errorMessage;
    ExceptionType exceptionType;

public:
    explicit ExceptionHandler(const std::string& message, ExceptionType type = ExceptionType::Error)
        : errorMessage(message), exceptionType(type) {}

    const char* what() const noexcept override {
        return errorMessage.c_str();
    }

    void showMessage() const {
        auto icon = exceptionType == ExceptionType::Warning
            ? System::Windows::Forms::MessageBoxIcon::Warning
            : System::Windows::Forms::MessageBoxIcon::Error;

        System::Windows::Forms::MessageBox::Show(
            gcnew System::String(errorMessage.c_str()),
            exceptionType == ExceptionType::Warning ? "Зауваження" : "Помилка",
            System::Windows::Forms::MessageBoxButtons::OK,
            icon
        );
    }
};
