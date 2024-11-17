// User.h
#pragma once
#include <string>

public ref class User abstract {
protected:
    System::String^ name;
    System::String^ email;

public:
    User(System::String^ name, System::String^ email) : name(name), email(email) {}

    virtual System::String^ getRole() = 0;

    System::String^ getName() { return name; }
    System::String^ getEmail() { return email; }

    virtual ~User() {}
};
