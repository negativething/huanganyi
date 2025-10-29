#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/core.hpp>
#include<opencv2/objdetect.hpp>
#include<iostream>
using namespace std;
using namespace cv;
    string path = "../imgs/task2_video.mp4";
    Mat img= imread(path);
    vector<vector<int>> newPoint;
    vector<vector<int>> myColors{{83,56,18,179,255,255},{80,30,150,140,150,255},{0,0,240,172,255,255}};
    //装甲板黑色(83,56,18,179,255,255) 字的灰色(57~104,25~38,80~199,126~165,55~255,255)   灯(0,0,240,172,255,255)

    vector<Scalar> myColorValues {{0,0,0},{255,255,255},{0,0,255}};
    VideoCapture cap(path);
    int hmin =83,smin=56,vmin=18;
    int hmax=179,smax=255,vmax=255;


Point getContours(Mat imgDil){
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    findContours(imgDil,contours,hierarchy,RETR_EXTERNAL,CHAIN_APPROX_SIMPLE);
    drawContours(img,contours,-1,Scalar(83,56,18),2);

    vector<vector<Point>> conPoly(contours.size());
    vector<Rect> boundRect(contours.size());

    Point myPoint(0,0);
    for(int i=0;i<contours.size();i++){
        int area= contourArea(contours[i]);
        cout<<area<<endl;

        string objectType;

        if(area>1000){
            float peri = arcLength(contours[i],true);
            approxPolyDP(contours[i],conPoly[i],0.02*peri,true);
            cout<<conPoly[i].size()<<endl;
            boundRect[i]=boundingRect(conPoly[i]);
            myPoint.x = boundRect[i].x+boundRect[i].width/2;
            myPoint.y = boundRect[i].y;
            drawContours(img,conPoly,i,Scalar(0,0,0),2);
            rectangle(img,boundRect[i].tl(),boundRect[i].br(),Scalar(0,0,255),3);
        }
    }
    return myPoint;
}

vector<vector<int>> findColor(Mat img){
    string path = "../imgs/task2_video.mp4";
    img = imread(path);
    Mat imgHSV ;
    cvtColor(img,imgHSV,COLOR_BGR2HSV);

    for (int a ;a<myColors.size();a++){
        Scalar lower(myColors[a][0],myColors[a][1],myColors[a][2]);
        Scalar upper(myColors[a][3],myColors[a][4],myColors[a][5]);
        Mat mask;
        inRange(imgHSV,lower,upper,mask);
        Point myPoint = getContours(mask);
        if(myPoint.x!=0 && myPoint.y!=0){
            newPoint.push_back({myPoint.x,myPoint.y,a});
        }
    }
    return newPoint;
}

void detect_number(){
    CascadeClassifier numberCascade;
    numberCascade.load(path);

    if(numberCascade.empty()){
        cout<<"file not find"<<endl;
        vector<Rect> numbers;
        while(true){
            cap.read(img);
            numberCascade.detectMultiScale(img,numbers,1.1,10);
            for(int b;b<numbers.size();b++){
                Mat imgCrop=img(numbers[b]);
                imshow(to_string(b),imgCrop);
                imwrite("../imgs/"+to_string(b)+".jpg",imgCrop);
                rectangle(img,numbers[b].tl(),numbers[b].br(),Scalar(255,255,255),3);
            }
        }
    }
}
/*--------------------------检测灯带&装甲板---------------------------*/
    /*namedWindow("Trackbars",(640,100));
    createTrackbar("Hue Min","Trackbars",&hmin,179);
    createTrackbar("Hue Max","Trackbars",&hmax,179);
    createTrackbar("Sat Min","Trackbars",&smin,255);
    createTrackbar("Sat Max","Trackbars",&smax,255);
    createTrackbar("Val Min","Trackbars",&vmin,255);
    createTrackbar("Val Max","Trackbars",&vmax,255);
            //inRange(imgHSV,lower,upper,mask);
        //imshow("Image Mask",mask);
                //imshow("Image HSV",imgHSV);*/

int main(){
    VideoCapture cap(path);
    findColor(img);
    detect_number();
    getContours(img);
    while(true){
        Scalar lower(hmin,smin,vmin);
        Scalar upper(hmax,smax,vmax);
        cap.read(img);
        imshow("Image",img);
        waitKey(1000);
    }
}