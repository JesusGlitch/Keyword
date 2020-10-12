// Aperture Science CIA Breaker simulation for CIA recruits 
// Jesus Uribe

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int rightanswers = 0;//intiger for rightanswer
int wronganswers = 0;//intiger for wronganser
int totalanswers = 0;//intiger for total attempts
string wordArray[3];
    

int main()
{   
    //amount of words used
    enum fields { WORD, HINT, NUM_FIELDS };
    const int NUM_WORDS = 10;
    const string WORDS[NUM_WORDS][NUM_FIELDS] =
    {   //words that will be guess and their hints
        {"paint", "Comes in an array of colors."},
        {"glasses", "These might help you see the answer."},
        {"shades", "The Sun is to bright cover your eyes!"},
        {"sunburn", "Thats going to hurt after a pool day."},
        {"skateboard", "Just a peace of wood with 4 wheels."},
        {"room", "A place you go to sleep."},
        {"tesla", "Why would anyone want an electric car."},
        {"nintendo", "Marios platform."},
        {"gaben", "Lord of the pc master race."},
        {"car", "Your fastest mode of trasportation."},
       
    };
      

    for (int i = 0; i < 3; ++i)
    {
        srand(time(0));
        int words = (rand() % NUM_WORDS);
        for (int c = 0; c < 3; ++c)
        {
            while (WORDS[words][WORD] == wordArray[c])
            {
                words = (rand() % NUM_WORDS);
            }
        }
        wordArray[i] = WORDS[words][WORD];

        srand(static_cast<unsigned int>(time(0)));
        int choice = (rand() % NUM_WORDS);
            string theWord = WORDS[choice][WORD];  // word to guess
            string theHint = WORDS[choice][HINT];  // hint for word

        string jumble = theWord;  // jumbled version of word
            int length = jumble.size();

        for (int j = 0; j < length; ++j)
        {

            int index1 = (rand() % length);
            int index2 = (rand() % length);
            char temp = jumble[index1];
            jumble[index1] = jumble[index2];
            jumble[index2] = temp;
        }


        //text that will show in the start
        cout << "\t\t\Welcome To our Aperture Science monkey testing facility!\n\n";
        cout << "Unscramble the letters to make a word.This test should be easy enough a monkey can do it.\n";
        cout << "Enter hint if your dumber than a monkey and need a hint.\n";
        cout << "Enter 'pass' to pass the word because your dumber than a monkey\n\n";
        cout << "Keyword is: " << jumble;

        string guess;
        cout << "\n\nYour guess: ";
        cin >> guess;
        //game loop
        while ((guess != theWord) && (guess != "pass"))
        {
            if (guess == "hint")
            {
                cout << theHint;


            }
            else
            {
                cout << "Sorry, that's not it.";
                wronganswers++;
                totalanswers++;

            }

            cout << "\n\nYour guess: ";
            cin >> guess;
        }

        if (guess == theWord)
        {
            cout << "\nThat's it!  You guessed it!\n";
            totalanswers++;
            rightanswers++;

        }
    }

    //counter for right, wrong and amount of tries
                cout << "\n\t\tAperture Science Monekey Counter" << endl;
                cout << "." << endl;
                cout << "." << endl;
                cout << "Aperture Science counted  " << rightanswers << "  words correctly guessed." << endl;
                cout << "Aperture Science counted  " << wronganswers << "  words guessed incorrectly." << endl;
                cout << "Aperture Science counted a total  " << totalanswers << "  of words." << endl;

    //play again function 
    string playAgain;
         cout << "Would you like to play again? Y/N" << endl;
            cin >> playAgain;

    while (true) {
        if (playAgain == "y") {//keep playing
            system("cls");
            main();
        }
        else if (playAgain == "n") {
            cout << "Thanks for playing!" << endl;//ending game
            exit(0);
        }
        else {
            cout << "Please input y or n..." << endl;
            cin >> playAgain;
        }
    }
    return 0;
}
