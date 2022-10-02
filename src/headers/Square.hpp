
enum Direction : int{
    NONE = 0,
    RIGHT = 1,
    LEFT = 2,
    UP = 3,
    DOWN = 4
};

enum State : char{
    EMPTY = ' ',
    SNAKE = '#',
    FOOD = '*',
    FLOOR_CEILING = '=',
    WALL = '|'
};

struct Square{
    State state;
    Direction direction;

    Square();
    Square(State state, Direction direction);
};