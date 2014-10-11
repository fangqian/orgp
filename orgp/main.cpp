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

int main(int argc, const char * argv[]) {
    
    Org *org = new Org();

    Scan *scan = new Scan("/Users/LeslieZhu/GIT/orgp/sample.org");
    
    scan->scan(org);
    
    org->display("view: ");
    
    return 0;
}
