### qmk

The qmk config files need to be moved into a fully setup qmk build enviroment.

### hwdb

mv desired .hwdb into /usr/lib/udev/hwdb.d , and run
~~~
$ udevadm hwdb --update
$ udevadm trigger
~~~
