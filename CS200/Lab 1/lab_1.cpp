//Shin, Paul

//Part 1
map<string, set<string>> neighbors;

neighbors = {
{"Indiana", {"Illinois", "Michigan", "Ohio"}},
{"Illinois", {"Indiana", "Iowa", "Michigan", "Missouri", "Wisconsin"}},
{"Iowa", {"Illinois", "Minnesota", "Missouri", "Nebraska", "South Dakota", "Wisconsin"}},
{"Kansas", {"Missouri", "Nebraska"}},
{"Michigan", {"Illinois", "Indiana", "Minnesota", "Ohio", "Wisconsin"}},
{"Minnesota", {"Iowa", "Michigan", "North Dakota", "South Dakota", "Wisconsin"}},
{"Missouri", {"Illinois", "Iowa", "Kansas", "Nebraska"}},
{"Nebraska", {"Iowa", "Kansas", "Missouri", "South Dakota"}},
{"North Dakota", {"Minnesota", "South Dakota"}},
{"Ohio", {"Indiana", "Michigan"}},
{"South Dakota", {"Iowa", "Minnesota", "Nebraska", "North Dakota"}},
{"Wisconsin", {"Illinois", "Iowa", "Michigan", "Minnesota"}},
};


//Part 2
void printNeighbors(const map<string, set<string>>& neighbors) {
    for (auto neighbor : neighbors) {
        cout << neighbor.first << " borders with: ";
        for (auto state : neighbor.second) {
            cout << state << " ";
        }
        cout << endl;
    }
}

//Part 3
vector<vector<int>> neighbors{
   {0,1,1,0,1,0,1,0,0,0,0,1}, //Illinois
   {1,0,0,0,1,0,0,0,0,1,0,0}, //Indiana
   {1,0,0,0,0,1,1,1,0,0,1,1}, //Iowa
   {0,0,0,0,0,0,1,1,0,0,0,0}, //Kansas
   {1,1,0,0,0,1,0,0,0,1,0,1}, //Michigan
   {0,0,1,0,1,0,0,0,1,0,1,1}, //Minnesota
   {1,0,1,1,0,0,0,1,0,0,0,0}, //Missouri
   {0,0,1,1,0,0,1,0,0,0,1,0}, //Nebraska
   {0,0,0,0,0,1,0,0,0,0,1,0}, //North Dakota
   {0,1,0,0,1,0,0,0,0,0,0,0}, //Ohio
   {0,0,1,0,0,1,0,1,1,0,0,0}, //South Dakota
   {1,0,1,0,1,1,0,0,0,0,0,0}  //Wisconsin
};

//Part 4
bool areNeighbors(const vector<string>& states,
    const vector<vector<int>>& neighbors,
    const string& state1,
    const string& state2) {

    int count = 0;
    int row = 0;
    int col = 0;
    bool rowFound = false;
    bool colFound = false;
    while (!colFound || !rowFound) {
        if (states[count] == state1) {
            row = count;
            rowFound = true;
        }
        else if (states[count] == state2) {
            col = count;
            colFound = true;
        }
        count++;
    }
    return neighbors[row][col] == 1;
}

