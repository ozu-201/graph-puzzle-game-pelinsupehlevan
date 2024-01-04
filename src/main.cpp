//
// Created by pp028364 on 12/14/2023.
//

#include <iostream>
#include <fstream>
#include "C:\Users\TEMP\CLionProjects\graph-puzzle-game-pelinsupehlevan\src\Array\Graph\Graph.cpp"

using namespace std;

int main () {

    int count3 = 0;
    int count4 = 0;
    int count5 = 0;

    std::string line;
    std::ifstream file(R"(C:\Users\TEMP\CLionProjects\graph-puzzle-game-pelinsupehlevan\src\english.txt)" , std::ifstream::in);

    while (getline(file, line)) {
        if ( line.length() == 3 ) {
            count3++;
        }if ( line.length() == 4 ) {
            count4++;
        }if ( line.length() == 5 ) {
            count5++;
        }
    }

    array::Graph threeLetter(count3);
    array::Graph fourLetter(count4);
    array::Graph fiveLetter(count5);

    file.close();

    std::ifstream file2(R"(C:\Users\TEMP\CLionProjects\graph-puzzle-game-pelinsupehlevan\src\english.txt)" , std::ifstream::in);

    int newCount3 = 0;
    int newCount4 = 0;
    int newCount5 = 0;

    while (getline(file2, line)) {

        if ( line.length() == 3 ) {
            threeLetter.addName(newCount3, line);
            newCount3++;
        }if ( line.length() == 4 ) {
            fourLetter.addName(newCount4, line);
            newCount4++;
        }if ( line.length() == 5 ) {
            fiveLetter.addName(newCount5, line);
            newCount5++;
        }
    }

    // adds edges to the graph of 3-letter graphs
    for ( int i = 0 ; i < newCount3 ; i++ ) {
        for ( int j = 0; j < newCount3 ; j++ ) {
            int diff = 0;
            for (int k = 0 ; k < 3 ; k++ ) {
                if (threeLetter.getNames()[i][k] != threeLetter.getNames()[j][k]) {
                    diff++;
                }
                if ( diff == 1 ) {
                    threeLetter.addEdge(threeLetter.names[i],threeLetter.names[j]);
                    threeLetter.addEdge(threeLetter.names[j],threeLetter.names[i]);
                }
            }
        }
    }

    // adds edges to the graph of 4-letter graphs
    for ( int i = 0 ; i < newCount4 ; i++ ) {
        for ( int j = 0; j < newCount4 ; j++ ) {
            int diff = 0;
            for (int k = 0 ; k < 4 ; k++ ) {
                if (fourLetter.getNames()[i][k] != fourLetter.getNames()[j][k]) {
                    diff++;
                }
                if ( diff == 1 ) {
                    fourLetter.addEdge(fourLetter.names[i],fourLetter.names[j]);
                    fourLetter.addEdge(fourLetter.names[j],fourLetter.names[i]);
                }
            }
        }
    }

    // adds edges to the graph of 5-letter graphs
    for ( int i = 0 ; i < newCount5 ; i++ ) {
        for ( int j = 0; j < newCount5 ; j++ ) {
            int diff = 0;
            for (int k = 0 ; k < 5 ; k++ ) {
                if (fiveLetter.getNames()[i][k] != fiveLetter.getNames()[j][k]) {
                    diff++;
                }
                if ( diff == 1 ) {
                    fiveLetter.addEdge(fiveLetter.names[i],fiveLetter.names[j]);
                    fiveLetter.addEdge(fiveLetter.names[j],fiveLetter.names[i]);
                }
            }
        }
    }

    file.close();

    /*std::cout << threeLetter.getNames()[0] << endl;
    std::cout << threeLetter.getNames()[1] << endl;
    std::cout << threeLetter.getNames()[2] << endl;
    std::cout << threeLetter.getNames()[3] << endl;
    std::cout << threeLetter.getNames()[4] << endl;*/
    // std::cout << threeLetter.getEdges() << endl;
    threeLetter.breadthFirstSearch("ally" , "abel");



    return 0;
}