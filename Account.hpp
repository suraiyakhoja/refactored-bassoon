

#ifndef ACCOUNT_HPP_  
#define ACCOUNT_HPP_
#include <string>
#include <vector>
#include <iostream>
#include "Post.hpp"
#include "Network.hpp"


class Account
{
public:
    /*
        @pre : default constructor
        @post : sets the username and password of the Account to an empty string
        Sets the vector of posts to an empty vector
    */
    Account();

    /*
        @pre : parameterized constructor
        @post : sets the username and password of the Account to an empty string
        Sets the vector of posts to an emoty vector 
    */
    Account(std::string account_username, std::string account_password);

    /*
        @pre : setter method for username variable
        @param title : a reference to the username of the Account
        @post : sets the username.
    */
    void setUsername(const std::string& username);

    /*
        Getter method for username variable
        @return : the username of the Post
    */
    std::string getUsername() const;

    /*
        @pre : setter method for password variable
        @param title : a reference to the password of the Account
        @post : sets the password.
    */
    void setPassword(const std::string& password);

    /*
        Getter method for password variable
        @return : the password of the Post
    */
    std::string getPassword() const;

    //bool addPost(const std::string& post_title, const std::string& post_body);
    //^changed the function up a bit below

    /*
        @post: prints the vector of Posts using their display function
    */
    void viewPosts();

    /**
        Mutator function
        @param a_network_ptr  :   a pointer to a Network
        @post                 :   the Network pointer private member points to the input Network
    */
    void setNetwork(Network<Account> *a_network_ptr);

    /**
        Accessor function
        @return           :   the pointer to the Network the account is in
    */
    Network<Account>* getNetwork() const;

    /**
        STUB
        @param account_to_follow    :   the username of the Account to follow
        @return                     :   true if the account was successfully able to follow, false otherwise
        @post                       :   adds the username to the vector of following accounts only if
                                        it is affiliated to a Network AND it is not already following an account
                                        with the same username.
    */
    bool followAccount(std::string account_to_follow);

    /**
      @return      :   the vector of usernames the Account is following
    */
    std::vector<std::string> viewFollowing() const;

    /**
        MODIFY this function to also add the Account username to the Post and then add the Post
        to its Networks feed if it is connected to one. NOTE: you will need to add this functionality
        to the network as well (see Network modifications below - you may want to create a STUB for it,
        or implement this functionality after you modified the Network.)

        @param title   : A reference to the title used to generate the Post object
        @param body    : A reference to the body used to generate the Post object
        @post          : generates a Post with the given title and body and adds it to it's vector
                         of posts AND to the Network's feed if it is connected to a Network.
        @return        : Will return true if the Post does not have an empty title or body and the
                         Post is successfully added to the vector
    */
    bool addPost(std::string &title, std::string &body);


private: 
    std::string account_username;
    std::string account_password;
    std::vector<Post> account_posts;

    std::vector<std::string> following; //a vector of usernames the Account is following
    Network<Account> *account_network_ptr; //a pointer to the Network this Account is part of. 

};
#endif
