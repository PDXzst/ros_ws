// Generated by gencpp from file imu_uwb_eskf/LinktrackAoaNodeframe0.msg
// DO NOT EDIT!


#ifndef IMU_UWB_ESKF_MESSAGE_LINKTRACKAOANODEFRAME0_H
#define IMU_UWB_ESKF_MESSAGE_LINKTRACKAOANODEFRAME0_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <imu_uwb_eskf/LinktrackAoaNode0.h>

namespace imu_uwb_eskf
{
template <class ContainerAllocator>
struct LinktrackAoaNodeframe0_
{
  typedef LinktrackAoaNodeframe0_<ContainerAllocator> Type;

  LinktrackAoaNodeframe0_()
    : role(0)
    , id(0)
    , local_time(0)
    , system_time(0)
    , voltage(0.0)
    , nodes()  {
    }
  LinktrackAoaNodeframe0_(const ContainerAllocator& _alloc)
    : role(0)
    , id(0)
    , local_time(0)
    , system_time(0)
    , voltage(0.0)
    , nodes(_alloc)  {
  (void)_alloc;
    }



   typedef uint8_t _role_type;
  _role_type role;

   typedef uint8_t _id_type;
  _id_type id;

   typedef uint32_t _local_time_type;
  _local_time_type local_time;

   typedef uint32_t _system_time_type;
  _system_time_type system_time;

   typedef float _voltage_type;
  _voltage_type voltage;

   typedef std::vector< ::imu_uwb_eskf::LinktrackAoaNode0_<ContainerAllocator> , typename std::allocator_traits<ContainerAllocator>::template rebind_alloc< ::imu_uwb_eskf::LinktrackAoaNode0_<ContainerAllocator> >> _nodes_type;
  _nodes_type nodes;





  typedef boost::shared_ptr< ::imu_uwb_eskf::LinktrackAoaNodeframe0_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::imu_uwb_eskf::LinktrackAoaNodeframe0_<ContainerAllocator> const> ConstPtr;

}; // struct LinktrackAoaNodeframe0_

typedef ::imu_uwb_eskf::LinktrackAoaNodeframe0_<std::allocator<void> > LinktrackAoaNodeframe0;

typedef boost::shared_ptr< ::imu_uwb_eskf::LinktrackAoaNodeframe0 > LinktrackAoaNodeframe0Ptr;
typedef boost::shared_ptr< ::imu_uwb_eskf::LinktrackAoaNodeframe0 const> LinktrackAoaNodeframe0ConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::imu_uwb_eskf::LinktrackAoaNodeframe0_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::imu_uwb_eskf::LinktrackAoaNodeframe0_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::imu_uwb_eskf::LinktrackAoaNodeframe0_<ContainerAllocator1> & lhs, const ::imu_uwb_eskf::LinktrackAoaNodeframe0_<ContainerAllocator2> & rhs)
{
  return lhs.role == rhs.role &&
    lhs.id == rhs.id &&
    lhs.local_time == rhs.local_time &&
    lhs.system_time == rhs.system_time &&
    lhs.voltage == rhs.voltage &&
    lhs.nodes == rhs.nodes;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::imu_uwb_eskf::LinktrackAoaNodeframe0_<ContainerAllocator1> & lhs, const ::imu_uwb_eskf::LinktrackAoaNodeframe0_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace imu_uwb_eskf

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::imu_uwb_eskf::LinktrackAoaNodeframe0_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::imu_uwb_eskf::LinktrackAoaNodeframe0_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::imu_uwb_eskf::LinktrackAoaNodeframe0_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::imu_uwb_eskf::LinktrackAoaNodeframe0_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::imu_uwb_eskf::LinktrackAoaNodeframe0_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::imu_uwb_eskf::LinktrackAoaNodeframe0_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::imu_uwb_eskf::LinktrackAoaNodeframe0_<ContainerAllocator> >
{
  static const char* value()
  {
    return "0f131ffd1a11760ff33ff513bfedb13a";
  }

  static const char* value(const ::imu_uwb_eskf::LinktrackAoaNodeframe0_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x0f131ffd1a11760fULL;
  static const uint64_t static_value2 = 0xf33ff513bfedb13aULL;
};

template<class ContainerAllocator>
struct DataType< ::imu_uwb_eskf::LinktrackAoaNodeframe0_<ContainerAllocator> >
{
  static const char* value()
  {
    return "imu_uwb_eskf/LinktrackAoaNodeframe0";
  }

  static const char* value(const ::imu_uwb_eskf::LinktrackAoaNodeframe0_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::imu_uwb_eskf::LinktrackAoaNodeframe0_<ContainerAllocator> >
{
  static const char* value()
  {
    return "uint8 role\n"
"uint8 id\n"
"uint32 local_time\n"
"uint32 system_time\n"
"float32 voltage\n"
"LinktrackAoaNode0[] nodes\n"
"\n"
"================================================================================\n"
"MSG: imu_uwb_eskf/LinktrackAoaNode0\n"
"uint8 role\n"
"uint8 id\n"
"float32 dis\n"
"float32 angle\n"
"float32 fp_rssi\n"
"float32 rx_rssi\n"
;
  }

  static const char* value(const ::imu_uwb_eskf::LinktrackAoaNodeframe0_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::imu_uwb_eskf::LinktrackAoaNodeframe0_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.role);
      stream.next(m.id);
      stream.next(m.local_time);
      stream.next(m.system_time);
      stream.next(m.voltage);
      stream.next(m.nodes);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct LinktrackAoaNodeframe0_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::imu_uwb_eskf::LinktrackAoaNodeframe0_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::imu_uwb_eskf::LinktrackAoaNodeframe0_<ContainerAllocator>& v)
  {
    s << indent << "role: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.role);
    s << indent << "id: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.id);
    s << indent << "local_time: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.local_time);
    s << indent << "system_time: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.system_time);
    s << indent << "voltage: ";
    Printer<float>::stream(s, indent + "  ", v.voltage);
    s << indent << "nodes[]" << std::endl;
    for (size_t i = 0; i < v.nodes.size(); ++i)
    {
      s << indent << "  nodes[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::imu_uwb_eskf::LinktrackAoaNode0_<ContainerAllocator> >::stream(s, indent + "    ", v.nodes[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // IMU_UWB_ESKF_MESSAGE_LINKTRACKAOANODEFRAME0_H
