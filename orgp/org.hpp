//
//  org.hpp
//  orgp
//
//  Created by LeslieZhu on 14-10-11.
//  Copyright (c) 2014年 LeslieZhu. All rights reserved.
//

#ifndef __orgp__org__
#define __orgp__org__

#include <stdio.h>
#include <iostream>
#include <vector>
#include <ncurses.h>
#include <cstdlib>
#include <string>
#include <sstream>

namespace orgp{

    class Page;
    class Org;
    

    
    class Org{
    public:
        
        Org();
        
        Org(const std::string title, const std::string author, const std::string email,
            const std::string date);
        
        ~Org();
        
        void add_page(Page *page);
        
        void display();
        void homepage();
        void eachPage(Page *page);
        
        std::string num2str(double i);
        
    
        
        std::string author();
        void setAuthor(const std::string author);
        
        std::string title();
        void setTitle(const std::string title);
        
        std::string date();
        void setDate(const std::string date);
        
        std::string email();
        void setEmail(const std::string email);
        
        int pages();
        void setPages(const int pages);
        
        
        void inline printw( const int cur_line,const int cur_col,std::string msg );
        
    private:
        std::string _author;
        std::string _title;
        std::string _date;
        std::string _email;
        int _pages;
        Page *begin;
        Page *end;
    };
    
    
    
    class Page{
    public:
        Page();
        
        Page(const std::string section);
        
        Page(const int num_of_pages);
        
        Page(const std::string section,const int num_of_pages);
        
        ~Page();
        
        void view();
        
        void add_content(const std::string str);
        
        int num_of_pages();
        void set_num_of_pages(const int num_of_pages);
        
        std::string section();
        void setSection(const std::string section);
        
        
    public:
        int _num_of_pages;
        std::string _section;
        std::vector<std::string> _content;
        Page *prev;
        Page *next;
    };
    
    
    
    
}

#endif /* defined(__orgp__org__) */
