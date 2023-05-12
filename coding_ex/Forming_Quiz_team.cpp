/***
 * Let (x,y) be the integer corrdinates of a student's house on a 2D plane. There are 2N students and we want to pair them into N groups. Let di be the ditance
 * between the houses of 2 students in group i. Form N groups such that cost = Σ i = 1 to N di is minimized. Output the minimum cost as a floating point number with
 * 2 digits precision in one line. Constraints: 1<= N <= 8 and 0 <= x,y <= 1000.
*/

#include <iostream>
#include <utility>
#include <vector>

int main() {    
    //  freopen("in.txt", "r", stdin); //To input test cases
    while(1) {
        int N;
        std::cin >> N;
        std::vector <std::pair<int, int>> studentLocation;

        //If N is 0, exit and end the program
        if (N == 0) {
            break;
        }

        //Else, process the input
        for (int i = 0; i < 2*N; i++) {
            int x = 0;
            int y = 0;
            std:: cin >> x >> y;
            studentLocation.push_back(std::make_pair(x,y));
        }

        for (const auto& p : studentLocation) {
            std::cout << p.first << ", " << p.second << std::endl;
        }
    }
    return 0;
}
