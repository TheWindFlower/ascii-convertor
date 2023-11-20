#include <opencv2/opencv.hpp>
#include <string>
#include <bits/stdc++.h>
#include <chrono>
#include <thread>
#include <iostream>
#include <cstring>
#include "../include/include.hpp"

using std::string;
using namespace cv;

#define sleep(x) std::this_thread::sleep_for(std::chrono::milliseconds(x));

#define clear system("clear");

char grayToChar(int gray, int chrlst, bool invert)
{
    string CHAR_LIST;
    switch (chrlst)
    {
    case 1:
        CHAR_LIST = "@*";
        break;
    case 2:
        CHAR_LIST = "@%#*+=-:.";
        break;
    case 3:
        CHAR_LIST = ("$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/|()1{}[]?-_+~i!lI;:,\"^`");
        break;
    default:
        CHAR_LIST = "@.";
    }
    if (invert)
    {
        CHAR_LIST = reverseStr(CHAR_LIST);
    }
    int num_chars = CHAR_LIST.size();
    return CHAR_LIST[std::min(int(gray * num_chars / 255), num_chars - 1)];
}

std::vector<int> rect_of_pix(Mat greyMat, int cell_height, int cell_width, int col, int row)
{
    std::vector<int> array_of_pix;
    for (int cw = 0; cw < cell_width; cw++)
    {
        for (int ch = 0; ch < cell_height; ch++)
        {
            array_of_pix.push_back((int)greyMat.at<uchar>(ch + (cell_height * col), cw + (cell_width * row)));
        }
    }
    return array_of_pix;
}

string toASCII(Mat frame, int chrlist, bool invert, double res, bool color, bool bgcolor)
{
    Mat greyMat;
    Mat resizeMat;
    resize(frame, resizeMat, Size(), res, res, INTER_AREA);

    cvtColor(resizeMat, greyMat, COLOR_BGR2GRAY);
    // int rows = ;
    // int cols = ;
    int height = greyMat.rows; // max height array //line(rows)
    int width = greyMat.cols;  // max width array //colone(col)
    // int cell_width = width / cols;
    // int cell_height = height / rows;

    string result = "";
    string prefix;
    char tempchar;
    cv::Vec3b colorVar; // var to hold the vec3 of each rgb value

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (color)
            {
                tempchar = grayToChar((int)greyMat.at<uchar>(i, j), chrlist, invert); // (int)greyMat.at<uchar>(i, j) value of grey at i,j
                colorVar = resizeMat.at<cv::Vec3b>(i, j);                             // return the color of the pixel in form of a tuple vec3
                prefix = "\033[38;2;" + std::to_string(colorVar[2]) + ";" + std::to_string(colorVar[1]) + ";" + std::to_string(colorVar[0]) + "m";
                result += prefix + tempchar + tempchar;
            }
            else if (bgcolor)
            {
                colorVar = resizeMat.at<cv::Vec3b>(i, j); // return the color of the pixel in form of a tuple vec3
                prefix = "\033[48;2;" + std::to_string(colorVar[2]) + ";" + std::to_string(colorVar[1]) + ";" + std::to_string(colorVar[0]) + "m";
                result += prefix + "  ";
            }
            else
            {
                result += grayToChar((int)greyMat.at<uchar>(i, j), chrlist, invert);
            }
        }
        result += "\033[0m\n";
    }
    return result;
}

void runVideo(string filename, int chrlist, bool invert, double res)
{
    string video_path = samples::findFile(filename);
    VideoCapture capture(video_path);
    Mat frame;
    if (!capture.isOpened())
    {
        std::cerr << "error" << std::endl;
    }
    int i = 0;
    for (;;)
    {
        capture >> frame;
        if (!frame.empty())
        {
            std::cout << toASCII(frame, chrlist, invert, res, false, false) << std::endl; // pass false to color and bg color
            sleep(1000);                                                                  // divied the sleep to avoid blanking
            clear;
        }
    }
}

