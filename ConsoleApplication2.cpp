//I had an error where it kept looping forever. 

#include <iostream>
#include <string>


using namespace std;

void itemsOnStack(int stack[], int numItems) {
    cout << "Items on the Stack: ";
    for (int i = 0; i < numItems; i++) {
        cout << stack[i] << " ";
    }

    cout << endl;
}

int main()
{
    string choice = "";
    const int MAXITEMS = 15;

    while (true) {
        int stack[MAXITEMS];
        int numItems = 0;
        int item;

        while (true) {
            cout << endl << "Stack Menu Prompt" << endl << endl;
            cout << "Type A to push a number to the stack" << endl;
            cout << "Type B to pop a number from the stack" << endl;
            cout << "Type C to output the top of the stack" << endl;
            cout << "Type D to purge the stack " << endl;
            cout << "Type E to quit " << endl;
            cin >> choice;

            
            if (choice.size() == 0) {
                cout << "Invalid choice.  Please try again." << endl;
                continue;
            }
            
            if (choice.substr(0, 1) == "A" || choice.substr(0, 1) == "a") {
                if (numItems == MAXITEMS) {
                    cout << "Stack is full.  Cannot add more items" << endl;
                    continue;
                }

                cout << "Enter a number between 0 and 99 to push to the stack: " << endl;
                cin >> item;

                while (item < 0 || item > 99) {
                    cout << "Wrong input try again" << endl;
                    cout << "Enter a number between 0 and 99 to push to the stack: " << endl;
                    cin >> item;
                }

                stack[numItems] = item;
                numItems++;
                itemsOnStack(stack, numItems);
            }//choice.subtry(0,1)???
            else if (choice.substr(0, 1) == "B" || choice.substr(0, 1) == "b") {

                if (numItems == 0) {
                    cout << "Error underflow, stack is Empty" << endl;
                    continue;
                }

                cout <<  stack[numItems - 1] << " is popped" << endl;
                numItems--;//Does the item in the +1 position here get deleted or just ignored as you
                itemsOnStack(stack, numItems);	
				//itemsOnStack(stack, numItems+1);							//do numItems-- ??? 
            }//numItems and itemsOnStack will print outthe stack from 0 <0 so not at all but isn't 
            //that a bit fake as the array still has 1 item not 0?
            else if (choice.substr(0, 1) == "C" || choice.substr(0, 1) == "c") {

                if (numItems == 0) {
                    cout << "Error underflow, stack is Empty" << endl;
                    continue;
                }
//note: if the "pointer was on top of it, it wouldn't print it out, it'd be replaced with the next 
//cyle 
                cout << "Top of the Stack: " << stack[numItems - 1] << endl;//you print out 
                itemsOnStack(stack, numItems);//stack[] w/cout but you don't do anything to numItems
            } 			//it's just printed out in the for loops as is aka for i=0; i< numItems
            else if (choice.substr(0, 1) == "D" || choice.substr(0, 1) == "d") {
                numItems = 0;
                cout << "The stack was purged" << endl;
                itemsOnStack(stack, numItems);
            }
            else if (choice.substr(0, 1) == "E" || choice.substr(0, 1) == "e") {
                break;
            }
            else {
                cout << "Invalid choice.  Please try again." << endl;
                continue;
            }


        }
        
        cout << "Would you like to run the program again Y/N: ";
        cin >> choice;
        if (choice != "Y" && choice != "y") break;
    }
}

