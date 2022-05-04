#include "/home/julio/Desktop/OnlinePetition-FIS/include/DataBase/db.h"

// main function to test the database class and the filehandler class


int main() {
  db::filehandler fh({
    query_helper::type::get,
    "0000000000000006"
  });

  if(fh.result_) {
    if(const user* pval = std::get_if<user>(&fh.data_))
      std::cout << *pval << '\n'; 
    else 
      std::cout << "Its a petition" << '\n'; 
  }
  else 
    std::cout << "failed to get value!" << '\n'; 

}