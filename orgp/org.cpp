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
        
        this->_pages += 1;

        
        
    }
    
    void Org::display(const std::string prompt){
        std::cout << prompt << "\n";
        for(Page *p = this->begin->next; p != NULL; p = p->next){

            p->view();
        }
        
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