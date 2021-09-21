struct Item
{
    int value;
    int weight;
};
struct comparitor_
{
    bool operator()(Item min, Item max)
    {

        return (double)max.value / max.weight > (double)min.value / min.weight;
    }
};
double fractionalKnapsack(int capacity, Item arr[], int n)
{
    priority_queue<Item, vector<Item>, comparitor_> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }

    double total_value = 0;
    while (capacity && pq.size())
    {
        auto top = pq.top();
        pq.pop();
        if (top.weight <= capacity)
        {
            total_value += top.value;
            capacity -= top.weight;
        }
        else
        {
            total_value += (double)top.value / top.weight * capacity;
            capacity = 0;
        }
    }
    return total_value;
}