#ifndef __EDIT__
#define __EDIT__

#include "../DataBase/db.h"
#include "petition.h"

#if defined(_WIN32) || defined(_WIN64)
  #define clear_screen() system("cls")
#elif defined(__linux__)
  #define clear_screen() system("clear")
#endif

enum class edit_petition {
  TITLE,
  DESCRIPTION,
  TAGS,
  BACK
};

// Edit function that edits a petition
void edit_petit(block::petition_p& petition) {
  int option = -1;
  clear_screen();
  
  while(true) {
    std::cout << "<< Editing '" + petition.data_.title_ + "' petition >>\n\n";
    std::cout << "0. Edit title\n";
    std::cout << "1. Edit description\n";
    std::cout << "2. Edit tags\n";
    std::cout << "3. Back\n> ";
    std::cin >> option;

    edit_petition edit_opt = static_cast<edit_petition>(option);
    switch (edit_opt) {
    case edit_petition::TITLE: {
      std::string title;
      std::cout << "\nEnter new title: ";
      std::cin.ignore();
      std::getline(std::cin, title, '\n');
      db::query::edit_petition(petition.data_.get_pid(), db_edit::petition({
        title(title)
      }));
    }
      break;
    case edit_petition::DESCRIPTION:{
      std::string description;
      std::cout << "\nEnter new description: ";
      std::cin.ignore();
      std::getline(std::cin, description, '\n');
      db::query::edit_petition(petition.data_.get_pid(), db_edit::petition({
        description(description)
      }));
    }
      break;
    case edit_petition::TAGS: {
      std::string tags;
      std::cout << "\nEnter new tags: ";
      std::cin.ignore();
      std::getline(std::cin, tags, '\n');
      db::query::edit_petition(petition.data_.get_pid(), db_edit::petition({
        tags(tags)
      }));
    }
      break;
    case edit_petition::BACK:
      std::cout << "\nExiting edition menu...\n\n";
      return;
      break;
    }
    //std::this_thread::sleep_for(2s);
    clear_screen();
  }
  return;
}

#endif  // __EDIT__