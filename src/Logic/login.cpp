#include <iostream>

#include "../../include/DataBase/db.h"
#include "../../include/Logic/login.h"

bool login_function(std::string email, std::string passwd, account::user* user) {
  db::user db_user(db::query::get_user(email));
  std::string uid = std::to_string(std::hash<std::string_view>{}(email));
  std::cout << uid << " -- db: " << db_user.get_uid() << "\n\n";
  if (db_user.get_uid() == uid) {
    if (db_user.account_type_ == 1) {
      user = new account::Admin();
    } 
    else {
      user = new account::Registered();
    }
    
    *user = db_user;
    return true;
  }
  return false;
}