void play_audio(string file)
{
    string cmd_ = "nohup play" + file;
    const char *cmd = cmd_.c_str();
    std::system(cmd);
}

int main(int argc, char *argv[])
{
    bool silent = false;
    int chrlist = 1;
    bool invert = false;
    double res = 0.2;
    bool vid = false;
    bool display = true;
    bool color = false;
    bool bgcolor = false;
    std::string path = "/mnt/c/Users/camil/Documents/dev/ascii-convertor/files/images/1.jpg";

    for (int i = 0; i < argc; i++)
    {
        if (strcmp(argv[i], "-s") == 0)
        {
            silent = true;
        }
        else if (strcmp(argv[i], "-cl") == 0)
        {
            chrlist = std::stoi(argv[i + 1]);
        }
        else if (strcmp(argv[i], "-path") == 0)
        {
            path = argv[i + 1];
        }
        else if (strcmp(argv[i], "-i") == 0)
        {
            invert = true;
        }
        else if (strcmp(argv[i], "-r") == 0)
        {
            res = std::stod(argv[i + 1]);
        }
        else if (strcmp(argv[i], "-v") == 0)
        {
            vid = true;
        }
        else if (strcmp(argv[i], "-c") == 0)
        {
            color = true;
        }
        else if (strcmp(argv[i], "-bg") == 0)
        {
            bgcolor = true;
        }
        else if (strcmp(argv[i], "-h") == 0)
        {
            std::cout
                << "┍━━━━━━━━━━━━━━━━━━━━━━━┯━━━━━━━━━━━━━━━━━┯━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┑" << std::endl
                << "|-s  (silent)           | {option:None}   | does not print the result in the console       |" << std::endl
                << "|-cl (char array)       | {option:1,2,3}  | choose between 3 array of char //UNSAFE        |" << std::endl
                << "|-i  (invert)           | {option:None}   | invert the array of char                       |" << std::endl
                << "|-c  (color)            | {option:None}   | display the image in color //WIP               |" << std::endl
                << "|-bg (background color) | {option:None}   | display the image without char in color //WIP  |" << std::endl
                << "|-r  (resize)           | {option:double} | choose the ration to resize the image //UNSAFE |" << std::endl
                << "|-v  (video)            | {option:None}   | send each frame of the video to be converted   |" << std::endl
                << "|-h  (help)             | {option:None}   | show this message                              |" << std::endl
                << "┕━━━━━━━━━━━━━━━━━━━━━━━┷━━━━━━━━━━━━━━━━━┷━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┙" << std::endl;
            display = false;
        }
    }
    // char *instr = argv[1];

    if (display) // display false
    {
        if (vid)
        {
            string video_filename = "/mnt/c/Users/camil/Documents/dev/ascii-convertor/files/video/output.mp4";
            string audio_file = "/mnt/c/Users/camil/Documents/dev/ascii-convertor/files/video/output.mp3"; // point the path of the generated audio file

            // extract audio
            // const char *cmd = std::string("ffmpeg -i " + video_filename + " -q:a 0 -map a" + audio_file).c_str();
            // std::system(cmd);

            // std::thread t1(play_audio, audio_file);
            // sleep(500);
            runVideo(video_filename, chrlist, invert, res);
        }
        else
        {
            Mat frame = imread(path);
            std::string data = toASCII(frame, chrlist, invert, res, color, bgcolor);
            if (!silent)
                std::cout << data << std::endl;

            // write result in html file and add style
            std::ofstream file("/mnt/c/Users/camil/Documents/dev/ascii-convertor/web/index.html");
            if (!file.is_open())
            {
                std::cerr << "Error opening the file." << std::endl;
            }
            std::string prefix = "<link href='styles.css' rel='stylesheet' type='text/css' /> <span style = 'white-space: pre-line'>";
            std::string suffix = "</span>";
            file << prefix + data + suffix;

            file.close();
        }
    }
    return 0;
}
