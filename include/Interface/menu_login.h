#include "../Logic/login.h"

bool menu_login(account::user* user) {
  size_t count = 0;
  std::cout << "Email:\n> ";
  std::string email;
  std::cin >> email;
  std::cout << "Contraseña:\n> ";
  std::string passwd;
  std::cin >> passwd;

  // call login function
  bool login = false;
  while(!login) {
    if(count == 3) {
      std::cout << "Too many tries. Leaving logging page\n";
      return false;
    }
    login = login_function(email, passwd, user);
    if(!login) {
      count++;
      std::cout << "Error: Login failed. Try again...\n";
      std::cout << "Email:\n> ";
      std::cin >> email;
      std::cout << "Contraseña:\n> ";
      std::cin >> passwd;
    }
  }
  return true;
}