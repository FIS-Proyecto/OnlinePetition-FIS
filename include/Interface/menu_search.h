#ifndef __MENU_SEARCH__
#define __MENU_SEARCH__

#include "../Logic/search.h"
#include "../Logic/user.h"
#include "menu_petition.h"

// Search options for the user input
enum class search_options {
  NAME,
  TAG,
  SEARCH,
  OWN
};

// Menu function that returns a variety of petitions base on the user's input
bool menu_search(std::vector<block::petition_p> &petitions, account::user* &user) {
  int type;
  std::cout << "Search by:" << std::endl;
  std::cout << "0. Name" << std::endl;
  std::cout << "1. Tag" << std::endl;
  std::cout << "2. Search 5 petitions\n";
  std::cout << "3. Search my own petitions\n> ";
  std::cin >> type;

  search_options type_search = static_cast<search_options>(type);

  int search_five_controler = 0;
  switch (type_search) {
    case search_options::NAME: {
      std::string name;
      std::cout << "\nName: ";
      std::cin >> name;
      petitions = search_petit_by_name(name);
      if(petitions.size() == 0) {
        std::cout << "\nNo petitions found\n\n";
        return false;
      }
      for (auto& petition : petitions) {
        std::cout << "\n\n" << petition;
      }
    }
      break;
    case search_options::TAG: {
      std::string tag;
      std::cout << "\nTag: ";
      std::cin >> tag;
      petitions = search_petit_by_tag(tag);
      if(petitions.size() == 0) {
        std::cout << "\nNo petitions found\n\n";
        return false;
      }
      for (auto& petition : petitions) {
        std::cout << "\n\n" << petition;
      }
    }
      break;
    case search_options::SEARCH: {
      std::cout << "\n5 petitions: " << std::endl;
      petitions = show_five_petition(search_five_controler);
      if(petitions.size() == 0) {
        std::cout << "\nNo petitions found\n\n";
        return false;
      }
      for (auto& petition : petitions) {
        std::cout << "\n\n" << petition;
      }
      search_five_controler += 5;
    }
      break;
  case search_options::OWN:
      if (user->getAccountType() == account::UNREGISTERED) {
      std::cout << "\nYou must be logged in to search your petitions\n\n";
      std::this_thread::sleep_for(2s);
      clear_screen();
      if (!menu_login(user)) {
        break;
      } 
    } 
    try{
      petitions = search_owner_petition(user);
      if(petitions.size() == 0) {
        std::cout << "\nNo petitions found\n\n";
        break;
      }
      for (auto& petition : petitions) {
      std::cout << "\n\n" << petition;
      }
    } 
    catch (std::invalid_argument& e) {
      std::cout << "\nCould not find petitions\n\n";
      std::this_thread::sleep_for(2s);
      clear_screen();
      break;
    }
    break;    
  }
  return true;
}

#endif // __MENU_SEARCH__