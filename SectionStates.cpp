#include "PowerTycoon.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <chrono>
#include <thread>

int *users = new int[24];

int sites[4];

void getSampleData(){
    std::ifstream file("usersSample.txt");
    std::string line;
    int pos = 0;
    while (std::getline(file, line)){       //
        std::istringstream iss(line);       // Adds each number from usersSample.txt to users
        std::string token;                  // users[0,4,8...] = Videos users
        while (iss >> token){               // users[1,5,9...] = Shop users
            users[pos] = std::stoi(token);  // users[2,6,10...] = Discussion users
            ++pos;                          // users[3,7,11...] = Recipes users
        }
    }
}

void Videos(){
    int pos;
    for (pos = 0; pos < 25; pos+=4){
        sites[0] = users[pos];
        //std::cout<<videoUsers << "\n";
        std::this_thread::sleep_for (std::chrono::seconds(5));
    }
}

void Shop(){
    int pos;
    for (pos = 1; pos < 25; pos+=4){
        sites[1] = users[pos];
        std::this_thread::sleep_for (std::chrono::seconds(5));
    }
}

void Discussions(){
    int pos;
    for (pos = 2; pos < 25; pos+=4){
        sites[2] = users[pos];
        std::this_thread::sleep_for (std::chrono::seconds(5));
    }
}

void Recipes(){
    int pos;
    for (pos = 3; pos < 25; pos+=4){
        sites[3] = users[pos];
        std::this_thread::sleep_for (std::chrono::seconds(5));
    }
}

