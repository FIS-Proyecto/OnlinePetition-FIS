#ifndef __MENU_CREATE__
#define __MENU_CREATE__

#include "../Logic/create.h"

void menu_create(account::user* user) {
  std::string title, description, tags;
  std::cout << "<< Create new petition >>\n\n";
  std::cout << "Title:\n> ";
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::getline(std::cin, title, '\n'); 

  std::cout << "Description:\n> ";
  std::getline(std::cin, description, '\n');

  std::cout << "Tags:\n> ";
  std::getline(std::cin, tags, '\n');

  try {
    create_petit(user, title, description, tags);
  }
  catch (std::invalid_argument& e) {
    // std::cerr << e.what() << std::endl;
    std::cout << "\nCould not create petition. This petition is already in database\n\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    return;
  }
  std::cout << "\nPetition created successfully\n\n";
  std::this_thread::sleep_for(std::chrono::milliseconds(2000));
}


#endif // __MENU_CREATE__