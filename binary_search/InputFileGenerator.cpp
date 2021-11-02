//COPYRIGHT NATHAN RICKETT 2021
//CSCE 350 SECTION 002

#include <iostream>
#include <fstream>

using std::cout;
using std::string;
using std::endl;
using std::to_string;

void makeFile10(int number) {
    string file_name = "numbers/ten" + to_string(number) + ".txt";
    std::ofstream file (file_name);
    for(int i = 0; i < 10; ++i) {
        float random_num = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/100));
        file << random_num << " ";
    }
    file.close();
}

void makeFiles100(int number) {
    string file_name = "numbers/one_hundred" + to_string(number) + ".txt";
    std::ofstream file (file_name);
    for(int i = 0; i < 100; ++i) {
        float random_num = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/100));
        file << random_num << " ";
    }
    file.close();
}

void makeFile1000(int number) {
    string file_name = "numbers/one_thousand" + to_string(number) + ".txt";
    std::ofstream file (file_name);
    for(int i = 0; i < 1000; ++i) {
        float random_num = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/100));
        file << random_num << " ";
    }
    file.close();
}

void makeFile10000(int number) {
    string file_name = "numbers/ten_thousand" + to_string(number) + ".txt";
    std::ofstream file (file_name);
    for(int i = 0; i < 10000; ++i) {
        float random_num = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/100));
        file << random_num << " ";
    }
    file.close();
}

void makeFile100000(int number) {
    string file_name = "numbers/one_hundred_thousand" + to_string(number) + ".txt";
    std::ofstream file (file_name);
    for(int i = 0; i < 100000; ++i) {
        float random_num = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/100));
        file << random_num << " ";
    }
    file.close();
}

int main() {
    for (int i = 1; i <= 100; ++i) {
        makeFile10(i);
        makeFiles100(i);
        makeFile1000(i);
        makeFile10000(i);
        makeFile100000(i);
    }
    return 0;
}
