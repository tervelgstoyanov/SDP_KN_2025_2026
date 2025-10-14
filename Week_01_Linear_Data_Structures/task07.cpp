#include <iostream>
#include <queue>

const int N_MOVES = 8;
const int dX[] = { 1, 1, -1, -1, 2, -2, 2, -2 },
          dY[] = { 2, -2, 2, -2, 1, 1, -1, -1 };

struct Position {
    int x, y;
};
struct Moves {
    Position pos;
    unsigned int k;
};

enum State {
    UNVISITED,
    IN_QUEUE,
    DONE
};

bool is_valid(unsigned int size, Position pos)
{
    return 0 <= pos.x && pos.x < size
        && 0<= pos.y && pos.y < size;
}
int getMinMoves(
    std::size_t size,
    Position start,
    Position end
) {
    std::queue<Moves> moves;
    std::vector<std::vector<State>> visited(size, std::vector<State>(size, UNVISITED));
    moves.push({start, 0});
    
    while (!moves.empty())
    {
        Moves current = moves.front();
        moves.pop();

        if (current.pos.x == end.x && current.pos.y == end.y)
            return current.k;

        visited[current.pos.x][current.pos.y] = DONE;
            
        for (int it = 0; it < N_MOVES; ++it)
        {
            Position next_pos = {
                current.pos.x + dX[it],
                current.pos.y + dY[it]
            };

            if (is_valid(size, next_pos) && visited[next_pos.x][next_pos.y] == UNVISITED)
            {
                moves.push({next_pos, current.k + 1});
                visited[next_pos.x][next_pos.y] = IN_QUEUE;
            }
        }
    }

    return -1;
}

int main()
{
    unsigned int n;
    std::cin >> n;
    Position start, end;
    std::cin >> start.x >> start.y;
    std::cin >> end.x >> end.y;

    std::cout << getMinMoves(n, start, end) << std::endl;

    return 0;
}