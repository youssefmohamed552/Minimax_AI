#ifndef STATE_HPP
#define STATE_HPP

#include <vector>
#include <unordered_set>
#include "action.hpp"



enum StateStatus{
  S_TERMINAL,
  S_NON_TERMINAL
};


class State{
  protected:
    int m_utility;
    int m_huristic;
    StateStatus m_status;
  public:
    virtual ~State();
    virtual void display() const = 0;
    virtual bool act(const Action& a, int p) = 0;
    virtual void compute_utility(int player_order) = 0;
    virtual int compute_huristic(int player_order) = 0;
    virtual std::vector<Action*> action_set(int player_order) const = 0;
    virtual State* copy() = 0;
    virtual StateStatus check_status() = 0;
    virtual StateStatus check_draw() const = 0;
    virtual StateStatus status() const { return m_status; }
    virtual int utility() const { return m_utility; }
    virtual int huristic() const { return m_huristic; }

};

class StateNode{
  private:
    State* m_state;
    int m_player;
    int m_utility;
  public:
    int player_move;
    static int count;

  public:
    StateNode( State* state, int player);
    StateNode( const StateNode& other );
    virtual ~StateNode();
    State* state() const { return m_state; }
    int utility() const { return m_utility; }
    int player() const { return m_player; }
    int huristic() const { return m_state->huristic(); }
    int check_huristic() { return m_state->compute_huristic(m_player); }
    bool is_terminal() const { return m_state->status() == S_TERMINAL; }
    bool update(const Action& a, int p);

};

#endif /* STATE_HPP */
