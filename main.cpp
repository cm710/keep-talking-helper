//
//  main.cpp
//  bombhelper
//
//  Created by Constantin Manea on 07/11/2015.
//  Copyright © 2015 Constantin Manea. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <map>

using namespace std;

#define INT_MAX (int) ((unsigned) -1 / 2)

void password(vector<string> pass){
    int i;
    int index;

    string input;

    vector<string> result;

    for(i=0;i<pass.size();i++){
        result.push_back(pass[i]);
    }
    vector<char> alphabet;


    for(index=0;index<5;index++){
        for(i=0;i<26;i++){
            alphabet.push_back((char)('a'+i));
        }
        cout<<"Enter letters for posistion "<<index<<": ";
        cin>>input;
        for(i=0;i<input.size();i++){
            for (vector<char>::iterator k = alphabet.begin(); k!=alphabet.end(); k++) {
                if(input.at(i) == *k){
                    alphabet.erase(k);
                    break;
                }
            }
        }
        for(i=0;i<alphabet.size();i++){
            for(vector<string>::iterator j = result.begin();j!=result.end();j++){
                while(j->at(index)==alphabet[i]){
                    //cout<<"removing "<<(*j)<<" "<<alphabet[i]<<endl;
                    j=result.erase(j);
                    if(j==result.end()){
                        break;
                    }
                }
                if(j==result.end()){
                    break;
                }
            }
        }

        cout<<"Remaining: ";
        for(vector<string>::iterator j = result.begin();j!=result.end();j++){
            cout<<(*j)<<" ";
        }
        cout<<endl;

        alphabet.clear();

    }



}



