//Shin, Paul

if (totalNodes == 0) { // Edgecase empty tree
    cerr << "Cannot delete from an empty tree.\n";
}
else if (totalNodes == 1) { //Edgecase root = itemToDelete
    if (root->data == itemToDelete) {
        delete root;
        root = nullptr;
        totalNodes--;
    }
    else cerr << "The item to delete is not in the tree.\n";
}
else {
    bool foundItem = false;
    Node* current = root;
    Node* currentParent = nullptr;

    while (current != nullptr 
        && current->data != itemToDelete) {
        currentParent = current;
        if (current->data < itemToDelete) {
            current = current->rlink;
        }
        else if (current->data > itemToDelete) {
            current = current->llink;
        }
    }

    if (current == nullptr) {
        cout << "The item to delete is not in the tree.\n";
    }
    else if (current->rlink == nullptr 
        && current->llink == nullptr) {
        if (currentParent->rlink == current) {
            currentParent->rlink = nullptr;
        }
        else {
            currentParent->llink = nullptr;
        }
        delete current;
        totalNodes--;
    }
    else if (current->rlink == nullptr 
        && current->llink != nullptr) {
        deleteNoRightSubtree(current, currentParent);
        totalNodes--;
    }
    else if (current->rlink != nullptr 
        && current->llink == nullptr) {
        deleteNoLeftSubtree(current, currentParent);
        totalNodes--;
    }
    else {
        deleteInternalNode(current);
        totalNodes--;
    }
    current = nullptr;
    currentParent = nullptr;
}