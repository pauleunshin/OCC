//Shin, Paul

//Part 1

Node* insertNode = new Node();
insertNode->data = elemToInsert;
Node* current = root;

if (root == nullptr) {
    root = insertNode;
    count++;
    cerr << root->data;
}
else {
    Node* prev = nullptr;
    Node* current = root;

    while (current != nullptr) {
        if (current->data > elemToInsert) {
            prev = current;
            current = current->llink;
        }
        else if (current->data < elemToInsert) {
            prev = current;
            current = current->rlink;
        }
        else if (current->data == elemToInsert) {
            prev = current;
            current = nullptr;
            cerr << "Element " << elemToInsert 
                << " is already in the list. Duplicates are not allowed.\n";
        }
    }
    if (prev->data > elemToInsert) {
        prev->llink = insertNode;
        count++;
    }
    else if (prev->data < elemToInsert) {
        prev->rlink = insertNode;
        count++;
    }
}


//Part 2
void BST::nonRecursiveInorder() const{
    Node* current = root;
    stack<Node*> inorder;

    while (current != nullptr || !inorder.empty()) {
        if (current != nullptr) {
            inorder.push(current);
            current = current->llink;
        }
        else {
            current = inorder.top();
            inorder.pop();
            cout << current->data << " ";
            current = current->rlink;
        }
    }
    cout << endl;
}
