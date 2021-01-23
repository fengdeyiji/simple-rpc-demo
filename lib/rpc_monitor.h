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
  int data_len = msg.get_serialize_size();
  memcpy(&buffer[pos], &data_len, sizeof(data_len));
  pos += sizeof(data_len);
  msg.serialize(&buffer[pos], len - pos);
}

}// namespace rpc
#endif