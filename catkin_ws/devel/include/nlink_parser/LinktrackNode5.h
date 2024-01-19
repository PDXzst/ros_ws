// Generated by gencpp from file nlink_parser/LinktrackNode5.msg
// DO NOT EDIT!


#ifndef NLINK_PARSER_MESSAGE_LINKTRACKNODE5_H
#define NLINK_PARSER_MESSAGE_LINKTRACKNODE5_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace nlink_parser
{
template <class ContainerAllocator>
struct LinktrackNode5_
{
  typedef LinktrackNode5_<ContainerAllocator> Type;

  LinktrackNode5_()
    : role(0)
    , id(0)
    , dis(0.0)
    , fp_rssi(0.0)
    , rx_rssi(0.0)  {
    }
  LinktrackNode5_(const ContainerAllocator& _alloc)
    : role(0)
    , id(0)
    , dis(0.0)
    , fp_rssi(0.0)
    , rx_rssi(0.0)  {
  (void)_alloc;
    }



   typedef uint8_t _role_type;
  _role_type role;

   typedef uint32_t _id_type;
  _id_type id;

   typedef float _dis_type;
  _dis_type dis;

   typedef float _fp_rssi_type;
  _fp_rssi_type fp_rssi;

   typedef float _rx_rssi_type;
  _rx_rssi_type rx_rssi;





  typedef boost::shared_ptr< ::nlink_parser::LinktrackNode5_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::nlink_parser::LinktrackNode5_<ContainerAllocator> const> ConstPtr;

}; // struct LinktrackNode5_

typedef ::nlink_parser::LinktrackNode5_<std::allocator<void> > LinktrackNode5;

typedef boost::shared_ptr< ::nlink_parser::LinktrackNode5 > LinktrackNode5Ptr;
typedef boost::shared_ptr< ::nlink_parser::LinktrackNode5 const> LinktrackNode5ConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::nlink_parser::LinktrackNode5_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::nlink_parser::LinktrackNode5_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::nlink_parser::LinktrackNode5_<ContainerAllocator1> & lhs, const ::nlink_parser::LinktrackNode5_<ContainerAllocator2> & rhs)
{
  return lhs.role == rhs.role &&
    lhs.id == rhs.id &&
    lhs.dis == rhs.dis &&
    lhs.fp_rssi == rhs.fp_rssi &&
    lhs.rx_rssi == rhs.rx_rssi;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::nlink_parser::LinktrackNode5_<ContainerAllocator1> & lhs, const ::nlink_parser::LinktrackNode5_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace nlink_parser

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::nlink_parser::LinktrackNode5_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::nlink_parser::LinktrackNode5_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::nlink_parser::LinktrackNode5_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::nlink_parser::LinktrackNode5_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::nlink_parser::LinktrackNode5_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::nlink_parser::LinktrackNode5_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::nlink_parser::LinktrackNode5_<ContainerAllocator> >
{
  static const char* value()
  {
    return "a9a6a698583281aaa5b8500c404c95b6";
  }

  static const char* value(const ::nlink_parser::LinktrackNode5_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xa9a6a698583281aaULL;
  static const uint64_t static_value2 = 0xa5b8500c404c95b6ULL;
};

template<class ContainerAllocator>
struct DataType< ::nlink_parser::LinktrackNode5_<ContainerAllocator> >
{
  static const char* value()
  {
    return "nlink_parser/LinktrackNode5";
  }

  static const char* value(const ::nlink_parser::LinktrackNode5_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::nlink_parser::LinktrackNode5_<ContainerAllocator> >
{
  static const char* value()
  {
    return "uint8 role\n"
"uint32 id\n"
"float32 dis\n"
"float32 fp_rssi\n"
"float32 rx_rssi\n"
;
  }

  static const char* value(const ::nlink_parser::LinktrackNode5_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::nlink_parser::LinktrackNode5_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.role);
      stream.next(m.id);
      stream.next(m.dis);
      stream.next(m.fp_rssi);
      stream.next(m.rx_rssi);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct LinktrackNode5_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::nlink_parser::LinktrackNode5_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::nlink_parser::LinktrackNode5_<ContainerAllocator>& v)
  {
    s << indent << "role: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.role);
    s << indent << "id: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.id);
    s << indent << "dis: ";
    Printer<float>::stream(s, indent + "  ", v.dis);
    s << indent << "fp_rssi: ";
    Printer<float>::stream(s, indent + "  ", v.fp_rssi);
    s << indent << "rx_rssi: ";
    Printer<float>::stream(s, indent + "  ", v.rx_rssi);
  }
};

} // namespace message_operations
} // namespace ros

#endif // NLINK_PARSER_MESSAGE_LINKTRACKNODE5_H
