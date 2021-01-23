
#ifndef COMPILE_RELECTOR_H
#define COMPILE_RELECTOR_H
#include <cstdint>
#define NEED_DECLARATION
#include "user_declare.h"
#undef NEED_DECLARATION
namespace rpc {

template <typename T>
class __TypeMapper {};

template <int ID>
class __IDMapper {};

#define REGISTE_TYPE_ID(T, ID) \
template <>\
class __TypeMapper<T> {\
public:\
  static const std::uint64_t id = ID;\
};\
template <>\
class __IDMapper<ID> {\
public:\
  typedef T type;\
};

#define GET_TYPE(ID) __IDMapper<ID>::type
#define GET_ID(T) __TypeMapper<T>::id

#define USER_REGISTER(T, ID) REGISTE_TYPE_ID(T, ID)
#define NEED_REGISTER
#include "user_declare.h"
#undef NEED_REGISTER
#undef USER_REGISTER

}// namespace rpc
#endif