void memory(){
    int disp, i;
    vector<string> positions = {"FIRST", "SECOND", "THIRD", "FOURTH"};
    vector<pair<int, int>> hist;//(pos, value)


    vector<vector<int>> mem;
    vector<int> temp;

    string curlab;
    cout<<endl;
    cout<<"Enter FIRST display:";
    cin>>disp;
    cout<<"Enter FIRST row:";
    cin>>curlab;
    temp.clear();

    for(i=0;i<4;i++){
        temp.push_back((int)(curlab.at(i)-'0'));
    }
    mem.push_back(temp);

    switch (disp) {
        case 1:
            cout<<"Press button with LABEL "<<mem[0][1]<<endl;
            hist.push_back(pair<int, int>(2, mem[0][1]));
            break;
        case 2:
            cout<<"Press button with LABEL "<<mem[0][1]<<endl;
            hist.push_back(pair<int, int>(2, mem[0][1]));
            break;
        case 3:
            cout<<"Press button with LABEL "<<mem[0][2]<<endl;
            hist.push_back(pair<int, int>(3, mem[0][2]));
            break;
        case 4:
            cout<<"Press button with LABEL "<<mem[0][3]<<endl;
            hist.push_back(pair<int, int>(4, mem[0][3]));
            break;
        default:
            break;
    }

    //cout<<"( "<<hist[0].first<<" "<<hist[0].second<<" )"<<endl;

    cout<<endl;
    cout<<"Enter SECOND display:";
    cin>>disp;
    cout<<"Enter SECOND row:";
    cin>>curlab;
    temp.clear();

    for(i=0;i<4;i++){
        temp.push_back((int)(curlab.at(i)-'0'));
    }
    mem.push_back(temp);

    switch (disp) {
        case 1:
            cout<<"Press button with LABEL 4"<<endl;
            for(i=0;i<4;i++){
                if(mem[1][i]==4){
                    hist.push_back(pair<int, int>(i+1, 4));
                    break;
                }
            }
            break;
        case 2:
            cout<<"Press button with LABEL "<<mem[1][hist[0].first-1]<<endl;
            hist.push_back(pair<int, int>(hist[0].first, mem[1][hist[0].first-1]));
            break;
        case 3:
            cout<<"Press button with LABEL "<<mem[1][0]<<endl;
            hist.push_back(pair<int, int>(1, mem[1][0]));
            break;
        case 4:
            cout<<"Press button with LABEL "<<mem[1][hist[0].first-1]<<endl;
            hist.push_back(pair<int, int>(hist[0].first, mem[1][hist[0].first-1]));
            break;
        default:
            break;
    }


    cout<<endl;
    cout<<"Enter THIRD display:";
    cin>>disp;
    cout<<"Enter THIRD row:";
    cin>>curlab;
    temp.clear();

    for(i=0;i<4;i++){
        temp.push_back((int)(curlab.at(i)-'0'));
    }
    mem.push_back(temp);

    switch (disp) {
        case 1:
            for(i=0;i<4;i++){
                if (mem[2][i]==hist[1].second) {
                    cout<<"Press button with LABEL "<<mem[2][i]<<endl;
                    hist.push_back(pair<int, int>(i+1, mem[2][i]));
                    break;
                }
            }
            break;
        case 2:
            for(i=0;i<4;i++){
                if (mem[2][i]==hist[0].second) {
                    cout<<"Press button with LABEL "<<mem[2][i]<<endl;
                    hist.push_back(pair<int, int>(i+1, mem[2][i]));
                    break;
                }
            }
            break;
        case 3:
            cout<<"Press button in THIRD position"<<endl;
            hist.push_back(pair<int, int>(3, mem[2][2]));
            break;
        case 4:
            cout<<"Press button with LABEL 4"<<endl;
            for(i=0;i<4;i++){
                if(mem[2][i]==4){
                    hist.push_back(pair<int, int>(i+1, 4));
                    break;
                }
            }
            break;
        default:
            break;
    }


    cout<<endl;
    cout<<"Enter FOURTH display:";
    cin>>disp;
    cout<<"Enter FOURTH row:";
    cin>>curlab;
    temp.clear();

    for(i=0;i<4;i++){
        temp.push_back((int)(curlab.at(i)-'0'));
    }
    mem.push_back(temp);

    switch (disp) {
        case 1:
            cout<<"Press button with LABEL "<<mem[3][hist[0].first-1]<<endl;
            hist.push_back(pair<int, int>(hist[0].first, mem[3][hist[0].first-1]));
            break;
        case 2:
            cout<<"Press button with LABEL "<<mem[3][0]<<endl;
            hist.push_back(pair<int, int>(1, mem[3][0]));
            break;
        case 3:
            cout<<"Press button with LABEL "<<mem[3][hist[1].first-1]<<endl;
            hist.push_back(pair<int, int>(hist[1].first, mem[3][hist[1].first-1]));
            break;
        case 4:
            cout<<"Press button with label "<<mem[3][hist[1].first-1]<<endl;
            hist.push_back(pair<int, int>(hist[1].first, mem[3][hist[1].first-1]));
            break;
        default:
            break;
    }

    cout<<endl;
    cout<<"Enter FIFTH display:";
    cin>>disp;
    cout<<"Enter FIFTH row:";
    cin>>curlab;
    temp.clear();

    for(i=0;i<4;i++){
        temp.push_back((int)(curlab.at(i)-'0'));
    }
    mem.push_back(temp);

    switch (disp) {
        case 1:
            for(i=0;i<4;i++){
                if (mem[4][i]==hist[0].second) {
                    cout<<"Press button with LABEL "<<mem[4][i]<<endl;
                    hist.push_back(pair<int, int>(i+1, mem[4][i]));
                    break;
                }
            }
            break;
        case 2:
            for(i=0;i<4;i++){
                if (mem[4][i]==hist[1].second) {
                    cout<<"Press button with LABEL "<<mem[4][i]<<endl;
                    hist.push_back(pair<int, int>(i+1, mem[4][i]));
                    break;
                }
            }
            break;
        case 3:
            for(i=0;i<4;i++){
                if (mem[4][i]==hist[3].second) {
                    cout<<"Press button with LABEL "<<mem[4][i]<<endl;
                    hist.push_back(pair<int, int>(i+1, mem[4][i]));
                    break;
                }
            }
            break;
        case 4:
            for(i=0;i<4;i++){
                if (mem[4][i]==hist[2].second) {
                    cout<<"Press button with LABEL "<<mem[4][i]<<endl;
                    hist.push_back(pair<int, int>(i+1, mem[4][i]));
                    break;
                }
            }
            break;
        default:
            break;
    }

}

int minDist(int dist[], bool sptSet[]){
    int min = INT_MAX, min_index = 0, i;

    for(i = 0;i<36;i++){
        if(sptSet[i] == false && dist[i]<=min)
            min = dist[i], min_index = i;
    }
    return min_index;
}

