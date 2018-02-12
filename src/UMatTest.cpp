//============================================================================
// Name        : UMatTest.cpp
// Author      : Jean Vitor
//============================================================================
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core/ocl.hpp>
#include <string>
#include <iostream>
#include <fstream>
#include <chrono>

/*****************************************************************************************************************************/
//Namespaces
using namespace cv;
using namespace std::chrono;
using std::cout;
using std::endl;
/*****************************************************************************************************************************/
//Headers
void MatProcessing(const std::string& name);
void UMatProcessing(const std::string& name);
bool fileExists(std::string& filename);
/*****************************************************************************************************************************/
//Main
auto main(int argc, char *argv[]) -> int {
	std::string imageName;
	high_resolution_clock::time_point start,end;
	duration<double> elapsedTime;
	int type;
	cout << "OpenCL is available? " << cv::ocl::haveOpenCL() << endl; // returns true, OCL available
	ocl::setUseOpenCL(true);
	cout <<"Please enter the name of the image" <<endl;
	std::cin >> imageName;
	if (!fileExists(imageName)){
		cout<<"File does not exist";
		return EXIT_FAILURE;
	}
	cout <<"TYPE:\n 1 - UMAT\n 2 - MAT\n 3 - UMAT and MAT"<<endl;
	std::cin >> type;

	switch (type){
	case 1:
	case 3:
			cout <<"Processing UMAT image.." << endl;
		    start = high_resolution_clock::now();
		    	UMatProcessing(imageName);
			end = high_resolution_clock::now();
			elapsedTime = duration_cast<duration<double>>(end - start);
			cout <<"Success!"<<endl;
			cout<< "Elapsed time using UMAT:" << elapsedTime.count() << "s\n" << endl;
			if (type==1)
				break;
	case 2:
			cout <<"Processing MAT image.." << endl;
			start = high_resolution_clock::now();
				MatProcessing(imageName);
			end = high_resolution_clock::now();
			elapsedTime = duration_cast<duration<double>>(end - start);
			cout <<"Success!"<< endl;
			cout<< "Elapsed time using MAT:" << elapsedTime.count() << "s\n" << endl;
			break;
	 default :
		cout <<"Invalid option"<<endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
/*****************************************************************************************************************************/
void MatProcessing(const std::string& name){
	Mat img,dst;
	img = imread(name.c_str());
	cv::cvtColor(img,img,CV_BGR2GRAY);
	bilateralFilter(img, dst, 0, 10, 3);
}
/*****************************************************************************************************************************/
void UMatProcessing(const std::string& name){
	UMat Uimg, Udst;
	Uimg = imread(name.c_str(), IMREAD_COLOR).getUMat(ACCESS_READ);
	cv::cvtColor(Uimg,Uimg,CV_BGR2GRAY);
	bilateralFilter(Uimg, Udst, 0, 10, 3);
}
/****************************************************************************************************************************/
bool fileExists(std::string& filename) {
  std::ifstream ifile(filename.c_str());
  return static_cast<bool>(ifile);
}
/****************************************************************************************************************************/
