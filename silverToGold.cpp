#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<cmath>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main() {
    vector <vector<int>> checkPoints;
    bool boostUsed = false;
    bool allFound = false;
    int bestXtoBoostFor = -5;
    int lapNumber = 1;
    bool lapCountHelper = true;
    int lastIterDist = 0;
    int speed = 0;
    // game loop
    while (1) {
        double PI = 3.14159;
        int x;
        int y;
        int nextCheckpointX; // x position of the next check point
        int nextCheckpointY; // y position of the next check point
        int nextCheckpointDist; // distance to the next checkpoint
        int nextCheckpointAngle; // angle between your pod orientation and the direction of the next checkpoint
        cin >> x >> y >> nextCheckpointX >> nextCheckpointY >> nextCheckpointDist >> nextCheckpointAngle;
        cin.ignore();
        int opponentX;
        int opponentY;
        cin >> opponentX >> opponentY;
        cin.ignore();
        if (nextCheckpointAngle < 0)
            nextCheckpointAngle = nextCheckpointAngle * -1;
        speed = lastIterDist - nextCheckpointDist;
        if (speed < 0)
            speed = speed * -1;



        //default values incase we dont know nextnext checkpoint's coordinates.
        int nextnextX = 8000;
        int nextnextY = 4500;
        vector<int> currentNext = {nextCheckpointX, nextCheckpointY};
        if (!allFound) { //populate vectors
            if (checkPoints.size() == 0)
                checkPoints.push_back(currentNext);
            else if (checkPoints[0] == currentNext && checkPoints.size() != 1){
                allFound = true;
                checkPoints.push_back(currentNext);
            } else{
                bool contains = false;
                for (vector<int> v : checkPoints){
                    if (v == currentNext)
                        contains = true;
                }
                if (!contains)
                    checkPoints.push_back(currentNext);
            }
        }

        if (allFound && bestXtoBoostFor == -5) { //if we have not found longest to X then lets find it.
            double largest = 0;
            for (int j = 0; j < checkPoints.size() - 1; j++) {
                int x1 = checkPoints[j][0];
                int y1 = checkPoints[j][1];
                int x2 = checkPoints[j + 1][0];
                int y2 = checkPoints[j + 1][1];
                int dx = x1 - x2;
                int dy = y1 - y2;
                double dist = sqrt(dx * dx + dy * dy);
                if (dist > largest) {
                    largest = dist;
                    bestXtoBoostFor = x2;
                }
            }
        }

        if (allFound){ //if we have data, then change default values for nextnext checkpoint
            for (int i = 0; i < checkPoints.size()-1; i++) {
                if (checkPoints[i] == currentNext){
                    nextnextX = checkPoints[i+1][0];
                    nextnextY = checkPoints[i+1][1];
                }
            }
        }

        if (checkPoints.size() > 1){
            if (currentNext == checkPoints[0] && lapCountHelper){
                lapNumber++;
                lapCountHelper = false;
            }
            if (currentNext == checkPoints[1])
                lapCountHelper = true;
        }


        //Debug
        cerr << "angle: " << nextCheckpointAngle << endl;
        cerr << "lap number: " << lapNumber << endl;
        cerr << "dist: " << nextCheckpointDist << endl;
        cerr << "boost used: " << boostUsed << endl;
        cerr << "going to: " << nextCheckpointX << " " << nextCheckpointY << endl;
        cerr << "after that to: " << nextnextX << " " << nextnextY << endl;
        cerr << "bestXToBoost: " << bestXtoBoostFor << endl;
        cerr << "speed: " << speed << endl;
        cerr << "vector content: " << endl;
        for (vector<int> v : checkPoints){
            cerr << v[0] << ", " << v[1] << endl;
        }


        double anglePerc = 1 - (double)nextCheckpointAngle / 90.0;
        int thrust = 100;
        thrust = thrust * anglePerc;

        if (nextCheckpointDist < 1600)
            thrust = 70;

        if (nextCheckpointDist < 2000 && speed > 400) { //TODO dont jump to next if previous was missed
            nextCheckpointX = nextnextX;
            nextCheckpointY = nextnextY;
        }

        if (nextCheckpointAngle > 3 && speed > 180)
            thrust = 80;

        if (nextCheckpointAngle > 90)
            thrust = 0;


        lastIterDist = nextCheckpointDist;

        if (lapNumber == 3 && currentNext == checkPoints[checkPoints.size()-2] && nextCheckpointAngle < 2 && !boostUsed){ // If boost not used and going to finish point.
            boostUsed = true;
            cout << nextCheckpointX << " " << nextCheckpointY << " " << "BOOST" <<  " " << thrust << endl;
        }
        if (nextCheckpointDist > 4500 && nextCheckpointAngle < 2 && allFound && bestXtoBoostFor == nextCheckpointX) {
            boostUsed = true;
            cout << nextCheckpointX << " " << nextCheckpointY << " " << "BOOST" <<  " " << thrust << endl;
        } else
            cout << nextCheckpointX << " " << nextCheckpointY << " " << thrust <<  " " << thrust << endl;

    }
}