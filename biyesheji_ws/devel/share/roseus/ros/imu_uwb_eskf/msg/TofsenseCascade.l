;; Auto-generated. Do not edit!


(when (boundp 'imu_uwb_eskf::TofsenseCascade)
  (if (not (find-package "IMU_UWB_ESKF"))
    (make-package "IMU_UWB_ESKF"))
  (shadow 'TofsenseCascade (find-package "IMU_UWB_ESKF")))
(unless (find-package "IMU_UWB_ESKF::TOFSENSECASCADE")
  (make-package "IMU_UWB_ESKF::TOFSENSECASCADE"))

(in-package "ROS")
;;//! \htmlinclude TofsenseCascade.msg.html


(defclass imu_uwb_eskf::TofsenseCascade
  :super ros::object
  :slots (_nodes ))

(defmethod imu_uwb_eskf::TofsenseCascade
  (:init
   (&key
    ((:nodes __nodes) ())
    )
   (send-super :init)
   (setq _nodes __nodes)
   self)
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
    ;; imu_uwb_eskf/TofsenseFrame0[] _nodes
    (apply #'+ (send-all _nodes :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; imu_uwb_eskf/TofsenseFrame0[] _nodes
     (write-long (length _nodes) s)
     (dolist (elem _nodes)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; imu_uwb_eskf/TofsenseFrame0[] _nodes
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _nodes (let (r) (dotimes (i n) (push (instance imu_uwb_eskf::TofsenseFrame0 :init) r)) r))
     (dolist (elem- _nodes)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(setf (get imu_uwb_eskf::TofsenseCascade :md5sum-) "e254ff763c3396ff0c54cf33bd09b21b")
(setf (get imu_uwb_eskf::TofsenseCascade :datatype-) "imu_uwb_eskf/TofsenseCascade")
(setf (get imu_uwb_eskf::TofsenseCascade :definition-)
      "TofsenseFrame0[] nodes

================================================================================
MSG: imu_uwb_eskf/TofsenseFrame0
uint8 id
uint32 system_time
float32 dis
uint8 dis_status
uint16 signal_strength
uint8 range_precision

")



(provide :imu_uwb_eskf/TofsenseCascade "e254ff763c3396ff0c54cf33bd09b21b")


