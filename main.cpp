#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include "toolbox.h"

using std::string;
using std::cout;
using std::vector;
using std::deque;

void packer(const string &input){

    string parsedInput;
    int stringSize =0;

    parsedInput = removeChar(input, ' ');

    if(parsedInput.size() < 1000){
        stringSize = parsedInput.size();

    }
    vector <int> divisors;
    getDivisors(stringSize, divisors);

    int length = divisors.at( (divisors.size()/2) );
    int index = 0;
    int colIndex;

    vector < deque <char> > answer;

    while (index < stringSize){

        answer.push_back( deque<char> () );
        colIndex =(answer.size()-1);

        for (int rowIndex =0; rowIndex < length; rowIndex ++){
            answer.at(colIndex).push_back( parsedInput.at(index) );
            index++;
        }

        if (index<stringSize){

            answer.push_back( deque<char> () );
            colIndex =(answer.size()-1);

            for (int rowIndex =0; rowIndex < length; rowIndex ++){
                answer.at(colIndex).push_front( parsedInput.at(index) );
                index++;
            }
        }

    }

    cout << "1 1\n";
    for (size_t col =0; col < answer.size(); col++){

        for (size_t row =0; row < length; row++){
            cout << answer.at(col).at(row);
        }
        cout<<"\n";
    }
    cout<<"\n";
};

int main(){
    string input ="EVERYWHERE IS WITHIN WALKING DISTANCE IF YOU HAVE THE TIME";
    packer(input);

    input ="IT IS RAINING CATS AND DOGS OUT THERE";
    packer(input);
}
