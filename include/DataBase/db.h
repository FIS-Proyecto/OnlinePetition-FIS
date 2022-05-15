#ifndef __DB_h__
#define __DB_h__

#include <iostream>
#include <variant>
#include <tuple>
#include <string>
#include <string_view>
#include <sstream>
#include <vector>
#include <fstream>
#include <random>
#include <filesystem>

#include "assert.h"


// Define utils for edit options
#define name(new_d)         sp_user(u_options::name,             new_d)
#define email(new_d)        sp_user(u_options::email,            new_d)
#define passwd(new_d)       sp_user(u_options::passwd,           new_d)
#define account_type(new_d) sp_user(u_options::account_type,     new_d)
#define pid(new_d)          sp_petition(p_options::pid,          new_d)
#define title(new_d)        sp_petition(p_options::title,        new_d)
#define description(new_d)  sp_petition(p_options::description,  new_d)
#define author(new_d)       sp_petition(p_options::author,       new_d)
#define author_uid(new_d)   sp_petition(p_options::author_uid,   new_d)
#define date(new_d)         sp_petition(p_options::date,         new_d)
#define n_signs(new_d)      sp_petition(p_options::nSigns,       new_d)
#define tags(new_d)         sp_petition(p_options::tags,         new_d)

// Query types
enum query_type {
  get,
  add,
  del,
  edit,
  filter
};

// Account types
enum account_t {
  user_t,
  admin_t
};

// User options
enum u_options {
  name,
  email,
  passwd,
  account_type
};

// Petition options
enum p_options {
  pid,
  title,
  description,
  author,
  author_uid,
  date,
  nSigns,
  tags
};

// Edit contructor for easy handling of edit options for petitions and users (see below)
namespace edit_config {
  struct sp_user {
    sp_user(u_options ops, std::string data) : opt_(ops), data_(data) {}
    std::string data_;
    u_options opt_;
  };

  struct sp_petition {
    sp_petition(p_options ops, std::string data) : opt_(ops), data_(data) {}
    std::string data_;
    p_options opt_;
  };
}

using namespace edit_config;

// Edit configuration that uses edit_config::sp_user and edit_config::sp_petition
namespace db_edit {
  struct user {
    user(std::vector<edit_config::sp_user> opt) {
      for(auto& sls : opt) {
        switch(sls.opt_) {
          case name:
            name_ = sls.data_;
            break;
          case email:
            email_ = sls.data_;
            break;
          case passwd:
            passwd_ = sls.data_;
            break;
          case account_type:
            account_type_ = sls.data_;
            break;
        }
      }
    }
    std::string UID_;
    std::string name_;
    std::string email_;
    std::string passwd_;
    std::string account_type_;
  };

  struct petition {
    petition(std::vector<edit_config::sp_petition> opt) {
      for(auto& sls : opt) {
        switch(sls.opt_) {
          case pid:
            pid_ = sls.data_;
            break;
          case title:
            title_ = sls.data_;
            break;
          case description:
            description_ = sls.data_;
            break;
          case author:
            author_ = sls.data_;
            break;
          case author_uid:
            author_uid_ = sls.data_;
            break;
          case date:
            date_ = sls.data_;
            break;
          case nSigns:
            nSigns_ = sls.data_;
            break;
          case tags:
            tags_ = sls.data_;
            break;
        }
      }
    }
    std::string pid_;
    std::string title_;
    std::string description_;
    std::string author_;
    std::string author_uid_;
    std::string date_;
    std::string nSigns_;
    std::string tags_;
  };

// Query for petition comments
  struct petition_comment {
    bool ID;
    bool petition_ID;
    bool user_ID;
    bool comment;
    bool date;
  };
 
  // Query for petition signatures
  struct petition_vote {
    bool ID;
    bool petition_ID;
    bool user_ID;
    bool vote;
  };

  // Query for petition tags
  struct petition_tag {
    bool ID;
    bool petition_ID;
    bool tag;
  };
};

// Data for type of queries
enum data_t {
  user,
  petition,
  petition_comment,
  petition_vote,
  petition_signature,
  petition_tag
};

typedef std::string Tags;


// Database file directories and files
const std::string users_database = std::filesystem::current_path().string() + "/doc/users.db";
const std::string petitions_database = std::filesystem::current_path().string()+ "/doc/petitions.db";


