;; Auto-generated. Do not edit!


(when (boundp 'imu_uwb_eskf::LinktrackNode6)
  (if (not (find-package "IMU_UWB_ESKF"))
    (make-package "IMU_UWB_ESKF"))
  (shadow 'LinktrackNode6 (find-package "IMU_UWB_ESKF")))
(unless (find-package "IMU_UWB_ESKF::LINKTRACKNODE6")
  (make-package "IMU_UWB_ESKF::LINKTRACKNODE6"))

(in-package "ROS")
;;//! \htmlinclude LinktrackNode6.msg.html


(defclass imu_uwb_eskf::LinktrackNode6
  :super ros::object
  :slots (_role _id _data ))

(defmethod imu_uwb_eskf::LinktrackNode6
  (:init
   (&key
    ((:role __role) 0)
    ((:id __id) 0)
    ((:data __data) (make-array 0 :initial-element 0 :element-type :char))
    )
   (send-super :init)
   (setq _role (round __role))
   (setq _id (round __id))
   (setq _data __data)
   self)
  (:role
   (&optional __role)
   (if __role (setq _role __role)) _role)
  (:id
   (&optional __id)
   (if __id (setq _id __id)) _id)
  (:data
   (&optional __data)
   (if __data (setq _data __data)) _data)
  (:serialization-length
   ()
   (+
    ;; uint8 _role
    1
    ;; uint32 _id
    4
    ;; uint8[] _data
    (* 1    (length _data)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _role
       (write-byte _role s)
     ;; uint32 _id
       (write-long _id s)
     ;; uint8[] _data
     (write-long (length _data) s)
     (princ _data s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _role
     (setq _role (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint32 _id
     (setq _id (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint8[] _data
   (let ((n (sys::peek buf ptr- :integer))) (incf ptr- 4)
     (setq _data (make-array n :element-type :char))
     (replace _data buf :start2 ptr-) (incf ptr- n))
   ;;
   self)
  )

(setf (get imu_uwb_eskf::LinktrackNode6 :md5sum-) "12433dd4216ed52aa29f9a5cb9f00380")
(setf (get imu_uwb_eskf::LinktrackNode6 :datatype-) "imu_uwb_eskf/LinktrackNode6")
(setf (get imu_uwb_eskf::LinktrackNode6 :definition-)
      "uint8 role
uint32 id
uint8[] data

")



(provide :imu_uwb_eskf/LinktrackNode6 "12433dd4216ed52aa29f9a5cb9f00380")


