# OpenCV's UMat: The basics and performance test
You can verify using this code if your OpenCV has OpenCL enabled using an implementation of the T-API and also compare the performance of both Mat and UMat. This code is part of a post on my blog about UMat.

# How to use
Your OpenCV has to be built with the flag `WITH_OPENCL` set as `ON`.

This project was developed using Eclipse. Therefore, clone using `git clone` or download and open it as a Project, configure the Linker and Compiler to match your OpenCV folder.

For compiling with G++ (Considering the OpenCV folders `C:\opencv\install\include` and `C:\opencv\install\x64\mingw\lib`):

* `git clone`

* `cd UMatTest\src`

* `g++ "-IC:\\opencv\\install\\include" -O0 -g3 -Wall -c -fmessage-length=0 -o "UMatTest.o" "UMatTest.cpp"`

* `g++ "-LC:\\opencv\\install\\x64\\mingw\\lib" -o UMatTest.exe "UMatTest.o" -lopencv_core340 -lopencv_highgui340 -lopencv_imgcodecs340 -lopencv_imgproc340`

* `.\UMatTest` 

# Additional Info
Give a look at my results with an i5 3330/AMD Radeon 7970 on the [post on my blog](http://jeanvitor.com/opencv-opencl-umat-performance/).