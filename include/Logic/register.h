#ifndef __REGISTER__
#define __REGISTER__

#include <string>

#include "user.h"
#include "../DataBase/db.h"


bool register_function(std::string name, std::string email, std::string passwd, account::user* &user) {
  db::user new_user(name, email, passwd, 0);
  try {
    if (db::query::add_user(new_user)) {
      user = new account::Registered();
      *user = new_user;
    }
  }
  catch (std::exception& e) {
    // std::cerr << e.what() << std::endl;
    std::cerr << "User already exists.\n\n";
    return false;
  }
  return true;
}


#endif // __REGISTER__