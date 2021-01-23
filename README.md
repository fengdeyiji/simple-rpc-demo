# simple-rpc-demo
A demo using c++ meta programming implement compile reflection and rpc.  
简单的使用方式，只需要一二三齐步走：  
1，定义消息和消息的接受处理
```c++
// user/user_message.h
// 定义消息
namespace user{
  // 定义消息
  struct message {
    // 消息的序列化
    void serialize(char* const buffer, int len) const;
    // 消息的反序列化
    void deserialize(const char* const buffer, int len);
    void print() const;
  private:
    int a = 12345;
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
```
2，将消息的相关信息注册到rpc模块中：  
```c++
//在lib/user_declare.h中注册用户消息的相关信息
#ifdef NEED_DEFINE
// 用户的消息定义头文件
// 用于反序列化时可以知道具体的消息结构
#include "user_message.h"
#endif

#ifdef NEED_DECLARATION
// 用户消息的前向声明
// 用于模版偏特化
namespace user {
 class message;
}
#endif

#ifdef NEED_REGISTER
// 用户为自己的消息选择一个ID
// 用于rpc框架区分不同的消息
#define REGISTER(T, ID) USER_REGISTER(T, ID)
REGISTER(user::message, 1)
#undef REGISTER
#endif
```
3，使用这个消息：  
```c++
int main() {
  char buffer[buffer_len];
  user::message msg;
  msg.set_v(12345);
  rpc::Monitor::send(msg, buffer, buffer_len);// 模拟消息发送
  rpc::Monitor::receive_and_process(buffer, buffer_len);// 模拟消息接受和处理
  return 0;
}
```
output：
```
~/Desktop/code/simple-rpc-demo   main ● ?  make        ✔  1406  23:36:41
g++ main_test.cpp ./lib/rpc_monitor.cpp ./user/user_message.cpp -I./lib/ -I./user -std=c++11 -o test
 ~/Desktop/code/simple-rpc-demo   main ● ?  ./test      ✔  1407  23:36:54
12345
```