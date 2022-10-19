
#include "Account.hpp"



/*
    @pre : default constructor
    @post : sets the username and password of the Account to an empty string
    Sets the vector of posts to an empty vector
*/
Account::Account() 
{
    account_username = ""; //set account_username to empty string
    account_password = ""; //set account_password to empty string
    account_posts = {}; // empty account_posts vector
    //following = {};
    account_network_ptr = nullptr; //default value 
}

/*
    @pre : parameterized constructor
    @post : sets the username and password of the Account to an empty string
    Sets the vector of posts to an emoty vector 
*/
Account::Account(std::string username, std::string password)
{
    account_username = username;
    account_password = password;
    account_posts = {}; //empty account_posts vector
    //following = {};
    account_network_ptr = nullptr; //default value 
}

/*
    @pre : setter method for username variable
    @param title : a reference to the username of the Account
    @post : sets the username.
*/
void Account::setUsername(const std::string& username) { account_username = username; }

/*
    Getter method for username variable
    @return : the username of the Post
*/
std::string Account::getUsername() const { return account_username; }

/*
    @pre : setter method for password variable
    @param title : a reference to the password of the Account
    @post : sets the password.
*/
void Account::setPassword(const std::string& password) { account_password = password; }

/*
    Getter method for password variable
    @return : the password of the Post
*/
std::string Account::getPassword() const { return account_password; }


/*
    @param post_title : a reference to the title used to generate the Post object
    @param post_body : a reference to the body used to generate the Post object
    @post : generates a Post with the given title and body and adds it to its vector of posts
    @return : will return true if the Post does not have an empty title or body and the Post
    is successfully added to the vector
*/
/*
bool Account::addPost(const std::string& post_title, const std::string& post_body)
{
    //generates a Post with the given title and body and adds it to it's 
    //vector of posts
    
    Post new_post(post_title, post_body);
   
   //condition to test if the title and body are empty. if they are, return false for no add post
    if (post_title == "" || post_body == "" ) {
        return false;
    } 
    account_posts.push_back(new_post); //add post to account_posts vector
    return true;
}
*/

/*
    @post: prints the vector of Posts using their display function
*/
void Account::viewPosts() 
{
    for (int i = 0; i < account_posts.size(); i++) {
        account_posts[i].getTimeStamp();
        account_posts[i].displayPost();
    }

}


/**
    Mutator function
    @param a_network_ptr  :   a pointer to a Network
    @post                 :   the Network pointer private member points to the input Network
*/
void Account::setNetwork(Network<Account> *a_network_ptr) { account_network_ptr = a_network_ptr; }

/**
    Accessor function
    @return           :   the pointer to the Network the account is in
*/
Network<Account>* Account::getNetwork() const { return account_network_ptr; }

/**
    STUB
    @param account_to_follow    :   the username of the Account to follow
    @return                     :   true if the account was successfully able to follow, false otherwise
    @post                       :   adds the username to the vector of following accounts only if
                                    it is affiliated to a Network AND it is not already following an account
                                    with the same username.
*/
bool Account::followAccount(std::string account_to_follow)
{
    /*
    Account has a private member variable which is a pointer to the network, so through that pointer, 
    A can call authenticateFollow(), the Net work will check if they are both in the Network and return true or false.
    
    bool result;
    bool unique;
    bool authenticated = account_network_ptr->authenticateFollow(*this, account_to_follow);
    for (int i = 0; i < following.size(); i++)
    {
        if (following[i] != account_to_follow) unique = true;
    }

    if (authenticated == true && unique == true) result = true;
    else result = false;
    return result;
    
    following.push_back(account_to_follow);
    */
    return true;
}


/**
    @return      :   the vector of usernames the Account is following
*/
std::vector<std::string> Account::viewFollowing() const 
{ 
    return following; 
}


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
bool Account::addPost(std::string &title, std::string &body)
{

    Post new_post(title, body, this->getUsername()); //creates post 

    if (title == "" || body == "" ) { //conditions to make sure post ok
        return false;
    } 
        

    account_posts.push_back(new_post); //add post to vector of posts given account
    getNetwork()->addToFeed(new_post); //adds post to network feed
    

    return true;
}

