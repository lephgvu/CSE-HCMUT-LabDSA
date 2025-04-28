#include <iostream>

using namespace std;

int hashFunction(int key, int capacity) {
    return key % capacity;
}

template<class K, class V>
class XHashMap {
public:
    class Entry {
    public:    
        K key;
        V value;  
        Entry* next; 
        
        Entry(K key, V value, Entry* next = 0) {
            this->key = key;
            this->value = value;
            this->next = next;
        }
    };

private:
    Entry** table; // hash table
    int capacity; // size for the hash table
    int count;   

public:
    // Constructor
    XHashMap() {
        this->capacity = 10;
        this->count = 0;
        table = new Entry*[capacity];
        //reset table to 0
        for (int i = 0; i < capacity; i++) {
            table[i] = 0;  
        }
    }
    
    ~XHashMap(){ // Destructor
        //Remove all entries in the current map
        for(int idx=0; idx < this->capacity; idx++){
            Entry* entry = this->table[idx];
            while(entry != 0){
                Entry * next = entry->next;
                delete entry;
                entry = next;
            }
        }
        //Remove table
        delete []table;
    } 
        
    // YOUR ANSWER 
    void put(int key, int value) {
        //TODO: Compute the index using the hash function
        int index = hashFunction(key, capacity);
    
        //TODO: Check if the key exists in the linked list at the index, update if found
        Entry* entry = table[index];
        while (entry != nullptr) {
            if (entry->key == key) {
                entry->value = value;
                return;
            }
            entry = entry->next;
        }
    
        //TODO: If the key doesn't exist, create and insert a new entry
        Entry* newEntry = new Entry(key, value);
        newEntry->next = table[index];
        table[index] = newEntry;
        
        //TODO: Increment the count and ensure load factor by resizing if needed
        count++;
        ensureLoadFactor(count);
    }
    
    void ensureLoadFactor(int current_size) {
        //TODO: Calculate the maximum allowed size based on the load factor (0.75 * capacity)
        int maxSize = int(0.75 * capacity);
    
        //TODO: If the current size exceeds or equals the max allowed size, trigger rehashing
        if (current_size >= maxSize) {
            //TODO: Calculate the new capacity (1.5 times the old capacity)
            int newcapacity = int(capacity * 1.5);
    
            //TODO: Call the rehash function with the new capacity
            rehash(newcapacity);
        }
    }
    
    void rehash(int newCapacity) {
        //TODO: Store the current table and capacity
        Entry** oldTable = table;
        int oldCapacity = capacity;
    
        //TODO: Create a new table with the new capacity and update the capacity
        capacity = newCapacity;
        table = new Entry*[capacity];
    
        //TODO: Initialize the new table with nullptr values
        for (int i = 0; i < capacity; i++) {
            table[i] = nullptr;
        }
    
        //TODO: For each index in the old table:
        //      - Traverse the linked list at that index
        //      - Recompute the new index for each entry using the new capacity
        //      - Insert the entry into the new table at the recomputed index
        for (int i = 0; i < oldCapacity; i++) {
            Entry* current = oldTable[i];
            while (current != nullptr) {
                Entry* tmp = current->next;
                int newIndex = hashFunction(current->key, capacity);
    
                // Insert current entry at new index in the new table
                current->next = table[newIndex];
                table[newIndex] = current;
    
                current = tmp;
            }
        }
    
        //TODO: Delete all entries in the old table by traversing each linked list and deleting nodes
        for (int i = 0; i < oldCapacity; i++) {
            Entry* delEntry = oldTable[i];
            while (delEntry && delEntry->next) {
                Entry* deleteEntry = delEntry;
                delEntry = delEntry->next;
                delete deleteEntry;
            }
        }
    
        //TODO: Delete the old table array
        delete[] oldTable;
    } 

    V& get(K key) {
        // Calculate the index using the hash function.
        int index = hashFunction(key, capacity);   

        // Access and traverse the linked list at that index.
        // If the current entry's key matches, return its value.
        Entry* entry = table[index];
        while (entry != nullptr) {
            if(entry->key == key) {
                return entry->value;
            }
            entry = entry->next;
        }
        // If not found, throw std::out_of_range("Key not found");
        throw std::out_of_range("Key not found");
    }

    V remove(int key) {
    /*
            An index need to find by using the hash function,
            then find the Entry of this index
                
            Check if the key already exists. If yes, remove the key from the table
            
            If the key doesn't exist, throw out_of_range("Key not found");
        
        */
    int index = hashFunction(key, capacity);
    Entry* entry = table[index];
    Entry* prev = nullptr;

    while (entry != nullptr) {
        if(entry->key == key) {
            V value = entry->value; 
            if (prev == nullptr) {
                table[index] = entry->next; // Remove the first entry
            } else {
                prev->next = entry->next; // Bypass the current
            }
            delete entry;
            count--;
            return value; // Return the removed value
        }
        prev = entry;
        entry = entry->next;
    }
    // If not found, throw std::out_of_range("Key not found");
    throw std::out_of_range("Key not found");
    }

    // print table method (for testing)
    void printTable() const {

        cout << "------------The hash table is shown below------------\n";
        for (int i = 0; i < capacity; i++) {
            Entry* entry = table[i];
            cout << "Index " << i << ": ";
            while (entry != 0) {
                cout << "(" << entry->key << ", " << entry->value << ") ";
                entry = entry->next;
            }
            cout << endl;
        }
        cout << "-----------------------------------------------------\n";
        
    }

};

int main() {

    return 0;
}