//
//  scan.cpp
//  orgp
//
//  Created by LeslieZhu on 14-10-11.
//  Copyright (c) 2014年 LeslieZhu. All rights reserved.
//

#include "scan.hpp"

namespace orgp{
    
    Scan::Scan()
    :_srcfile(){
        
    }
    
    Scan::Scan(const std::string srcfile)
    :_srcfile(srcfile){
        
    }
    
    void Scan::scan(Org *org){
        
        std::ifstream src(this->srcfile());
        
        if (!src.is_open()) {
            std::cout << "**Failed To Open File : " << this->srcfile() << std::endl;
            exit(-1);
        }
        
        std::string line;
        int line_count = 0;
        int page_num = 0;
        Page *page=new Page();
        
        while (src.good()) {
            getline(src, line);
            line_count++;
            
            if(line.find_first_of("#+TITLE") == 0){
                org->setTitle(line);
            }
            else if(line.find_first_of("#+AUTHOR") == 0){
                org->setAuthor(line);
            }
            else if(line.find_first_of("#+EMAIL") == 0){
                org->setEmail(line);
            }
            else if(line.find_first_of("#+DATE") == 0){
                org->setDate(line);
            }
            
            else if(line.find_first_of("*") == 0){
                
                if(page_num > 0){
                    org->add_page(page);
                }
                
                page_num++;
                page = new Page(line,page_num);
                
            }
            else{
                page->add_content(line);
            }
        }
        
    }
    
    Scan::~Scan(){
        
    }
    
    std::string Scan::srcfile(){
        return this->_srcfile;
    }
}