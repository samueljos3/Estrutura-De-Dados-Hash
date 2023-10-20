#include <iostream>
#include <vector>
#include <list>

const int firstLevelSize = 10;
const int secondLevelSize = 10;

// Função de hash para o primeiro nível
int customFirstLevelHash(int key) {
    return key % firstLevelSize;
}

// Função de hash para o segundo nível
int customSecondLevelHash(int key) {
    return key % secondLevelSize;
}

class CustomHashTable {
private:
    std::vector<std::vector<std::list<int>>> customTable; // Tabela de hash com encadeamento separado duplo

public:
    CustomHashTable() {
        customTable.resize(firstLevelSize);
        for (int i = 0; i < firstLevelSize; i++) {
            customTable[i].resize(secondLevelSize);
        }
    }

    void customInsert(int key, int value) {
        int firstIndex = customFirstLevelHash(key);
        int secondIndex = customSecondLevelHash(key);
        customTable[firstIndex][secondIndex].push_back(value);
    }

    bool customFind(int key, int value) {
        int firstIndex = customFirstLevelHash(key);
        int secondIndex = customSecondLevelHash(key);
        for (int item : customTable[firstIndex][secondIndex]) {
            if (item == value) {
                return true;
            }
        }
        return false;
    }

    void customRemove(int key, int value) {
        int firstIndex = customFirstLevelHash(key);
        int secondIndex = customSecondLevelHash(key);
        customTable[firstIndex][secondIndex].remove(value);
    }
};

int main() {
    CustomHashTable customHashTable;

    // Inserir elementos na tabela hash
    customHashTable.customInsert(1, 10);
    customHashTable.customInsert(2, 20);
    customHashTable.customInsert(3, 30);

    // Verificar se um elemento está na tabela hash
    std::cout << "Encontrou 2: " << customHashTable.customFind(2, 20) << std::endl;

    // Remover um elemento da tabela hash
    customHashTable.customRemove(2, 20);
    std::cout << "Encontrou 2 após a remoção: " << customHashTable.customFind(2, 20) << std::endl;

    return 0;
}
