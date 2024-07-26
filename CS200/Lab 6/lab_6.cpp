//Shin, Paul

//Part 1 Iterative Swap
void iterSwapStacks(stack<int>& startStack, stack<int>& target)
{
   while (!startStack.empty())
   {
      int size = startStack.size() - 1;
      int storage = 0;
      for (int i = 0; i < size; i++)
      {
         target.push(startStack.top());
         startStack.pop();
      }
      storage = startStack.top();
      startStack.pop(); 
      for (int j = 0; j < size; j++)
      {
         startStack.push(target.top());
         target.pop();
      }
      target.push(storage);
   }
}

//Part 2 Recursive Swap
void recurSwapStacks(stack<int>& startStack, stack<int>& target)
{
   if (!startStack.empty())
   {
      int x = startStack.top();
      startStack.pop();
      recurSwapStacks(startStack, target);
      target.push(x);
   }
}

//Part 3 STL Swap
void stlSwapStacks(stack<int>& startStack, stack<int>& target)
{
   swap(startStack, target);
}

//Part 4 Move Swap
void moveStacks(stack<int>& startStack, stack<int>& target)
{
   target = startStack;
   while(!startStack.empty())
   {
      startStack.pop();
   }
}
