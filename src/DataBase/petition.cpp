#include "/home/julio/Desktop/OnlinePetition-FIS/include/DataBase/db.h"
#include "random"

db::petition::petition() = default;
db::petition::petition(std::string title,  std::string description, std::string author,
                  std::string author_uid, std::string date, std::string nSigns, Tags tags) : 
                  title_(title),
                  description_(description),
                  author_(author),
                  author_uid_(author_uid), 
                  date_(date),
                  nSigns_(nSigns),
                  tags_(tags) {
                      std::random_device dev;
                      std::mt19937 rng(dev());
                      std::uniform_int_distribution<std::mt19937::result_type> dist6(0,INT64_MAX);
                      pid_ = std::to_string(std::hash<std::string_view>{}(title + std::to_string(dist6(rng))));
                   }
db::petition::petition(std::string pid, std::string title,  std::string description, std::string author,
                  std::string author_uid, std::string date, std::string nSigns, Tags tags) : 
                  pid_(pid),
                  title_(title),
                  description_(description),
                  author_(author),
                  author_uid_(author_uid), 
                  date_(date),
                  nSigns_(nSigns),
                  tags_(tags) {}