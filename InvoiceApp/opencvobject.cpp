#include "opencvobject.h"
#include <QMessageBox>

void getFiles(string lpPath, std::vector<std::string> &fileList)
{
    char szFind[MAX_PATH];
    WIN32_FIND_DATA FindFileData;

    strcpy(szFind, lpPath.c_str());
    strcat(szFind, "\\*.*");
    CString str = CString(szFind);

    USES_CONVERSION;
    LPCWSTR classname = A2CW(W2A(str));

    HANDLE hFind = ::FindFirstFile(classname, &FindFileData);
    if (INVALID_HANDLE_VALUE == hFind)  return;

    while (true)
    {
        if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
        {
            if (FindFileData.cFileName[0] != '.')
            {
                char szFile[MAX_PATH];
                strcpy(szFile, lpPath.c_str());
                strcat(szFile, "\\");
                strcat(szFile, (char*)(FindFileData.cFileName));
                getFiles(szFile, fileList);

            }
        }
        else
        {
            std::string szDst;
            DWORD dwNum = WideCharToMultiByte(CP_OEMCP,NULL,FindFileData.cFileName,-1,NULL,0,NULL,FALSE);
            char * pstext = new char[dwNum];
            WideCharToMultiByte(CP_OEMCP,NULL,FindFileData.cFileName,-1,pstext,dwNum,NULL,FALSE);
            szDst = pstext;
            fileList.push_back(szDst);
            printf("%s",szDst);
        }
        if (!FindNextFile(hFind, &FindFileData))  break;
    }
    FindClose(hFind);
}





opencvObject::opencvObject(QObject *parent)
{

}

int opencvObject::reorder_point(std::vector<Point> &keypoints, bool xorder)
{
    if (xorder)
    {
        std::sort(keypoints.begin(), keypoints.end(), comp_x);
    }
    else
    {
        std::sort(keypoints.begin(), keypoints.end(), comp_y);
    }

    return 0;
}

