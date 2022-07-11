#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

void recycling_locations();
void recycling_information();
void recycling_facts();
vector<string> get_facts();

int main(){

    //introduce the user to the program
    cout << "\nCS361 Assignment #4 UI" << endl;

    //create a string to hold the user's input
    string input;

    //until the user runs the "quit" command, ask them what they would like to do
    while(true){

        //display the command options and get input from the user
        cout << "\n1) Find a recycling location near me using an address or zip code" << endl;
        cout << "2) Information on what can be recycled" << endl;
        cout << "3) Give me an interesting recycling fact" << endl;
        cout << "4) Quit" << endl;
        cout << "Please enter corresponding number of the option you'd like to run: ";
        cin >> input;

        //run the correct command
        if(input != "" && input[0] == '1')
            recycling_locations();
        else if(input != "" && input[0] == '2')
            recycling_information();
        else if(input != "" && input[0] == '3')
            recycling_facts();
        else if(input != "" && input[0] == '4')
            break;
        else
            cout << "Invalid input. Please enter a valid command" << endl;
    }

    return 0;
}

void recycling_locations(){
    cout << "\nYou chose to find recycling locations near you." << endl;
    unsigned int step = 0;
    bool use_address;
    string input;
    string street;
    string city;
    string state;
    string zipcode;

    //run through the steps of getting the user's address/zipcode
    while(true){

        if(step==0){
            //let the user decide whether they'd like to use a zip code or full address
            while(true){
                //display the command options and get input from the user
                cout << "\n1) Find location via zip code" << endl;
                cout << "2) Find location via address" << endl;
                cout << "3) Quit" << endl;
                cout << "Please enter corresponding number of the option you'd like: ";
                cin >> input;

                //run the correct command
                if(input != "" && input[0] == '1'){
                    use_address = false;
                    step = 4;
                    break;
                }
                else if(input != "" && input[0] == '2'){
                    use_address = true;
                    step = 1;
                    break;
                }
                else if(input != "" && input[0] == '3')
                    return;
                else
                    cout << "Invalid input. Please enter a valid command" << endl;
            }
        }

        else if(step == 1){
            //get the user's street address
            cout << "\nPlease enter your street address (or enter \"back\" to return to the previous step): ";
            cin >> street;

            //run the correct command
            if(street != "" && street == "back")
                step--;
            else
                step++;
        }

        else if(step == 2){
            //get the user's city
            cout << "\nPlease enter your city (or enter \"back\" to return to the previous step): ";
            cin >> city;

            //run the correct command
            if(city != "" && city == "back")
                step--;
            else
                step++;
        }

        else if(step == 3){
            //get the user's state
            cout << "\nPlease enter your state (or enter \"back\" to return to the previous step): ";
            cin >> state;

            //run the correct command
            if(state != "" && state == "back")
                step--;
            else
                step++;
        }

        else if(step == 4){
            //get the user's zip code
            cout << "\nPlease enter your zipcode (or enter \"back\" to return to the previous step): ";
            cin >> zipcode;

            //run the correct command
            if(zipcode != "" && zipcode == "back"){
                if(use_address)
                    step = 3;
                else
                    step = 0;
            }
            else
                step++;
        }

        else{
            break;
        }
    }

    //display results
    cout << "\nHere are the 5 closest locations to you:" << endl;
    cout << "1234 Super St. Corvallis, OR 97331" << endl;
    cout << "5969 Crazy Frog Ln. Albany, OR 92786" << endl;
    cout << "1279 Ducks-Suck Ave. Eugene, OR 80085" << endl;
    cout << "4464 Parkington Ln. Beaverton, OR 28678" << endl;
    cout << "9034 Beach Dr. Astoria, OR 98254" << endl;

}

void recycling_information(){
    //print all of the recycling information to the user interface
    cout << "\nYou chose to view recycling information." << endl;
    cout << "The three categories of recyclables are Bottles and Cans, Paper, and Cardboard." << endl;

    cout << "\nBottles and Cans:" << endl;
    cout << "> Glass bottles and jars" << endl;
    cout << "> Aluminum and Tin Cans" << endl;
    cout << "> Plastic bottles (containers with narrow neck) and jugs (bottles with a handle" << endl;
    cout << "Note: Bottles and Cans should be emptied, washed, and dried. Caps should be removed whenever possible. They must have contained food or beverages. Glass containers from labs are not accepted. " << endl;

    cout << "\nPaper:" << endl;
    cout << "> Notebook paper, spam mail, newspapers, and magazines" << endl;
    cout << "> Paperback books, yellow pages, and notebooks (metal binding is accepted!)" << endl;
    cout << "> Paper bags and packing paper" << endl;
    cout << "> Paperboard (heavier, non-corrugated paper)" << endl;

    cout << "\nNot acceptable Paper products:" << endl;
    cout << "> Hardback books" << endl;
    cout << "> Cartons and aseptic containers" << endl;
    cout << "> Butcher paper" << endl;
    cout << "> Egg cartons" << endl;
    cout << "> Paper cups and plates" << endl;
    cout << "> Napkins and paper towels" << endl;
    cout << "Note: Paper should be greater than 2x2 inches in size, otherwise it should be thrown away or composted if it is 100 percent paper." << endl;

    cout << "\nOnly Flattened, corrugated cardboard is accepted. Contents must be emptied and the cardboard must not be contaminated with food and oil. Must be placed in a marked container outside your building, located near the dumpsters." << endl;
    return;
}

void recycling_facts(){
    //prepare to give the user a fact
    cout << "\nYou chose to receive an interesting recycling fact." << endl;
    srand(time(NULL));
    string input;

    //get the list of facts
    vector<string> facts = get_facts();
    unsigned int num_facts = facts.size();

    while(true){
        //choose a random one of those facts
        int idx = rand()%num_facts;

        //display the chosen fact
        cout << "\n" << facts[idx] << endl;

        //ask the user if they'd like another fact
        cout << "\nWould you like another fact? (1-yes, 0-no): ";
        cin >> input;

        //break out of the loop if they choose 'no'
        if(input != "" && input[0] == '0')
            break;
        else if(input != "" && input[0] != '1')
            cout << "Invalid input. Please enter a valid command" << endl;
    }
    
    return;
}

vector<string> get_facts(){
    //create a vector and fill it with all of the recycling facts we know
    vector<string> facts;
    facts.push_back("More than 52 million tons of paper products were recycled in 2018. That's roughly the same weight as almost 350,000 blue whales.");
    facts.push_back("Over 24 trillion Styrofoam coffee cups are thrown away each year.");
    facts.push_back("On average, each one of us produces 4.4 pounds of solid waste each day.");
    facts.push_back("If all our newspaper was recycled, we could save 250,000,000 trees each year.");
    facts.push_back("In the US we use 2,500,000 plastic bottles every hour.");
    facts.push_back("There is no limit to the amount of times a can made from aluminum can be recycled.");
    facts.push_back("We generate 21.5 million tons of food waste each year.");
    return facts;
}