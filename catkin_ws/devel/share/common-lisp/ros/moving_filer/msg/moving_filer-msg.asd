
(cl:in-package :asdf)

(defsystem "moving_filer-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "LinktrackNode2" :depends-on ("_package_LinktrackNode2"))
    (:file "_package_LinktrackNode2" :depends-on ("_package"))
    (:file "LinktrackNodeframe2" :depends-on ("_package_LinktrackNodeframe2"))
    (:file "_package_LinktrackNodeframe2" :depends-on ("_package"))
  ))