#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main(int argc, char *argv[]) {
  CascadeClassifier cascade;
  string imageName, cascadeName;
  Mat image, gray;
  vector<Rect> faces;
  Scalar color = Scalar(0, 255, 0);

  cascadeName = "./haarcascade_frontalface_default.xml";
  imageName = argv[1];

  // load image and classifier
  if (!cascade.load(cascadeName)) {
    cerr << "Could not load classifier cascade " << endl;
  } else if (imageName.empty()) {
    cout << "Could not read " << imageName << endl;
  } else {
    image = imread(imageName, 1);
    if (image.empty()) {
      cout << "Could not imread image" << endl;
    }
  }

  // convert to grey
  cvtColor(image, gray, COLOR_BGR2GRAY);

  // run face detector
  cascade.detectMultiScale(image, faces, 1.1, 2, 0, Size(30, 30));

  // output rectangle
  for (size_t i = 0; i < faces.size(); ++i) {
    Rect r = faces[i];
    rectangle(
        image, Point(cvRound(r.x), cvRound(r.y)),
        Point(cvRound((r.x + r.width - 1)), cvRound((r.y + r.height - 1))),
        color, 3, 8, 0);
  }

  // show image
  imshow("result", image);
  waitKey(0);
  destroyAllWindows();
  return 0;
}
