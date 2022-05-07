#include "/home/julio/Desktop/OnlinePetition-FIS/include/DataBase/db.h"
#include "/home/julio/Desktop/OnlinePetition-FIS/include/Logic/tools.h"

using namespace db;

db::user query::get_user(std::string ID) {
  db::filehandler fh(
    query_type::get,
    ID,
    data_t::user
  );
  if(fh.result_) {
    return tools::wrapUser(fh.data_);
  }
  else {
    std::cout << "failed query: 'get_user' with ID: " << ID << '\n';
    return user(fh.data_, fh.data_, fh.data_, fh.data_, SIZE_MAX);
  } 
}
db::petition query::get_petition(std::string ID) {
  db::filehandler fh(
    query_type::get,
    ID,
    data_t::petition
  );
  if(fh.result_) {
    return tools::wrapPetition(fh.data_);
  }
  else {
    std::cout << "failed query: 'get_petition' with ID: " << ID << '\n';
    return petition(fh.data_, fh.data_, fh.data_, fh.data_, fh.data_, fh.data_, fh.data_, fh.data_);
  }
}
bool query::add_user(db::user add_usr) {
  db::filehandler fh(
    query_type::add,
    add_usr
  );
  return fh.result_;
}
bool query::add_petition(db::petition add_petit) {
  db::filehandler fh(
    query_type::add,
    add_petit
  );
  return fh.result_;
}
bool query::del_petition(std::string ID) {
  db::filehandler fh(
    query_type::del,
    ID,
    data_t::petition
  );
  return fh.result_;
}
bool query::del_user(std::string ID) {
  db::filehandler fh(
    query_type::del,
    ID,
    data_t::user
  );
  return fh.result_;
}
bool query::edit_user(std::string ID, db_edit::user edit_usr) {
  db::filehandler fh(
    query_type::edit,
    ID,
    edit_usr
  );
  return fh.result_;
}
bool query::edit_petition(std::string ID, db_edit::petition edit_petit) {
  db::filehandler fh(
    query_type::edit,
    ID,
    edit_petit
  );
  return fh.result_;
}