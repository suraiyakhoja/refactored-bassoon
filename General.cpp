
#include "General.hpp"



General::General(const std::string general_post_name, const std::string general_post_body, const std::string general_account_username)
:Post(general_post_name, general_post_body, general_account_username) 
{
    //sets the title, body, and username of the General post to params
    Post::setTitle(general_post_name);
    Post::setBody(general_post_body);
    Post::setUsername(general_account_username);

    //Generates the current time and stores it 
    //time_t time_stamp_ = time(NULL);
    getTimeStamp();

    //Initializes the array reaction_tally[6] with default values
    for (int i = 0; i < 6; i++) {reaction_tally[i] = 0;}

}


bool General::reactToPost(const Reactions& react) {
    if (react < 6) {
        reaction_tally[react] += 1;
        return true;
    }
    return false;
}

    
void General::getReactions() const{  
    std::vector<std::string> temp = {"Likes", "Dislike", "Laugh", "Wow", "Sad", "Angry"};
    for(int i = 0; i < 5 ; i++) {
        std::cout << temp[i] << " : " << reaction_tally[i] << " | ";
    }
    std::cout << temp[5] << " : " << reaction_tally[5] << std::endl;

}

    
void General::displayPost() {
    std::cout << '\n' << getTitle() << " at ";
    getTimeStamp();
    std::cout << getBody() << std::endl;
    getReactions();
    
        
}

    


