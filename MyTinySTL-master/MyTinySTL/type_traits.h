#ifndef MYTINYSTL_TYPE_TRAITS_H_
#define MYTINYSTL_TYPE_TRAITS_H_

// 这个头文件用于提取类型信息

// use standard header for type_traits
#include <type_traits>

namespace mystl
{

// helper struct

template <class T, T v>//这个结构体可以用于其他类型萃取的定义和推导。
struct m_integral_constant
{
  static constexpr T value = v;//value 是其的一个静态数据成员,值为 v
};

template <bool b>
using m_bool_constant = m_integral_constant<bool, b>;//用于存储 bool 类型的值。

typedef m_bool_constant<true>  m_true_type;
typedef m_bool_constant<false> m_false_type;

/*****************************************************************************************/
// type traits

// is_pair

// --- forward declaration begin
template <class T1, class T2>
struct pair;//这是 pair 的前向声明(forward declaration),表示 pair 是一个类模板,有两个模板参数 T1 和 T2。前向声明的目的是允许在定义 is_pair 之前使用 pair 这个类型,避免编译器报错。
// --- forward declaration end

template <class T>
struct is_pair : mystl::m_false_type {};

template <class T1, class T2>
struct is_pair<mystl::pair<T1, T2>> : mystl::m_true_type {};
//通过这种特化的方式,is_pair 可以用于判断一个类型是否为 mystl::pair。如果是,is_pair 的 value 为 true,否则为 false。
//在实现通用容器和算法时,根据类型是否为 pair,我们可以做不同的处理,从而提高代码的复用性。
} // namespace mystl

#endif // !MYTINYSTL_TYPE_TRAITS_H_

