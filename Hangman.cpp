#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define in(i) cin >> i
#define out(i) cout << i
#define ll long long

void intro()
{
    out(endl);
    out("---------------------------------\n");
    out("Game :  Hangman\n");
    out("---------------------------------\n");
    out("Mission:\n");
    out("Save Mr.X from being hanged.\n");
    out("How to play?\n");
    out("Guess the correct letters of the codeword. Every wrong guess makes Mr.X closer to being hanged.\n");
    out("Best of luck!!!!\n");
    out("=================================\n");
    out(endl);
}

void display_miss(int misses)
{
    if (misses == 0)
    {
        out(" +---+ \n");
        out(" |   | \n");
        out("     | \n");
        out("     | \n");
        out("     | \n");
        out("     | \n");
        out(" ========= \n");
    }
    else if (misses == 1)
    {
        out(" +---+ \n");
        out(" |   | \n");
        out(" O   | \n");
        out("     | \n");
        out("     | \n");
        out("     | \n");
        out(" ========= \n");
    }
    else if (misses == 2)
    {
        out(" +---+ \n");
        out(" |   | \n");
        out(" O   | \n");
        out(" |   | \n");
        out("     | \n");
        out("     | \n");
        out(" ========= \n");
    }
    else if (misses == 3)
    {
        out(" +---+ \n");
        out(" |   | \n");
        out(" O   | \n");
        out("/|   | \n");
        out("     | \n");
        out("     | \n");
        out(" ========= \n");
    }
    else if (misses == 4)
    {
        out(" +---+ \n");
        out(" |   | \n");
        out(" O   | \n");
        out("/|\\   | \n");
        out("     | \n");
        out("     | \n");
        out(" ========= \n");
    }
    else if (misses == 5)
    {
        out(" +---+ \n");
        out(" |   | \n");
        out(" O   | \n");
        out("/|\\   | \n");
        out("/   | \n");
        out("     | \n");
        out(" ========= \n");
    }
    else if (misses == 6)
    {
        out(" +---+ \n");
        out(" |   | \n");
        out(" O   | \n");
        out("/|\\   | \n");
        out("/ \\  | \n");
        out("     | \n");
        out(" ========= \n");
    }
}

void display_status(vector<char> incorrect, string ans)
{
    out("Incorrect guesses: \n");

    for (int i = 0; i < incorrect.size(); i++)
    {
        out(incorrect[i]);
        out(" ");
    }

    out("\nCodeword:\n");

    for (int i = 0; i < ans.length(); i++)
    {
        out(ans[i]);
        out(" ");
    }
}

void end(string ans, string s)
{
    if (ans == s)
    {
        out("Hooray! You saved Mr.X\n");
    }
    else
    {
        out("Oh No! Mr.X is hanged\n");
    }

    out("Thanks for playing!");
}

int main()
{

    intro();

    string s = "flowers";
    string ans = "_______";

    int misses = 0;

    vector<char> incorrect;

    bool guess = false;
    char letter;

    while (ans != s && misses < 7)
    {
        display_miss(misses);
        display_status(incorrect, ans);

        out("\n\nPlease enter your guess: ");
        in(letter);

        for (int i = 0; i < s.length(); i++)
        {
            if (letter == s[i])
            {
                ans[i] = letter;
                guess = true;
            }
        }

        if (guess)
        {
            out("\nCorrect\n");
        }
        else
        {
            out("\nIncorrect! Mr.X is one step close to hanging.\n");
            incorrect.pb(letter);
            misses++;
        }
        guess = false;
    }

    end(ans, s);

    return 0;
}