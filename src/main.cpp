#include <thread>
#include <chrono>

#include "../include/Interface/menu_register.h"
#include "../include/Interface/menu_login.h"
#include "../include/Interface/menu_buscar.h"
#include "../include/Logic/color.h"

#if defined(_WIN32) || defined(_WIN64)
  #define clear_screen() system("cls")
#elif defined(__linux__)
  #define clear_screen() system("clear")
#endif

enum menu_options {
  EXIT,
  REGISTER,
  LOGIN,
  SEARCH
};

using namespace std::chrono_literals;

int main() {
  int option = -1;
  account::user* user = new account::Unregistered();

  while (true) {
    std::cout << "Welcome to the petition system\n\n";
    std::cout << "0. Exit\n";
    std::cout << "1. Register\n";
    std::cout << "2. Login\n";
    std::cout << "3. Search for petitions\n-> ";
    std::cin >> option;

    menu_options option_menu = static_cast<menu_options>(option);
    switch (option_menu) {
      case menu_options::EXIT:
        return 0;
      case REGISTER: {
        if (user->getAccountType() == account::ADMIN) {
          std::cout << Color::BG_RED << "\nYou are an admin. You can't register\n\n" << Color::BG_DEFAULT;
          break;
        }
        else if (user->getAccountType() == account::REGISTERED) {
          std::cout << Color::BG_RED << "\nYou are a user. You can't register\n\n" << Color::BG_DEFAULT;
          break;
        }
        else {
          clear_screen();
          if (menu_register(user)) {
            std::cout << Color::BG_GREEN << "\nRegister successful\n\n" << Color::BG_DEFAULT;
          }
          else {
            std::cout << Color::BG_RED << "\nRegister failed\n\n" << Color::BG_DEFAULT;
          }
        }
      }
        break;
      case LOGIN: {
        if (user->getAccountType() != account::UNREGISTERED) {
          std::cout << Color::BG_RED << "\nYou are already logged in\n\n" << Color::BG_DEFAULT;
          break;
        }
        else {
          clear_screen();
          if (menu_login(user)) {
            std::cout << Color::BG_GREEN << "\nLogin successful\n\n" << Color::BG_DEFAULT;
          }
          else {
            std::cout << Color::BG_RED << "\nLogin failed\n\n" << Color::BG_DEFAULT;
          }
        }
      }
        break;
      case SEARCH: {
        menu_buscar();
      }
        break;
      }
    std::this_thread::sleep_for(2s);
    clear_screen();
  }

  return 0;
}
