// Guest.h
#pragma once
#include "User.h"

public ref class Guest : public User {
public:
    Guest(System::String^ name, System::String^ email) : User(name, email) {}

    virtual System::String^ getRole() override {
        return "Guest";
    }
};
