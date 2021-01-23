#ifndef USER_MESSAGE_H
#define USER_MESSAGE_H
#include "rpc_monitor.h"

namespace user{
  // 定义消息
  struct message {
    // 消息的序列化
    void serialize(char* const buffer, int len) const;
    // 消息的反序列化
    void deserialize(const char* const buffer, int len);
    void print() const;
    void set_v(int v);
  private:
    int v_ = 0;
  };
}
namespace rpc{
  // 定义消息的接收处理行为
  template <>
  struct MessageProcesser<user::message>{
    void process(user::message &msg) {
      msg.print();
    }
  };
}
#endif