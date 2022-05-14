#ifndef __USER__
#define __USER__

#include <string>
#include <iostream>

#include "../DataBase/db.h"


namespace account {
  const size_t REGISTERED = 0;
  const size_t ADMIN = 1;
  const size_t UNREGISTERED = 2;

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

  class Unregistered : public user {
   public:
    size_t getAccountType() override { return account_type_; }
   private:
    const size_t account_type_ = UNREGISTERED;
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


#endif  // __USER__