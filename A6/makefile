Hash.exe: driver.o DoublyLinkedList.o HashEntry.o HashTableArray.o HashTableChaining.o HashTableCuckoo.o LinkedList.o LinkedNode.o Node.o
	g++ driver.o DoublyLinkedList.o HashEntry.o HashTableArray.o HashTableChaining.o HashTableCuckoo.o LinkedList.o LinkedNode.o Node.o -o Hash.exe

driver.o: driver.cpp
	g++ -c driver.cpp -o driver.o

DoublyLinkedList.o: DoublyLinkedList.cpp
	g++ -c DoublyLinkedList.cpp -o DoublyLinkedList.o

HashEntry.o: HashEntry.cpp
	g++ -c HashEntry.cpp -o HashEntry.o

HashTableArray.o: HashTableArray.cpp
	g++ -c HashTableArray.cpp -o HashTableArray.o

HashTableChaining.o: HashTableChaining.cpp
	g++ -c HashTableChaining.cpp -o HashTableChaining.o

HashTableCuckoo.o: HashTableCuckoo.cpp
	g++ -c HashTableCuckoo.cpp -o HashTableCuckoo.o

LinkedList.o: LinkedList.cpp
	g++ -c LinkedList.cpp -o LinkedList.o

LinkedNode.o: LinkedNode.cpp
	g++ -c LinkedNode.cpp -o LinkedNode.o

Node.o: Node.cpp
	g++ -c Node.cpp -o Node.o

clean:
	rm *.o *.exe