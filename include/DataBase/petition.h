#include <string>

typedef std::string Tags;

class petition {
 public:
  petition();
  petition(std::string uid, std::string title, 
           std::string description, std::string tags, std::string author,
           std::string date, std::string nSigns);
  ~petition();
 private:
  std::string uid_;
  std::string title_;
  std::string description_;
  std::string author_;
  std::string author_uid_;
  std::string date_;
  std::string nSigns_;
  Tags tags_;
};