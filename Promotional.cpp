
#include "Promotional.hpp"
#include "Post.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <time.h>
#include <regex>


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
    Promotional::Promotional(const std::string promo_name, const std::string promo_body, const std::string acct_username, std::string url):Post(promo_name, promo_body, acct_username) {
        //sets the title, body, username, and link (if its proper) of the Promo to the value of params
        Post::setTitle(promo_name);
        Post::setBody(promo_body);
        Post::setUsername(acct_username);
        
        //if link is proper
        setLink(url);


        //generate the current time and store it 
        //time_t time_stamp_ = time(NULL);
        getTimeStamp();

    }

    /*
        Accessor function
        @return : returns the post link
    */
   std::string Promotional::getLink() const{ return url; }

    /*
        @param link : a reference to the link that is in the format 'http://www.something.something'
                or 'http://www.something.something' with the last 'something being at least 2 
                characters.
        @return : true if the link is correctly formatted, false otherwise
        @post : if the link is not correctly formatted, store "Broken Link" in the link member
                variable, otherwise store the value of the parameter (Hint: see <regex>)
    */
    bool Promotional::setLink(const std::string& link) {
        const std::regex pattern("((http|https)://)(www.)[a-zA-Z0-9@:%._\\+~#?&//=]{2,256}\\.[a-z]{2,6}\\b([-a-zA-Z0-9@:%._\\+~#?&//=]*)");
        if(regex_match(link, pattern))  {
            url = link;
            return true;
        } 
        url = "Broken Link";
        return false;
    }

    /*
        @post : displays the entire Promotional post (example): 
                \n
                {post_title_} at {time_stamp_}:
                {post_body_} 
                \n
                {link}
                \n
    */
    void Promotional::displayPost() {
        std::cout << '\n' << getTitle() << " at ";
        getTimeStamp();
        std::cout << getBody() << std::endl;
        std::cout << getLink() << std::endl;
    }
