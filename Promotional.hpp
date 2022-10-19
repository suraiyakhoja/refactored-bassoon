
#ifndef PROMOTIONAL_HPP_
#define PROMOTIONAL_HPP_
#include <string>
#include <vector>
#include <iostream>
#include "Post.hpp"



class Promotional : public Post{ //Poll inherits public members from Post

//private member variables
private:
    std::string url; //string that represents a url


public:
    /*
        Parameterized constructor.
        @param promo_name : the name of the Promotional post (string)
        @param promo_body: the body of the Promotional post (string)
        @param acct_username : the username of the Account that added this post (string)
        @param url : the link of the Promotional post (string)
        @post : Sets the title, body, username, and link (if it's a proper link otherwise 
                "Broken Link") of the Promotional to the value of the parameters. 
                Also generates the current time and stores it. 
    */
    Promotional(const std::string promo_name, const std::string promo_body, const std::string acct_username, std::string url);

    /*
        Accessor function
        @return : returns the post link
    */
   std::string getLink() const;

   /*
   @param link : a reference to the link that is in the format 'http://www.something.something'
            or 'http://www.something.something' with the last 'something being at least 2 
            characters.
    @return : true if the link is correctly formatted, false otherwise
    @post : if the link is not correctly formatted, store "Broken Link" in the link member
            variable, otherwise store the value of the parameter (Hint: see <regex>)
   */
    bool setLink(const std::string& link);

    /*
        @post : displays the entire Promotional post (example): 
                \n
                {post_title_} at {time_stamp_}:
                {post_body_} 
                \n
                {link}
                \n
    */
    void displayPost();






};
#endif
