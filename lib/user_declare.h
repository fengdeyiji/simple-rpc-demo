#ifdef NEED_DEFINE
// the header file including user data structure definition
// for 反序列化
#include "user_message.h"
#endif

#ifdef NEED_DECLARATION
// user‘s data forward declaration
// for 模版特化
namespace user {
 class message;
}
#endif

#ifdef NEED_REGISTER
// user‘s data register micro.
// make sure every assigned ID unique, or compile error.
// for 消息ID分配
#define REGISTER(T, ID) USER_REGISTER(T, ID)
REGISTER(user::message, 1)
#undef REGISTER
#endif
