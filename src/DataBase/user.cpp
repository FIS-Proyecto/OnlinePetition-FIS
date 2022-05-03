#include "user.h"

user::user() = default;
user::user(std::string name, std::string email, std::string passwd, std::string uid) : 
          passwd_(passwd), 
          name_(name), 
          email_(email), 
          uid_(uid) {
            uid_ = std::to_string(std::hash<std::string_view>{}(name_));
          }