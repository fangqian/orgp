//
//  scan.hpp
//  orgp
//
//  Created by LeslieZhu on 14-10-11.
//  Copyright (c) 2014年 LeslieZhu. All rights reserved.
//

#ifndef __orgp__scan__
#define __orgp__scan__

#include <stdio.h>
#include <iostream>
#include <fstream>
#include "org.hpp"

namespace orgp{
    

    class Scan{
    public:
        Scan();
        
        Scan(const std::string srcfile);
        
        void scan(Org *org);
        
        ~Scan();
        
        std::string srcfile();
        
    private:
        std::string _srcfile;
    };
}

#endif /* defined(__orgp__scan__) */
