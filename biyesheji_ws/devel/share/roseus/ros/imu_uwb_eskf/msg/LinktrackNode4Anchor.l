;; Auto-generated. Do not edit!


(when (boundp 'imu_uwb_eskf::LinktrackNode4Anchor)
  (if (not (find-package "IMU_UWB_ESKF"))
    (make-package "IMU_UWB_ESKF"))
  (shadow 'LinktrackNode4Anchor (find-package "IMU_UWB_ESKF")))
(unless (find-package "IMU_UWB_ESKF::LINKTRACKNODE4ANCHOR")
  (make-package "IMU_UWB_ESKF::LINKTRACKNODE4ANCHOR"))

(in-package "ROS")
;;//! \htmlinclude LinktrackNode4Anchor.msg.html


(defclass imu_uwb_eskf::LinktrackNode4Anchor
  :super ros::object
  :slots (_id _dis ))

(defmethod imu_uwb_eskf::LinktrackNode4Anchor
  (:init
   (&key
    ((:id __id) 0)
    ((:dis __dis) 0.0)
    )
   (send-super :init)
   (setq _id (round __id))
   (setq _dis (float __dis))
   self)
  (:id
   (&optional __id)
   (if __id (setq _id __id)) _id)
  (:dis
   (&optional __dis)
   (if __dis (setq _dis __dis)) _dis)
  (:serialization-length
   ()
   (+
    ;; uint8 _id
    1
    ;; float32 _dis
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _id
       (write-byte _id s)
     ;; float32 _dis
       (sys::poke _dis (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _id
     (setq _id (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; float32 _dis
     (setq _dis (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get imu_uwb_eskf::LinktrackNode4Anchor :md5sum-) "3449514afa3f54cb0e542c3e3a394e77")
(setf (get imu_uwb_eskf::LinktrackNode4Anchor :datatype-) "imu_uwb_eskf/LinktrackNode4Anchor")
(setf (get imu_uwb_eskf::LinktrackNode4Anchor :definition-)
      "uint8 id
float32 dis

")



(provide :imu_uwb_eskf/LinktrackNode4Anchor "3449514afa3f54cb0e542c3e3a394e77")


