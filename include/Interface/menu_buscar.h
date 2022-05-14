#ifndef MENU_BUSCAR_H
#define MENU_BUSCAR_H

#include "../Logic/buscar.h"
#define linejump std::cout << "\n"

enum class search_options {
  NAME,
  TAG,
  SEARCH
};

int menu_buscar() {
  int type;
  std::cout << "Search by:" << std::endl;
  std::cout << "0. Name" << std::endl;
  std::cout << "1. Tag" << std::endl;
  std::cout << "2. Search 5 petitions\n>";
  std::cin >> type;
  linejump;
  search_options type_search = static_cast<search_options>(type);

  int search_five_controler = 0;
  switch (type_search) {
  case search_options::NAME: {
    std::string name;
    std::cout << "Name: ";
    std::cin >> name;
    linejump;
    std::vector<block::petition_p> petitions = search_petit_by_name(name);
    for (auto& i : petitions) {
      std::cout << i.data_.title_ << std::endl;
    }
  }
    break;
  case search_options::TAG: {
    std::string tag;
    std::cout << "Tag: ";
    std::cin >> tag;
    linejump;
    std::vector<block::petition_p> petitions = search_petit_by_tag(tag);
    for (auto& i : petitions) {
      std::cout << i.data_.title_ << std::endl;
    }
  }
    break;
  case search_options::SEARCH: {
    std::cout << "5 petitions: " << std::endl;
    std::vector<block::petition_p> petitions = show_five_petition(search_five_controler);
    for (auto& i : petitions) {
      std::cout << i.data_.title_ << std::endl;
    }
    search_five_controler += 5;
  }
    break;
  }
  return 0;
}

#endif // MENU_BUSCAR_H