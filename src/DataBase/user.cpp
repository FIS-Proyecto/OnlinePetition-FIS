#include "/home/julio/Desktop/OnlinePetition-FIS/include/DataBase/db.h"

user::user() = default;
user::user(std::string name, std::string email, std::string passwd, size_t account_type) : 
          passwd_(passwd), 
          name_(name), 
          account_type_(account_type),
          email_(email) {
            uid_ = std::to_string(std::hash<std::string_view>{}(name_));
          }
user::user(std::string uid, std::string name, std::string email, std::string passwd, size_t account_type) : 
          passwd_(passwd), 
          name_(name), 
          email_(email),
          account_type_(account_type), 
          uid_(uid) {}