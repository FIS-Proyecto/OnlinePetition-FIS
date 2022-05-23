#ifndef __MENU_SIGN__
#define __MENU_SIGN__

#include "../Logic/petition.h"
#include "../Logic/sign.h"
#include "../Logic/user.h"
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
  std::cout << "<< " + petition.data_.title_ + " actions >>\n\n";
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
      std::this_thread::sleep_for(2s);
      clear_screen();
      if (menu_login(user)) {
        sign_petit(petition);
        std::cout << "\nPetition signed successfully\n";
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
    if (user->getAccountType() != account::UNREGISTERED) {
      if (user->getAccountType() == account::REGISTERED && user->data_.get_uid() != petition.data_.author_uid_) {
        std::cout << "\nOnly the author can delete the petition\n";
        std::cout << "Cancelling petition deletion...\n\n";
        std::this_thread::sleep_for(2s);
        return;
      }
      try {
        db::query::del_petition(petition.data_.get_pid());
      }
      catch (std::invalid_argument& e) {
        // std::cerr << e.what() << std::endl;
        std::cout << "\nCould not delete petition\n\n";
        std::this_thread::sleep_for(2s);
        return;
      }
      std::cout << "\nPetition deleted successfully\n\n";
    }
    break;
  case petition_options::BACK:
    return;
    break;
  }
}

#endif  // __MENU_SIGN__