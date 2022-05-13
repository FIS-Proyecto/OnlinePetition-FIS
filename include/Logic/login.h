#ifndef LOGIN_FUNCTION_H
#define LOGIN_FUNCTION_H

#include "user.h"

bool login_function(std::string email, std::string passwd, account::user* user);

#endif // LOGIN_FUNCTION_H