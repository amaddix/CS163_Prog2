//Ashley Maddix, CS 163, Prog 2, Spring 2018

//main.cpp
//menu
//receiving

//stack.cpp
//constuctor
//destuctor
//push
//save_in
//pop
//peek
//display

//queue.cpp
//constructor
//destuctor
//enqueue
//save_out
//save_message 
//dequeue
//peek
//display

#include <iostream>
#include <cstring> 
#include <cstdlib>
#include <ctime>

using namespace std;

//A constant global variable for the size of all my arrays in
//my LLL of arrays
const int MAX=5;

//struct for all the information included in a message
struct message
{
	//dynamically allocated char arrays
	char * name;
	char * number;
	char * email;
	char * nick;
	
	bool blocked;
	bool secret;

	char * date;
	char * time;
	char * subject;
	char * body;
		
};

//stuct for the node for my stack
struct s_node
{
	// a pointer to an array of messages
	message * list;
	//a next points for my s_nodes
	s_node * next; 
};

//stuct for the node for my queue
struct q_node
{
	message sent; // variable of type message
	//to show the information from the message initally sent
	// (if user is responding to a message
	message reply;//varible to use to show the information from the message
	//we are sending out ( or our reply to another messge).
	bool responce; //bool variable to tell if a certain message was 
	//a responce or a sent message on its own

	q_node * next; //pointer to the next q_node
};	

//class for the messages that the user received (which will go into the stack)
class received_message
{
	public:
		// constructor for recived messages
		received_message(); 
		// destuctor for the recived messages
		~received_message();

		//function to add the information added from from 
		//'sent _in' ( which should be filled from user) at the 
		// d beggining of the ata structure	
		int push( message sent_in);
		//function to remove the most recient peice of information added
		// from our data structure
		int pop ();
		//function to look at the  last message added, and save it into the 
		// variable 'peeked' and passed back to client program.
		int peek (message & peeked);	
		//function to display the most recient message recieved
		int display();

	
	private:
		
		// a pointer to the head of our stack
		s_node * stack_head; 
		// an int to keep track of what index of our
		//head we are currently at.
		int stack_index;

		//function to save the information from 'sent_in'
		//into the appropriate place in our data structure
		int save_in(message & sent_in);
		//function to clear everything in the index of our array
		//when deleting
		int clear_index();
};

// class for the messages being sent out by user ( or their responces)
// (class for our queue)
class replied_message
{
	public: 
		//constuctore for the sent messages
		replied_message();
		//destuctor for the messages sent out
		~replied_message();

		//function to add the mesages sent from user to the 
		// to the end of our data structure (using the information from
		// 'sent_in'), if the sent message was a responce, then the 
		//message saved in peeked, will be saved as the message responded to. 
		int enqueue(message sent_in, message peeked, bool a_responce);
		// function to delete the message sent longest ago.
		int dequeue ();
		//function to look at the message sent longest ago, and save
		// into the variable 'peeked'
		int peek ( message & peeked);
		// function to display the contesnt our the message sent
		// longest ago.
		int display();
		//wrapper function for the recursive 'count'
		int count();
		//functions to clear everything out of my messages sent and 
		//relied to
		int clear_sent();
		int clear_reply();

	private:
		//pointer to the end out our queue
		q_node * queue_rear;

		// function to save the information we found from peeked
		// as the contents of the message we're responding to.
		int save_message(message & peeked);
		// function to save the information sent in from user
		// as the contents of our message
		int save_out(message & sent_in);
		//recusive function to count how many messages are
		// waiting to get 'sent out'
		int count (q_node * queue_rear);
};

// function to display the option the user has
char menu (char & choose);
// function to get the contents of the message we're recieving or sending out
int receiving (message & sent_in, char choose);
	
