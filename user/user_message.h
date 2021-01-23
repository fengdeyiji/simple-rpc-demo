#ifndef USER_MESSAGE_H
#define USER_MESSAGE_H
#include "rpc_monitor.h"

namespace user{
  struct message {
    void serialize(char* const buffer, int len) const;
    void deserialize(const char* const buffer, int len);
    int get_serialize_size() const;
    void print() const;
  private:
    int a = 12345;
  };
}
namespace rpc{
  template <>
  struct MessageProcesser<user::message>{
    void process(user::message &msg) {
      msg.print();
    }
  };
}
#endif