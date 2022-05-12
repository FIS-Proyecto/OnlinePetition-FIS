#ifndef MENU_BUSCAR_H
#define MENU_BUSCAR_H

#include "../Logic/buscar.h"
#define linejump std::cout << "\n"

enum buscar_menu_options {
  NAME,
  TAG,
  SEARCH
};

int menu_buscar() {
  int type;
  std::cout << "Buscar por:" << std::endl;
  std::cout << "0. Nombre." << std::endl;
  std::cout << "1. Tag." << std::endl;
  std::cout << "2. Buscar 5 peticiones.\n>";
  std::cin >> type;
  linejump;
  buscar_menu_options type_search = static_cast<buscar_menu_options>(type);

  int search_five_controler = 0;
  switch (type_search) {
  case NAME: {
    std::string name;
    std::cout << "Nombre: ";
    std::cin >> name;
    linejump;
    std::vector<block::petition_p> petitions = search_petit_by_name(name);
    for (auto& i : petitions) {
      std::cout << i.data_.title_ << std::endl;
    }
  }
    break;
  case TAG: {
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
  case SEARCH: {
    std::cout << "5 peticiones: " << std::endl;
    std::vector<block::petition_p> petitions = show_five_petition(search_five_controler);
    for (auto& i : petitions) {
      std::cout << i.data_.title_ << std::endl;
    }
    search_five_controler += 5;
  }
    break;
  default:
    break;
  }
  return 0;
}

#endif // MENU_BUSCAR_H

