#include <string>
#include <string_view>
#include <iostream>

class user {
 public:
  user();
  user(std::string passwd, std::string name, std::string email, std::string uid = "0");
  friend std::ostream& operator<<(std::ostream& os, const user& u) {
    os << "UId: " << u.uid_ << "\n" << "Name: " << u.name_ << "\n" 
       << "Email: " << u.email_ << "\n" << "Password: " << u.passwd_;
    return os;
  }
 private:
  std::string uid_;
  std::string name_;
  std::string passwd_;
  std::string email_;
};