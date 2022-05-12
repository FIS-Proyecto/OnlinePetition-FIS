#include "../include/DataBase/db.h"
#include "../include/Logic/login.h"

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
