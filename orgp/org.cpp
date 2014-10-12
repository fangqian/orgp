//
//  org.cpp
//  orgp
//
//  Created by LeslieZhu on 14-10-11.
//  Copyright (c) 2014年 LeslieZhu. All rights reserved.
//


#include "org.hpp"
//#include <iostream>

namespace orgp{
    
    Org::Org()
    :_title(),_author(),_email(),_date(),_pages(0){
        this->begin = new Page();
        this->end = NULL;
        
        this->begin->next = this->end;
    }
    
    Org::Org(const std::string title,
             const std::string author,
             const std::string email,
             const std::string date)
    :_title(title),_author(author),_email(email),_date(date),_pages(0){
        this->begin = new Page();
        this->end = NULL;
        
        this->begin->next = this->end;
    }
    
    Org::~Org(){
        for(Page *p = this->begin; p != NULL; p = p->next){
            delete p;
        }
        
    }
    
    void Org::add_page(Page *page){
        
        
        Page *p = this->begin;
        while(p->next != NULL){
            p = p->next;
        }
      
        p->next = page;
        page->next = this->end;
        page->prev = p;
        
        this->_pages += 1;

        
        
    }
    
    std::string Org::num2str(double i) {
        std::stringstream ss;
        ss << i;
        return ss.str();
    }
    
    
    void inline Org::printw( const int cur_line,const int cur_col,std::string msg ){
        mvprintw(cur_line, cur_col, "%s\n", msg.c_str());
    }
    
    void Org::homepage(){
        int cur_line = 1;
        attron(A_BOLD);
        if (this->title().length() > 0){
            this->printw(cur_line,0,"Title: "+this->title());
            cur_line++;
        }
        
        if (this->author().length() > 0){
            this->printw(cur_line,0, "Author:"+this->author());
            cur_line++;
        }
        
        if (this->email().length() > 0){
            this->printw(cur_line,0,"Email:"+this->email());
            cur_line++;
        }
        
        if (this->date().length() > 0){
            this->printw(cur_line,0,"Date:"+this->date());
            cur_line++;
        }
        attroff(A_BOLD);
        
        
        
    }
    
    void Org::eachPage(Page *p){
        int cur_line;
        if ((p->section()).length() > 0){
            attron(A_BOLD);
            this->printw(2,0, p->section());
            attroff(A_BOLD);
            this->printw(4,0, "------------------------------------");
        }
        
        refresh();
        
        cur_line = 5;
        std::vector<std::string>::iterator j;
        
        for(j=p->_content.begin();j != p->_content.end(); ++j){
            this->printw(cur_line,0, *j);
            cur_line++;
            refresh();
            
        }
    }
    
    void Org::display(){
        
        int ch;
        int row,col;
        std::string msg;
        
        initscr();
        getmaxyx(stdscr,row,col);
        raw();
        noecho();

        this->homepage();
        this->printw(row-2,col/2,
                     "Page: 0/" + this->num2str(this->pages()));
        //refresh();

        Page *p = this->begin;
        
        
        while(this->end != p){
            ch=getch();
            switch(ch){
                case 'q':
                    p=this->end;
                    
                    break;
                case 'H':
                    p = this->begin;
                    break;
                case 'E':
                    while(p->next != this->end){
                        p=p->next;
                    }
                    break;
                case 'k':
                    if(this->begin != p){
                        p = p->prev;
                    }
                    break;
                case 'j':
                default:
                    p = p->next;
                    break;
            }
            
            clear();
            if(this->begin == p){
                this->homepage();
                this->printw(row-2,col/2,
                             "Page: 0/" + this->num2str(this->pages()));
            } else if(this->end != p){
                this->eachPage(p);
                this->printw(row-2,col/2,
                             "Page: " + this->num2str(p->num_of_pages()) +
                             "/" + this->num2str(this->pages()));
            }
            
            
            
        }
        
        clear();
        //this->printw(row/2,col/2,"Orgp Done!");
        //getch();
        
        echo();
        endwin();
        
        std::cout << "Orgp Done!" << "\n";
    }

    std::string Org::author(){
        return this->_author;
    }
    
    void Org::setAuthor(const std::string author){
        this->_author = author;
    }
    
    std::string Org::title(){
        return this->_title;
    }
    
    void Org::setTitle(const std::string title){
        this->_title = title;
    }
    
    std::string Org::date(){
        return this->_date;
    }
    
    void Org::setDate(const std::string date){
        this->_date = date;
    }
    
    std::string Org::email(){
        return this->_email;
    }
    
    void Org::setEmail(const std::string email){
        this->_email = email;
    }
    
    int Org::pages(){
        return this->_pages;
    }
    
    void Org::setPages(const int pages){
        this->_pages = pages;
    }
    
    
    
    Page::Page()
    :_section(),_content(),_num_of_pages(0){
        
    }
    
    Page::Page(const std::string section)
    :_section(section),_content(),_num_of_pages(0){
        
    }
    
    Page::Page(const int num_of_pages)
    :_section(),_content(),_num_of_pages(num_of_pages){
        
    }
    
    Page::Page(const std::string section,const int num_of_pages)
    :_section(section),_content(),_num_of_pages(num_of_pages){

        
    }
    
    Page::~Page(){

    }
    
    void Page::view(){
        std::cout << "section: " << this->_section
                  << " , page num: " << this->_num_of_pages << "\n";
        

        std::vector<std::string>::iterator j;
        
        for(j=this->_content.begin();j != this->_content.end(); ++j){
            std::cout << "\t\t" << *j << "\n";
        }
    }
    
    void Page::add_content(const std::string str){
        this->_content.push_back(str);
        

    }
    
    int Page::num_of_pages(){
        return this->_num_of_pages;
    }
    void Page::set_num_of_pages(const int num_of_pages){
        this->_num_of_pages = num_of_pages;
    }
    
    std::string Page::section(){
        return this->_section;
    }
    
    void Page::setSection(const std::string section){
        this->_section = section;
    }

}