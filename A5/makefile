RBT.exe: driver.o BinaryTree.o TreeNode.o RedBlackTree.o 
	g++ driver.o BinaryTree.o TreeNode.o RedBlackTree.o -o RBT.exe

driver.o: driver.cpp
	g++ -c driver.cpp -o driver.o

BinaryTree.o: BinaryTree.cpp
	g++ -c BinaryTree.cpp -o BinaryTree.o

TreeNode.o: TreeNode.cpp
	g++ -c TreeNode.cpp -o TreeNode.o

RedBlackTree.o: RedBlackTree.cpp
	g++ -c RedBlackTree.cpp -o RedBlackTree.o

clean:
	rm *.o *.exe