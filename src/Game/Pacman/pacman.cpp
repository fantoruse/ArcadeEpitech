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
    
    _playerPosition.first = 11;
    _playerPosition.second = 10;
    std::srand(std::time(0));
    loadMap();
    _slow = 0;
    _stats = false;
    _enemies.push_back(std::make_pair(7, 10));
    while (n != 3) {
        _enemies.push_back(std::make_pair(9, 9 + n));
        n++;
    }
    n = 0;
    while (n != 4) {
        _enemiesMov.push_back(std::make_pair(0, 0));
        n++;
    }
}

arcade::Pacman::~Pacman(){}

const std::vector<std::shared_ptr<arcade::IObject>> arcade::Pacman::play(arcade::events_e ev)
{
    if (_objects.empty())
        init_all_object();
    if (ev == arcade::RESTART) {
    }
    enemiesGetOut();
    move(ev);
    headMov();
    enemiesMoves();
    checkTp();
    eatPacgum();
    checkStats();
    auto temp = _objects;
    temp.insert(temp.end(), _comsomable.begin(), _comsomable.end());
    temp.insert(temp.end(), _special.begin(), _special.end());
    temp.push_back(init_object(true, "player",
        createDrawableVector("player"), std::make_pair(_playerPosition.first, _playerPosition.second)));
    for (std::size_t i = 0; i < _enemies.size(); ++i)
        if (_stats == true) {
            temp.push_back(init_object(true, "stat",
                        createDrawableVector("stat"), std::make_pair(_enemies[i].first, _enemies[i].second)));
        }
        else {
            temp.push_back(init_object(true, "enemie",
                        createDrawableVector("enemie"), std::make_pair(_enemies[i].first, _enemies[i].second)));
        }
    temp.push_back(updateScore());
    return temp;
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

static const std::map<int, std::pair<float, float>> DIRECTIONSENEM = {
    {0, std::make_pair(1, 0)},
    {1, std::make_pair(0, -1)},
    {2, std::make_pair(0, 1)},
    {3, std::make_pair(-1, 0)}
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
    if (std::chrono::duration_cast<std::chrono::seconds>(end - start) >= std::chrono::milliseconds(450)) {
        if (_started)
        _playerPosition.first += _playerMov.first;
        _playerPosition.second += _playerMov.second;
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
            if (_map[y][x] == ' ') {
                _comsomable.push_back(init_object(true, "ball",
                    createDrawableVector("ball"), std::make_pair(y, x)));
            }
            if (_map[y][x] == '0') {
                _special.push_back(init_object(true, "special",
                    createDrawableVector("special"), std::make_pair(y, x)));
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

bool arcade::Pacman::isLost()
{
    float player_y = _playerPosition.first;
    float player_x = _playerPosition.second;

    for (std::size_t i = 0; i < _enemies.size(); ++i) {
        if (player_y == _enemies[i].first && player_x == _enemies[i].second
            && _stats == false)
            return true;
        if (_stats &&
            player_y == _enemies[i].first && player_x == _enemies[i].second) {
            _enemies[i].first = 9;
            _enemies[i].second = 10;
        }
    }
    return false;
}

void arcade::Pacman::checkStats()
{
    static auto start = std::chrono::steady_clock::now();
    auto end = std::chrono::steady_clock::now();
    static int n = 0;

    if (_stats == true) {
        if (n == 0 && _stats == true) {
            start = std::chrono::steady_clock::now();
            n++;
        }
        if (std::chrono::duration_cast<std::chrono::milliseconds>(end - start) >= std::chrono::seconds(10)) {
            _stats = false;
            _slow = 0;
            n = 0;
        }
        else
            _slow = 1000;
    }
}

void arcade::Pacman::eatPacgum()
{

    std::size_t n = 0;

    while (n != _comsomable.size()) {
        if (_playerPosition.second == _comsomable[n]->getPosition().second
        && _playerPosition.first == _comsomable[n]->getPosition().first) {
            _comsomable.erase(_comsomable.begin() + n);
            _score += 10;
            break;
        }
        n++;
    }
    n = 0;
    while (n != _special.size()) {
        if (_playerPosition.second == _special[n]->getPosition().second
        && _playerPosition.first == _special[n]->getPosition().first) {
            _special.erase(_special.begin() + n);
            _score += 50;
            _stats = true;
            break;
        }
        n++;
    }
}

void arcade::Pacman::enemiesMoves()
{
    static auto start1 = std::chrono::steady_clock::now();
    auto end1 = std::chrono::steady_clock::now();
    static auto start2 = std::chrono::steady_clock::now();
    auto end2 = std::chrono::steady_clock::now();
    std::size_t n = 0;
    bool notAWall = false;
    int dir = 0;

    if (std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1) >= std::chrono::milliseconds(1600 + _slow))
    {
        while (n != _enemiesMov.size()) {
            dir = std::rand() % 4;
            _enemiesMov[n] = DIRECTIONSENEM.at(dir);
            while (!notAWall) {
                if (_map[_enemies[n].first + _enemiesMov[n].first][_enemies[n].second + _enemiesMov[n].second] != '#') {
                    notAWall = true;
                    n++;
                    continue;
                }
                dir = std::rand() % 4;
                _enemiesMov[n] = DIRECTIONSENEM.at(dir);
            }
            notAWall = false;
        }
        start1 = std::chrono::steady_clock::now();
    }
    else if (std::chrono::duration_cast<std::chrono::milliseconds>(end2 - start2) >= std::chrono::milliseconds(750 + _slow)) {
        while (n != _enemiesMov.size()) {
            if (_map[_enemies[n].first + _enemiesMov[n].first][_enemies[n].second + _enemiesMov[n].second] != '#') {
                _enemies[n].first += _enemiesMov[n].first;
                _enemies[n].second += _enemiesMov[n].second;
            }
            n++;
        }
        start2 = std::chrono::steady_clock::now();
    }
}

void arcade::Pacman::enemiesGetOut()
{
    static auto start = std::chrono::steady_clock::now();
    auto end = std::chrono::steady_clock::now();
    std::size_t n = 1;

    if (std::chrono::duration_cast<std::chrono::milliseconds>(end - start) >= std::chrono::seconds(10)) {
        while (n != _enemies.size()) {
            if (_enemies[n].first == 9 &&
            _enemies[n].second >= 9 && _enemies[n].second <= 11) {
                _enemies[n].first = 7;
                _enemies[n].second = 10;
                break;
            }
            n++;
        }
        start = std::chrono::steady_clock::now();
    }
}

void arcade::Pacman::checkTp()
{
    std::size_t n = 0;

    if (_playerPosition.first == 9 && _playerPosition.second == 20)
        _playerPosition.second = 2;
    if (_playerPosition.first == 9 && _playerPosition.second == 1)
        _playerPosition.second = 19;
    while (n != _enemies.size()) {
        if (_enemies[n].first == 9 && _enemies[n].second == 20)
            _enemies[n].second = 2;
        if (_enemies[n].first == 9 && _enemies[n].second == 1)
            _enemies[n].second = 19;
        n++;
    }
}

extern  "C" arcade::IGame *getGame() {
        auto b = new arcade::Pacman();
        return b;
}

extern "C" std::string getType() {
    return "game";
}
