//
//  main.cpp
//  bombhelper
//
//  Created by Constantin Manea on 07/11/2015.
//  Copyright © 2015 Constantin Manea. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
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

void hold_button(){
    string strip_colour;
    cout<<"Hold the button down and enter the strip colour: ";
    cin>>strip_colour;
    
    if (strip_colour.at(0) == 'b') {
        cout<<"Release when the countdown contains a FOUR (4) in any position."<<endl;
        return;
    }
    
    if (strip_colour.at(0) == 'y') {
        cout<<"Release when the countdown contains a FIVE (5) in any position."<<endl;
        return;
    }
    
    cout<<"Release when the countdown contains a ONE (1) in any position."<<endl;
}

bool evalans(string answer){
    if (answer.at(0) == 'y') {
        return true;
    }
    
    if (answer.at(0) <= '9') {
        return true;
    }
    
    return false;
}

void button(){
    string colour;
    string text;
    string answer;
    int nr_bat=-1;
    
    cout<<"Enter button colour: ";
    cin>>colour;
    cout<<"Enter button text: ";
    cin>>text;
    
    switch (colour.at(0)) {
        case 'b':
            colour = "blue";
            break;
        case 'w':
            colour = "white";
            break;
        case 'y':
            colour = "yellow";
            break;
        case 'r':
            colour = "red";
            break;
        
        default:
            break;
    }
    
    
    if (colour == "blue" && text == "abort") {
        hold_button();
        return;
    }
    
    if (text == "detonate") {
        cout<<"Insert number of batteries: ";
        cin>>nr_bat;
        if (nr_bat>1) {
            cout<<"Press and IMMEDIATELY release the button."<<endl;
            return;
        }
    }
    
    if (colour == "white") {
        cout<<"Is there a lit indicator with label CAR?";
        cin>>answer;
        if (evalans(answer)) {
            hold_button();
            return;
        }
    }
    
    if(nr_bat > 2){
        cout<<"Is FRK lit on the side? ";
        cin>>answer;
        if (evalans(answer)) {
            cout<<"Press and IMMEDIATELY release the button."<<endl;
            return;
        }
    }
    if (nr_bat < 0) {
        cout<<"Are there more than 2 batteries and a lit FRK indicator?";
        cin>>answer;
        if (evalans(answer)) {
            cout<<"Press and IMMEDIATELY release the button."<<endl;
            return;
        }
    }
    
    
    if (colour == "yellow") {
        hold_button();
        return;
    }
    
    if (colour == "red" && text == "hold") {
        cout<<"Press and IMMEDIATELY release the button."<<endl;
        return;
    }
    
    hold_button();
    
}

void wiresec(){
    //Red to A = 11
    //Blue to C = 23
    //Black to B = 32
    int red[9] = {1, 2, 4, 5, 2, 5, 7, 6, 2};
    int blue[9] = {2, 5, 2, 4, 2, 3, 1, 5, 1};
    int black[9] = {7, 5, 2, 5, 2, 3, 6, 1, 1};
    
    int redc = 0, bluec = 0, blackc = 0;
    
    int curwire = 0;
    int temp;
    cout<<"Begin writing the wires:"<<endl;
    
    while (curwire<100) {
        cin>>curwire;
        temp=1<<(3-curwire%10);
        switch (curwire/10) {
            case 1:
                if (temp & red[redc]) {
                    cout<<curwire/10<<" CUT!"<<endl;
                } else {
                    cout<<curwire/10<<" DONT!"<<endl;
                }
                redc++;
                break;
            case 2:
                if (temp & blue[bluec]) {
                    cout<<curwire/10<<" CUT!"<<endl;
                } else {
                    cout<<curwire/10<<" DONT!"<<endl;
                }
                bluec++;
                break;
            case 3:
                if (temp & black[blackc]) {
                    cout<<curwire/10<<" CUT!"<<endl;
                } else {
                    cout<<curwire/10<<" DONT!"<<endl;
                }
                blackc++;
                break;
            default:
                return;
        }
    }
    
}


void vennlookup(int wirecode, int* sn, int* nr_bat, int* pp){
    string venn = "CDCBSPDPSBCBSSPD";
    
    switch (venn.at(wirecode)) {
        case 'C':
            cout<<"P CUT"<<endl;
            break;
        case 'D':
            cout<<"D DON'T"<<endl;
            break;
        case 'S':
            if (*sn < 0) {
                cout<<"Insert last digit of Serial Number: ";
                cin>>(*sn);
            }
            
            if ((*sn)%2 == 0) {
                cout<<"S CUT"<<endl;
            } else{
                cout<<"S DON'T"<<endl;
            }
            break;
        case 'P':
            if (*pp < 0) {
                cout<<"Insert 1 or more if you have parallel ports: ";
                cin>>(*pp);
            }
            
            if (*pp > 0) {
                cout<<"P CUT"<<endl;
            } else{
                cout<<"P DON'T"<<endl;
            }
            break;
        case 'B':
            if (*nr_bat < 0) {
                cout<<"Insert number of batteries: ";
                cin>>(*nr_bat);
            }
            
            if (*nr_bat > 1) {
                cout<<"B CUT"<<endl;
            } else{
                cout<<"B DON'T"<<endl;
            }
            break;
            
        default:
            break;
    }
    cout<<endl;
}

