

#ifndef POLL_HPP_
#define POLL_HPP_
#include <string>
#include <vector>
#include "Post.hpp"


class Poll : public Post{ //Poll inherits public members from Post


private: //private members of class 
    std::vector<std::string> poll_options; //vector of strings containing the poll options
    std::vector<int> poll_options_votes; //vector of ints containing the number of votes
                                         // for each poll option
   


public: 
    /*
    Parameterized constructor.
    @param poll_title : the title of the Poll post
    @param poll_question : the question of the Poll post
    @param poll_creator_username : the username of the Account that added this poll (a string)
    @oaram poll_options : a vector of options for the Poll post.
    @post : sets the title, body, and username of the Poll post to the value of the parameters.
            It will also generate the current time and store it and will initialize the 
            vectors of options and their respective number of votes. 
    */
    Poll(const std::string poll_post_title, const std::string poll_post_question, const std::string poll_creator_username,  std::vector<std::string> poll_options);
    

    /*
    @param option_index : a reference to int between 0 < number of options
    @return : true if index is within range and we can vote for a poll, false otherwise
    @post : increments the poll votes based on the index which will refer to the index
            in the poll options
    */
    bool votePoll(const int& index);

    /*
    Mutator function used to either add a poll or change one of the poll options
    @param new_poll_option : a reference to the new poll option
    @param poll_for_replacement : a reference to int that can either represent the index of the 
                                  existing option that will be replaced or if choice_number > 
                                  current number of options, it will add this new option to the 
                                  poll. 
    @post: resets the number of votes for this option. 
    */
    void changePollOption(const std::string& new_poll_option, const int& new_poll_option_index);


    /*
    Accessor function
    @post : prints the reaction to the post in this format 
            (example where option_n is the string at postition n in the poll options vector):
            0 votes for: option_1
            5 votes for: option_2
            2 votes for: option_3
            ...
    */
    void getPollOptions() const;

    /*
    Accessor function
    @param option_index : the index of the option
    @return : returns the number of votes for a given option
    */
    int getPollVotes(int option_index) const;

    /*
    @post: displays the whole Poll post (example):
    \n
    {post_title_} at {time_stamp_};
    {post_body_}
    \n
    0 votes for: option_1
    5 votes for: option_2
    2 votes for: option_3
    ...
    \n
    */
    void displayPost();

};
#endif
