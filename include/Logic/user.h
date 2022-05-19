#ifndef __USER__
#define __USER__

#include <string>
#include <iostream>

#include "../DataBase/db.h"

namespace account {
  const size_t REGISTERED = 0;
  const size_t ADMIN = 1;
  const size_t UNREGISTERED = 2;
  // User class that contains the user data
  class user {
   public:
    user() = default;
    user& operator=(const db::user& data_user) {
      data_ = data_user;
      return *this;
    }
    void set_uid(const std::string& uid) { data_.set_uid(uid); }
    virtual size_t getAccountType() = 0;
    virtual bool delete_petition() = 0;
    
    db::user data_;
  };

  // Unregistered class that contains the user data
  class Unregistered : public user {
   public:
    Unregistered() {
      data_.set_uid("");
      data_.passwd_ = "";
      data_.account_type_ = UNREGISTERED;
    }
    size_t getAccountType() override { return account_type_; }
    bool delete_petition() override { 
      std::cout << "You must be logged in to delete petitions\n";
      return false; 
    }
   private:
    const size_t account_type_ = UNREGISTERED;
  };

  // Registered class that contains the user data
  class Registered : public user {
   public:
    Registered() {
      data_.account_type_ = REGISTERED;
    }
    size_t getAccountType() { return account_type_; }
    bool delete_petition() override { return true; }
   private:
    const size_t account_type_ = REGISTERED;
  };

  // Admin class that contains the user data
  class Admin : public user {
   public:
    Admin() {
      data_.account_type_ = ADMIN;
    }
    size_t getAccountType() { return account_type_; }
    bool delete_petition() override { return true; }
   private:
    const size_t account_type_ = ADMIN;
  };
}


#endif  // __USER__