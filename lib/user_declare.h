#ifdef NEED_DEFINE
// 用户的消息定义头文件
// 用于反序列化时可以知道具体的消息结构体类型
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
