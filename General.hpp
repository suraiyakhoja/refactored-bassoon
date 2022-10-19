

#ifndef GENERAL_HPP_
#define GENERAL_HPP_
#include <string>
#include "Post.hpp"
#include "Poll.hpp"
#include "Promotional.hpp"


/**
    ENUM used as indexes to reactions_
*/
enum Reactions {
    LIKE = 0,
    DISLIKE = 1,
    LAUGH = 2,
    WOW = 3,
    SAD = 4,
    ANGRY = 5
};
class General : public Post{ //General inherits public members from Post

//private member variables: 
private: 
    /*
        reaction_tally is an integer array of size 6 that, indexed by Reactions, will store the number
        of reactions of each type the post has received. 
    */
    int reaction_tally[6];
    

//public member functions:
public: 
    /*
        Parameterized constructor
            @param general_name : the name of the General post
            @param general_body : the body of the General post
            @param general_username : the username of the Account that added this Post 
            @post : Sets the title, body, and username of the General post to the parameters. 
                    It will also generate the current time and store it and it 
                    ininializes the array with default values. 
    */
    General(const std::string general_post_name, const std::string general_post_body, const std::string general_account_username);

    /*
        Mutator function to add a reaction.
        @param : A reference to reaction (represented by a value of type Reaction)
        @return : return True if the react to the post is successful or false if the reaction 
                  provided is not within a valid Reaction value.
        @post : Incrememts the array at the index corresponding to the input Reaction.
    */
    bool reactToPost(const Reactions& react);

    /*
        @post: Prints the reaction to the post in this format (example): 
               Like : 2 | Dislike : 0 | Laugh : 4 | Wow : 2 | Sad : 1 | Angry : 5
    */
    void getReactions() const;

    /*
        @post : Displays the General post (example):
                \n
                {post_title_} at {time_stamp_}:
                {post_body_}
                \n
                Like : 2 | Dislike : 0 | Laugh : 4 | Wow : 2 | Sad : 1 | Angry : 5
                \n 
    */
    void displayPost();

};
#endif
