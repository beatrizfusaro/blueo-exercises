C++ and Python publisher and subscriber to do performance testing.

The folder 'docs' holds the performance test data.

Performance tests:

roslaunch performance_tests cpptocpp.launch, for C++ publisher to C++ subscriber
roslaunch performance_tests cpptopy.launch, for C++ publisher to Python subscriber
roslaunch performance_tests pytocpp.launch, for Python publisher to C++ subscriber
roslaunch performance_tests pytopy.launch, for Python publisher to Python subscriber

Based on Thomas Denewiler's Cpp/Python Publisher and Subscriber example code.
