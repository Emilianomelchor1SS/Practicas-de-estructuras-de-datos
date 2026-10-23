#include <iostream>
 using namespace std;

void construirtablero() {
    for( int i =0 ; i < 6;i++)
    {
        for( int j =0 ; j < 3;j++)
        {
            if (i < 5 && i % 2 ==1) {
                cout << "___";
            } else {
                cout << "   ";
            }
            
            if (j< 2)
            {
                std::cout << "|";
            }
        }
    std::cout << std::endl;
    }
  
}
int main() {
    construirtablero();
    return 0;
}