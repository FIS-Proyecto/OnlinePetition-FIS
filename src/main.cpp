#include "db.h"

// main function to test the database class and the filehandler class


int main() {
  db::filehandler fh({
    query_helper::type::get,
    "12039840912306"
  });

  if(fh.result_) {
    if(const user* pval = std::get_if<user>(&fh.data_))
      std::cout << "variant value: " << *pval << '\n'; 
    else 
      std::cout << "Its a petition" << '\n'; 
  }
  else 
    std::cout << "failed to get value!" << '\n'; 

}