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
        reverseStr(CHAR_LIST);
    }
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

string toASCII(Mat frame, int chrlist, bool invert, double res)
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
            result += grayToChar((int)greyMat.at<uchar>(i, j), chrlist, invert);
        }
        result += "\n";
    }
    return result;
}

void run(string filename, int chrlist, bool invert, double res)
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
            std::cout << toASCII(frame, chrlist, invert, res) << std::endl;
            sleep(1000); // divied the sleep to avoid blanking
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
    std::string path = "/mnt/c/Users/camil/Documents/dev/ascii-convertor/files/images/tes.png";

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
        else if (strcmp(argv[i], "-h") == 0)
        {
            std::cout
                << "┍━━━━━━━━━━━━━━━━┯━━━━━━━━━━━━━━━━━┯━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┑" << std::endl
                << "|-s  (silent)    | {option:None}   | does not print the result in the console       |" << std::endl
                << "|-cl (char array)| {option:1,2,3}  | choose between 3 array of char //UNSAFE        |" << std::endl
                << "|-i  (invert)    | {option:None}   | invert the array of char                       |" << std::endl
                << "|-r  (resize)    | {option:double} | choose the ration to resize the image //UNSAFE |" << std::endl
                << "|-v  (video)     | {option:None}   | send each frame of the video to be converted   |" << std::endl
                << "|-h  (help)      | {option:None}   | show this message                              |" << std::endl
                << "┕━━━━━━━━━━━━━━━━┷━━━━━━━━━━━━━━━━━┷━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┙" << std::endl;
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
            run(video_filename, chrlist, invert, res);
        }
        else
        {
            Mat frame = imread(path);
            std::string data = toASCII(frame, chrlist, invert, res);
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
    }
    return 0;
}
