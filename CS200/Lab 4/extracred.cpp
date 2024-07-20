//if the tree is empty
if (root == nullptr)
{
    cerr << "Cannot delete from an empty tree." << endl;
}
//if the item is the only node
else if (root->data == itemToDelete &&
    root->llink == nullptr && root->rlink == nullptr)
{
    delete root;
    root = nullptr;
    totalNodes = 0;
}
//for other cases, loop to find the node and then delete
else
{
    Node* current = root;
    Node* parent = nullptr;
    bool found = false;

    //loop to find the node
    while (!found && current != nullptr)
    {
        if (itemToDelete < current->data)
        {
            parent = current;
            current = current->llink;
        }
        else if (itemToDelete > current->data)
        {
            parent = current;
            current = current->rlink;
        }
        else
        {
            found = true;
        }
    }

    //if the item exists, delete
    if (found)
    {
        //if it's a leaf
        if (current->llink == nullptr && current->rlink == nullptr)
        {
            if (parent->llink == current)
            {
                parent->llink = nullptr;
            }
            else
            {
                parent->rlink = nullptr;
            }

            delete current;
            current = nullptr;
        }
        //if it's internal node
        else if (current->llink == nullptr)
        {
            deleteNoLeftSubtree(current, parent);
        }
        else if (current->rlink == nullptr)
        {
            deleteNoRightSubtree(current, parent);
        }
        else
        {
            deleteInternalNode(current);
        }

        --totalNodes;
    }
    //if the item does not exist, error
    else
    {
        cerr << "The item to delete is not in the tree." << endl;
    }
}