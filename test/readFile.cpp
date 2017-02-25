#include <iostream>
#include <fstream>
#include <cstdlib>
#include <random>

using namespace std;

double generate_random()
{
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis(0, 1);
    // for (int n = 0; n < 10; ++n) {
    //     //Use dis to transform the random unsigned int generated by gen into a double in [1, 2)
    //     std::cout << dis(gen) << ' '; //Each call to dis(gen) generates a new random double
    // }
    // std::cout << '\n';
    return dis(gen);
}

int main() {
    string line;
    ifstream graph ("graph.txt");

    if(graph.is_open())
    {
        while (getline (graph, line))
        {
            cout << line.at(0) << "->" << line.at(2) << '\n';
        }
        graph.close();
    }

    else cout << "Unable to open file";

    double rand = generate_random();
    cout << rand << endl;

    return 0; 
}
