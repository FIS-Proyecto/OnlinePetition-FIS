#include <fstream>
#include <string>

// [0-49] UIDs
// [50-INF] Petitions data
/**
 * PetitionID
 * Contenido
 * Contenido
 * Titulo
 * Fecha
 * OwnerID
 * Numero de votos
 * Comentarios????????
 * Tags
 * BLANK
 */
 
const std::string database = "database.db";

class filehandler {
 public:
  filehandler();
  
  template<class Type_>
  Type_ get();
  
  bool add();

  bool del();

  bool close();

 private:
  std::fstream file_;
};