#include "C:\Users\Rules\Desktop\OnlinePetition-FIS\include\DataBase\db.h"

using namespace db;

user::user() = default;
user::user(std::string name, std::string email, std::string passwd, size_t account_type) : 
          passwd_(passwd), 
          name_(name), 
          account_type_(account_type),
          email_(email) {
            std::random_device dev;
            std::mt19937 rng(dev());
            std::uniform_int_distribution<std::mt19937::result_type> dist6(0,4294967295);
            uid_ = std::to_string(std::hash<std::string_view>{}(name + std::to_string(dist6(rng))));
          }
user::user(std::string uid, std::string name, std::string email, std::string passwd, size_t account_type) : 
          passwd_(passwd), 
          name_(name), 
          email_(email),
          account_type_(account_type), 
          uid_(uid) {}