void compwires(){
    /*
     r = red
     b = blue
     s = star
     any digit = led on
     */
    int sn = -1, nr_bat = -1, pp = -1;
    
    int wirecode; //bitwise -> red, blue, star, led
    string input;
    int index;
    
    cout<<"Enter wires: "<<endl<<endl;
    
    while (true) {
        wirecode = 0;
        index = 0;
        cout<<"Enter wire: ";
        cin>>input;
        
        if (input.at(index) == 'r') {
            wirecode = wirecode | 8;
            index++;
        }
        if (index < input.size() && input.at(index) == 'b') {
            wirecode = wirecode | 4;
            index++;
        }
        
        if (index < input.size() && input.at(index) == 'w') {
            index++;
        }
        
        if (index == 0) {
            cout<<"Exiting..."<<endl;
            return;
        }
        
        if (index < input.size() && input.at(index) == 'r') {
            wirecode = wirecode | 8;
            index++;
        }
        if (index < input.size() && input.at(index) == 'b') {
            wirecode = wirecode | 4;
            index++;
        }
        
        if (index < input.size() && input.at(index) == 'w') {
            index++;
        }
        
        if (index < input.size() && input.at(index) == 's') {
            wirecode = wirecode | 2;
            index++;
        }
        
        if (index < input.size() && input.at(index) <= '9') {
            wirecode = wirecode | 1;
            index++;
        }
        vennlookup(wirecode, &sn, &nr_bat, &pp);
    }
    
}

void whosonfirst(vector<pair<string, int>> who_first_pos, vector<vector<string>> who_first){
    string word;
    int i, j;
    string temp;
    
    cout<<"Insert display word (if blank put '<' first):";
    cin>> word;
    if (word.at(0) == '<') {
        word = "<<BLANK>>";
    }
    
    std::transform(word.begin(), word.end(), word.begin(), ::toupper);
    
    for (i=0; i<who_first_pos.size(); i++) {
        if (who_first_pos[i].first == word) {
            switch (who_first_pos[i].second) {
                case 1:
                    cout<<"Type the word in the top left"<<endl;
                    break;
                case 2:
                    cout<<"Type the word in the middle left"<<endl;
                    break;
                case 3:
                    cout<<"Type the word in the bottom left"<<endl;
                    break;
                case 4:
                    cout<<"Type the word in the top right"<<endl;
                    break;
                case 5:
                    cout<<"Type the word in the middle right"<<endl;
                    break;
                case 6:
                    cout<<"Type the word in the bottom right"<<endl;
                    break;
                default:
                    break;
            }
            break;
        }
    }
    
    cin>>word;
    std::transform(word.begin(), word.end(), word.begin(), ::toupper);
    
    cout<<"Insert anything if you don't see it. Otherwise insert 'x'."<<endl;
    for (i=0; i<who_first.size();i++) {
        if (word == who_first[i][0]) {
            for (j=1; j<who_first[i].size(); j++) {
                cout<<who_first[i][j]<<endl;
                cin>>word;
                if (word.at(0)=='x') {
                    return;
                }
            }
            return;
        }
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
    string tempstring;
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


    vector<pair<string, int>> who_first_pos;
    
    for (i=0; i<28; i++) {
        f>>tempstring>>temp;
        
        if (tempstring == "HOLDON") {
            tempstring = "HOLD ON";
        }
        
        if (tempstring == "YOUARE") {
            tempstring = "YOU ARE";
        }
        
        if (tempstring == "THEYARE") {
            tempstring = "THEY ARE";
        }
        
        who_first_pos.push_back(pair<string, int>(tempstring, temp));
    }
    
    vector<string> who_first_row;
    vector<vector<string>> who_first;
    
    for (i=0; i<28; i++) {
        who_first_row.clear();
        for (j=0; j<15; j++) {
            f>>tempstring;
            
            if (tempstring == "UHHUH") {
                tempstring = "UH HUH";
            }
            
            if (tempstring == "UHUH") {
                tempstring = "UH UH";
            }
            
            if (tempstring == "YOUARE") {
                tempstring = "YOU ARE";
            }
            
            who_first_row.push_back(tempstring);
        }
        who_first.push_back(who_first_row);
    }







    string com;

    while(com!="exit"){
        cout<<endl<<"Enter puzzle type"<<endl<<"(pass, mem, maze, wires, button, wiresec, comp, whos): ";
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
        } else if(com == "button"){
            cout<<"Entering Button"<<endl;
            button();
        } else if(com == "wiresec"){
            cout<<"Entering wire sequences"<<endl;
            wiresec();
        } else if(com == "comp"){
            cout<<"Entering complicated wires"<<endl;
            compwires();
        } else if(com == "whos"){
            cout<<"Entering Who's on first"<<endl;
            whosonfirst(who_first_pos, who_first);
        } else break;
    }




    return 0;
}
