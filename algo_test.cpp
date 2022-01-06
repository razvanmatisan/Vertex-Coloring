#include <iostream> 
#include <list>
#include <fstream>

#include "algo.h"

using namespace std;

int main() {
    ifstream fin;
    ofstream fout;

    int num;

    for (int i = 1; i <= 12; i++) {
        switch(i) {
            case(1):
                fin.open("in/test1.in");
                fout.open("out/test1.out");
                fout << "TEST 1" << endl << endl;
                fin >> num;
                fout << "Chromatic number: " << num << endl << endl;
                break;
            case(2):
                fin.open("in/test2.in");
                fout.open("out/test2.out");
                fout << "TEST 2" << endl << endl;
                fin >> num;
                fout << "Chromatic number: " << num << endl << endl;
                break;
            case(3):
                fin.open("in/test3.in");
                fout.open("out/test3.out");
                fout << "TEST 3" << endl << endl;
                fin >> num;
                fout << "Chromatic number: " << num << endl << endl;
                break;
            case(4):
                fin.open("in/test4.in");
                fout.open("out/test4.out");
                fout << "TEST 4" << endl << endl;
                fin >> num;
                fout << "Chromatic number: " << num << endl << endl;
                break;
            case(5):
                fin.open("in/test5.in");
                fout.open("out/test5.out");
                fout << "TEST 5" << endl << endl;
                fin >> num;
                fout << "Chromatic number: " << num << endl << endl;
                break;
            case(6):
                fin.open("in/test6.in");
                fout.open("out/test6.out");
                fout << "TEST 6" << endl << endl;
                fin >> num;
                fout << "Chromatic number: " << num << endl << endl;
                break;
            case(7):
                fin.open("in/test7.in");
                fout.open("out/test7.out");
                fout << "TEST 7" << endl << endl;
                fin >> num;
                fout << "Chromatic number: " << num << endl << endl;
                break;
            case(8):
                fin.open("in/test8.in");
                fout.open("out/test8.out");
                fout << "TEST 8" << endl << endl;
                fin >> num;
                fout << "Chromatic number: " << num << endl << endl;
                break;
            case(9):
                fin.open("in/test9.in");
                fout.open("out/test9.out");
                fout << "TEST 9" << endl << endl;
                fin >> num;
                fout << "Chromatic number: " << num << endl << endl;
                break;
            case(10):
                fin.open("in/test10.in");
                fout.open("out/test10.out");
                fout << "TEST 10" << endl << endl;
                fin >> num;
                fout << "Chromatic number: " << num << endl << endl;
                break;
            case(11):
                fin.open("in/test11.in");
                fout.open("out/test11.out");
                fout << "TEST 11" << endl << endl;
                fin >> num;
                fout << "Chromatic number: " << num << endl << endl;
                break;
            case(12):
                fin.open("in/test12.in");
                fout.open("out/test12.out");
                fout << "TEST 12" << endl << endl;
                fin >> num;
                fout << "Chromatic number: " << num << endl << endl;
                break;
            default:
                cout << "Can't find file!\n";
                exit(-1);
                break;
        }

        fin >> num;
        Graph graph(num);
        int a, b;

        while (!fin.eof()) {
            fin >> a >> b;
            graph.addEdge(a, b);
        }

        graph.greedyColoring(fout);

        if (i != 11) {
            graph.backtrackingColoring(fout);
        } else {
            fout << "Too much time for Backtracking!\n";
        }

        fin.close();
        fout.close();
    }

    return 0;    
}
