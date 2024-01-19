;; Auto-generated. Do not edit!


(when (boundp 'imu_single_uwb::LinktrackNodeframe6)
  (if (not (find-package "IMU_SINGLE_UWB"))
    (make-package "IMU_SINGLE_UWB"))
  (shadow 'LinktrackNodeframe6 (find-package "IMU_SINGLE_UWB")))
(unless (find-package "IMU_SINGLE_UWB::LINKTRACKNODEFRAME6")
  (make-package "IMU_SINGLE_UWB::LINKTRACKNODEFRAME6"))

(in-package "ROS")
;;//! \htmlinclude LinktrackNodeframe6.msg.html


(defclass imu_single_uwb::LinktrackNodeframe6
  :super ros::object
  :slots (_role _id _nodes ))

(defmethod imu_single_uwb::LinktrackNodeframe6
  (:init
   (&key
    ((:role __role) 0)
    ((:id __id) 0)
    ((:nodes __nodes) ())
    )
   (send-super :init)
   (setq _role (round __role))
   (setq _id (round __id))
   (setq _nodes __nodes)
   self)
  (:role
   (&optional __role)
   (if __role (setq _role __role)) _role)
  (:id
   (&optional __id)
   (if __id (setq _id __id)) _id)
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
    ;; uint8 _role
    1
    ;; uint32 _id
    4
    ;; imu_single_uwb/LinktrackNode6[] _nodes
    (apply #'+ (send-all _nodes :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _role
       (write-byte _role s)
     ;; uint32 _id
       (write-long _id s)
     ;; imu_single_uwb/LinktrackNode6[] _nodes
     (write-long (length _nodes) s)
     (dolist (elem _nodes)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _role
     (setq _role (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint32 _id
     (setq _id (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; imu_single_uwb/LinktrackNode6[] _nodes
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _nodes (let (r) (dotimes (i n) (push (instance imu_single_uwb::LinktrackNode6 :init) r)) r))
     (dolist (elem- _nodes)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(setf (get imu_single_uwb::LinktrackNodeframe6 :md5sum-) "1a03d588826898748d603f388e814eb2")
(setf (get imu_single_uwb::LinktrackNodeframe6 :datatype-) "imu_single_uwb/LinktrackNodeframe6")
(setf (get imu_single_uwb::LinktrackNodeframe6 :definition-)
      "uint8 role
uint32 id
LinktrackNode6[] nodes

================================================================================
MSG: imu_single_uwb/LinktrackNode6
uint8 role
uint32 id
uint8[] data

")



(provide :imu_single_uwb/LinktrackNodeframe6 "1a03d588826898748d603f388e814eb2")


