#include <opencv2/opencv.hpp>

int main(int argc, char *argv[]) {
  cv::Mat imgOriginal;

  imgOriginal = cv::imread("building.jpg");
  if (imgOriginal.empty()) {
    return -1;
  }

  cv::namedWindow("Example1", cv::WINDOW_AUTOSIZE);
  cv::imshow("Example1", imgOriginal);
  cv::waitKey();
  cv::destroyWindow("Example1");
  return 0;
}
