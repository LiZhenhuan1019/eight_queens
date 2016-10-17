#include <iostream>
#include <cmath>
#include <vector>
class eight_queens
{
public:
    eight_queens(int chess_board_size,std::ostream& ostream = std::cout)
        :size(chess_board_size),ostream(ostream)
    {
        queen_positions.reserve(size);
    }
    void fill_and_print_all_queen_poisitions()
    {
        queen_positions.clear();
        fill_and_print_queen_poisitions_impl();
    }
private:
    void fill_and_print_queen_poisitions_impl()
    {
        if(queen_positions.size() == size)
        {
            print_all_queen_poisitions();
            return ;
        }
        for(int pos = 0;pos<size;++pos)
            if(queen_position_is_legal(pos))
            {
                queen_positions.push_back(pos);
                fill_and_print_queen_poisitions_impl();
                queen_positions.pop_back();
            }
    }
    bool queen_position_is_legal(int new_x)
    {
        int new_y = queen_positions.size();
        for(int old_y = 0; old_y < queen_positions.size();++old_y)
        {
            int old_x = queen_positions[old_y];
            if(old_x== new_x || std::abs(new_x - old_x) == new_y - old_y)
                return false;
        }
        return true;
    }

    void print_all_queen_poisitions()
    {
        ostream<<"chess "<<++counts<<'\n';
        for(int line = 0;line < queen_positions.size();++line)
            print_line(line);
        ostream<<'\n';
    }
    void print_line(int line)
    {
        int pos_x = queen_positions[line];
        for(int x = 0;x<pos_x;++x)
            ostream<<'0';
        ostream<<'1';
        for(int x = pos_x+1;x<size;++x)
            ostream<<'0';
        ostream<<'\n';
    }
    const int size;
    std::vector<int> queen_positions;
    std::ostream& ostream;
    std::size_t counts = 0;
};
int main()
{
    eight_queens queens(8);
    queens.fill_and_print_all_queen_poisitions();
    return 0;
}