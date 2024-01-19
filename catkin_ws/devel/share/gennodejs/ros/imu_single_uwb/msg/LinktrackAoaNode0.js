// Auto-generated. Do not edit!

// (in-package imu_single_uwb.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class LinktrackAoaNode0 {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.role = null;
      this.id = null;
      this.dis = null;
      this.angle = null;
      this.fp_rssi = null;
      this.rx_rssi = null;
    }
    else {
      if (initObj.hasOwnProperty('role')) {
        this.role = initObj.role
      }
      else {
        this.role = 0;
      }
      if (initObj.hasOwnProperty('id')) {
        this.id = initObj.id
      }
      else {
        this.id = 0;
      }
      if (initObj.hasOwnProperty('dis')) {
        this.dis = initObj.dis
      }
      else {
        this.dis = 0.0;
      }
      if (initObj.hasOwnProperty('angle')) {
        this.angle = initObj.angle
      }
      else {
        this.angle = 0.0;
      }
      if (initObj.hasOwnProperty('fp_rssi')) {
        this.fp_rssi = initObj.fp_rssi
      }
      else {
        this.fp_rssi = 0.0;
      }
      if (initObj.hasOwnProperty('rx_rssi')) {
        this.rx_rssi = initObj.rx_rssi
      }
      else {
        this.rx_rssi = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type LinktrackAoaNode0
    // Serialize message field [role]
    bufferOffset = _serializer.uint8(obj.role, buffer, bufferOffset);
    // Serialize message field [id]
    bufferOffset = _serializer.uint8(obj.id, buffer, bufferOffset);
    // Serialize message field [dis]
    bufferOffset = _serializer.float32(obj.dis, buffer, bufferOffset);
    // Serialize message field [angle]
    bufferOffset = _serializer.float32(obj.angle, buffer, bufferOffset);
    // Serialize message field [fp_rssi]
    bufferOffset = _serializer.float32(obj.fp_rssi, buffer, bufferOffset);
    // Serialize message field [rx_rssi]
    bufferOffset = _serializer.float32(obj.rx_rssi, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type LinktrackAoaNode0
    let len;
    let data = new LinktrackAoaNode0(null);
    // Deserialize message field [role]
    data.role = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [id]
    data.id = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [dis]
    data.dis = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [angle]
    data.angle = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [fp_rssi]
    data.fp_rssi = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [rx_rssi]
    data.rx_rssi = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 18;
  }

  static datatype() {
    // Returns string type for a message object
    return 'imu_single_uwb/LinktrackAoaNode0';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '14ecc209e569ea4b0a93a8b73bd0cd13';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    uint8 role
    uint8 id
    float32 dis
    float32 angle
    float32 fp_rssi
    float32 rx_rssi
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new LinktrackAoaNode0(null);
    if (msg.role !== undefined) {
      resolved.role = msg.role;
    }
    else {
      resolved.role = 0
    }

    if (msg.id !== undefined) {
      resolved.id = msg.id;
    }
    else {
      resolved.id = 0
    }

    if (msg.dis !== undefined) {
      resolved.dis = msg.dis;
    }
    else {
      resolved.dis = 0.0
    }

    if (msg.angle !== undefined) {
      resolved.angle = msg.angle;
    }
    else {
      resolved.angle = 0.0
    }

    if (msg.fp_rssi !== undefined) {
      resolved.fp_rssi = msg.fp_rssi;
    }
    else {
      resolved.fp_rssi = 0.0
    }

    if (msg.rx_rssi !== undefined) {
      resolved.rx_rssi = msg.rx_rssi;
    }
    else {
      resolved.rx_rssi = 0.0
    }

    return resolved;
    }
};

module.exports = LinktrackAoaNode0;
