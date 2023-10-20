#include <iostream>
#include <vector>
#include <list>

const int firstLevelSize = 10;
const int secondLevelSize = 10;

struct KeyValue {
    int key;
    int value;

    KeyValue(int k, int v) : key(k), value(v) {}
};

// Função de hash para o primeiro nível
int firstLevelHash(int key) {
    return key % firstLevelSize;
}

// Função de hash para o segundo nível
int secondLevelHash(int key) {
    return key % secondLevelSize;
}

class HashTable {
private:
    std::vector<std::vector<std::list<KeyValue>>> table; // Tabela de hash com encadeamento separado duplo

public:
    HashTable() {
        table.resize(firstLevelSize);
        for (int i = 0; i < firstLevelSize; i++) {
            table[i].resize(secondLevelSize);
        }
    }

    // Função de inserção
    void insert(int key, int value) {
        int firstIndex = firstLevelHash(key);
        int secondIndex = secondLevelHash(key);
        table[firstIndex][secondIndex].push_back(KeyValue(key, value));
    }

    // Função de busca
    int find(int key) {
        int firstIndex = firstLevelHash(key);
        int secondIndex = secondLevelHash(key);

        for (const KeyValue &item : table[firstIndex][secondIndex]) {
            if (item.key == key) {
                return item.value;
            }
        }

        return -1; // Retornar um valor indicando que a chave não foi encontrada
    }
};

int main() {
    HashTable hashTable;

    // Inserir elementos na tabela hash
    hashTable.insert(1, 10);
    hashTable.insert(2, 20);
    hashTable.insert(3, 30);

    // Recuperar elementos da tabela hash
    int value1 = hashTable.find(1);
    int value2 = hashTable.find(2);
    int value4 = hashTable.find(4);

    if (value1 != -1) {
        std::cout << "Chave 1: " << value1 << std::endl;
    } else {
        std::cout << "Chave 1 não encontrada." << std::endl;
    }

    if (value2 != -1) {
        std::cout << "Chave 2: " << value2 << std::endl;
    } else {
        std::cout << "Chave 2 não encontrada." << std::endl;
    }

    if (value4 != -1) {
        std::cout << "Chave 4: " << value4 << std::endl;
    } else {
        std::cout << "Chave 4 não encontrada." << std::endl;
    }

    return 0;
}
