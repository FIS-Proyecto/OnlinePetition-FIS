#ifndef __MENU_SIGN__
#define __MENU_SIGN__

#include "../Logic/sign.h"
#include "../Logic/user.h"
#include "../Logic/petition.h"
#include "menu_login.h"

#if defined(_WIN32) || defined(_WIN64)
  #define clear_screen() system("cls")
#elif defined(__linux__)
  #define clear_screen() system("clear")
#endif

using namespace std::chrono_literals;

enum class petition_options {
  SIGN,
  EDIT,
  DELETE,
  BACK
};

void menu_petition(block::petition_p& petition, account::user* &user) {
  int option;
  std::cout << "<<<" + petition.data_.title_ + " actions >>\n\n";
  std::cout << "0. Sign petition\n";
  std::cout << "1. Edit petition\n";
  std::cout << "2. Delete petition\n";
  std::cout << "3. Back\n> ";
  std::cin >> option;

  petition_options petition_opt = static_cast<petition_options>(option);
  switch (petition_opt) {
  case petition_options::SIGN:
    if (user->getAccountType() == account::UNREGISTERED) {
      std::cout << "\nYou must be logged in to sign petitions\n\n";
      std::this_thread::sleep_for(3s);
      clear_screen();
      if (menu_login(user)) {
        sign_petit(petition);
        std::cout << "Petition signed successfully\n";
      }
      else {
        return;
      }
    }
    else {
      sign_petit(petition);
      std::cout << "Petition signed successfully\n";
    }
    break;
  case petition_options::EDIT:
    std::cout << "Not implemented yet\n";
    break;
  case petition_options::DELETE:
    std::cout << "Not implemented yet\n";
    break;
  case petition_options::BACK:
    return;
    break;
  }
}

#endif  // __MENU_SIGN__