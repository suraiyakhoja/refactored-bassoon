

#ifndef NETWORK_H_
#define NETWORK_H_
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Post.hpp"




template<class T>
class Network 
{
private:
    T *accounts[200];                   //an array of pointers to Network items
    int num_of_accounts;                //a count of the current number of accounts in the network
    std::vector<Post> network_feed;     //vector of Posts: all posts posted by accounts in the network

    /**
        @param target_account   :   string - the username of item we want the index of
        @return                 :   int - the index of the item, -1 if the account is not found
    */
    int getIndexOf(const std::string target_account) const; 

public:

    /**
        Default constructor.
        Initializes private variables to default initial values.
    */
    Network();

    /**
        Used in main to access and test the getIndexOf private method. 
        @param an_account : a pointer to an account given in main 
        @return index of account 
    */
    int getIndexOfHelper(T* an_account);

    /**
        Accessor function
        @return           : int -  the current size of the network (number of items in the array)
    */
    int getSizeOfNetwork() const;

    /**
        @return           : bool -  true if the bag is empty, false otherwise
    */
    bool isEmpty() const;

    /**
        @param new_account      : a POINTER to the item that will be added to the Network
        @return                 : bool- true  if the item was successfully added, false otherwise
        @post                   : stores a pointer to the item, if there is room. This is a network specific function,
                                  it has an additional constraint: the item will be added only if no other item in the network
                                  has the same username (usernames are considered unique)
                                  REMEMBER WE ARE STORING POINTERS TO ITEMS, NOT ITEMS.
                                  Finally, the Account being added to the network will update it's private member to point to this network
                                  (see Account class modifications below, you may come back and implement this feature after
                                  you work on Task 2, but don't forget!!!).
                                  NOTE: every object in C++ has access to a pointer to itself called `this`, thus the nework can pass `this` pointer to the account!
    */
    bool addAccount(T *new_account);

    /**
        Mutator function
        @param an_account   :   a POINTER to the item that will be removed from Network
        @return             :   true if if the item was successfully removed, false otherwise
        @post               :   updates the bag/network to remove the pointer, if a pointer to that item was found.
    */
    bool removeAccount(T *an_account);

    /**
        Mutator function
        @post             :   Empties the bag/network
    */
    void clear();

    /**
        @param an_account   :   a POINTER to the item to find
        @return             :   true if the item was successfully found, false otherwise
    */
    bool containsAccount(const T *an_account) const;

    /**
        Mutator function
        @param input_file :   the name of an input file
        @pre              :   The format of the text file is as follows:
                              username password
                              username password
                              ;

                              where ';' signals the end of the file. Check the provided example (accounts.txt).

        @post             :   Reads every line in the input file, creates an Account from that information and
                              adds the Account to the network. If a line of input is missing some required information,
                              it prints out "Improper Format" and terminates.
                              Keep in mind that, although the input will always be an Account, the Network class is
                              a template, thus it will store a pointer to a generic type. It will do so by creating a new
                              dynamic object of type ItemType but passing the account information (username and password)
                              as to the Account constructor. This is a bit hacky, but it will work for our Network.
    */
    void populateNetwork(const std::string input_file);

    /**
        Mutator function
        @param another_network      :   a reference to another Network

        @post                       :  Removes from the Network any items that also appear in the other Network.
                                       In other words, removes elements from the network on the left of the operator that
                                       are also found in the network on the right of the operator.
        Why is this useful? For example, given a network of known bot accounts, remove all bots from this Network.
    */
    void operator-=(const Network<T> &another_network);

    /**
        Accessor function
        @param an_account :   a reference to the item whose feed will be displayed
        @post             :   prints the feed of the given account by checking who they are following
                              and displaying all the posts from the feed that were made by those accounts.
                              Keep in mind that the Network parameters are general template types
                              in this project rather than accounts, although this functionality is
                              specific to accounts.
    */
    void printFeedForAccount(const T &an_account);

    /**
        @param an_account       :   a reference to an item (account) 
        @param account_username :   username of the account it wants to follow 
        @return                 :   true if the item was authorized to follow, false otherwise

        @post                   :   the referenced Account follows another account with the username
                                    specified by the second argument if they both exist in the network
    */
    bool authenticateFollow(T &an_account, const std::string account_username);

    /**
        STUB
        Mutator function
        @param p          :   a reference to a Post be added to the feed
        @return           :   returns true if the Post was successfully added to the feed, false otherwise
        @post             :   Adds the post to its feed only if the Post was created by an Account
                              in this Network.
    */
    bool addToFeed(const Post &p);
    


};
#include "Network.cpp"
#endif
