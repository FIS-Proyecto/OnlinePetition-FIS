#include "C:\Users\Rules\Desktop\OnlinePetition-FIS\include\DataBase\db.h"
#include "C:\Users\Rules\Desktop\OnlinePetition-FIS\include\Logic\tools.h"

using namespace db;

const db::user query::get_user(std::string search) {
  db::filehandler fh(
    query_type::get,
    search,
    data_t::user
  );
  if(fh.result_) {
    return tools::wrapUser(fh.data_);
  }
  else {
    std::cout << "failed query: 'get_user' did not find " << search << '\n';
    return user(fh.data_, fh.data_, fh.data_, fh.data_, SIZE_MAX);
  } 
}
const db::petition query::get_petition(std::string ID) {
  db::filehandler fh(
    query_type::get,
    ID,
    data_t::petition
  );
  if(fh.result_) {
    return tools::wrapPetition(fh.data_);
  }
  else {
    std::cout << "failed query: 'get_petition' did not find " << ID << '\n';
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

std::vector<db::user> query::filter_user(std::string filter) {
  db::filehandler fh(
    query_type::filter,
    filter,
    data_t::user
  );
  std::vector<db::user> users;
  for(auto& user : fh.data_vec_) {
    users.emplace_back(tools::wrapUser(user));
  }
  return users;
}
std::vector<db::petition> query::filter_petition(std::string filter) {
  db::filehandler fh(
    query_type::filter,
    filter,
    data_t::petition
  );
  std::vector<db::petition> petitions;
  for(auto& petition : fh.data_vec_) {
    petitions.emplace_back(tools::wrapPetition(petition));
  }
  return petitions;
}