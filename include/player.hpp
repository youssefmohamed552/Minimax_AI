#ifndef PLAYER_HPP
#define PLAYER_HPP


#include <unordered_set>
#include "game.hpp"


class Player{
  protected:
    int m_order;
    // std::unordered_set<Action*> m_actions;
  public:
    static int count;
    virtual ~Player();
    virtual GameState move(State* state) = 0;
    int order() const { return m_order;}
};

class HumanPlayer : public Player {
  public:
    HumanPlayer();
    virtual ~HumanPlayer();
    virtual GameState move(State* state) override;
};

class ComputerPlayer : public Player {
  public:
    virtual ~ComputerPlayer();

};

class RandomPlayer : public ComputerPlayer {
  public:
    RandomPlayer();
    virtual ~RandomPlayer();
    virtual GameState move(State* state) override;
    int get_random_number(int bound);
};

class MiniMaxPlayer : public ComputerPlayer {
  protected:
    int m_depth;
  public:
    MiniMaxPlayer();
    virtual ~MiniMaxPlayer();
    virtual GameState move(State* state) override;
    virtual std::pair<int,int> eval(StateNode root, bool is_maximize, int depth);
};

class H_MiniMaxPlayer : public MiniMaxPlayer {
  public:
    H_MiniMaxPlayer(int depth);
    virtual ~H_MiniMaxPlayer();
};



#endif /* PLAYER_HPP */
