#include <iostream>
void construirtablero() {
    for( int i =0 ; i < 3;i++)
    {
        for(int j =0 ; j < 3;j++)
        {
            std::cout << "|_|";
        }
    std::cout << std::endl;
    }
  
}
int main() {
    construirtablero();
    return 0;
}