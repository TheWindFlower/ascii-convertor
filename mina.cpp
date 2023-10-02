#include <opencv2/opencv.hpp>
#include <string>
#include <bits/stdc++.h>
#include <chrono>
#include <thread>
#include <iostream>
#include <cstring>

using std::string;
using namespace cv;

#define sleep(x) std::this_thread::sleep_for(std::chrono::milliseconds(x));

#define clear system("clear");

void reverseStr(string &str)
{
    int n = str.length();

    // Swap character starting from two
    // corners
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}

char grayToChar(int gray)
{
    // string CHAR_LIST = " *@";
    string CHAR_LIST = ".:-=+*#%@";
    // string CHAR_LIST = ("$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/|()1{}[]?-_+~i!lI;:,\"^` ");
    reverseStr(CHAR_LIST);
    int num_chars = CHAR_LIST.size();
    return CHAR_LIST[std::min(int(gray * num_chars / 255), num_chars - 1)];
}

int mean(std::vector<int> a)
{
    int f = 0;
    for (int i = 0; i < a.size(); i++)
    {
        f += a[i];
    }
    f = f / a.size();
    return f;
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

string toASCII(Mat frame)
{
    Mat greyMat;
    Mat resizeMat;
    resize(frame, resizeMat, Size(), 0.2, 0.2, INTER_AREA);
    cvtColor(resizeMat, greyMat, COLOR_BGR2GRAY);
    // int rows = ;
    // int cols = ;
    int height = greyMat.rows; // max height array //line(rows)
    int width = greyMat.cols;  // max width array //colone(col)
    // int cell_width = width / cols;
    // int cell_height = height / rows;
    string result = "";

    // int pixelValue = (int)greyMat.at<uchar>(i, j); // get greyscale value
    //  need to take a rectangle of pixel, get their greyscale value make a mean of all of them
    /*
        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                int gray = mean(rect_of_pix(greyMat, cell_height, cell_width, col, row));
                result += grayToChar(gray);
            }
            result.append("\n");
        }
        return result;
        */
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            result += grayToChar((int)greyMat.at<uchar>(i, j));
        }
        result += "\n";
    }
    return result;
}

void run(string filename)
{
    string video_path = samples::findFile(filename);
    VideoCapture capture(video_path);
    Mat frame;
    if (!capture.isOpened())
    {
        std::cout << "balls" << std::endl;
    }
    for (;;)
    {
        capture >> frame;
        if (!frame.empty())
        {
            // std::cout << toASCII(frame) << std::endl;
            sleep(32); // divied the sleep to avoid blanking
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

    for (int i = 0; i < argc; i++)
    {
        std::cout << argv[i] << std::endl;
        if (argv[i] == "-s")
        {
            silent = true;
        }
    }
    // char *instr = argv[1];
    /*if (strcmp(instr, "-v") == 0 || strcmp(instr, "--video") == 0)
    {
        string video_filename = "";
        string audio_file = ""; // point the path of the generated audio file

        // extract audio
        const char *cmd = std::string("ffmpeg -i " + video_filename + " -q:a 0 -map a" + audio_file).c_str();
        std::system(cmd);

        std::thread t1(play_audio, audio_file);
        sleep(500);
        run(video_filename);
    }*/
    if (1 == 2)
    {
    }
    else
    {
        Mat frame = imread("/mnt/c/Users/camil/Documents/dev/ascii-convertor/files/images/back.png");
        std::string data = toASCII(frame);
        if (!silent)
            std::cout << data << std::endl;

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
    return 0;
}
