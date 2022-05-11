
#include <string>


namespace account {
  class User {
   public:
    User() = default;
    void set_uid(const std::string& uid) { uid_ = uid; }
    virtual size_t getAccountType() = 0;

    std::string name_;
    std::string passwd_;
    std::string email_;
   private:
    std::string uid_;
  };

  class Registered : public User {
   public:
    size_t getAccountType() { return account_type_; }
   private:
    size_t account_type_ = 0;
  };

  class Admin : public User {
   public:
    size_t getAccountType() { return account_type_; }
   private:
    size_t account_type_ = 1;
  };
}