void  opencvObject::photoProcess(QString path)
{
    clock_t start, ends;

    string PicPath = path.toStdString();

    vector<string> filePath;
    getFiles(PicPath, filePath);
    Mat pic, gray, thres, thres1, thres2, thres3;

    Mat dilateee1;
    cout << filePath.size() << endl;

    int resizeRate = 4;
    int resizeWHRate = resizeRate * resizeRate;

     for (int i = 0; i < filePath.size(); i++)
    {
        start = clock();
        //  cout << i << endl;
        char aaa[255];

        sprintf(aaa, "%s\\%s", PicPath.c_str(), filePath[i].c_str());

       // sprintf(aaa, "%s", PicPath.c_str());
        pic = imread(aaa);

        //灰度化
        cvtColor(pic, gray, COLOR_BGR2GRAY);

        //过滤色值(暗和亮的过滤)
        threshold(gray, thres1, 170, 255, CV_THRESH_BINARY);
        threshold(gray, thres2, 10, 255, CV_THRESH_BINARY_INV);

        //剩下的融合
        thres = thres1 | thres2;

        vector<vector<Point> > contours;    //储存轮廓
        vector<Vec4i> hierarchy;

        //膨胀轮廓,为了闭合轮廓线
        cv::dilate(thres, dilateee1, Mat());
        //轮廓检测
        findContours(dilateee1, contours, hierarchy, RETR_TREE, CHAIN_APPROX_NONE);

        vector <int> fitContour;

        int nMaxNum = -1;
        int nMaxArea = 0;

        Mat contourMask = Mat::zeros(Size(pic.cols, pic.rows), CV_8UC3);

        for (int index = 0; index < contours.size(); index++) {
            int num = index;
            //过滤太小的轮廓
            float area = contourArea(contours[num]);

            if (area < 500 * resizeWHRate)
                continue;

            //保存有轮廓里面有内容的轮廓
            if (num + 1 == contours.size())
                break;

            //从实际发票图像来看,发票里面是有内容的,所以,hierarchy[num][3],判断这一轮廓里面是否有内容
            if (hierarchy[num][3] == -1 && hierarchy[num + 1][3] != -1)
            {
                if (nMaxNum == -1)
                {
                    nMaxArea = area;
                    nMaxNum = num;
                }
                else if (nMaxNum != -1 && nMaxArea < area)
                {
                    nMaxArea = area;
                    nMaxNum = num;
                }
            }
        }

                    if (nMaxNum == -1)
                        continue;

        //凸包检测
        vector<Point> polyContours;

        Mat result;

        //获取多边形轮廓
        approxPolyDP(contours[nMaxNum], polyContours, 10, true);
        //获取贴合轮廓的四边形
        RotatedRect temp1 = minAreaRect(polyContours);

        Point2f vertices[4];
        vector<Point> pts_dst;
        temp1.points(vertices);
        for (int i = 0; i < 4; i++)
        {
            pts_dst.push_back(vertices[i]);
        }

        //得到的框图的四个顶点坐标需要按顺序排序
        reorder_point(pts_dst, true);

        if (pts_dst[0].y > pts_dst[1].y)
            swap(pts_dst[0], pts_dst[1]);

        if (pts_dst[2].y < pts_dst[3].y)
            swap(pts_dst[2], pts_dst[3]);

        swap(pts_dst[1], pts_dst[3]);

        int nWidth = max(pts_dst[1].x, pts_dst[2].x) - min(pts_dst[0].x, pts_dst[3].x);
        int nHeight = max(pts_dst[2].y, pts_dst[3].y) - min(pts_dst[0].y, pts_dst[1].y);

        vector<Point> pts_src;
        pts_src.push_back(Point(0, 0));
        pts_src.push_back(Point(nWidth, 0));
        pts_src.push_back(Point(nWidth, nHeight));
        pts_src.push_back(Point(0, nHeight));

        vector<vector<Point> > ncontours;

        ncontours.push_back(pts_dst);

        drawContours(contourMask, ncontours, 0, Scalar(255, 255, 255), -1);

        Mat paperImg = contourMask & pic;

        //不规则四边形变换成正四边形
        Mat h = findHomography(pts_dst, pts_src);
        warpPerspective(paperImg, result, h, Size(nWidth, nHeight));

        /***********************上面为获取发票矩形,并且把倾斜四边形摆正*************************/
        /***********************下面为把发票摆正*************************/
        //算法为找到椭圆盖章的图案

        Mat rGray, HSV;

        Mat canny, erobe1;

        vector<Mat> splitRGB;
        split(result, splitRGB);

        //提取HSV,红色亮度特别明显
        vector<Mat> splitHSV;
        cvtColor(result, HSV, COLOR_BGR2HSV);

        split(HSV, splitHSV);

        Mat splitRGB0thres, splitRGB1thres, splitHSV1thres;

        threshold(splitRGB[0], splitRGB0thres, 80, 255, CV_THRESH_BINARY_INV);
        threshold(splitHSV[1], splitHSV1thres, 180, 255, CV_THRESH_BINARY);

        cv::dilate(splitHSV1thres, dilateee1, Mat());
        cv::erode(dilateee1, erobe1, getStructuringElement(MORPH_RECT, Size(5, 5)));
        //cv::imwrite("erode1.jpg", erobe1);

        vector<vector<Point> > contours1;    //储存轮廓
        vector<Vec4i> hierarchy1;

        //轮廓检测
        findContours(erobe1, contours1, hierarchy1, RETR_EXTERNAL, CHAIN_APPROX_NONE);

        Mat newImg = result.clone();

        int nCenterX = newImg.cols / 2;
        int nCenterY = newImg.rows / 2;

        int nCenterX3 = newImg.cols / 3;
        int nCenterY3 = newImg.rows / 3;

        int nCenterLeft = nCenterX - 10 * resizeRate;
        int nCenterRight = nCenterX + 10 * resizeRate;

        int nCenterUp = nCenterY - 10 * resizeRate;
        int nCenterDown = nCenterY + 10 * resizeRate;

        int bDetectFinish = 0;

        //这一部分算法是提取正常红色的发票.
        for (int i = 0; i < contours1.size(); i++)
        {
            float area = contourArea(contours1[i]);

            if (area < 300 * resizeWHRate)
                continue;

            RotatedRect box = cv::fitEllipse(contours1[i]);

            //Point2f vertices[4];
            //box.points(vertices);
            //for (int i = 0; i < 4; i++)
            //	line(newImg, vertices[i], vertices[(i + 1) % 4], Scalar(0, 255, 0),3);

            //椭圆为是正的或者是垂直,在下面设置的范围内,皆可接受
            if (box.angle > 82 && box.angle < 98)
            {
                //cout << box.center.x << "," << box.center.y << "," << nCenterLeft << "," << nCenterRight << "," << nCenterY << endl;

                //并且椭圆的坐标必须在正中间,左右多少像素范围内,皆可接受
                if (box.center.x > nCenterLeft && box.center.x < nCenterRight)
                {
                    //判断椭圆盖章在上面还是颠倒了
                    if (box.center.y > nCenterY)
                    {
                        //flip(newImg, newImg, 0);
                        newImg = matRotateClockWise180(newImg);
                    }

                    bDetectFinish = 1;
                }
            }
            else if (box.angle > 175 || box.angle < 5)
            {
                if (box.center.y > nCenterUp && box.center.y < nCenterDown)
                {
                    //transpose(newImg, newImg);

                    if (box.center.x < nCenterX)
                    {
                        //flip(newImg, newImg, 0);
                        newImg = matRotateClockWise90(newImg);
                    }
                    else
                    {
                        newImg = myRotateAntiClockWise90(newImg);
                    }

                    bDetectFinish = 1;
                }
            }
        }

        //这一部分是提取红色不太明显的发票
        if (bDetectFinish == 0)
        {
            //提取轮廓
            Canny(splitRGB[0], canny, 128, 255);

            //颜色不明显,会影响轮廓,所以先把轮廓线膨胀一下,让他们相连接
            cv::dilate(canny, dilateee1, Mat());

            //找到轮廓后,填充轮廓
            findContours(dilateee1, contours1, hierarchy1, RETR_EXTERNAL, CHAIN_APPROX_NONE);

            for (int i = 0; i < contours1.size(); i++)
            {
                float area = contourArea(contours1[i]);

                if (area < 300 * resizeWHRate)
                    continue;

                //RotatedRect box = cv::fitEllipse(contours1[i]);
                //ellipse(newImg, box, Scalar(0, 255, 255), -1, CV_AA);

                drawContours(dilateee1, contours1, i, Scalar(255, 255, 255), -1);
            }

            //针对有椭圆的盖章轮廓,和手写的字体会误判为椭圆,所以,较大力的腐蚀掉轮廓,可以有效去除字体
            cv::erode(dilateee1, erobe1, getStructuringElement(MORPH_RECT, Size(9, 9)));

            //再找椭圆
            findContours(erobe1, contours1, hierarchy1, RETR_EXTERNAL, CHAIN_APPROX_NONE);

            for (int i = 0; i < contours1.size(); i++)
            {
                float area = contourArea(contours1[i]);

                if (area < 300 * resizeWHRate)
                    continue;

                RotatedRect box = cv::fitEllipse(contours1[i]);

                Rect rt = box.boundingRect();

                if (rt.width >= nCenterX3 && rt.height >= nCenterY3)
                    continue;

                if (box.angle > 82 && box.angle < 98)
                {
                    if (box.center.x > nCenterLeft && box.center.x < nCenterRight)
                    {
                        if (box.center.y < nCenterY3 || box.center.y >(newImg.rows - nCenterY3))
                        {
                            if (box.center.y > nCenterY)
                            {
                                //flip(newImg, newImg, 0);
                                newImg = matRotateClockWise180(newImg);
                            }

                            bDetectFinish = 2;

                            //ellipse(newImg, box, Scalar(0, 255, 255), -1, CV_AA);
                        }
                    }
                }
                else if (box.angle > 175 || box.angle < 5)
                {
                    if (box.center.y > nCenterUp && box.center.y < nCenterDown)
                    {
                        if (box.center.x < nCenterX3 || box.center.x >(newImg.cols - nCenterX3))
                        {
                            //transpose(newImg, newImg);

                            if (box.center.x < nCenterX)
                            {
                                //flip(newImg, newImg, 0);
                                newImg = matRotateClockWise90(newImg);
                            }
                            else
                            {
                                newImg = myRotateAntiClockWise90(newImg);
                            }

                            bDetectFinish = 2;
                            //ellipse(newImg, box, Scalar(0, 255, 255), -1, CV_AA);
                        }
                    }
                }
            }
        }

        //这一部分是提取黑色的发票
        if (bDetectFinish == 0)
        {
            threshold(splitRGB[0], splitRGB0thres, 30, 255, CV_THRESH_BINARY_INV);

            cv::dilate(splitRGB0thres, dilateee1, Mat());

            findContours(dilateee1, contours1, hierarchy1, RETR_EXTERNAL, CHAIN_APPROX_NONE);

            for (int i = 0; i < contours1.size(); i++)
            {
                float area = contourArea(contours1[i]);

                if (area < 300 * resizeWHRate)
                    continue;

                //RotatedRect box = cv::fitEllipse(contours1[i]);
                //ellipse(newImg, box, Scalar(0, 255, 255), -1, CV_AA);

                drawContours(dilateee1, contours1, i, Scalar(255, 255, 255), -1);
            }

            cv::erode(dilateee1, erobe1, getStructuringElement(MORPH_RECT, Size(9, 9)));

            findContours(erobe1, contours1, hierarchy1, RETR_EXTERNAL, CHAIN_APPROX_NONE);

            for (int i = 0; i < contours1.size(); i++)
            {
                float area = contourArea(contours1[i]);

                if (area < 300 * resizeWHRate)
                    continue;

                RotatedRect box = cv::fitEllipse(contours1[i]);

                Rect rt = box.boundingRect();

                if (rt.width >= nCenterX3 && rt.height >= nCenterY3)
                    continue;

                if (box.angle > 82 && box.angle < 98)
                {
                    if (box.center.x > nCenterLeft && box.center.x < nCenterRight)
                    {
                        if (box.center.y < nCenterY3 || box.center.y >(newImg.rows - nCenterY3))
                        {
                            if (box.center.y > nCenterY)
                            {
                                //flip(newImg, newImg, 0);
                                newImg = matRotateClockWise180(newImg);
                            }

                            bDetectFinish = 3;
                        }
                    }
                }
                else if (box.angle > 175 || box.angle < 5)
                {
                    if (box.center.y > nCenterUp && box.center.y < nCenterDown)
                    {
                        if (box.center.x < nCenterX3 || box.center.x >(newImg.cols - nCenterX3))
                        {
                            //transpose(newImg, newImg);

                            if (box.center.x < nCenterX)
                            {
                                //flip(newImg, newImg, 0);
                                newImg = matRotateClockWise90(newImg);
                            }
                            else
                            {
                                newImg = myRotateAntiClockWise90(newImg);
                            }

                            bDetectFinish = 3;
                        }
                    }
                }
            }
        }

        //这一部分是直接旋转特别不清晰,但是是针对大发票
        if (bDetectFinish == 0)
        {
            if (result.cols > 300 * resizeRate && result.rows > 500 * resizeRate)
            {
                //flip(newImg, newImg, 0);
                newImg = myRotateAntiClockWise90(newImg);
            }
        }

        ends = clock();

        cout << ends - start << "ms" << endl;

        //        //显示结果
        //        imshow("pic", pic);
        //        //imshow("result", result);

        //        imshow("newImg", newImg);


        sprintf(aaa, "%s\\%s",PicPath.c_str(),filePath[i].c_str());
       // sprintf(aaa, "%s",PicPath.c_str());
        imwrite(aaa, newImg);
        //imwrite(aaa, result);

        int key = waitKey(1);

        if (key == 27)
        {
             break;
            //return;
        }
    }
    return;

}

