# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from imu_uwb_eskf/LinktrackNodeframe5.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import imu_uwb_eskf.msg

class LinktrackNodeframe5(genpy.Message):
  _md5sum = "26bd069cbc20641e42df0ae46b96110c"
  _type = "imu_uwb_eskf/LinktrackNodeframe5"
  _has_header = False  # flag to mark the presence of a Header object
  _full_text = """uint8 role
uint32 id
uint32 local_time
uint32 system_time
float32 voltage
LinktrackNode5[] nodes

================================================================================
MSG: imu_uwb_eskf/LinktrackNode5
uint8 role
uint32 id
float32 dis
float32 fp_rssi
float32 rx_rssi
"""
  __slots__ = ['role','id','local_time','system_time','voltage','nodes']
  _slot_types = ['uint8','uint32','uint32','uint32','float32','imu_uwb_eskf/LinktrackNode5[]']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       role,id,local_time,system_time,voltage,nodes

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(LinktrackNodeframe5, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.role is None:
        self.role = 0
      if self.id is None:
        self.id = 0
      if self.local_time is None:
        self.local_time = 0
      if self.system_time is None:
        self.system_time = 0
      if self.voltage is None:
        self.voltage = 0.
      if self.nodes is None:
        self.nodes = []
    else:
      self.role = 0
      self.id = 0
      self.local_time = 0
      self.system_time = 0
      self.voltage = 0.
      self.nodes = []

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_get_struct_B3If().pack(_x.role, _x.id, _x.local_time, _x.system_time, _x.voltage))
      length = len(self.nodes)
      buff.write(_struct_I.pack(length))
      for val1 in self.nodes:
        _x = val1
        buff.write(_get_struct_BI3f().pack(_x.role, _x.id, _x.dis, _x.fp_rssi, _x.rx_rssi))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    if python3:
      codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      if self.nodes is None:
        self.nodes = None
      end = 0
      _x = self
      start = end
      end += 17
      (_x.role, _x.id, _x.local_time, _x.system_time, _x.voltage,) = _get_struct_B3If().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.nodes = []
      for i in range(0, length):
        val1 = imu_uwb_eskf.msg.LinktrackNode5()
        _x = val1
        start = end
        end += 17
        (_x.role, _x.id, _x.dis, _x.fp_rssi, _x.rx_rssi,) = _get_struct_BI3f().unpack(str[start:end])
        self.nodes.append(val1)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_get_struct_B3If().pack(_x.role, _x.id, _x.local_time, _x.system_time, _x.voltage))
      length = len(self.nodes)
      buff.write(_struct_I.pack(length))
      for val1 in self.nodes:
        _x = val1
        buff.write(_get_struct_BI3f().pack(_x.role, _x.id, _x.dis, _x.fp_rssi, _x.rx_rssi))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    if python3:
      codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      if self.nodes is None:
        self.nodes = None
      end = 0
      _x = self
      start = end
      end += 17
      (_x.role, _x.id, _x.local_time, _x.system_time, _x.voltage,) = _get_struct_B3If().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.nodes = []
      for i in range(0, length):
        val1 = imu_uwb_eskf.msg.LinktrackNode5()
        _x = val1
        start = end
        end += 17
        (_x.role, _x.id, _x.dis, _x.fp_rssi, _x.rx_rssi,) = _get_struct_BI3f().unpack(str[start:end])
        self.nodes.append(val1)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_B3If = None
def _get_struct_B3If():
    global _struct_B3If
    if _struct_B3If is None:
        _struct_B3If = struct.Struct("<B3If")
    return _struct_B3If
_struct_BI3f = None
def _get_struct_BI3f():
    global _struct_BI3f
    if _struct_BI3f is None:
        _struct_BI3f = struct.Struct("<BI3f")
    return _struct_BI3f
