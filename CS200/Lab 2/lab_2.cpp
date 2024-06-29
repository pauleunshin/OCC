//Shin, Paul

list<int>& bfs(const vector<vector<int>>& graph, list<int>& result, const int start) {
    const int SIZE = graph.size();
    bool* arr = new bool[SIZE];
    arr[start] = true;
    queue<int> order;
    order.push(start);

    while (!order.empty()) {
        int counter = 0;
        for (auto iter : graph[order.front()]) {
            if (iter == 1) {
                if (arr[counter] != true) {
                    arr[counter] = true;
                    order.push(counter);
                }
            }
            counter++;
        }
        result.emplace_back(order.front());
        order.pop();
    }
    delete[] arr;
    arr = nullptr;
    return result;
}