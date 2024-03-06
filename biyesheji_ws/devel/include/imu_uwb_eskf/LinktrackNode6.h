// Generated by gencpp from file imu_uwb_eskf/LinktrackNode6.msg
// DO NOT EDIT!


#ifndef IMU_UWB_ESKF_MESSAGE_LINKTRACKNODE6_H
#define IMU_UWB_ESKF_MESSAGE_LINKTRACKNODE6_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace imu_uwb_eskf
{
template <class ContainerAllocator>
struct LinktrackNode6_
{
  typedef LinktrackNode6_<ContainerAllocator> Type;

  LinktrackNode6_()
    : role(0)
    , id(0)
    , data()  {
    }
  LinktrackNode6_(const ContainerAllocator& _alloc)
    : role(0)
    , id(0)
    , data(_alloc)  {
  (void)_alloc;
    }



   typedef uint8_t _role_type;
  _role_type role;

   typedef uint32_t _id_type;
  _id_type id;

   typedef std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>> _data_type;
  _data_type data;





  typedef boost::shared_ptr< ::imu_uwb_eskf::LinktrackNode6_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::imu_uwb_eskf::LinktrackNode6_<ContainerAllocator> const> ConstPtr;

}; // struct LinktrackNode6_

typedef ::imu_uwb_eskf::LinktrackNode6_<std::allocator<void> > LinktrackNode6;

typedef boost::shared_ptr< ::imu_uwb_eskf::LinktrackNode6 > LinktrackNode6Ptr;
typedef boost::shared_ptr< ::imu_uwb_eskf::LinktrackNode6 const> LinktrackNode6ConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::imu_uwb_eskf::LinktrackNode6_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::imu_uwb_eskf::LinktrackNode6_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::imu_uwb_eskf::LinktrackNode6_<ContainerAllocator1> & lhs, const ::imu_uwb_eskf::LinktrackNode6_<ContainerAllocator2> & rhs)
{
  return lhs.role == rhs.role &&
    lhs.id == rhs.id &&
    lhs.data == rhs.data;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::imu_uwb_eskf::LinktrackNode6_<ContainerAllocator1> & lhs, const ::imu_uwb_eskf::LinktrackNode6_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace imu_uwb_eskf

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::imu_uwb_eskf::LinktrackNode6_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::imu_uwb_eskf::LinktrackNode6_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::imu_uwb_eskf::LinktrackNode6_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::imu_uwb_eskf::LinktrackNode6_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::imu_uwb_eskf::LinktrackNode6_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::imu_uwb_eskf::LinktrackNode6_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::imu_uwb_eskf::LinktrackNode6_<ContainerAllocator> >
{
  static const char* value()
  {
    return "12433dd4216ed52aa29f9a5cb9f00380";
  }

  static const char* value(const ::imu_uwb_eskf::LinktrackNode6_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x12433dd4216ed52aULL;
  static const uint64_t static_value2 = 0xa29f9a5cb9f00380ULL;
};

template<class ContainerAllocator>
struct DataType< ::imu_uwb_eskf::LinktrackNode6_<ContainerAllocator> >
{
  static const char* value()
  {
    return "imu_uwb_eskf/LinktrackNode6";
  }

  static const char* value(const ::imu_uwb_eskf::LinktrackNode6_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::imu_uwb_eskf::LinktrackNode6_<ContainerAllocator> >
{
  static const char* value()
  {
    return "uint8 role\n"
"uint32 id\n"
"uint8[] data\n"
;
  }

  static const char* value(const ::imu_uwb_eskf::LinktrackNode6_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::imu_uwb_eskf::LinktrackNode6_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.role);
      stream.next(m.id);
      stream.next(m.data);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct LinktrackNode6_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::imu_uwb_eskf::LinktrackNode6_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::imu_uwb_eskf::LinktrackNode6_<ContainerAllocator>& v)
  {
    s << indent << "role: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.role);
    s << indent << "id: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.id);
    s << indent << "data[]" << std::endl;
    for (size_t i = 0; i < v.data.size(); ++i)
    {
      s << indent << "  data[" << i << "]: ";
      Printer<uint8_t>::stream(s, indent + "  ", v.data[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // IMU_UWB_ESKF_MESSAGE_LINKTRACKNODE6_H
