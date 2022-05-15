#include <iostream>

#include "../../include/DataBase/db.h"
#include "../../include/Logic/login.h"


bool login_function(std::string email, std::string passwd, account::user* &user) {
  db::user db_user;
  try {
    db_user = db::query::get_user(email);
  }
  catch (std::exception& e) {
    // std::cerr << e.what() << std::endl;
    std::cerr << "User not found.\n";
    return false;
  }

  std::string uid = std::to_string(std::hash<std::string_view>{}(email));
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