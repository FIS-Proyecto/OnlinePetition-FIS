#include "../include/Interface/menu_register.h"
#include "../include/Interface/menu_login.h"

int main() {
  /*
  account::User* user;
  if (menu_login(user)) {
    std::cout << "Login successful\n";
  }
  else {
    std::cout << "Login failed\n";
  }
  */

  if (menu_register()) {
    std::cout << "OK" << std::endl;
  }
  else {
    std::cout << "OKn't" << std::endl;
  }

  return 0;
}
