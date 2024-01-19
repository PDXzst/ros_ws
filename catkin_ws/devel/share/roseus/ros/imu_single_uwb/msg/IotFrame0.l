;; Auto-generated. Do not edit!


(when (boundp 'imu_single_uwb::IotFrame0)
  (if (not (find-package "IMU_SINGLE_UWB"))
    (make-package "IMU_SINGLE_UWB"))
  (shadow 'IotFrame0 (find-package "IMU_SINGLE_UWB")))
(unless (find-package "IMU_SINGLE_UWB::IOTFRAME0")
  (make-package "IMU_SINGLE_UWB::IOTFRAME0"))

(in-package "ROS")
;;//! \htmlinclude IotFrame0.msg.html


(defclass imu_single_uwb::IotFrame0
  :super ros::object
  :slots (_uid _system_time _io_status _nodes ))

(defmethod imu_single_uwb::IotFrame0
  (:init
   (&key
    ((:uid __uid) 0)
    ((:system_time __system_time) 0)
    ((:io_status __io_status) 0)
    ((:nodes __nodes) ())
    )
   (send-super :init)
   (setq _uid (round __uid))
   (setq _system_time (round __system_time))
   (setq _io_status (round __io_status))
   (setq _nodes __nodes)
   self)
  (:uid
   (&optional __uid)
   (if __uid (setq _uid __uid)) _uid)
  (:system_time
   (&optional __system_time)
   (if __system_time (setq _system_time __system_time)) _system_time)
  (:io_status
   (&optional __io_status)
   (if __io_status (setq _io_status __io_status)) _io_status)
  (:nodes
   (&rest __nodes)
   (if (keywordp (car __nodes))
       (send* _nodes __nodes)
     (progn
       (if __nodes (setq _nodes (car __nodes)))
       _nodes)))
  (:serialization-length
   ()
   (+
    ;; uint32 _uid
    4
    ;; uint32 _system_time
    4
    ;; uint8 _io_status
    1
    ;; imu_single_uwb/IotFrame0Node[] _nodes
    (apply #'+ (send-all _nodes :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint32 _uid
       (write-long _uid s)
     ;; uint32 _system_time
       (write-long _system_time s)
     ;; uint8 _io_status
       (write-byte _io_status s)
     ;; imu_single_uwb/IotFrame0Node[] _nodes
     (write-long (length _nodes) s)
     (dolist (elem _nodes)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint32 _uid
     (setq _uid (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint32 _system_time
     (setq _system_time (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint8 _io_status
     (setq _io_status (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; imu_single_uwb/IotFrame0Node[] _nodes
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _nodes (let (r) (dotimes (i n) (push (instance imu_single_uwb::IotFrame0Node :init) r)) r))
     (dolist (elem- _nodes)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(setf (get imu_single_uwb::IotFrame0 :md5sum-) "8854697b4ab999e932111a65ada95ab0")
(setf (get imu_single_uwb::IotFrame0 :datatype-) "imu_single_uwb/IotFrame0")
(setf (get imu_single_uwb::IotFrame0 :definition-)
      "uint32 uid
uint32 system_time
uint8 io_status
IotFrame0Node[] nodes

================================================================================
MSG: imu_single_uwb/IotFrame0Node
uint32 uid
float32 dis
float32 aoa_angle_horizontal
float32 aoa_angle_vertical
float32 fp_rssi
float32 rx_rssi
string user_data

")



(provide :imu_single_uwb/IotFrame0 "8854697b4ab999e932111a65ada95ab0")


