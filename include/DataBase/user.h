
#include <string>


class user {
 public:
  user(std::string uid, std::string passwd, std::string name = "");
 private:
  std::string uid_;
  std::string name_;
  std::string passwd_;
};