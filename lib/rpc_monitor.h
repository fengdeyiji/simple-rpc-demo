#ifndef RPC_MONITOR_H
#define RPC_MONITOR_H
#include "compile_reflector.h"
#include <string.h>

namespace rpc {

template <typename T>
class MessageProcesser {};

struct Monitor {
  template<typename T>
  static void send(const T &msg, char* buffer, int len);
  static void receive_and_process(char* buffer, int len);
};

template<typename T>
void Monitor::send(const T &msg, char* buffer, int len) {// 未考虑缓冲区溢出
  uint64_t id = GET_ID(T);
  int pos = 0;
  memcpy(&buffer[pos], &id, sizeof(id));
  pos += sizeof(id);
  msg.serialize(&buffer[pos], len - pos);
}

}// namespace rpc
#endif