Mat opencvObject::matRotateClockWise90(Mat src)
{
    // 矩阵转置
    transpose(src, src);
    //0: 沿X轴翻转； >0: 沿Y轴翻转； <0: 沿X轴和Y轴翻转
    flip(src, src, 1);// 翻转模式，flipCode == 0垂直翻转（沿X轴翻转），flipCode>0水平翻转（沿Y轴翻转），flipCode<0水平垂直翻转（先沿X轴翻转，再沿Y轴翻转，等价于旋转180°）
    return src;
}

Mat opencvObject::matRotateClockWise180(Mat src)//顺时针180
{
    //0: 沿X轴翻转； >0: 沿Y轴翻转； <0: 沿X轴和Y轴翻转
    flip(src, src, 0);// 翻转模式，flipCode == 0垂直翻转（沿X轴翻转），flipCode>0水平翻转（沿Y轴翻转），flipCode<0水平垂直翻转（先沿X轴翻转，再沿Y轴翻转，等价于旋转180°）
    flip(src, src, 1);
    return src;
    //transpose(src, src);// 矩阵转置
}

Mat opencvObject::matRotateClockWise270(Mat src)//顺时针270
{
    // 矩阵转置
    //transpose(src, src);
    //0: 沿X轴翻转； >0: 沿Y轴翻转； <0: 沿X轴和Y轴翻转
    transpose(src, src);// 翻转模式，flipCode == 0垂直翻转（沿X轴翻转），flipCode>0水平翻转（沿Y轴翻转），flipCode<0水平垂直翻转（先沿X轴翻转，再沿Y轴翻转，等价于旋转180°）
    flip(src, src, 0);
    return src;
}

Mat opencvObject::myRotateAntiClockWise90(Mat src)//逆时针90°
{
    transpose(src, src);
    flip(src, src, 0);
    return src;
}
