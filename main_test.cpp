#include "user_message.h"
#include "rpc_monitor.h"

constexpr int buffer_len = 1024;

int main() {
  char buffer[buffer_len];
  user::message msg;
  rpc::Monitor::send(msg, buffer, buffer_len);// 模拟消息发送
  rpc::Monitor::receive_and_process(buffer, buffer_len);// 模拟消息接受和处理
  return 0;
}