#include "/home/julio/Desktop/OnlinePetition-FIS/include/DataBase/db.h"

// main function to test the database class and the filehandler class

using namespace edit_config;
using namespace db;

#define name(new_d)         sp_user(u_options::name,         new_d)
#define email(new_d)        sp_user(u_options::email,        new_d)
#define passwd(new_d)       sp_user(u_options::passwd,       new_d)
#define account_type(new_d) sp_user(u_options::account_type, new_d)

int main() { 
  // Petition database options

  db::petition new_petition("1093800298120385", "title", "desc", "author", "auth_id", "date", "n_signs", "tags");
  std::cout <<  (db::query::add_petition(new_petition) ? "added" : "not added") << std::endl;
  std::cout << db::query::get_petition("1093810298120391") << std::endl;
  std::cout <<  (db::query::edit_petition("1093810298120391", db_edit::petition({
    sp_petition(author, "michele"),
    sp_petition(title, "new_title")
  })) ? "edited" : "not edited") << std::endl;
  std::cout <<  (db::query::del_petition("10938002981203851") ? "deleted" : "not deleted") << std::endl;

  // User database options

  db::user new_user("1013810798120392", "name", "email", "passwd", 0);
  std::cout << (db::query::add_user(new_user) ? "added" : "not added") << std::endl;
  std::cout << db::query::get_user("1013810798120392") << std::endl;
  std::cout <<  (db::query::edit_user("1013810798120392", db_edit::user({
    sp_user(name, "caca"),
    sp_user(email, "caca"),
    sp_user(passwd, "caca"),
    sp_user(account_type, "caca")
  })) ? "edited" : "not edited") << std::endl;
  std::cout << (db::query::del_user("1013810798120392") ? "deleted" : "not deleted") << std::endl;
}
