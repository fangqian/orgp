//
//  main.cpp
//  orgp
//
//  Created by LeslieZhu on 14-10-7.
//  Copyright (c) 2014年 LeslieZhu. All rights reserved.
//


#include "org.hpp"
#include "scan.hpp"
using namespace orgp;
using namespace std;

const std::string program = "Orgp";
const std::string version = " version 0.1";
const std::string author  = " by Leslie Zhu<pythonisland@gmail.com>";

const std::string usage =
"\nUsage:\n"
"\torgp org-file\n";


int main(int argc, const char * argv[]) {
    
    if(argc != 2){
        std::cout << program << version << author << "\n";
        std::cout << usage << "\n";
        return -1;
    }
    
    Org *org = new Org();

    Scan *scan = new Scan(argv[1]);
    
    scan->scan(org);
    
    org->display();
    
    return 0;
}
