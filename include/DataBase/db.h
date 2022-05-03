#include <iostream>
#include <variant>
#include <tuple>
#include <string>
#include <sstream>

#include "user.h"
#include "fstream"

struct query_helper {
  enum type {
    get,
    add,
    del,
    edit
  } action_t;
  std::string ID;
};

typedef std::string Petition;

const std::string database = "database.db";

namespace db {
  // database classes
  class filehandler {
   public:
    filehandler(query_helper qr);
    ~filehandler();
    bool result_ = false;
    std::variant<user, Petition> data_;
    
   private:
    std::fstream file_;
    query_helper::type action_;

    template<typename Type_> 
             std::tuple<Type_, bool> get(std::string ID);
                                bool add();
                                bool del();
                                bool edit();

    //tools 
    user wrapUser(std::string line);
  };

};