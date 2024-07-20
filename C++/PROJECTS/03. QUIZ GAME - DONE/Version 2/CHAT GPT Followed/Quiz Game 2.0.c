#include <iostream>
#include <string>

using namespace std;


int main(){
// Intro
    cout<<"DAILY QUIZ"<<endl;
    cout<<"Press Enter to start "<<endl;

    cin.get(); // Để có chức năng Bấm Enter

// Input the details
string Name;
int Age;

    cout<<"What is your name: "<<endl;
    cin>>Name;

    cout<<endl;

    cout<<"How old are you: "<<endl;
    cin>>Age;

    cout<<endl;


// Ask the player
string Rep;
    cout<<"Are you ready to take"<<" the quiz "<<Name<<"?"<<endl<<"yes / no"<<endl;
    cin>>Rep;
    if(Rep == "yes"){
        cout<<endl<<"Good luck! "<<endl;
    }
    else {
        cout<<"OK. Good Bye!"<<endl;
    return 0; //chưa hiểu, nếu ko có thì vẫn hiện ra chạy game -> ĐỂ NGẮT CHƯƠNG TRÌNH nếu trả lời 'no'
    }


// Display the score -> Finish or Try again
    cout<<"Total score = "<<Total<<" out of 100"<<endl;

    cout<<endl;

    if(Total >=70){
        cout<<"Congrats "<<Name<<" you have passed the quiz"<<endl;
    }
    else {
        cout<<"Too bad, you have failed the quiz"<<endl;
        cout<<"Try again "<<endl;
    }
        return 0;
    }



// IF RIGHT
    if(Guess == Correct_Answer){
        cout<<"Correct!"<<endl;
        cout<<"Score = 10"<<endl;
        //Update the score
        Total = Total + Question_Score;
        cout<<"Total score = "<<Total<<endl;

    }
// IF WRONG
    else {
        cout<<"Wrong"<<endl;
        cout<<"Score = 0"<<endl;
        Total = Total;
        cout<<"Total score = "<<Total<<endl;
        cout<<"Correct answer was "<<Correct_Answer<<endl;
    }
    cout<<"__________________________"<<endl;
}