// Namespace for database entries
namespace db {
  // Database petition class
  class petition {
   public:
    petition();
    // Constructor for petition without PID
    petition(std::string title, 
            std::string description, std::string author,
            std::string author_uid, std::string date, 
            std::string nSigns, Tags tags);
    // Constructor for petition with PID
    petition(std::string pid, std::string title, 
            std::string description, std::string author,
            std::string author_uid, std::string date, 
            std::string nSigns, Tags tags);
    // Overload incersion operator to print a petition with the datbase format
    friend std::ostream& operator<<(std::ostream& os, const petition& p) {
      os << p.pid_ << ";" << p.title_ << ";" << p.description_ 
         << ";" << p.author_ << ";" << p.author_uid_ << ";" << p.nSigns_ << ";" << p.date_ << ";" << p.tags_;
      return os;
    }
    // Overload extraction operator to read a petition with the database format
    friend std::basic_string<char>& operator<<(std::basic_string<char>& os, const petition& p) {
      os += p.pid_;
      os += ";";
      os += p.title_;
      os += ";";
      os += p.description_;
      os += ";";
      os += p.author_;
      os += ";";
      os += p.author_uid_;
      os += ";";
      os += p.nSigns_;
      os += ";";
      os += p.date_;
      os += ";";
      os += p.tags_;
      os += ";";
      return os;
    }
    // Function to get the constant petition ID
    const std::string& get_pid() const;
    // Function to set the petition ID
    void set_pid(const std::string& pid);
    std::string title_;
    std::string description_;
    std::string author_;
    std::string author_uid_;
    std::string date_;
    std::string nSigns_;
    Tags tags_;
   private:
    std::string pid_;
  };

  // Database user class
  class user {
   public:
    user();
    // Constructor for user without UID
    user(std::string name, std::string email, std::string passwd, size_t account_type);
    // Constructor for user with UID
    user(std::string uid, std::string name, std::string email, std::string passwd, size_t account_type);
    // Overload incersion operator to print a user with the database format
    friend std::ostream& operator<<(std::ostream& os, const user& u) {
      os << u.uid_ << ";" << u.name_ << ";" << u.email_ 
         << ";" << u.passwd_ << ";" << u.account_type_;         
      return os;
    }
    // Overload extraction operator to read a user with the database format
    friend std::basic_string<char>& operator<<(std::basic_string<char>& os, const user& u) {
      os += u.uid_;
      os += ";";
      os += u.name_;
      os += ";";
      os += u.email_;
      os += ";";
      os += u.passwd_;
      os += ";";
      os += std::to_string(u.account_type_);
      return os;
    }

    // Function to get the constant user ID
    const std::string& get_uid() const;
    // Function to set the user ID
    void set_uid(const std::string& uid);
    std::string name_;
    std::string passwd_;
    std::string email_;
    size_t account_type_;
   private:
    std::string uid_;
  };

  // Database class that handles every query to the database and returns the results in a friendly way
  class filehandler {
   public:
    // Constructor for the a 'get' query
    filehandler(query_type qr, std::string ID, data_t ac_ty);                      // get / delete
    // Constructor for the 'edit user' query
    filehandler(query_type qr, std::string ID, db_edit::user edit_usr);            // edit user
    // Constructor for the 'edit petition' query
    filehandler(query_type qr, std::string ID, db_edit::petition edit_petit);      // edit petition
    // Constructor for the 'add user' query
    filehandler(query_type qr, user add_usr);                                      // add user
    // Constructor for the 'add petition' query
    filehandler(query_type qr, petition del_petit);                                // add user
    ~filehandler();
    // Public information for the returned data after the query
    bool result_ = false;
    std::string data_;
    std::vector<std::string> data_vec_;
    
   private:
    std::fstream file_;
    query_type action_;

    // Function to get the data from the database
    template<typename Type_>
    void get(std::string ID);
    // Function to filter the data from the database
    template<typename Type_>
    void filter(std::string search);
    // Function to add the data in the database
    template<typename Type_>
    void add(Type_ data);
    // Function to delete the data in the database
    void del(std::string ID, std::string db_name);
    // Function to edit a user in the database
    void edit(std::string ID, db_edit::user edit_usr);
    // Function to edit a petition in the database
    void edit(std::string ID, db_edit::petition edit_petit);
  };

  // Database query for an easier way to handle queries
  namespace query {
    // Query handler for getting a user from the database
    const user get_user(std::string ID);
    // Query handler for getting a petition from the database
    const petition get_petition(std::string ID);
    // Query handler for filtering users from the database
    std::vector<user> filter_user(std::string filter);
    // Query handler for filtering petitions from the database
    std::vector<petition> filter_petition(std::string filter);
          // std::string get_petition_comment(std::string ID);
          // size_t get_petition_vote(std::string ID);
          // std::string get_petition_tag(std::string ID);
    // Query handler for adding a user to the database
    bool add_user(db::user add_usr);
    // Query handler for adding a petition to the database
    bool add_petition(db::petition add_petit);
    // Query handler for deleting a user from the database
    bool del_petition(std::string ID);
    // Query handler for deleting a petition from the database
    bool del_user(std::string ID);
    // Query handler for editing a user in the database
    bool edit_user(std::string ID, db_edit::user edit_usr);
    // Query handler for editing a petition in the database
    bool edit_petition(std::string ID, db_edit::petition edit_petit);
  }
};


#endif