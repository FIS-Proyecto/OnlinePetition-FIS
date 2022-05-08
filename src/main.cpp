#include "C:\Users\Rules\Desktop\OnlinePetition-FIS\include\DataBase\db.h"

// main function to test the database class and the filehandler class

using namespace edit_config;
using namespace db;

int main() { 
  // Petition database options

  db::petition new_petition("10938002981203831", "title", "desc", "author", "auth_id", "date", "n_signs", "tags");
  std::cout << (db::query::add_petition(new_petition) ? "added" : "not added") << std::endl;
  std::cout << db::query::get_petition("10938002981203831") << std::endl;
  for(auto& i : db::query::filter_petition("genero,hambre")) {
    std::cout << i.title_ << std::endl;
  }
  std::cout << (db::query::edit_petition("10938002981203831", db_edit::petition({
    sp_petition(author, "michele"),
    title("new title"),
  })) ? "edited" : "not edited") << std::endl;
  std::cout <<  (db::query::del_petition("10938002981203831") ? "deleted" : "not deleted") << std::endl;

  // User database options

  db::user new_user("nombre", "nombre@usuario.com", "mi_contraseña", 0);
  std::cout << (query::add_user(new_user) ? "added" : "not added") << std::endl;
  std::cout << query::get_user("daniel@admin.com") << std::endl;
  std::cout << (query::edit_user("1013810798120392", db_edit::user({
    name("michele"),
    sp_user(email, "caca"),
    sp_user(passwd, "caca"),
    account_type("0"),
  })) ? "edited" : "not edited") << std::endl;
  std::cout << (query::del_user("1013810798120392") ? "deleted" : "not deleted") << std::endl;
}
