// Member.h
#pragma once
#include "User.h"

public ref class Member : public User {
public:
    Member(System::String^ name, System::String^ email) : User(name, email) {}

    virtual System::String^ getRole() override {
        return "Member";
    }
};
