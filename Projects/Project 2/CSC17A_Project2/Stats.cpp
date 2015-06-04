/* 
 * File:   Stats.cpp
 * Author: Owner
 *
 * Created on June 3, 2015, 11:56 AM
 */

#include <cstdlib>
#include <fstream>
#include <iostream>
#include "Stats.h"
using namespace std;

void Stats::outfile(Player p,int turns){
    char name[20];
    cin.getline(name, 20, '\n');
    fstream statsFile;
    statsFile.open("player.txt", ios::out | ios::binary);
    statsFile.write(name,sizeof(name));
    statsFile.close();
    p.setName(name);
}

void Stats::infile(Player p){
    fstream statsFile;
    char name[20];
    statsFile.open("player.txt", ios::in | ios::binary);
    statsFile.read(name, sizeof(name));
    cout << "weeb" << endl;
    statsFile.close();
     p.setName(name);
}