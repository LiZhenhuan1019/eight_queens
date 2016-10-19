#include <iostream>
#include <cmath>
#include <vector>

class eight_queens
{
public:
    eight_queens(int chess_board_size, std::ostream& ostream = std::cout)
        : size(chess_board_size), ostream(ostream)
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
        if (all_queens_are_placed())
        {
            print_all_queen_poisitions();
            return;
        }
        for (int column = 0; column < size; ++column)
            if (queen_position_is_legal(column))
            {
                place_queen_at_column(column);
                fill_and_print_queen_poisitions_impl();
                remove_queen_at_last_column();
            }
    }
    void place_queen_at_column(int column)
    {
        queen_positions.push_back(column);
    }
    void remove_queen_at_last_column()
    {
        queen_positions.pop_back();
    }
    bool all_queens_are_placed() const
    {
        return queen_positions.size() == size;
    }
    bool queen_position_is_legal(int new_x)
    {
        int new_y = queen_positions.size();
        for (int old_y = 0; old_y < queen_positions.size(); ++old_y)
        {
            int old_x = queen_positions[old_y];
            if (can_touch(new_x, new_y, old_x, old_y))
                return false;
        }
        return true;
    }
    bool can_touch(int new_x, int new_y, int old_x, int old_y)
    {
        return old_x == new_x || std::abs(new_x - old_x) == new_y - old_y;
    }
    void print_all_queen_poisitions()
    {
        ostream << "solution " << ++counts << '\n';
        for (int line = 0; line < queen_positions.size(); ++line)
            print_row(line);
        ostream << '\n';
    }
    void print_row(int line)
    {
        int pos_x = queen_positions[line];
        for (int x = 0; x < pos_x; ++x)
            ostream << '0';
        ostream << '1';
        for (int x = pos_x + 1; x < size; ++x)
            ostream << '0';
        ostream << '\n';
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