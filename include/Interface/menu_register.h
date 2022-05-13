#include "../Logic/register.h"

bool menu_register() {
  std::string name, email, passwd;
  std::cout << "Nombre:\n> ";
  std::cin >> name;
  std::cout << "Email:\n> ";
  std::cin >> email;
  std::cout << "Contraseña:\n> ";
  std::cin >> passwd;
  
  return register_function(name, email, passwd); 
}