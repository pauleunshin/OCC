//Shin, Paul

list<int>& bfs(const vector<vector<int>>& graph, list<int>& result, const int start) {
    const int SIZE = graph.size();
    bool* arr = new bool[SIZE];
    int entryCount = 1;

    queue<int> order;
    result.emplace_back(start);
    arr[start] = true;

    int counter = 0;
    for (auto iter : graph[start]) {
        if (iter == 1) {
            arr[counter] = true;
            order.push(counter);
            entryCount++;
        }
        counter++;
    }

    while (!order.empty()) {
        counter = 0;
        if (entryCount != SIZE) {
            for (auto iter : graph[order.front()]) {
                if (iter == 1) {
                    if (arr[counter] != true) {
                        arr[counter] = true;
                        order.push(counter);
                        entryCount++;
                    }
                }
                counter++;
            }
        }
        result.emplace_back(order.front());
        order.pop();
    }

    delete[] arr;
    arr = nullptr;
    return result;
}
