#include <iostream>
#include <string>
#include <array>
#include <fstream>

std::string compiler(std::string code);

int main(int argc, char** argv)
{
    std::ifstream ifs(argv[1]);
    std::string srcCode;

    if (argc > 1)
    {
        srcCode.assign( (std::istreambuf_iterator<char>(ifs)),
                      (std::istreambuf_iterator<char>()   ));
    } else {
        std::cout << "No file to run";
    }
    std::cout << compiler(srcCode);
    return 0;
}

std::string compiler(std::string code)
{
    using Storage_size = std::array<char, 8>;

    const int maxStorage {8};
    Storage_size storage {};
    int ptr {0};
    int keyBeginLoop {0};
    std::string finalText {};

    for (int key{0}; key < code.length(); key++)
    {
        switch (code[key])
        {
            case '+':
                storage[ptr]++;
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
                keyBeginLoop = key;
                break;
            case ']':
                if (storage[ptr] != 0)
                {
                    key = keyBeginLoop;
                }
                break;
            default:
                break;
        }
    }
    return finalText;
}
