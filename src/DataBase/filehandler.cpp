#include "C:\Users\Rules\Desktop\OnlinePetition-FIS\include\DataBase\db.h"

using namespace db;

void deleteEmptyLinesFile(std::string file_path) {
  std::ifstream in_file("bruh.txt");
  std::ofstream out_file(file_path);

  std::string line;
  while (getline(in_file, line)) {
    if (!line.empty() ) {
      out_file << line << '\n';
    }
  }
}

//get user/petition by id

filehandler::filehandler(query_type qr, std::string ID, data_t dt_ty) {
  if(qr != query_type::get && qr != query_type::del) {
    throw std::invalid_argument("Invalid action type with incorrect arguments");
    exit(EXIT_SUCCESS);
  }

  switch(dt_ty) {
    case data_t::user:
      try {
        file_.open(users_database, std::fstream::in | std::fstream::out | std::fstream::app);
      } catch (std::exception e) {
        std::cout << "Error while opening database: " << e.what() << std::endl;
      }
      if (qr == query_type::get) this->get<db::user>(ID);
      if (qr == query_type::del) this->del(ID, users_database);
      break;
    case data_t::petition:
      try {
        file_.open(petitions_database, std::fstream::in | std::fstream::out | std::fstream::app);
      } catch (std::exception e) {
        std::cout << "Error while opening database: " << e.what() << std::endl;
      }
      if (qr == query_type::get) this->get<db::petition>(ID);
      if (qr == query_type::del) this->del(ID, petitions_database);
      break;
    default:
      throw std::invalid_argument("Invalid data type");
      exit(EXIT_SUCCESS);
  }
}

filehandler::filehandler(query_type qr, std::string ID, db_edit::user edit_usr) {
  if(qr != query_type::edit) {
    throw std::invalid_argument("Invalid action type with incorrect arguments");
    exit(EXIT_SUCCESS);
  }

  try {
    file_.open(users_database, std::fstream::in | std::fstream::out | std::fstream::app);
  } catch (std::exception e) {
    std::cout << "Error while opening users database: " << e.what() << std::endl;
  }

  this->edit(ID, edit_usr);
}

filehandler::filehandler(query_type qr, std::string ID, db_edit::petition edit_petit) {
  if(qr != query_type::edit) {
    throw std::invalid_argument("Invalid action type with incorrect arguments");
    exit(EXIT_SUCCESS);
  }

  try {
    file_.open(petitions_database, std::fstream::in | std::fstream::out | std::fstream::app);
  } catch (std::exception e) {
    std::cout << "Error while opening users database: " << e.what() << std::endl;
  }

  this->edit(ID, edit_petit);
}

filehandler::filehandler(query_type qr, user add_usr) {
  if(qr != query_type::add && qr != query_type::del) {
    throw std::invalid_argument("Invalid action type with incorrect arguments");
    exit(EXIT_SUCCESS);
  }

  try {
    file_.open(users_database, std::fstream::in | std::fstream::out | std::fstream::app);
  } catch (std::exception e) {
    std::cout << "Error while opening users database: " << e.what() << std::endl;
  }

  this->add<db::user>(add_usr);
  // deleteEmptyLinesFile(users_database);
}

filehandler::filehandler(query_type qr, petition add_petit) {
  if(qr != query_type::add && qr != query_type::del) {
    throw std::invalid_argument("Invalid action type with incorrect arguments");
    exit(EXIT_SUCCESS);
  }

  try {
    file_.open(petitions_database, std::fstream::in | std::fstream::out | std::fstream::app);
  } catch (std::exception e) {
    std::cout << "Error while opening users database: " << e.what() << std::endl;
  }

  this->add<db::petition>(add_petit);
}


filehandler::~filehandler() {
  file_.close();
}

template<typename Type_>
void filehandler::get(std::string ID) {
  std::string line;
  if(typeid(Type_) == typeid(db::user)) { 
    while (getline(file_, line)) {
      if (line.find(ID) != std::string::npos) {
        data_ = line;
        result_ = true;
        return;
      }
    }
    throw std::invalid_argument("'get' -> user ID '" + ID + "' doesnt exist");
  }
  if(typeid(Type_) == typeid(petition)) { 
    while (getline(file_, line)) {
      if (line.find(ID) != std::string::npos) {
        data_ = line;
        result_ = true;
        return;
      }
    }
    throw std::invalid_argument("'get' -> petition ID '" + ID + "' doesnt exist");
  }
  data_ = "ERROR";
  result_ = false;
}

