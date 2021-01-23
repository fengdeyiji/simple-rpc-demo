#include "user_message.h"
#include <iostream>

namespace user{

  void message::serialize(char* const buffer, int len) const {
    memcpy(buffer, &a, sizeof(a));
  }

  void message::deserialize(const char* const buffer, int len) {
    memcpy(&a, buffer, sizeof(a));
  }

  int message::get_serialize_size() const {
    return sizeof(a);
  }

  void message::print() const {
    std::cout << a << std::endl;
  }

}