#include "../include/Interface/menu_register.h"
#include "../include/Interface/menu_login.h"
#include "../include/Interface/menu_buscar.h"


enum menu_options {
  EXIT,
  REGISTER,
  LOGIN,
  SEARCH
};


int main() {
  int option = -1;
  account::user* user = new account::Unregistered();

  while (option != 0) {
    std::cout << "Welcome to the petition system\n\n";
    std::cout << "0. Exit\n";
    std::cout << "1. Register\n";
    std::cout << "2. Login\n";
    std::cout << "3. Search for petitions\n-> ";
    std::cin >> option;

    menu_options option_menu = static_cast<menu_options>(option);
    switch (option_menu) {
    case REGISTER: {
      if (user->getAccountType() == account::ADMIN) {
        std::cout << "You are an admin. You can't register\n\n";
        break;
      }
      else if (user->getAccountType() == account::REGISTERED) {
        std::cout << "You are a user. You can't register\n\n";
        break;
      }
      else {
        if (menu_register(user)) {
          std::cout << "Register successful\n\n";
        }
        else {
          std::cout << "Register failed\n\n";
        }
      }
    }
      break;
    case LOGIN: {
      if (user->getAccountType() != account::UNREGISTERED) {
        std::cout << "You are already logged in\n\n";
        break;
      }
      else {
        if (menu_login(user)) {
          std::cout << "Login successful\n\n";
        }
        else {
          std::cout << "Login failed\n\n";
        }
      }
    }
      break;
    case SEARCH: {
      menu_buscar();
    }
      break;
    }
  }

  return 0;
}
