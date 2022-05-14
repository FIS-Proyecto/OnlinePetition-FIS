#ifndef __MENU_REGISTER__
#define __MENU_REGISTER__

#include "../Logic/register.h"


bool menu_register(account::user* &user) {
  std::cout << "<< Register new user >>\n\n";
  std::string name, email, passwd;
  std::cout << "Name:\n> ";
  std::cin >> name;
  std::cout << "Email:\n> ";
  std::cin >> email;
  std::cout << "Password:\n> ";
  std::cin >> passwd;
  
  return register_function(name, email, passwd, user); 
}


#endif // __MENU_REGISTER__