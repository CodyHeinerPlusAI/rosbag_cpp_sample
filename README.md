Overview:
 - `ws` is the catkin workspace parent folder
 - `ws/src` contains a set of folders, each of which is a single package
 - `ws/src/write_rosbag_sample` contains an example package that includes ros headers and pcl
 headers.
 
To compile, enter the `ws` directory and use the command `catkin_make`.

To run, you can find the name of the built app via `find . -name "rosbag_write_sample"`, then run
the result.  This can be done in the single command `` `find . -name "rosbag_write_sample"` ``.

This should produce a bag called `test.bag` and write some output to the console.
