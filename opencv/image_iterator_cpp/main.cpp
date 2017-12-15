//
// Created by modric on 17-12-14.
//

#include <iostream>
#include <opencv2/opencv.hpp>


using std::cout;
using std::string;
using std::vector;


void load_pic(const string &path) {
    auto image = cv::imread(path);
    auto row = static_cast<unsigned >(image.rows);
    auto col = static_cast<unsigned >(image.cols);

    //0 not blank   1 blank
    auto blank = vector<vector<int>>(row, vector<int>(col, 0));

    auto tot_blank = 0;

    for (auto i = 0; i < image.rows; i++) {
        auto *pxVec = image.ptr<uchar>(i);
        for (auto j = 0; j < image.cols * image.channels(); j += image.channels()) {
            auto g = pxVec[j], b = pxVec[j + 1], r = pxVec[j + 2];
            if (g + b + r >= 3 * 240) {
                blank[i][j / image.channels()] = 1;
                tot_blank++;
            }
        }
    }
    cout << tot_blank << "\n";
}


int main() {
    load_pic("pic.jpg");
}
