#ifndef __USER_h__
#define __USER_h__


#include <string>
#include <string_view>
#include <iostream>

class user {
 public:
  user();
  user(std::string name, std::string email, std::string passwd, size_t account_type);
  user(std::string uid, std::string name, std::string email, std::string passwd, size_t account_type);
  friend std::ostream& operator<<(std::ostream& os, const user& u) {
    os << "UId: " << u.uid_ << "\n" << "Name: " << u.name_ << "\n" 
       << "Email: " << u.email_ << "\n" << "Password: " << u.passwd_ << "\n";
    os << "Type: " << (u.account_type_ == 0 ? "(User)" : "(Admin)");
    return os;
  }
 private:
  std::string uid_;
  std::string name_;
  std::string passwd_;
  std::string email_;
  size_t account_type_;
};

#endif