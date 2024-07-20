#include <iostream>
#include <fstream>
#include <random>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>


using namespace std;

// Structure definition
struct Question{
    string QuestionText;
    string ans1;
    string ans2;
    string ans3;
    string ans4;
    char CorrectAns;
    int QuestionScore;

    void askQuestion();
};

// Function ask Questions
void Question :: askQuestion(){
    cout<<endl;
    cout<<QuestionText<<endl;
    cout<<"A. "<<ans1<<"           "<<"B. "<<ans2<<endl;
    cout<<"C. "<<ans3<<"           "<<"D. "<<ans4<<endl;

    char Guess;
    cout<<"What is your answer: "<<endl;
    cin>>Guess;

    if(Guess == CorrectAns){
        cout<<"Correct!"<<endl;
        cout<<"Score = "<<QuestionScore<<endl;
    } else{
        cout<<"Wrong."<<endl;
        cout<<"Score = 0"<<endl;
        cout<<"The correct answer was: "<<CorrectAns<<endl;
    }
    cout<<"_________________________________"<<endl;
}



int main(){
// Read from the text file
    fstream file("Questions.txt");

// Create a text string to output the text file
    string line;

    vector<Question> questions;
    int totalScore = 0;

// A loop with the getline() function to read the file line by line
    while(getline(file, line)){
        stringstream ss(line);
        Question q;
        string score;
        getline(ss, q.QuestionText, ',');
        getline(ss, q.ans1, ';');
        getline(ss, q.ans2, ';');
        getline(ss, q.ans3, ';');
        getline(ss, q.ans4, ';');
        ss>>q.CorrectAns;
        ss.ignore();
        getline(ss,score);
        q.QuestionScore = stoi(score);
// Reading question details from stringstream...
        questions.push_back(q);
    }

// Shuffle the questions
    random_device rd;
    mt19937 g(rd());
    shuffle(questions.begin(), questions.end(), g);

// Continue the program setup
    for(auto &q : questions){
        q.askQuestion();
        totalScore += q.QuestionScore;
    }

// Output the total score
    cout<<"Total score = "<<totalScore<<" out of "<<questions.size() * 10 <<endl;



    return 0;
}
