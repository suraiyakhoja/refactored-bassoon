
#ifndef POST_HPP_
#define POST_HPP_
#include <string>
#include <vector>
#include <iostream>
#include <time.h>


class Post
{

//private member variables
private: 
    std::string post_title;
    std::string post_body;
    time_t time_stamp_;
    std::string account_username; 
    

//public member variables 
public:
    
    /*
        @pre : Parameterized constructor for Post. 
        @param post_title : The title of the post
        @param post_body : The body content of the post
        @param account_username : the username of the account that added this post
        @post : sets the title and body of the Post to what was passed by the user.
                Also generates the current time and stores it in a variable. 
    
    */
    Post(const std::string title, const std::string body/*, const std::string username*/);
    Post(const std::string title, const std::string body, const std::string username);

    /*
        @pre : setter method for title variable
        @param title : a reference to the title of the Post
        @post : sets the title.
    */
    void setTitle(const std::string& title);

    /*
        Getter method for title variable
        @return : the title of the Post
    */
    std::string getTitle() const;

    /*
        @pre : setter method for the body variable
        @param body : a reference to body of the Post
        @post : sets the body content.
    */
    void setBody(const std::string& body);

    /*
        Getter method for body variable
        @return : the body of the Post
    */
    std::string getBody() const; 

    /*
        Getter method for the time variable
        @post : prints the time the Post was created to the standard output 
                as ascttine(localtime(&time_stamp))
    */
    void getTimeStamp() const;
    
    /*
        Print the post in the following format:
        {title} posted at {time}: {body}
    */
    void displayPost();
    
    /*
        Accessor/getter function for username variable
        @return : username associated with this post
    */
    std::string getUsername() const;

    /*
        Mutator/setter function for the username 
        @param username : a reference to the username associated with this Post
    */
   void setUsername(const std::string& username);

};
#endif
