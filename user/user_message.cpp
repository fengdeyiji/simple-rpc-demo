#include "user_message.h"
#include <iostream>

namespace user{

  void message::serialize(char* const buffer, int len) const {
    memcpy(buffer, &v_, sizeof(v_));
  }

  void message::deserialize(const char* const buffer, int len) {
    memcpy(&v_, buffer, sizeof(v_));
  }

  void message::set_v(int v) {
    v_ = v;
  }

  void message::print() const {
    std::cout << v_ << std::endl;
  }

}