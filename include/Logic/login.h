#ifndef __LOGIN__
#define __LOGIN__

#include "user.h"

// Login function that returns if the user has been logged in successfully
bool login_function(std::string email, std::string passwd, account::user* &user);

#endif // __LOGIN__