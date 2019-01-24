#include "PowerTycoon.h"
#include <iostream>
#include <thread>
#include <math.h>
#include <iomanip>

int rotations;

int findBiggestServer(int);
int getServerData();
void print(int);

int main() {
    int servers;
    servers = getServerData();
    getSampleData();                        // Read from 'usersSample.txt'
    std::thread video (Videos);             // Initialise Threads
    std::thread shop (Shop);                //
    std::thread discussions (Discussions);  //
    std::thread recipes (Recipes);          //
    int total;
    rotations = 0;
    int oldVideoUsers, oldShopUsers, oldDiscussionUsers, oldRecipeUsers = -1;   // By making
    while (rotations < 6 ){                 //Outputs to terminal for each line in 'usersSample.txt'
        print(servers);
    }
    video.join();                           // Join Threads
    shop.join();                            //
    discussions.join();                     //
    recipes.join();                         //
    return 0;
}

int getServerData(){ //Gets the quantity of servers from the user
    int servers;
    std::cout << "Enter how many servers you have: ";
    std::cin >> servers;
    return servers;
}

int findBiggestServer(int serversInUse){
    int max = sites[0];             // Finds the server with the highest amount of servers
    int maxPos = 0;                 // dedicated to it and returns its position in
    int pos;                        // 'sites'
    for (pos = 0; pos < 4; ++pos){  //
        if (sites[pos] > max) {     //
            max = sites[pos];       //
            maxPos = pos;           //
        }
    }
    return maxPos;
}

void print(int servers){
    int total;
    int oldVideoUsers, oldShopUsers, oldDiscussionUsers, oldRecipeUsers = -1;
    if ((sites[0] != oldVideoUsers) && (sites[1] != oldShopUsers) && (sites[2] != oldDiscussionUsers) && (sites[3] != oldRecipeUsers)){
        total = sites[0] + sites[1] + sites[2] + sites[3];
        float serversToSite[4];
        serversToSite[0] = ((float) sites[0] / (float) total) * servers;    // Calculation for how many servers should be given to each site
        serversToSite[1] = ((float) sites[1] / (float) total) * servers;    //
        serversToSite[2] = ((float) sites[2] / (float) total) * servers;    //
        serversToSite[3] = ((float) sites[3] / (float) total) * servers;    //
        int serversInUse = floor(serversToSite[0]) + floor(serversToSite[1]) + floor(serversToSite[2]) + floor(serversToSite[3]);
        if (serversInUse < servers) {
            int maxPos = findBiggestServer(serversInUse);
            serversToSite[maxPos] += servers - serversInUse;
        }
        std::cout << std::setprecision(0) <<std::fixed; 
        std::cout << "Video Site Servers: " << floor(serversToSite[0]) << " Shop Site Servers: " << floor(serversToSite[1])
        << " Discussion Site Servers: " << floor(serversToSite[2]) << " Recipes Site Servers: " << floor(serversToSite[3]) <<"\n";
        oldVideoUsers = sites[0];
        oldShopUsers = sites[1];
        oldDiscussionUsers = sites[2];
        oldRecipeUsers = sites[3];
        ++rotations;
    }
}