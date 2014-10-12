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
            
            if(line.find("#+TITLE") == 0 or line.find("#+title") == 0){
                org->setTitle(line.substr(line.find(":")+1));
            }
            else if(line.find("#+AUTHOR") == 0 or line.find("#+author") == 0){
                org->setAuthor(line.substr(line.find(":")+1));
            }
            else if(line.find("#+EMAIL") == 0 or line.find("#+email") == 0){
                org->setEmail(line.substr(line.find(":")+1));
            }
            else if(line.find("#+DATE") == 0 or line.find("#+date") == 0){
                org->setDate(line.substr(line.find(":")+1));
            }
            else if(line.find("#+BEGIN") == 0 or
                    line.find("#+begin") == 0 or
                    line.find("#+END") == 0 or
                    line.find("#+end") == 0){
                continue;
            }
            else if(line.find("* ") == 0){
            
                
                if(page_num > 0){
                    org->add_page(page);
                    //page->view();
                }
                
                page_num++;
                page = new Page(line,page_num);
                
            }
            else{
                page->add_content(line);
            }
        }
        
        org->add_page(page);
        //page->view();
        
    }
    
    std::string Scan::cleanup(std::string line){
        
        
        
        return line;
    }
    
    Scan::~Scan(){
        
    }
    
    std::string Scan::srcfile(){
        return this->_srcfile;
    }
}