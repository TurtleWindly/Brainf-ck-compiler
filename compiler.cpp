#include <iostream>
#include <string>
#include <array>

using Storage_size = std::array<char, 8>;

void testCompiler();
std::string compiler(std::string code);

int main()
{
    testCompiler();
    return 0;
}

void testCompiler()
{
    auto result = compiler("++++++++++[>++++++++++<-]>++++.+.");
    if ("hi" == result)
        std::cout << "compiler succeded!";
    else
    {
        std::cout << "compiler failed!\n" << "Result is: \'" << result << '\'';
    }
}

void sPlus(Storage_size& storage, int ptr)
{
    storage[ptr]++;
}

std::string compiler(std::string code)
{
    const int maxStorage {8};
    Storage_size storage {};
    int ptr {0};
    std::string finalText {};
    for (int key{0}; key < code.length(); key++)
    {
        switch (code[key])
        {
            case '+':
                sPlus(storage, ptr);
                break;
            case '-':
                storage[ptr]--;
                break;
            case '.':
                finalText += storage[ptr];
                break;
            case '>':
                ptr++;
                if (ptr >= maxStorage) ptr = 0;
                break;
            case '<':
                ptr--;
                if (ptr < 0) ptr = maxStorage - 1;
                break;
            case '[':
                // TODO: work here
                int indexBracket {};
                while (1 != 0)
                {

                }
                break;
            default:
                break;
        }
    }
    return finalText;
}
