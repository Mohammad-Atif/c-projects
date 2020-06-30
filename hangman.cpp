/*this is a hangman(word guessing) game
created by- Mohammad Atif    */
#include<iostream>
#include<string>
#include<random>
#include<ctime>
#include<cstdlib>
#include<vector>
using namespace std;

vector<string> words={"anaconda","aeroplane","telivision","india","yamaha","owl","keyboard","youtube","smartphone","argentina","movie","zebra","thug","thunder","upset","harmonium","efficiency","classmate","clay","banana","coconut","football","cricket","physics","mathematics","laptop","bank","building","coffee","table","guitar","coffin","exercise","geometry","gesture","guest","hockey","house","inevitable","isolate","jewel","kangaroo","kitchen","layout","manifest","measurement","offend","opposition","overflow","performance","pigeon","raspberry","republic","satisfaction","sequence","panaroma","specification","summary","syringe","tattoo","thermodynamics","transaction","vinegar","volleyball","wildlife","elephant","workbook"};


string randomword(vector<string> a)
{
    int s=a.size(),n;
    srand((unsigned) time(0));
    n = (rand() % s) + 1;
    return a[n];
}
string diff_word(string w)
{   int i,s=w.size();
    if(s>5)
    {
        srand((unsigned) time(0));
        int random_nums[3];
        for(i=0;i<3;i++)
        {
            random_nums[i]=(rand() % s);
            w.replace(random_nums[i],1,"*");

        }
    }
    else
    {
        int rands[2];
        for(i=0;i<3;i++)
        {
            rands[i]=(rand() % s);
            w.replace(rands[i],1,"*");
        }
    }
    return w;
}
void exiting()
{
    cout<<"Mann...learn to type firstt \t wrong input :(";
    exit(0);
}
void game()
{
    cout<<"--------------Hello------------"<<endl;
    cout<<"WELCOME TO THE HANGMAN GAME"<<endl;
    cout<<"PRESS ENTER TO START PLAYING "<<endl;
    int choice;
    cout<<"Enter the no of rounds do you want to play";
    cout<<"\n1- 5 rounds \n2-10 rounds\n3-20 rounds"<<endl;
    cin>>choice;
    cout<<"OKK LETS PLAY ....GUESS THE WORDS....\n";
    int rounds;
    if(choice==1)
        rounds=5;
    else if(choice==2)
        rounds=10;
    else if(choice==3)
        rounds=20;
    else
        exiting();
    string game_word,game_diff_word,user_word;
    int corrects=0;
    for(int counts=0;counts<rounds;counts++)
    {
        game_word=randomword(words);
        game_diff_word=diff_word(game_word);
        cout<<"\n"<<game_diff_word<<"--?"<<endl;
        cin>>user_word;
        if(game_word==user_word)
        {
           cout<<"\nCorrect answer"<<endl;
           corrects=corrects+1;

        }
        else
        {
            cout<<"Wrong answer\nThe word is-"<<game_word<<endl;

        }

    }
    cout<<"\n\tYour score="<<corrects<<"/"<<rounds<<endl;





}

int main()
{
   game();
   int ch;
   cout<<"\nDo you want to play again\n1-Yes\t2-No"<<endl;
   cin>>ch;
   if(ch==1)
    game();
   else  if (ch==2)
    cout<<"Thank You for playing";
   else
        exiting();
   return 0;
}


