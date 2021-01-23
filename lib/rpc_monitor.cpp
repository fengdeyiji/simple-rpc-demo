#include "rpc_monitor.h"
#define NEED_DEFINE
#include "user_declare.h"
#undef NEED_DEFINE

namespace rpc {

void Monitor::receive_and_process(char* buffer, int len) {// 未考虑缓冲区溢出
  int pos = 0;
  uint64_t msg_id = 0;
  int data_len = 0;
  memcpy(&msg_id, &buffer[pos], sizeof(msg_id));
  pos += sizeof(msg_id);
  memcpy(&data_len, &buffer[pos], sizeof(data_len));
  pos += sizeof(data_len);
  switch (msg_id) {
    #define USER_REGISTER(T, ID) \
    case ID:\
    {\
    GET_TYPE(ID) msg;\
    msg.deserialize(&buffer[pos], len - pos);\
    MessageProcesser<GET_TYPE(ID)> p;\
    p.process(msg);\
    }\
    break;
    #define NEED_REGISTER
    #include "user_declare.h"
    #undef NEED_REGISTER
    #undef USER_REGISTER
  default:
    break;
  }
}

}// namespace rpc