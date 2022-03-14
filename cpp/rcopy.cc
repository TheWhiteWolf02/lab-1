#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int main(const int argc, const char **argv)
{
    char ch;
    ifstream ifs1;
    int pos;
    ifs1.open(argv[1], ios::in);
    ifs1.seekg(-1, std::ios_base::end);
    pos = ifs1.tellg() + 1;

    ifs1.close();

    ifstream ifs;
    ifs.open(argv[1], ios::in);
    ofstream ofs1;
    ofs1.open(argv[2], ios::out);
    ifs.seekg(--pos);

    while (pos >= 0) {
        ifs.get(ch);
        ofs1.put(ch);
        pos--;
        ifs.seekg(pos);
    }

    ifs.close();
    ofs1.close();

    ifs1.open(argv[1], ios::in);
    while (!ifs1.eof()) {
        ifs1.get(ch);
    }
    ifs1.close();
    return 0;
}
