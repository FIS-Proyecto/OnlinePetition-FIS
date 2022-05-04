#include "/home/julio/Desktop/OnlinePetition-FIS/include/DataBase/db.h"
#include "/home/julio/Desktop/OnlinePetition-FIS/include/Logic/tools.h"

db::filehandler::filehandler(query_helper qr) {

  try {
    file_.open(database, std::fstream::in | std::fstream::out | std::fstream::app);
  } catch (std::exception e) {
    std::cout << "Error while opening database: " << e.what() << std::endl;
  }

  switch (qr.action_t) {
    case query_helper::type::add:
      result_ = this->add();
      break;
    case query_helper::type::del:
      result_ = this->del();
      break;
    case query_helper::type::edit:
      this->edit();
      break;
    case query_helper::type::get: 
    {
      auto[data_tpl, result_tpl] = this->get<user>(qr.ID);
      data_ = data_tpl;
      result_ = result_tpl;
    }
      // if(std::holds_alternative<user>(data_))
      //   std::cout << std::get<user>(data_) << std::endl;
      // else if(std::holds_alternative<Petition>(data_))
      //   std::cout << std::get<Petition>(data_) << std::endl;
      break;
    default:
      result_ = false;
      break;
  }
}

db::filehandler::~filehandler() {
  file_.close();
}

template<typename Type_>
std::tuple<Type_, bool> db::filehandler::get(std::string ID) {
  size_t line_inx = 1;
  std::string line;
  if(typeid(Type_) == typeid(user)) { 
    while (getline(file_, line)) {
      if(line_inx == 50) {
        return std::forward_as_tuple(user(), false);
        break;
      }
      if (line.find(ID) != std::string::npos) {
        std::stringstream ss(line);
        return std::forward_as_tuple(this->wrapUser(line), true);
      }
      ++line_inx;
    }
  }
  if(typeid(Type_) == typeid(Petition)) { 
    tools::GotoLine(file_, 50);
  }
  return std::forward_as_tuple(user(), true);
}

bool db::filehandler::add() {
  return false;
}

bool db::filehandler::del() {
  return false;
}

bool db::filehandler::edit() {
  return false;
}

//tools

user db::filehandler::wrapUser(std::string line) {
  std::stringstream ss(line);
  std::string segment, name, uid, email, passwd;
  size_t account_type;

  std::getline(ss, segment, ';');
  uid = segment;
  std::getline(ss, segment, ';');
  name = segment;
  std::getline(ss, segment, ';');
  email = segment;
  std::getline(ss, segment, ';');
  passwd = segment;
  std::getline(ss, segment, ';');
  account_type = std::stoi(segment);
  return user(name, email, passwd, uid, account_type);
}