void dijkstra(int maze[36][36], int src, int prev[36]){
    int dist[36];
    bool sptSet[36];
    int i, count;

    for(i=0;i<36;i++){
        dist[i]=INT_MAX, prev[i] = -1, sptSet[i] = false;
    }

    dist[src] = 0;

    for(count = 0;count<35;count++){
        int u = minDist(dist, sptSet);
        sptSet[u] = true;

        for(i=0;i<36;i++){
            if (!sptSet[i] && maze[u][i] == 1 && dist[u]!=INT_MAX && dist[u]+maze[u][i]<dist[i]) {
                dist[i]=dist[u]+maze[u][i];
                prev[i]=u;
            }
        }
    }
    cout<<"Done! ";
    cout.flush();
}



void labyrinth(vector<vector<int>> maze_set, vector<vector<int>> mazes){
    int x, y;
    int maze[36][36];
    int i, j, temp;

    for(i=0;i<36;i++){
        for (j=0; j<=36; j++) {
            maze[i][j] = INT_MAX;
        }
    }

    cout<<"Enter position for any circle:";
    cin>>x>>y;




    for(i=0;i<9;i++){
        if ((maze_set[i][0] == x && maze_set[i][1] == y) || (maze_set[i][2] == x && maze_set[i][3] == y)) {
            x=i;

            for(i=0;i<36;i++){
                switch (mazes[x][i]) {
                    case 2: //RIGHT
                        maze[i][(i/6*6)+(i%6)+1]=1;
                        maze[(i/6*6)+(i%6)+1][i] = 1;
                        break;
                    case 1: //DOWN
                        maze[i][((i/6+1)*6)+i%6] = 1;
                        maze[((i/6+1)*6)+i%6][i] = 1;
                        break;
                    case 3: //RIGHT DOWN
                        maze[i][(i/6*6)+(i%6)+1]=1;
                        maze[(i/6*6)+(i%6)+1][i] = 1;
                        maze[i][((i/6+1)*6)+i%6] = 1;
                        maze[((i/6+1)*6)+i%6][i] = 1;
                        break;

                    default:
                        break;
                }
            }
            break;
        }
    }

    pair<int, int> square, triangle;

    cout<<"Insert SQUARE position: ";
    cin>>square.first>>square.second;

    cout<<"Insert TRIANGLE position: ";
    cin>>triangle.first>>triangle.second;

    //TODO: SHORTEST PATH
    /*
    for(i=0;i<36;i++){
        for(j=0;j<36;j++){
            if(maze[i][j]==INT_MAX){
                cout<<0<<" ";
            }
            else cout<<maze[i][j]<<" ";
            if(j==35) cout<<endl;
        }
    }*/

    int pathlist[36];
    dijkstra(maze, (triangle.first-1)*6+triangle.second-1, pathlist);
    vector<int> path;

    int src = (triangle.first-1)*6+triangle.second-1;
    int dest = (square.first-1)*6+square.second-1;



    while (dest!=src) {
        path.push_back(dest);
        dest = pathlist[dest];
    }
    path.push_back(src);

    for(i=0;i<path.size()-1;i++){
        switch (path[i+1]-path[i]) {
            case 1:
                cout<<"RIGHT ";
                break;
            case -1:
                cout<<"LEFT ";
                break;
            case -6:
                cout<<"UP ";
                break;
            case 6:
                cout<<"DOWN ";
                break;

            default:
                break;
        }
    }

    cout<<endl;
    /*cout<<endl<<"PATH:";
    for (i=0; i<path.size(); i++) {
        cout<<"( "<<path[i]/6+1<<" , "<<path[i]%6+1<<" ) ";
    }
    cout<<endl;

    for(i=0;i<6;i++){
        for(j=0;j<6;j++){
            temp = 0;
            if(i<5 && maze[i*6+j][(i+1)*6+j] == 1){
                temp += 1;
            }
            if (j<5 && maze[i*6+j][i*6+j+1] == 1) {
                temp += 2;
            }

            cout<<temp<<" ";
            if(j==5) cout<<endl;
        }
    }*/

}


