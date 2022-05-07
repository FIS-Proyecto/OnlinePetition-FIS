#include <fstream>
#include <limits>

namespace tools {
  // std::fstream& GotoLine(std::fstream& file, size_t num){
  //   file.seekg(std::ios::beg);
  //   for(int i = 0; i < num - 1; ++i){
  //     file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
  //   }
  //   return file;
  // }
  //tools

  db::user wrapUser(std::string line) {
    std::stringstream ss(line);
    std::string segment, name, uid, email, passwd;
    size_t account_type;

    std::getline(ss, uid, ';');
    std::getline(ss, name, ';');
    std::getline(ss, email, ';');
    std::getline(ss, passwd, ';');
    std::getline(ss, segment, ';');
    account_type = std::stoi(segment);
    return db::user(name, email, passwd, uid, account_type);
  }
  db::petition wrapPetition(std::string line) {
    std::stringstream ss(line);
    std::string pid, title, description, author, author_uid, date, nSigns, tags; 

    std::getline(ss, pid, ';');
    std::getline(ss, title, ';');
    std::getline(ss, description, ';');
    std::getline(ss, author, ';');
    std::getline(ss, author_uid, ';');
    std::getline(ss, date, ';');
    std::getline(ss, nSigns, ';');
    std::getline(ss, tags, ';');
    return db::petition(pid, title, description, author, author_uid, date, nSigns, tags);
  }

} // namespace tools 