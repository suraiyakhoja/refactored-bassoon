

//#include <string>
//#include <iostream>
#include "Post.hpp"
//#include "General.hpp"
//#include "Poll.hpp"
//#include "Promotional.hpp"


/*
    @pre : parameterized constructor
    @param title: the title of the post
    @param body: the body content of the post
    @param username : the username of the account that added this post
    @post : sets the title, body, and username of the Post to what was passed by the user
            Will also generate the current time and store it. 
*/
Post::Post(const std::string title, const std::string body, const std::string username):post_title(title), post_body(body), account_username(username) {
    //sets title, body, username, to parameter of Post
    post_title = title;
    post_body = body;
    account_username = username;
    //Generates the current time and stores it
    time_stamp_ = time(NULL);
}

/*
    @pre : setter method for title variable
    @param title : a reference to the title of the Post
    @post : sets the title.
*/
void Post::setTitle(const std::string& title) { post_title = title; }

/*
    Getter method for title variable
    @return : the title of the Post
*/
std::string Post::getTitle() const { return post_title; }

/*
    @pre : setter method for the body variable
    @param body : a reference to body of the Post
    @post : sets the body content.     
*/
void Post::setBody(const std::string& body) { post_body = body; }

/*
    Getter method for body variable
    @return : the body of the Post
*/
std::string Post::getBody() const { return post_body; }

/*
    Accessor/getter function for username variable
    @return : username associated with this post
*/
std::string Post::getUsername() const { return account_username; }

/*
    Mutator/setter function for the username 
    @param username : a reference to the username associated with this Post
*/
void Post::setUsername(const std::string& username) { account_username = username; }
/*
    Getter method for the time variable
    @post : prints the time the Post was created to the standard output 
            as ascttine(localtime(&time_stamp))
*/
void Post::getTimeStamp() const{ 
    std::cout << asctime(localtime(&time_stamp_));
}

/* 
    Print the post in the following format:
    {title} posted at {time}: {body}
*/
void Post::displayPost() 
{
    std::cout << post_title << " posted at " << time_stamp_ << ":" << std::endl;
    std::cout << post_body << std::endl;
}


    





