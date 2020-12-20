#include<iostream>
#include<string>
#include"coalescedHashing.h"
#include<vector>
#include<map>
#include<algorithm>
using namespace std;


int mainMenu() {
	int operation = -1;
	while (operation < 0 || operation > 11) {
		cout << "\n\n___________________________________________________________________________________";
		cout << "\n0 : Exist";
		cout << "\n1 : Store data in coalesced hashing";
		cout << "\n2 : Print coalesced hashing";
		cout << "\n3 : Delete any key from coalesced hashing";
		cout << "\n4 : Search in coalesced hashing";
		cout << "\n5 : Check size of coalesced hashing";
		cout << "\n6 : Check is coalesced hashing empty";
		cout << "\n7 : input numbers in array ";
		cout << "\n8 : compress string";
		cout << "\n9 : print number array";
		cout << "\n10 : Enter string";
		cout << "\n11 : Is possible to Rearrange characters in a string\n----->";
		cin >> operation;
		system("CLS");
	}
	return operation;
}
void updateFrequency(map<char, int> &hashTable, int &freq, char key) {
	if (hashTable[key] > freq) {
		freq = hashTable[key];
	}
}
void lowerCase(char *arr) { // convert upercase array into lower case
	for (int i = 0; arr[i] != '\0'; i++) {
		if (arr[i] >= 'A' && arr[i] <= 'Z') {
			arr[i] += 32;
		}
	}
}
void rearrange(map<char, int> hashTable, int size, char *arr) {
	int freq = 0;
	int key;
	//lowerCase(arr);//convert upper case into lower case
	while (arr[0] != '\0') {
		key = arr[0];
		hashTable[arr[0]] += 1; // if collision occur then increment 1 value
		//cout << hashTable[arr[0]];
		updateFrequency(hashTable, freq, key);
		arr++;
	}
	updateFrequency(hashTable, size, key);
	int difference = (size - freq); // is maximium frequency is less then the size or not
	if (freq < difference) {
		cout << "\nYes we can rearrange :) ";
	}
	else {
		cout << "\nNo we can't rearrange :( ";
	}
}

template<class I, class K >
struct Node {
	K key;
	I index;
	Node() {
		key = -1;
		index = -1;
	}
	Node(K k, I i) {
		key = k;
		index = i;
	}
	bool operator>(Node obj) {
		if (key > obj.key) {
			return true;
		}
		return false;
	}
	bool operator<(Node obj) {
		if (key < obj.key) {
			return true;
		}
		return false;
	}
	bool operator == (Node obj) {
		if (key == obj.key) {
			return true;
		}
		return false;
	}
	void operator =(Node obj) {
		key = obj.key;
		index = obj.index;
	}
	bool operator != (Node obj) {
		if (key != obj.key) {
			return true;
		}
		return false;
	}
};
void compress(int arr[], int n)
{
	vector <Node<int, int>> table;

	for (int i = 0; i < n; i++) { // O(N)
		Node<int, int> temp(arr[i], i);
		table.push_back(temp);
	}
	sort(table.begin(), table.end()); // O(nlog(n))

	// Put indexes of modified vector in arr[] 
	int i = 0;
	while (i < n) {//O(n)
		int tempVlaue = table[i].index;
		arr[tempVlaue] = i;
		i++;
	}
}
void printArray(int arr[], int size) {
	cout << "\n............ Compress array ............\n\n";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << "  ";
	}
}

int main() {
	
	HashMap<int, int> hash; // it will take key and value as int 
	int *intArr = NULL; // store number array 
	int size; // size of int array
	char *str = new char[36];
	map<char, int> hashTable;
	int opetion = -1;
	while (opetion) {
		opetion = mainMenu();
		int key = -1;
		int value;
		if (opetion == 1) { // insert in hash table
			while (key < 0) {
				cout << "\nEnter key : ";
				cin >> key;
			}
			cout << "Enter value : ";
			cin >> value;
			hash.insertNode(key, value);
		}
		else if (opetion == 2) { // display hash table
			hash.display();
		}
		else if (opetion == 3) { // delete from hash table
			while (key < 0) {
				cout << "\nEnter key that you want to delete : ";
				cin >> key;
			}
			hash.deleteNode(key);
		}
		else if (opetion == 4) { // search from hash table
			while (key < 0) {
				cout << "\nEnter key that you want to search : ";
				cin >> key;
			}
			if (hash.search(key)) {
				cout << "\n " << key << " present :)";
			}
			else {
				cout << "\n " << key << " not present :(";
			}
		}
		else if (opetion == 5) { // get size of hash table
			cout << "\nSize of coalesced hashing = "<<hash.sizeofMap();
		}
		else if (opetion == 6) { // find is hash table empty
			if (hash.isEmpty()) {
				cout << "\nHash table empty :(";
			}
			else {
				cout << "\nHash table not empty :)";
			}
		}
		else if (opetion == 7) { // take input in int array from user
			if (intArr != NULL) {
				delete []intArr;
			}
			size = 0;
			while (size <= 0) {
				cout << "\nEnter how many number you want to enter : ";
				cin >> size;
			}

			intArr = new int[size];
			for (int i = 0; i < size; i++) { // input numbers
				cout << "\nEnter " << i + 1 << " number : ";
				cin >> intArr[i];
			}

		}
		else if (opetion == 8) { // compress int array
			compress(intArr, size);
		}
		else if (opetion == 9) {
			printArray(intArr, size);
		}
		else if (opetion == 10) {
			cout << "\nEnter string : ";
			cin >> str;
		}
		else if (opetion == 11) {
			size = strlen(str);
			rearrange(hashTable, size, str);
		}
	}

	//free memory
	if (intArr != NULL) {
		delete[]intArr;
	}
	if (str != NULL) {
		delete[]str;
	}

	return 0;
}
