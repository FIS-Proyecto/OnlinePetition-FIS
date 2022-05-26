#include <thread>
#include <chrono>
#include <algorithm>

#include "../include/Interface/menu_register.h"
#include "../include/Interface/menu_login.h"
#include "../include/Interface/menu_search.h"
#include "../include/Interface/menu_petition.h"
#include "../include/Interface/menu_create.h"
// #include "../include/Logic/color.h"

#if defined(_WIN32) || defined(_WIN64)
  #define clear_screen() system("cls")
#elif defined(__linux__)
  #define clear_screen() system("clear")
#endif

enum menu_options {
  EXIT,
  REGISTER,
  LOGIN,
  SEARCH,
  CREATE
};

enum class choose_petition {
  SELECT,
  EXIT
};

using namespace std::chrono_literals;

int main() {
  int option = -1;
  account::user* user = new account::Unregistered();

  std::cout << "Welcome to the petition system\n\n";
  while (true) {
    std::cout << "PETITION SYSTEM\n\n";
    std::cout << "0. Exit\n";
    std::cout << "1. Register\n";
    std::cout << "2. Login\n";
    std::cout << "3. Search for petitions\n";
    std::cout << "4. Create petition\n-> ";
    std::cin >> option;

    menu_options option_menu = static_cast<menu_options>(option);
    switch (option_menu) {
      case menu_options::EXIT:
        std::cout << "\nThank you for using the petition system\n\n";
        return 0;
      case REGISTER: {
        if (user->getAccountType() == account::ADMIN) {
          std::cout << "\nYou are an admin. You can't register\n\n";
          break;
        }
        else if (user->getAccountType() == account::REGISTERED) {
          std::cout << "\nYou are a user. You can't register\n\n";
          break;
        }
        else {
          clear_screen();
          if (menu_register(user)) {
            std::cout << "\nRegister successful\n\n";
          }
          else {
            std::cout << "\nRegister failed\n\n";
          }
        }
      }
        break;
      case LOGIN: {
        if (user->getAccountType() != account::UNREGISTERED) {
          std::cout << "\nYou are already logged in\n\n";
          break;
        }
        else {
          clear_screen();
          if (menu_login(user)) {
            std::cout << "\nLogin successful\n\n";
          }
          else {
            std::cout << "\nLogin failed\n\n";
          }
        }
      }
        break;
      case SEARCH: {
        clear_screen();
        std::vector<block::petition_p> petitions;
        if(!menu_search(petitions, user)) break;
        size_t option;
        std::string title;
        std::cout << "\n\nOptions:\n"
                  << "\n0. Select petition"
                  << "\n1. Back\n> ";
        std::cin >> option;
        choose_petition petition_opt = static_cast<choose_petition>(option);
        switch (petition_opt) {
          case choose_petition::SELECT: {
            std::cout << "\nSelect the petition title that you want to interact\n> ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, title, '\n'); 
            auto petition_ptr = std::find_if(petitions.begin(), petitions.end(), [&title](block::petition_p& petition) {
              return (petition.data_.title_ == title);
            });
            if (petition_ptr == petitions.end()) {
              std::cout.clear();
              std::cout << "\nPetition not found\n\n";
              break;
            }
            clear_screen();
            menu_petition(*petition_ptr, user);
          }
            break;
          case choose_petition::EXIT:
            break;
        }
      }
        break;
      case CREATE: {
        if (user->getAccountType() == account::UNREGISTERED) {
          std::cout << "\nYou are not logged in, you can't create a petition\n\n";          
          std::this_thread::sleep_for(2s);
          clear_screen();
          if (menu_login(user)) {
            clear_screen();
            menu_create(user);
          }
          break;
        }
        else {
          clear_screen();
          menu_create(user);
        }
      }
        break;
    }
    std::this_thread::sleep_for(2s);
    clear_screen();
  }
  return 0;
}
