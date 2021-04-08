/*
** EPITECH PROJECT, 2021
** pacman.cpp
** File description:
** pacman.cpp
*/

#include "pacman.hpp"

arcade::Pacman::Pacman(): arcade::AGame("pacman") , _score(0), _name("Pacman"), _map(), _enemies(), _objects(), _started(false)
{
    int n = 0;
    
    _playerPosition.first = 0;
    _playerPosition.second = 0;
    std::srand(std::time(0));
    loadMap();
    while (n != 5) {
        _enemies.push_back(std::make_pair((_playerPosition.first), _playerPosition.second - n));
        n++;
    }
}

arcade::Pacman::~Pacman(){}

const std::vector<std::shared_ptr<arcade::IObject>> arcade::Pacman::play(arcade::events_e ev)
{

}

const std::string &arcade::Pacman::getName() const {
    return _name;
}

void arcade::Pacman::loadMap()
{
    std::ifstream file(".conf/Pacman_map.txt");
    std::string line;

    if (!file)
        return;
    while (std::getline(file, line)) {
        _map.push_back(line);
    }
}

static const std::map<arcade::events_e, std::pair<float, float>> DIRECTIONS = {
    {arcade::DOWN, std::make_pair(1, 0)},
    {arcade::LEFT, std::make_pair(0, -1)},
    {arcade::RIGHT, std::make_pair(0, 1)},
    {arcade::UP, std::make_pair(-1, 0)}
};

void arcade::Pacman::move(arcade::events_e dir)
{
    auto finded = DIRECTIONS.find(dir);

    if (finded == DIRECTIONS.cend() || collisionWall(dir))
        return;
    _playerMov = DIRECTIONS.at(dir);
    _started = true;
}

void arcade::Pacman::headMov()
{
    float y = _playerMov.first + _playerPosition.first;
    float x = _playerMov.second + _playerPosition.second;
    static auto start = std::chrono::steady_clock::now();
    auto end = std::chrono::steady_clock::now();

    if ((y < 1 || x < 1) || _map[y][x] == '#')
        return;
    if (std::chrono::duration_cast<std::chrono::seconds>(end - start) >= std::chrono::milliseconds(500)) {
        if (_started)
        _enemies[0].first += _playerMov.first;
        _enemies[0].second += _playerMov.second;
        start = std::chrono::steady_clock::now();
    }
}

bool arcade::Pacman::collisionWall(arcade::events_e dir)
{
    float y = _playerPosition.first + DIRECTIONS.at(dir).first;
    float x = _playerPosition.second + DIRECTIONS.at(dir).second;

    if ((y < 1 || x < 1) || _map[y][x] == '#')
        return true;
    return false;
}

std::shared_ptr<arcade::IObject> arcade::Pacman::init_object(bool is_static,
    const std::string &name, const std::vector<std::shared_ptr<arcade::IDrawable>> &drawables,
    std::pair<float, float> pos)
{
    if (is_static)
        return std::make_shared<arcade::StaticObject>(StaticObject(name, drawables, pos));
    else
        return std::make_shared<arcade::MovableObject>(MovableObject(name, drawables, pos));
}

void arcade::Pacman::init_all_object()
{
    for (std::size_t y = 0; y < _map.size(); y++) {
        for (std::size_t x = 0; _map[y][x] != '\0'; x++) {
            if (_map[y][x] == '#') {
                _objects.push_back(init_object(true, "Wall",
                    createDrawableVector("Wall"), std::make_pair(y, x)));
            }
        }
    }
}

std::vector<std::shared_ptr<arcade::IDrawable>> arcade::Pacman::createDrawableVector(
    const std::string &name) const
{
    std::vector<std::shared_ptr<arcade::IDrawable>> dest;

    if (DRAWABLE_LIST.find(name) == DRAWABLE_LIST.end())
        return dest;
    dest.push_back(std::make_shared<arcade::Drawable>(DRAWABLE_LIST.at(name)[0]));
    dest.push_back(std::make_shared<arcade::Drawable>(DRAWABLE_LIST.at(name)[1]));
    dest.push_back(std::make_shared<arcade::Drawable>(DRAWABLE_LIST.at(name)[2]));
    return dest;
}

std::shared_ptr<arcade::IObject> arcade::Pacman::updateScore()
{
    std::vector<std::shared_ptr<arcade::IDrawable>> dest;
    dest.push_back(std::make_shared<arcade::Drawable>("apple.png", 10, arcade::NO_TYPE, arcade::NONE));
    dest.push_back(std::make_shared<arcade::Drawable>("Rect", 50, arcade::NO_TYPE, arcade::RED));
    dest.push_back(std::make_shared<arcade::Drawable>("Score: " + std::to_string(_score), 2, arcade::TEXT, arcade::CYAN));

    return std::make_shared<arcade::StaticObject>(StaticObject(
        "Score", dest, std::make_pair(10, 30)));
}

bool arcade::Pacman::isLost() const
{
    float player_y = _playerPosition.first;
    float player_x = _playerPosition.second;

    for (std::size_t i = 1; i < _enemies.size(); ++i)
        if (player_y == _enemies[i].first && player_x == _enemies[i].second)
            return true;
    return (player_y < 1 || player_y > 17 || player_x < 1 || player_x > 17);
}

extern  "C" arcade::IGame *getGame() {
        auto b = new arcade::Pacman();
        return b;
}

extern "C" std::string getType() {
    return "game";
}
