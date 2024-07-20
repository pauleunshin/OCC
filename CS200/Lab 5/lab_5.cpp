//Shin, Paul

//Part 1 hashValue
int hashValue(int key, int j, int capacity)
{
	return (((3 * key) + 3) + (j * j)) % capacity;
}

//Part 2 insertKey
void insertKey(int table[], int capacity,
    int& numOfElements, int key)
{
    int j = 0;
    bool foundIndex = false;
    while (j < LIMIT && !foundIndex)
    {
        int hashVal = hashValue(key, j, capacity);
        if (table[hashVal] == key)
        {
            cerr << "Key " << key << " is a duplicate.\n";
            foundIndex = true;
        }
        else if (table[hashVal] == 0 || table[hashVal] == -2)
        {
            table[hashVal] = key;
            foundIndex = true;
            numOfElements++;
        }
        j++;
    }
    if (j == LIMIT) 
        cerr << "Key " << key << " not inserted. Need to rehash.\n";
}

//Part 3 searchKey
bool searchKey(const int table[], int capacity, int key)
{
    int j = 0;
    while (j < LIMIT)
    {
        int hashVal = hashValue(key, j, capacity);
        if (table[hashVal] == key) return true;
        else if (table[hashVal] == 0) return false;
        j++;
    }
    return false;
}

//Part 4 deleteKey
void deleteKey(int table[], int capacity,
    int& numOfElements, int key)
{
    int j = 0;
    bool foundZero = false;
    bool foundIndex = false;
    while (j < LIMIT && !foundIndex && !foundZero)
    {
        int hashVal = hashValue(key, j, capacity);
        if (table[hashVal] == 0)
            foundZero = true;
        else if (table[hashVal] == key)
        {
            foundIndex = true;
            table[hashVal] = -2;
            numOfElements--;
        }
        j++;
    }
    if (j == LIMIT || foundZero) 
        cerr << "Key " << key << " is not in the table.\n";
}