template<typename Type_>
void filehandler::add(Type_ data) {
  std::string line, search_id, data_id;
  std::string search;
  line << data;
  std::stringstream data_ss(line);
  std::getline(data_ss, data_id, ';');
  while (getline(file_, line)) {
      std::stringstream search_ss(line);
      std::getline(search_ss, search_id, ';');
      if(search_id == data_id) {
        std::string t_d;
        if(typeid(Type_) == typeid(petition)) t_d = "petition";
        if(typeid(Type_) == typeid(user)) t_d = "user";
        result_ = false;
        throw std::invalid_argument("'add' -> " + t_d + " ID already exists");
        return;
      }
  }
  file_.clear();
  file_.seekg(0, std::ios::beg);
  file_ << "\n" << data;
  result_ = true;
  return;
}

void filehandler::del(std::string ID, std::string db_name) {
  std::string line, search_id;
  std::ofstream temp_file;

  std::ofstream temp;
  temp.open("temp.txt");

  bool found;

  while (getline(file_, line)) {
    std::stringstream search_ss(line);
    std::getline(search_ss, search_id, ';');
    if(search_id == ID) {
      data_ = "deleted";
      result_ = true;
      found = true;
      continue;
    }
    temp << line << std::endl;
  }
  // deleteEmptyLinesFile("temp.txt");
  temp.close();
  file_.close();
  remove(db_name.c_str());
  rename("temp.txt", db_name.c_str());
  remove("temp.txt");

  if(!found) {
    result_ = false;
    throw std::invalid_argument("'del' -> ID not found in " + db_name);
    return;
  }
}

void filehandler::edit(std::string ID, db_edit::user edit_usr) {
  std::string line, search_id;
  std::ofstream temp;
  bool found;
  temp.open("temp.txt");
  while (getline(file_, line)) {
    std::stringstream search_ss(line);
    std::getline(search_ss, search_id, ';');
    if(search_id == ID) {
      std::string uid, name, email, passwd, acc_t;
      uid = search_id;
      std::getline(search_ss, name, ';');
      std::getline(search_ss, email, ';');
      std::getline(search_ss, passwd, ';');
      std::getline(search_ss, acc_t, ';');
      
      if(!edit_usr.UID_.empty()) {
        uid = edit_usr.UID_;
      }
      if(!edit_usr.name_.empty()) {
        name = edit_usr.name_;
      }
      if(!edit_usr.email_.empty()) {
        email = edit_usr.email_;
      }
      if(!edit_usr.passwd_.empty()) {
        passwd = edit_usr.passwd_;
      }
      if(!edit_usr.account_type_.empty()) {
        acc_t = edit_usr.account_type_;
      }
      line = uid + ";" + name + ";" + email + ";" + passwd + ";" + acc_t;
      found = true;
      result_ = true;
      data_ = "edited";
    }
    temp << line << std::endl;
  }
  // deleteEmptyLinesFile("temp.txt");
  temp.close();
  file_.close();
  remove(users_database.c_str());
  rename("temp.txt", users_database.c_str());
  remove("temp.txt");

  if(!found) {
    result_ = false;
    throw std::invalid_argument("'edit' -> user ID not found");
    return;
  }
}

void filehandler::edit(std::string ID, db_edit::petition edit_petit) {
  std::string line, search_id;
  std::ofstream temp;
  bool found;
  temp.open("temp.txt");
  while (getline(file_, line)) {
    std::stringstream search_ss(line);
    std::getline(search_ss, search_id, ';');
    if(search_id == ID) {
      std::string pid, title, description, author, author_uid, date, nSigns, tags;
      pid = search_id;
      std::getline(search_ss, title, ';');
      std::getline(search_ss, description, ';');
      std::getline(search_ss, author, ';');
      std::getline(search_ss, author_uid, ';');
      std::getline(search_ss, date, ';');
      std::getline(search_ss, nSigns, ';');
      std::getline(search_ss, tags, ';');

      if(!edit_petit.pid_.empty()) {
        pid = edit_petit.pid_;
      }
      if(!edit_petit.title_.empty()) {
        title = edit_petit.title_;
      }
      if(!edit_petit.description_.empty()) {
        description = edit_petit.description_;
      }
      if(!edit_petit.author_.empty()) {
        author = edit_petit.author_;
      }
      if(!edit_petit.author_uid_.empty()) {
        author_uid = edit_petit.author_uid_;
      }
      if(!edit_petit.date_.empty()) {
        date = edit_petit.date_;
      }
      if(!edit_petit.nSigns_.empty()) {
        nSigns = edit_petit.nSigns_;
      }
      if(!edit_petit.tags_.empty()) {
        tags = edit_petit.tags_;
      }
      line = pid + ";" + title + ";" + description + ";" + author + ";" + author_uid + ";" + date + ";" + nSigns + ";" + tags;      
      found = true;
      result_ = true;
      data_ = "edited";
    }
    temp << line << std::endl;
  }
  // deleteEmptyLinesFile("temp.txt");
  temp.close();
  file_.close();
  remove(petitions_database.c_str());
  rename("temp.txt", petitions_database.c_str());
  remove("temp.txt");

  if(!found) {
    result_ = false;
    throw std::invalid_argument("'edit' -> petition ID not found");
    return;
  }
}