void wires(){
    cout<<"Enter wires: ";
    string cables;

    cin>>cables;
    int red = 0, yellow = 0, black = 0, white = 0, blue = 0;

    int i;

    for(i=0;i<cables.size();i++){
        switch (cables.at(i)) {
            case 'y':
                yellow++;
                break;
            case 'w':
                white++;
                break;
            case 'b':
                black++;
                break;
            case 'r':
                red++;
                break;
            case 'a':
                blue++;
                break;
            default:
                break;
        }
    }


    if(cables.size() == 3){
        if (red == 0) {
            cout<<"Cut SECOND wire."<<endl;
            return;
        }
        if (cables.at(2)=='w') {
            cout<<"Cut LAST wire."<<endl;
            return;
        }
        if(blue>1){
            if (cables.at(2) == 'a') {
                cout<<"Cut THIRD wire."<<endl;
                return;
            }
            if (cables.at(1) == 'a') {
                cout<<"Cut SECOND wire."<<endl;
                return;
            }
            cout<<"Cut FIRST wire."<<endl;
            return;
        }
        cout<<"Cut LAST wire."<<endl;
        return;
    }
    if (cables.size() == 4) {
        cout<<"Insert the LAST digit of the SERIAL NUMBER: "<<endl;
        cin>>i;

        if (red>1 && i%2 == 1) {
            if (cables.at(3) == 'r') {
                cout<<"Cut FOURTH wire."<<endl;
                return;
            }
            if (cables.at(2) == 'r') {
                cout<<"Cut THIRD wire."<<endl;
                return;
            }
            if (cables.at(1) == 'r') {
                cout<<"Cut the SECOND wire."<<endl;
                return;
            }
        }
        if(cables.at(3)=='y'&&red==0){
            cout<<"Cut the FIRST wire"<<endl;
            return;
        }

        if (blue == 1) {
            cout<<"Cut FIRST wire."<<endl;
            return;
        }

        if (yellow>1) {
            cout<<"Cut the LAST wire."<<endl;
            return;
        }
        cout<<"Cut the SECOND wire."<<endl;
        return;
    }

    if(cables.size() == 5){
        cout<<"Insert the LAST digit of the SERIAL NUMBER: "<<endl;
        cin>>i;

        if (cables.at(4) == 'b' && i%2 == 1) {
            cout<<"Cut the FOURTH wire."<<endl;
            return;
        }
        if (red == 1 && yellow > 1) {
            cout<<"Cut the FIRST wire."<<endl;
            return;
        }
        if(black == 0){
            cout<<"Cut the SECOND wire."<<endl;
            return;
        }
        cout<<"Cut the FIRST wire."<<endl;
        return;
    }
    if(cables.size() == 6){
        cout<<"Insert the LAST digit of the SERIAL NUMBER: "<<endl;
        cin>>i;

        if (yellow == 0 && i%2 == 1) {
            cout<<"Cut the THIRD wire."<<endl;
            return;
        }
        if (yellow == 1 && white > 1) {
            cout<<"Cut the FOURTH wire."<<endl;
            return;
        }
        if (red == 0) {
            cout<<"Cut the LAST wire."<<endl;
            return;
        }
        cout<<"Cut the FOURTH wire."<<endl;
        return;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...

    ifstream f("db.in");

    vector<string> pass;

    string input;

    int i, j, k;

    for (i=0; i<35; i++) {
        f>>input;
        pass.push_back(input);
    }


    vector<vector<int>> maze_set, mazes;
    int temp;
    vector<int> tempvec;

    for(i=0;i<9;i++){
        tempvec.clear();
        for(j=0;j<4;j++){
            f>>temp;
            tempvec.push_back(temp);
        }
        maze_set.push_back(tempvec);
        tempvec.clear();

        for (j=0; j<36; j++) {
            f>>temp;
            tempvec.push_back(temp);
        }
        mazes.push_back(tempvec);
    }










    string com;

    map<string, int> commands;

    commands.insert(pair<string, int>("pass", 1));

    while(com!="exit"){
        cout<<endl<<"Enter puzzle type: ";
        cin>>com;
        cout<<endl;
        if (com=="pass") {
            cout<<"Entering pass"<<endl;
            password(pass);
        } else if(com=="mem") {
            cout<<"Entering Memory"<<endl;
            memory();

        } else if(com == "maze"){
            cout<<"Entering Labyrinth"<<endl;
            labyrinth(maze_set, mazes);
        } else if(com == "wires") {
            cout<<"Entering wires"<<endl;
            wires();
        } else break;
    }




    return 0;
}
