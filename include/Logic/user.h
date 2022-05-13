#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>

#include "../DataBase/db.h"

#define ADMIN 1
#define REGISTERED 0

namespace account {
  class user {
   public:
    user() = default;
    user& operator=(const db::user& data_user) {
      data_ = data_user;
      return *this;
    }
    void set_uid(const std::string& uid) { data_.set_uid(uid); }
    virtual size_t getAccountType() = 0;
    
    db::user data_;
  };

  class Registered : public user {
   public:
    size_t getAccountType() { return account_type_; }
   private:
    const size_t account_type_ = REGISTERED;
  };

  class Admin : public user {
   public:
    size_t getAccountType() { return account_type_; }
   private:
    const size_t account_type_ = ADMIN;
  };
}

#endif