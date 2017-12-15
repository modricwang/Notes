# OpenCV

## image_iterator

场景描述：遍历一张图片，找到其中颜色较浅（定义为r+g+b值）小于3*240的点，标记位置并统计个数。

做法：遍历这张图的每一个点，挨个统计。

首先读入图片，使用cv::imread(),返回类型为cv::Mat
```c++
auto image = cv::imread(path);
```

图片数据是以行为单位存储的，几何意义上相邻的行可能存储位置不相邻。可以通过cv::Mat.ptr<uchar>() 来获得行首的指针，返回类型为uchar *
```c++
auto *pxVec = image.ptr<uchar>(i);
```

一般的图片通道数为3，RGB，有些图片还有一个 $\alpha$ 通道来表示透明度。使用cv::Mat.channels()可以得到图片的通道数。可以用一个for循环来遍历一个行。注意，对于行来说，存储的结构是，对于每个点相关的内容存储在一起，如果是三通道，就是G1 R1 B1 G2 R2 B2 ... 这样的形式

存储判断信息需要用二位数组，这里我使用了二维vector
```c++
//0 not blank   1 blank
auto blank = vector<vector<int>>(row, vector<int>(col, 0));
for (auto j = 0;
          j < image.cols * image.channels();
          j += image.channels()) {

            auto g = pxVec[j],
                 b = pxVec[j + 1],
                 r = pxVec[j + 2];

            if (g + b + r >= 3 * 240) {
                blank[i][j / image.channels()] = 1;
            }
        }
```

完整的遍历全图，标记浅色位置并统计浅色块个数的代码如下：
```c++
void load_pic(const string &path) {
    auto image = cv::imread(path);
    auto row = static_cast<unsigned >(image.rows);
    auto col = static_cast<unsigned >(image.cols);

    //0 not blank   1 blank
    auto blank = vector<vector<int>>(row, vector<int>(col, 0));

    auto tot_blank = 0;

    for (auto i = 0; i < image.rows; i++) {
        auto *pxVec = image.ptr<uchar>(i);
        for (auto j = 0;
                  j < image.cols * image.channels();
                  j += image.channels()) {

            auto g = pxVec[j],
                 b = pxVec[j + 1],
                 r = pxVec[j + 2];
            if (g + b + r >= 3 * 240) {
                blank[i][j / image.channels()] = 1;
                tot_blank++;
            }
        }
    }
    cout << tot_blank << "\n";
}
```
