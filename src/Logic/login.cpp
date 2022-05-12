#include <iostream>

#include "../../include/DataBase/db.h"
#include "../../include/Logic/login.h"

bool login_function(std::string email, std::string passwd, account::User* user) {
  db::user db_user(db::query::get_user(email));
  std::string uid = std::to_string(std::hash<std::string_view>{}(email));
  std::cout << uid << " -- db: " << db_user.get_uid() << "\n\n";
  if (db_user.get_uid() == uid) {
    if (db_user.account_type_ == 0) {
      user = new account::Admin();
    } 
    else {
      user = new account::Registered();
    }
    user->set_uid(db_user.get_uid());
    user->name_ = db_user.name_;
    user->email_ = db_user.email_;
    user->passwd_ = db_user.passwd_;
    return true;
  }
  return false;
}


bool register_function(std::string name, std::string email, std::string passwd) {
  db::user new_user(name, email, passwd, 0);
  if (db::query::add_user(new_user)) {
    return true;
  }
  return false;
}


bool menu_login(account::User* user) {
  size_t count = 0;
  std::cout << "Email:\n> ";
  std::string email;
  std::cin >> email;
  std::cout << "Contraseña:\n> ";
  std::string passwd;
  std::cin >> passwd;
  // call login function
  bool login = false;
  while(!login) {
    if(count == 3) {
      std::cout << "Too many tries. Leaving logging page\n";
      return false;
    }
    login = login_function(email, passwd, user);
    if(!login) {
      count++;
      std::cout << "Error: Login failed. Try again...\n";
      std::cout << "Email:\n> ";
      std::cin >> email;
      std::cout << "Contraseña:\n> ";
      std::cin >> passwd;
    }
  }
  return true;
}

bool menu_register() {
  std::string name, email, passwd;
  std::cout << "Nombre:\n> ";
  std::cin >> name;
  std::cout << "Email:\n> ";
  std::cin >> email;
  std::cout << "Contraseña:\n> ";
  std::cin >> passwd;
  
  return register_function(name, email, passwd); 
}