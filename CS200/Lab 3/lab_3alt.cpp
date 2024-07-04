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
    Node* current = root;
    bool found = false;
    while (!found) {
        if (current->data > elemToInsert) {
            if (current->llink == nullptr) {
                found = true;
            }
            else current = current->llink;
        }
        else if (current->data < elemToInsert) {
            if (current->rlink == nullptr) {
                found = true;
            }
            else current = current->rlink;
        }
        else if (current->data == elemToInsert) {
            found = true;
            cerr << "Element " << elemToInsert 
                << " is already in the list. Duplicates are not allowed.\n";
        }
    }
    if (current->data > elemToInsert) {
        current->llink = insertNode;
        count++;
    }
    else if (current->data < elemToInsert) {
        current->rlink = insertNode;
        count++;
    }
}


//Part 2
void BST::nonRecursiveInorder() const {
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
