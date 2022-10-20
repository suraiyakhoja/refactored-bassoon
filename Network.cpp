
#include "Network.hpp"

/**
    Default constructor.
    Initializes private variables to default initial values.
*/
template<class T>
Network<T>::Network(): num_of_accounts(0)
{
}


/**
    @param target_account   :   string - the username of item we want the index of
    @return                 :   int - the index of the item, -1 if the account is not found
*/
template<class T>
int Network<T>::getIndexOf(const std::string target_account) const 
{
    bool found = false;
    int result = -1;
    int search_index = 0;

    while (!found && (search_index < num_of_accounts)) //search through accounts in net
    {
        if (accounts[search_index]->getUsername() == target_account) //if an account username is the same as the given account
        {
            found = true;
            result = search_index;
        }
        else 
        {
            search_index++; //to continue iterating 
        }
    }
    return result;
}


/**
    Used in main to access and test the getIndexOf private method. 
    @param an_account : a pointer to an account given in main 
    @return index of account 
*/
template<class T>
int Network<T>::getIndexOfHelper(T* an_account)
{
    return getIndexOf(an_account->getUsername()); 
}


/**
    Accessor function
    @return           : int -  the current size of the network (number of items in the array)
*/
template<class T>
int Network<T>::getSizeOfNetwork() const
{
    return num_of_accounts;
}


/**
    @return           : bool -  true if the bag is empty, false otherwise
*/
template<class T>
bool Network<T>::isEmpty() const
{
    return num_of_accounts == 0;
}


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
template<class T>
bool Network<T>::addAccount(T *new_account)
{
    
    int index_of_new_account = getIndexOf(new_account->getUsername()); //get index of given account

    bool has_room_to_add = (num_of_accounts < 200); 
    if (has_room_to_add) //if index is less than max capacity -> network can add more accounts
    {
        if (index_of_new_account == -1) //account is not in net
        {
            accounts[num_of_accounts] = new_account; //add account
            num_of_accounts++; //iterate through 
            return true;
        }
    }
    return false;
}


/**
    Mutator function
    @param an_account   :   a POINTER to the item that will be removed from Network
    @return             :   true if if the item was successfully removed, false otherwise
    @post               :   updates the bag/network to remove the pointer, if a pointer to that item was found.
*/
template<class T>
bool Network<T>::removeAccount(T *an_account)
{
    int located_index = getIndexOf(an_account->getUsername()); //get index of given account by finding user 
    bool can_remove = !isEmpty() && (located_index > -1); //checks to see if account is in network and network is not empty
    if (can_remove)
    {
        num_of_accounts--; 
        accounts[located_index] = accounts[num_of_accounts]; //replace removed account with last index 
    }
    return can_remove;

}



/**
    Mutator function
    @post             :   Empties the bag/network
*/
template<class T>
void Network<T>::clear()
{
    num_of_accounts = 0;
}


/**
    @param an_account   :   a POINTER to the item to find
    @return             :   true if the item was successfully found, false otherwise
*/
template<class T>
bool Network<T>::containsAccount(const T *an_account) const
{
    return getIndexOf(an_account->getUsername()) > -1;
}



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
template<class T>
void Network<T>::populateNetwork(const std::string input_file)
{
    
    std::fstream fin;
    fin.open(input_file, std::ios::in);
    std::string usr = "";
    std::string pswd = "";
    std::string line;
    std::string word;
    while (std::getline(fin, line)){
        if(line == ";") {
            break;
        }
        std::stringstream s(line);
        s >> usr;
        s >> pswd;
        if(usr == "" || pswd == "") {
            std::cout << "Improper format" << std::endl;
            break;
        }
        T* new_entry = new T(usr,pswd);
        bool is_added = addAccount(new_entry);
        if(!is_added) {
            std::cout << "Error when adding account" << std::endl;
            break;
        }
        usr = "";
        pswd = "";
    }
    fin.close();
    
}


/**
    Mutator function
    @param another_network      :   a reference to another Network

    @post                       :  Removes from the Network any items that also appear in the other Network.
                                   In other words, removes elements from the network on the left of the operator that
                                   are also found in the network on the right of the operator.
    Why is this useful? For example, given a network of known bot accounts, remove all bots from this Network.
*/
template<class T>
void Network<T>::operator-=(const Network<T> &another_network)
{
    
    int count = 0;
    while (count < this->getSizeOfNetwork()) //go through network
    {
        
        if (another_network.containsAccount(accounts[count])) //checks to see if given network has this network
        {
            this->removeAccount(accounts[count]); //calls removeAccount to, you guessed it, remove account
            count--;
        }
        count++;
    }
    
}


/**
    Accessor function
    @param an_account :   a reference to the item whose feed will be displayed
    @post             :   prints the feed of the given account by checking who they are following
                          and displaying all the posts from the feed that were made by those accounts.
                          Keep in mind that the Network parameters are general template types
                          in this project rather than accounts, although this functionality is
                          specific to accounts.
*/
template<class T>
void Network<T>::printFeedForAccount(const T &an_account)
{
    /*
    The Network class contains a vector of Posts made by all Accounts in the Network. If you are given an Account
    , could you get a list of all the usernames it's following? And given one of these usernames, could you go through 
    all the Posts in the Network and find all the Posts made by that username?
    */

    std::vector<std::string> an_account_followers = an_account.viewFollowing(); //list of followers of account
    for (int i = 0; i < an_account_followers.size(); i++)  //go through this accounts followers
    {
        for (int j = 0; j < network_feed.size(); j++) //go through the network feed
        {
            if (an_account_followers[i] == network_feed[j].getUsername()) //if account usernames match up
            {
                network_feed[j].displayPost(); //display that post 
            }
        }

    }
    
}

/**
    @param an_account       :   a reference to an item (account) 
    @param account_username :   username of the account it wants to follow 
    @return                 :   true if the item was authorized to follow, false otherwise

    @post                   :   the referenced Account follows another account with the username
                              specified by the second argument if they both exist in the network
*/
template<class T>
bool Network<T>::authenticateFollow(T &an_account, const std::string account_username)
{
    
    int index_of_an_account = getIndexOf(an_account.getUsername()); //index of an_account
    int index_of_account_username = getIndexOf(account_username); //index of account_username
    if (index_of_an_account != -1 && index_of_account_username != -1) //checks to see if they are both in the network
    {
        return true;
    }
    return false;
    
   
}


/**
    STUB
    Mutator function
    @param p          :   a reference to a Post be added to the feed
    @return           :   returns true if the Post was successfully added to the feed, false otherwise
    @post             :   Adds the post to its feed only if the Post was created by an Account
                          in this Network.
*/
template<class T>
bool Network<T>::addToFeed(const Post &p)
{
    /*
    bool result = false;
    int index = getIndexOf(p.getUsername());
    if (index != -1)
    {
        network_feed.push_back(p);
        result = true;
    }
    return result;
    */
    return true;
 
}
