#include <fstream>
#include <limits>

namespace tools {
  std::fstream& GotoLine(std::fstream& file, size_t num){
    file.seekg(std::ios::beg);
    for(int i = 0; i < num - 1; ++i){
      file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
    return file;
  }
} // namespace tools 