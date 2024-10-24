// Admin.h
#pragma once
#include "User.h"

public ref class Admin : public User {
public:
    Admin(System::String^ name, System::String^ email) : User(name, email) {}

    virtual System::String^ getRole() override {
        return "Admin";
    }
};

