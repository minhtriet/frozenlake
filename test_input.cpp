#include <iostream>
#include <fstream>
int main(int argc, char * argv[])
{
    std::fstream fp("input.txt");
   
    int n_row, n_col;
    fp >> n_row >> n_col;
    
    int start_x, start_y;
    fp >> start_x >> start_y;
    
    printf("%i\t%i\t%i\t%i\n", n_row, n_col, start_x, start_y);
    
}
