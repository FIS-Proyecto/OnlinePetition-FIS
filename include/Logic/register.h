#include <string>

#include "user.h"
#include "../DataBase/db.h"

bool register_function(std::string name, std::string email, std::string passwd) {
  db::user new_user(name, email, passwd, 0);
  if (db::query::add_user(new_user)) {
    return true;
  }
  return false;
}
