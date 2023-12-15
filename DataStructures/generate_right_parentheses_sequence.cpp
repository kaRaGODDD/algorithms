#include <iostream>
#include <string>

void generate_right_sequence(std::string s,int a, int b) {
    if (b == 0) {
        std::cout << s << "\n";
    }
    if (a > 0) {
        generate_right_sequence(s+"(",a-1,b);
    }
    if (b > a) {
        generate_right_sequence(s+")",a,b-1);
    }
}

//How many?? Catalan numbers

int main() {
    int n;
    std::cin >> n;
    generate_right_sequence("",n,n);

    return EXIT_SUCCESS;
}
