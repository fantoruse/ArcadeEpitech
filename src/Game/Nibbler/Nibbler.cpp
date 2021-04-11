/*
** EPITECH PROJECT, 2021
** nibbler.cpp.c
** File description:
** nibbler.cpp.c
*/

#include <exception>
#include "Nibbler.hpp"

arcade::Nibbler::Nibbler(): arcade::AGame("nibbler") , _applePosition(0, 0), _score(0), _name("Nibbler"), _map(), _enemies(), _objects(), _isApple(false), _started(false)
{
    int n = 0;

    std::srand(std::time(0));
    loadMap();
    while (n != 4) {
        _enemies.push_back(std::make_pair((_playerPosition.first), _playerPosition.second - n));
        n++;
    }
}

arcade::Nibbler::~Nibbler(){}

void arcade::Nibbler::updateSnake()
{
    auto prev = _enemies[0];
    auto next = _enemies[0];

    for (std::size_t i=1; i < _enemies.size(); ++i) {
        next = std::make_pair(_enemies[i].first, _enemies[i].second);
        _enemies[i] = std::make_pair(prev.first, prev.second);
        prev = next;
    }
}
const std::vector<std::shared_ptr<arcade::IObject>> arcade::Nibbler::play(arcade::events_e ev)
{
    if (_objects.empty())
        init_all_object();
    move(ev);
    headMov();
    eatApple();
    AppleGenerator();
    auto temp = _objects;
    temp.push_back(init_object(true, "apple",
            createDrawableVector("apple"), std::make_pair(_applePosition.first, _applePosition.second)));
    temp.push_back(init_object(true, "player",
        createDrawableVector("player"), std::make_pair(_enemies[0].first, _enemies[0].second)));
    for (std::size_t i = 1; i < _enemies.size(); ++i)
        temp.push_back(init_object(true, "enemie",
                    createDrawableVector("enemie"), std::make_pair(_enemies[i].first, _enemies[i].second)));
    temp.push_back(updateScore());
    return temp;
}



const std::string &arcade::Nibbler::getName() const {
    return _name;
}

void arcade::Nibbler::AppleGenerator()
{
    float rx = 0;
    float ry = 0;
    bool end = false;

    if (_isApple)
        return;
    while (!end) {
        ry = rand() % 18;
        rx = rand() % 18;
        for (auto it: _enemies) {
            if ((it.first != ry && it.second != rx) && _map[rx][ry] != '#') {
                end = true;
                break;
            }
        }
    _applePosition.first = rx;
    _applePosition.second = ry;
    _isApple = true;
    }
}

void arcade::Nibbler::loadMap()
{
    std::ifstream file(".conf/Nibbler_map.txt");
    std::string line;

    if (!file)
        throw std::runtime_error("No such file: .conf/Nibbler_map.txt");
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

void arcade::Nibbler::move(arcade::events_e dir)
{
    auto finded = DIRECTIONS.find(dir);

    if (finded == DIRECTIONS.cend() || collisionWall(dir))
        return;
    _playerMov = DIRECTIONS.at(dir);
    _started = true;
}

void arcade::Nibbler::headMov()
{
    float y = _enemies[0].first + _playerMov.first;
    float x = _enemies[0].second + _playerMov.second;
    static auto start = std::chrono::steady_clock::now();
    auto end = std::chrono::steady_clock::now();

    if ((y < 1 || x < 1) || _map[y][x] == '#')
        return;
    if (std::chrono::duration_cast<std::chrono::milliseconds>(end - start) >= std::chrono::milliseconds(500)) {
        if (_started)
            updateSnake();
        _enemies[0].first += _playerMov.first;
        _enemies[0].second += _playerMov.second;
        start = std::chrono::steady_clock::now();
    }
}

bool arcade::Nibbler::collisionWall(arcade::events_e dir)
{
    float y = _enemies[0].first + DIRECTIONS.at(dir).first;
    float x = _enemies[0].second + DIRECTIONS.at(dir).second;

    if ((y < 1 || x < 1) || _map[y][x] == '#')
        return true;
    return false;
}

std::shared_ptr<arcade::IObject> arcade::Nibbler::init_object(bool is_static,
    const std::string &name, const std::vector<std::shared_ptr<arcade::IDrawable>> &drawables,
    std::pair<float, float> pos)
{
    if (is_static)
        return std::make_shared<arcade::StaticObject>(StaticObject(name, drawables, pos));
    else
        return std::make_shared<arcade::MovableObject>(MovableObject(name, drawables, pos));
}


void arcade::Nibbler::init_all_object()
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

std::vector<std::shared_ptr<arcade::IDrawable>> arcade::Nibbler::createDrawableVector(
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

void arcade::Nibbler::eatApple()
{
    if (_enemies[0].second == _applePosition.second
    && _enemies[0].first == _applePosition.first) {
        _isApple = false;
        _enemies.push_back(std::make_pair(-100, -100));
        _score += 100;
    }
}

std::shared_ptr<arcade::IObject> arcade::Nibbler::updateScore()
{
    std::vector<std::shared_ptr<arcade::IDrawable>> dest;
    dest.push_back(std::make_shared<arcade::Drawable>("apple.png", 10, arcade::NO_TYPE, arcade::NONE));
    dest.push_back(std::make_shared<arcade::Drawable>("Rect", 50, arcade::NO_TYPE, arcade::RED));
    dest.push_back(std::make_shared<arcade::Drawable>("Score: " + std::to_string(_score), 2, arcade::TEXT, arcade::CYAN));

    return std::make_shared<arcade::StaticObject>(StaticObject(
        "Score", dest, std::make_pair(10, 30)));
}

bool arcade::Nibbler::isLost()
{
    float player_y = _enemies[0].first;
    float player_x = _enemies[0].second;
    static auto start = std::chrono::steady_clock::now();
    auto end = std::chrono::steady_clock::now();


    for (std::size_t i = 1; i < _enemies.size(); ++i) {
        if (player_y == _enemies[i].first && player_x == _enemies[i].second) {
            return true;
        }
    }
    if (std::chrono::duration_cast<std::chrono::milliseconds>(end - start) >= std::chrono::milliseconds(1000)) {
        start = std::chrono::steady_clock::now();
        return (player_y + _playerMov.first < 1 ||
            player_y + _playerMov.first > 17 ||
            player_x + _playerMov.second < 1 ||
            player_x + _playerMov.second > 17);
    }
    return false;
}

extern  "C" arcade::IGame *getGame() {
        auto b = new arcade::Nibbler();
        return b;
}

extern "C" std::string getType() {
    return "game";
}
