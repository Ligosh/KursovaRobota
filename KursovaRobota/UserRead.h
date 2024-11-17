#pragma once
#include "Admin.h"
#include "Member.h"
#include "Guest.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include <msclr/marshal_cppstd.h>

using namespace System::Collections::Generic;
using json = nlohmann::json;

public ref class UserRead {
public:
    static List<User^>^ readUsersFromJSON(System::String^ filename);
};



