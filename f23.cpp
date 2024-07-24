#include <iostream>
#include <list>
#include <vector>
#include <functional>

template <typename K, typename V>
class HashTable {
public:
    HashTable(size_t size = 101) : table(size) {}

    void insert(const K& key, const V& value) {
        auto& list = table[hashFunction(key) % table.size()];
        for (auto& pair : list) {
            if (pair.first == key) {
                pair.second = value;
                return;
            }
        }
        list.emplace_back(key, value);
    }

    void remove(const K& key) {
        auto& list = table[hashFunction(key) % table.size()];
        list.remove_if([&key](const std::pair<K, V>& pair) {
            return pair.first == key;
        });
    }

    bool get(const K& key, V& value) const {
        const auto& list = table[hashFunction(key) % table.size()];
        for (const auto& pair : list) {
            if (pair.first == key) {
                value = pair.second;
                return true;
            }
        }
        return false;
    }

    void display() const {
        for (size_t i = 0; i < table.size(); ++i) {
            std::cout << "Bucket " << i << ": ";
            for (const auto& pair : table[i]) {
                std::cout << "{" << pair.first << ": " << pair.second << "} ";
            }
            std::cout << std::endl;
        }
    }

private:
    std::vector<std::list<std::pair<K, V>>> table;
    std::hash<K> hashFunction;
};

int main() {
    HashTable<int, double> hashTable(5);

    hashTable.insert(1, 3.4);
    hashTable.insert(2, 4.5);
    hashTable.insert(3, 3.3);
    
    hashTable.insert(4, 7);
    hashTable.insert(5, 41);
    hashTable.insert(6, 33);
    hashTable.insert(7, 34);
    hashTable.insert(8, 45);
    hashTable.insert(9, 33);
    hashTable.insert(10, 334);
    hashTable.insert(11, 435);
    hashTable.insert(12, 3003);

    hashTable.display();
        return 0;
}
