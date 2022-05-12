#include "../../include/DataBase/db.h"


using namespace db;

petition::petition() = default;
petition::petition(std::string title,  std::string description, std::string author,
                  std::string author_uid, std::string date, std::string nSigns, Tags tags) : 
                  title_(title),
                  description_(description),
                  author_(author),
                  author_uid_(author_uid), 
                  date_(date),
                  nSigns_(nSigns),
                  tags_(tags) {
                    pid_ = std::to_string(std::hash<std::string_view>{}(title));
                  }
petition::petition(std::string pid, std::string title,  std::string description, std::string author,
                  std::string author_uid, std::string date, std::string nSigns, Tags tags) : 
                  pid_(pid),
                  title_(title),
                  description_(description),
                  author_(author),
                  author_uid_(author_uid), 
                  date_(date),
                  nSigns_(nSigns),
                  tags_(tags) {}
const std::string& petition::get_pid() const {
  return pid_;
}
void petition::set_pid(const std::string& pid) {
  pid_ = pid;
}