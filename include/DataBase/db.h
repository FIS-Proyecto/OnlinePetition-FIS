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

#include "assert.h"

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

enum query_type {
  get,
  add,
  del,
  edit,
  filter
};

enum account_t {
  user_t,
  admin_t
};

enum u_options {
  name,
  email,
  passwd,
  account_type
};

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

  struct petition_comment {
    bool ID;
    bool petition_ID;
    bool user_ID;
    bool comment;
    bool date;
  };

  struct petition_vote {
    bool ID;
    bool petition_ID;
    bool user_ID;
    bool vote;
  };

  struct petition_tag {
    bool ID;
    bool petition_ID;
    bool tag;
  };
};

enum data_t {
  user,
  petition,
  petition_comment,
  petition_vote,
  petition_signature,
  petition_tag
};

typedef std::string Petition;
typedef std::string Tags;


const std::string users_database = "C:\\Users\\Rules\\Desktop\\OnlinePetition-FIS\\doc\\users.db";
const std::string petitions_database = "C:\\Users\\Rules\\Desktop\\OnlinePetition-FIS\\doc\\petitions.db";

namespace db {
  // database classes
  class petition {
   public:
    petition();
    petition(std::string title, 
            std::string description, std::string author,
            std::string author_uid, std::string date, 
            std::string nSigns, Tags tags);
    petition(std::string pid, std::string title, 
            std::string description, std::string author,
            std::string author_uid, std::string date, 
            std::string nSigns, Tags tags);
    friend std::ostream& operator<<(std::ostream& os, const petition& p) {
      os << p.pid_ << ";" << p.title_ << ";" << p.description_ 
         << ";" << p.author_ << ";" << p.author_uid_ << ";" << p.nSigns_ << ";" << p.date_ << ";" << p.tags_;
      return os;
    }
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
    const std::string& get_pid() const;
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

  class user {
   public:
    user();
    user(std::string name, std::string email, std::string passwd, size_t account_type);
    user(std::string uid, std::string name, std::string email, std::string passwd, size_t account_type);
    friend std::ostream& operator<<(std::ostream& os, const user& u) {
      os << u.uid_ << ";" << u.name_ << ";" << u.email_ 
         << ";" << u.passwd_ << ";" << u.account_type_;         
      return os;
    }
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
    const std::string& get_uid() const;
    void set_uid(const std::string& uid);
    std::string name_;
    std::string passwd_;
    std::string email_;
    size_t account_type_;
   private:
    std::string uid_;
  };

  class filehandler {
   public:
    filehandler(query_type qr, std::string ID, data_t ac_ty);                      // get / delete
    filehandler(query_type qr, std::string ID, db_edit::user edit_usr);            // edit user
    filehandler(query_type qr, std::string ID, db_edit::petition edit_petit);      // edit petition
    filehandler(query_type qr, user add_usr);                                      // add user
    filehandler(query_type qr, petition del_petit);                                // add user
    ~filehandler();
    bool result_ = false;
    std::string data_;
    std::vector<std::string> data_vec_;
    
   private:
    std::fstream file_;
    query_type action_;

    template<typename Type_>
    void get(std::string ID);
    template<typename Type_>
    void filter(std::string search);
    template<typename Type_>
    void add(Type_ data);
    void del(std::string ID, std::string db_name);
    void edit(std::string ID, db_edit::user edit_usr);
    void edit(std::string ID, db_edit::petition edit_petit);
  };
  
  namespace query {
    const user get_user(std::string ID);
    const petition get_petition(std::string ID);
    std::vector<user> filter_user(std::string filter);
    std::vector<petition> filter_petition(std::string filter);
    // std::string get_petition_comment(std::string ID);
    // size_t get_petition_vote(std::string ID);
    // std::string get_petition_tag(std::string ID);
    bool add_user(db::user add_usr);
    bool add_petition(db::petition add_petit);
    bool del_petition(std::string ID);
    bool del_user(std::string ID);
    bool edit_user(std::string ID, db_edit::user edit_usr);
    bool edit_petition(std::string ID, db_edit::petition edit_petit);
  }
};


#endif