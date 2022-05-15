#ifndef __MENU_SEARCH__
#define __MENU_SEARCH__

#include "../Logic/search.h"


// Search options for the user input
enum class search_options {
  NAME,
  TAG,
  SEARCH
};

void print_petition(const block::petition_p& petition) {
  std::cout << petition.data_.title_ << "\t\tMade by: " << petition.data_.author_ << "\tTags: " << petition.data_.tags_ << "\n\n";
  std::cout << petition.data_.description_ << "\n\n";
  std::cout << "Votes: " << petition.data_.nSigns_ << "\n";
  std::cout << "Date: " << petition.data_.date_ << "\n\n";
}

// Menu function that returns a variety of petitions base on the user's input
int menu_search() {
  int type;
  std::cout << "Search by:" << std::endl;
  std::cout << "0. Name" << std::endl;
  std::cout << "1. Tag" << std::endl;
  std::cout << "2. Search 5 petitions\n>";
  std::cin >> type;

  search_options type_search = static_cast<search_options>(type);

  int search_five_controler = 0;
  switch (type_search) {
  case search_options::NAME: {
    std::string name;
    std::cout << "\nName: ";
    std::cin >> name;
    std::vector<block::petition_p> petitions = search_petit_by_name(name);
    for (auto& i : petitions) {
      print_petition(i);
    }
  }
    break;
  case search_options::TAG: {
    std::string tag;
    std::cout << "\nTag: ";
    std::cin >> tag;
    std::vector<block::petition_p> petitions = search_petit_by_tag(tag);
    for (auto& i : petitions) {
      print_petition(i);
    }
  }
    break;
  case search_options::SEARCH: {
    std::cout << "\n5 petitions: " << std::endl;
    std::vector<block::petition_p> petitions = show_five_petition(search_five_controler);
    for (auto& i : petitions) {
      print_petition(i);
    }
    search_five_controler += 5;
  }
    break;
  }
  return 0;
}

#endif // __MENU_SEARCH__