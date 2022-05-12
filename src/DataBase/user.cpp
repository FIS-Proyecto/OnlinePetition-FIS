#include "../../include/DataBase/db.h"


using namespace db;

user::user() = default;
user::user(std::string name, std::string email, std::string passwd, size_t account_type) : 
          name_(name), 
          account_type_(account_type),
          email_(email) {
            uid_ = std::to_string(std::hash<std::string_view>{}(email));
            passwd_ = std::to_string(std::hash<std::string_view>{}(passwd + uid_));
          }
user::user(std::string uid, std::string name, std::string email, std::string passwd, size_t account_type) : 
          passwd_(passwd), 
          name_(name), 
          email_(email),
          account_type_(account_type), 
          uid_(uid) {}
const std::string& user::get_uid() const {
  return uid_;
}
void user::set_uid(const std::string& uid) {
  uid_ = uid;
}