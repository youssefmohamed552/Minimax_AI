#ifndef PLAYER_HPP
#define PLAYER_HPP


#include <unordered_set>
#include "game.hpp"


class Player{
  protected:
    Game* m_game;
    int m_order;
    // std::unordered_set<Action*> m_actions;
  public:
    static int count;
    virtual ~Player();
    virtual GameState move() = 0;
};

class HumanPlayer : public Player {
  public:
    HumanPlayer(Game* game);
    virtual ~HumanPlayer();
    virtual GameState move();
};

class ComputerPlayer : public Player {
  public:
    virtual ~ComputerPlayer();

};

class RandomPlayer : public ComputerPlayer {
  public:
    RandomPlayer(Game* game);
    virtual ~RandomPlayer();
    virtual GameState move();
    int get_random_number(int bound);
};

class MiniMaxPlayer : public ComputerPlayer {
  protected:
    int m_depth;
  public:
    MiniMaxPlayer(){}
    MiniMaxPlayer(Game* game);
    virtual ~MiniMaxPlayer();
    virtual GameState move();
    virtual std::pair<int,int> eval(StateNode root, bool is_maximize, int depth);
};

class H_MiniMaxPlayer : public MiniMaxPlayer {
  public:
    H_MiniMaxPlayer(Game* game, int depth);
    virtual ~H_MiniMaxPlayer();
};



#endif /* PLAYER_HPP */
