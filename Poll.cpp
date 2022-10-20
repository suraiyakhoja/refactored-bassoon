

#include "Poll.hpp"
#include "Post.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <time.h>

 

Poll::Poll(const std::string poll_post_title, const std::string poll_post_question, const std::string poll_creator_username, std::vector<std::string> options)
:Post(poll_post_title,poll_post_question, poll_creator_username){
    //set the title, body, and username of the Poll post to what was passed by the user 
    Post::setTitle(poll_post_title);
    Post::setBody(poll_post_question);
    Post::setUsername(poll_creator_username);
    

    //generate the current time and store it 
    //time_t time_stamp_ = time(NULL);
    getTimeStamp();
    
    //initialize the vectors of options and their respective number of votes
    //side note: respective number of votes poll_options_votes was not passed as parameter
    for (int i = 0; i < poll_options.size(); i++) {
        poll_options.push_back(options[i]);
        poll_options_votes.push_back(0);
    }
  
    

}
    

bool Poll::votePoll(const int& index){


    //true if index is within range and we can vote for a poll, false otherwise
    if (index < poll_options.size()) {        
        poll_options_votes[index] += 1;   //increments the poll votes based on the index which will refer to the index
        return true;
    } 
    return false; 
}

/*
    Mutator function used to either add a poll or change one of the poll options
    @param new_poll_option : a reference to the new poll option
    @param poll_for_replacement : a reference to int that can either represent the index of the 
                                existing option that will be replaced or if choice_number > 
                                current number of options, it will add this new option to the 
                                poll. 
    @post: resets the number of votes for this option. 
*/
void Poll::changePollOption(const std::string& new_poll_option, const int& new_poll_option_index){ 

    //the new poll option is replacing an old one. 
    if (new_poll_option_index < poll_options.size()) { 
        poll_options[new_poll_option_index] = new_poll_option; //replace the old option at given index with the new option
        poll_options_votes[new_poll_option_index] = 0; //set the number of votes for the replaced option to 0
    } else {
        //a new poll option is being added to the vector of options
        poll_options.push_back(new_poll_option); //push the new option to the back of the vector
        poll_options_votes.push_back(0); //set the number of votes for the new option to 0
    }
}


/*
    Accessor function
    @post : prints the reaction to the post in this format 
            (example where option_n is the string at postition n in the poll options vector):
            0 votes for: option_1
            5 votes for: option_2
            2 votes for: option_3
            ...
*/
void Poll::getPollOptions() const{
    for (int i{0} ; i <= poll_options.size() -1 ; i++) {
        std::cout << poll_options_votes[i] << " votes for: " << poll_options[i] << std::endl;
    }
    std::cout << std::endl;
}

/*
    Accessor function
    @param option_index : the index of the option
    @return : returns the number of votes for a given option
*/
int Poll::getPollVotes(int option_index) const{
    return poll_options_votes[option_index];
}

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
void Poll::displayPost(){
    std::cout << '\n' << getTitle() << " at ";
    getTimeStamp();
    std::cout << getBody() << std::endl;
    getPollOptions();
    
}
    
    
    
    
    
    
    
    
    



