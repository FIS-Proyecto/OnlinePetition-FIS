
#include "/home/danielm/Desktop/OnlinePetition-FIS/include/Logic/user.h"


bool login_function(std::string email, std::string passwd, account::User* user);

bool register_function(std::string name, std::string email, std::string passwd);

bool menu_login(account::User* user);

bool menu_register();