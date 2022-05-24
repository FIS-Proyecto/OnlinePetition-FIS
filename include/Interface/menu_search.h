#ifndef __MENU_SEARCH__
#define __MENU_SEARCH__

#include "../Logic/search.h"

// Search options for the user input
enum class search_options {
  NAME,
  TAG,
  SEARCH
};

// Menu function that returns a variety of petitions base on the user's input
bool menu_search(std::vector<block::petition_p> &petitions) {
  int type;
  std::cout << "Search by:" << std::endl;
  std::cout << "0. Name" << std::endl;
  std::cout << "1. Tag" << std::endl;
  std::cout << "2. Search 5 petitions\n> ";
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
  }
  return true;
}

#endif // __MENU_SEARCH__